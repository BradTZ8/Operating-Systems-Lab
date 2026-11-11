#define _POSIX_C_SOURCE 200809L
// Producer process: coordinates with consumer using POSIX signals
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>

volatile sig_atomic_t ready_for_data = 0;
volatile sig_atomic_t data_processed = 0;

static void consumer_ready_handler(int sig)
{
    (void)sig;
    ready_for_data = 1;
    printf("Producer: Consumer is ready to receive data\n");
}

static void data_processed_handler(int sig)
{
    (void)sig;
    data_processed = 1;
    printf("Producer: Data successfully processed\n");
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <consumer_pid>\n", argv[0]);
        return 1;
    }

    pid_t consumer_pid = (pid_t)atoi(argv[1]);
    printf("Producer started (PID: %d)\n", (int)getpid());
    printf("Target consumer: %d\n", (int)consumer_pid);

    struct sigaction sa_ready, sa_processed;

    memset(&sa_ready, 0, sizeof(sa_ready));
    sa_ready.sa_handler = consumer_ready_handler;
    sigaction(SIGUSR1, &sa_ready, NULL);

    memset(&sa_processed, 0, sizeof(sa_processed));
    sa_processed.sa_handler = data_processed_handler;
    sigaction(SIGUSR2, &sa_processed, NULL);

    printf("Producer: Waiting for consumer readiness...\n");
    while (!ready_for_data) {
        pause();
    }

    // In a real application, shared memory or a pipe would carry the data.
    int data_packet = 42;
    printf("Producer: data is ready (packet=%d)\n", data_packet);

    kill(consumer_pid, SIGUSR1);
    printf("Producer: Waiting for processing confirmation...\n");

    while (!data_processed) {
        pause();
    }

    printf("Producer: Synchronization completed!\n");
    return 0;
}
