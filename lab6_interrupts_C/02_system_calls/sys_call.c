#define _POSIX_C_SOURCE 200809L
// Trace system calls and demonstrate user/kernel mode switches
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/sysinfo.h>
#include <time.h>

static void trace_system_calls(void)
{
    printf("\nSystem Call Tracing Example\n");

    // Process ID system call
    printf("getpid() system call:\n");
    pid_t pid = getpid();
    printf("          PID: %d\n", (int)pid);

    // Resource usage system call
    printf("getrusage() system call:\n");
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) == 0) {
        printf("          User time: %ld.%06ld\n",
               (long)usage.ru_utime.tv_sec, (long)usage.ru_utime.tv_usec);
        printf("          System time: %ld.%06ld\n",
               (long)usage.ru_stime.tv_sec, (long)usage.ru_stime.tv_usec);
    } else {
        perror("getrusage");
    }

    // System information call
    printf("sysinfo() system call:\n");
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        printf("         Free memory: %lu KB\n",
               (unsigned long)(info.freeram / 1024));
        printf("         Number of processes: %u\n", info.procs);
    } else {
        perror("sysinfo failed");
    }
}

static void mode_switching(void)
{
    printf("User/Kernel Mode Switching Example\n");
    printf("First; Running in user mode & Performing some simple "
           "mathematical calculations\n");

    int result = 0;
    for (int i = 0; i < 1000; i++) {
        result += i * i;
    }
    printf("Calculation result: %d\n", result);

    // Perform a system call that triggers a user/kernel transition
    printf("\nSecond; Switching to kernel mode by executing "
           "nanosleep() which is a system call\n");

    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = 100000000; // 100 ms

    if (nanosleep(&ts, NULL) == 0) {
        printf("Third; Returned to user mode\n");
    } else {
        perror("nanosleep failed");
    }
}

int main(void)
{
    trace_system_calls();
    mode_switching();
    return 0;
}
