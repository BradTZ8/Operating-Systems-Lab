#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/sysinfo.h>
#include <time.h>

static void trace_system_calls(void) {
    printf("\nSystem Call Tracing Example\n");

    printf("getpid():\n");
    printf("PID: %d\n", (int)getpid());

    printf("getrusage():\n");
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) == 0) {
        printf("User time: %ld.%06ld\n",
               (long)usage.ru_utime.tv_sec, (long)usage.ru_utime.tv_usec);
        printf("System time: %ld.%06ld\n",
               (long)usage.ru_stime.tv_sec, (long)usage.ru_stime.tv_usec);
    } else perror("getrusage");

    printf("sysinfo():\n");
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        unsigned long long free_kb =
            ((unsigned long long)info.freeram * info.mem_unit) / 1024ULL;
        printf("Free memory: %llu KB\n", free_kb);
        printf("Number of processes: %u\n", info.procs);
    } else perror("sysinfo");
}

static void mode_switching(void) {
    puts("\nUser/Kernel Mode Switching Example");
    puts("Performing calculations in user space...");
    int result = 0;
    for (int i = 0; i < 1000; ++i) result += i * i;
    printf("Calculation result: %d\n", result);

    puts("Requesting a 100 ms sleep via nanosleep...");
    struct timespec ts = { .tv_sec = 0, .tv_nsec = 100000000L };
    if (nanosleep(&ts, NULL) == 0) puts("Returned from nanosleep; user code continues.");
    else perror("nanosleep");
}

int main(void) {
    trace_system_calls();
    mode_switching();
    return 0;
}
