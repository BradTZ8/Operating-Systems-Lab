#define _GNU_SOURCE
// Signal handling example
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

static void signal_handler(int sig)
{
    printf("\nSignal received: %d (%s)\n", sig, strsignal(sig));
}

// Display current signal status by reading from /proc filesystem
static void print_signal_status(void)
{
    char command[256];
    snprintf(command, sizeof(command),
             "echo 'Current Signal Status:' && "
             "cat /proc/%d/status | grep -A4 Sig",
             (int)getpid());
    system(command);
    printf("\n");
}

int main(void)
{
    printf("Signal Handling Example\n");
    printf("Process ID: %d\n\n", (int)getpid());

    // Register handlers for user-defined signals.
    // SIGTERM and SIGINT retain their default termination behavior,
    // as in the supplied document.
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    signal(SIGTERM, SIG_DFL);
    signal(SIGINT, SIG_DFL);

    printf("Ready to receive signals.\n\n");
    printf("Send these signals from another terminal.\n");
    printf("     To send SIGUSR1:     kill -USR1 %d\n", (int)getpid());
    printf("     To send SIGUSR2:     kill -USR2 %d\n", (int)getpid());
    printf("     To send SIGTERM:    kill -TERM %d\n", (int)getpid());
    printf("     To interrupt:       Ctrl+C in this terminal\n");
    printf("     Check status:       cat /proc/%d/status | grep Sig\n\n",
           (int)getpid());

    // Wait for signals
    while (1) {
        printf("Waiting for a signal.\n");
        pause();
        printf("Received and processed a signal. Now waiting for the "
               "next signal.\n\n");
    }

    return 0;
}
