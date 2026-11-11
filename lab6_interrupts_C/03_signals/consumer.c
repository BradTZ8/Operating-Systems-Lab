#define _POSIX_C_SOURCE 200809L
// Consumer process: receives data-ready notification and acknowledges it
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

volatile sig_atomic_t data_ready = 0;
volatile sig_atomic_t producer_pid = 0;

static void data_ready_handler(int sig, siginfo_t *info, void *context)
{
    (void)sig;
    (void)context;
    data_ready = 1;
    producer_pid = (sig_atomic_t)info->si_pid;
    printf("Consumer: Data is produced by producer %d\n", (int)producer_pid);
}

static void sync_request_handler(int sig)
{
    (void)sig;
    printf("Consumer: Synchronization request received\n");
}

int main(void)
{
    printf("Consumer started (PID: %d)\n", (int)getpid());

    struct sigaction sa_data, sa_sync;

    memset(&sa_data, 0, sizeof(sa_data));
    sa_data.sa_sigaction = data_ready_handler;
    sa_data.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa_data, NULL);

    memset(&sa_sync, 0, sizeof(sa_sync));
    sa_sync.sa_handler = sync_request_handler;
    sigaction(SIGRTMIN, &sa_sync, NULL);

    printf("Consumer: Sending ready signal...\n");
    printf("Please enter producer PID: ");
    pid_t producer_pid_input;
    if (scanf("%d", &producer_pid_input) != 1) {
        fprintf(stderr, "Invalid PID\n");
        return 1;
    }

    kill(producer_pid_input, SIGUSR1);
    printf("Consumer: Ready signal sent\n");
    printf("Consumer: Waiting for data to be produced...\n");

    while (!data_ready) {
        pause();
    }

    printf("Consumer: Processing data...\n");
    sleep(2); // Simulate processing
    printf("Consumer: Processing completed\n");

    if (producer_pid > 0) {
        kill((pid_t)producer_pid, SIGUSR2);
        printf("Consumer: Processing confirmation sent\n");
    }

    printf("Consumer: Job completed!\n");
    return 0;
}
