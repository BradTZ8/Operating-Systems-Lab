#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

static double timeval_diff_seconds(struct timeval a, struct timeval b) {
    return (double)(b.tv_sec - a.tv_sec) +
           (double)(b.tv_usec - a.tv_usec) / 1000000.0;
}

static void report(const char *label, struct rusage a, struct rusage b) {
    printf("\n%s\n", label);
    printf("User CPU time:   %.6f seconds\n",
           timeval_diff_seconds(a.ru_utime, b.ru_utime));
    printf("System CPU time: %.6f seconds\n",
           timeval_diff_seconds(a.ru_stime, b.ru_stime));
}

int main(void) {
    struct rusage start, end;
    volatile unsigned long long result = 0;

    if (getrusage(RUSAGE_SELF, &start) != 0) {
        perror("getrusage"); return 1;
    }
    for (int i = 0; i < 10000; ++i) result += (unsigned long long)i * i;
    if (getrusage(RUSAGE_SELF, &end) != 0) {
        perror("getrusage"); return 1;
    }
    report("Calculation experiment", start, end);
    printf("Calculation checksum: %llu\n", result);

    if (getrusage(RUSAGE_SELF, &start) != 0) {
        perror("getrusage"); return 1;
    }
    for (int i = 0; i < 10000; ++i) printf("%d\n", i);
    fflush(stdout);
    if (getrusage(RUSAGE_SELF, &end) != 0) {
        perror("getrusage"); return 1;
    }
    report("printf experiment", start, end);

    if (getrusage(RUSAGE_SELF, &start) != 0) {
        perror("getrusage"); return 1;
    }
    for (int i = 0; i < 10000; ++i) {
        if (dprintf(STDOUT_FILENO, "%d\n", i) < 0) {
            perror("dprintf"); return 1;
        }
    }
    if (getrusage(RUSAGE_SELF, &end) != 0) {
        perror("getrusage"); return 1;
    }
    report("dprintf experiment", start, end);
    return 0;
}
