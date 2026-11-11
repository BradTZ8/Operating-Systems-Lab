#include <stdio.h>
#include <sys/resource.h>

static double timeval_diff_seconds(struct timeval a, struct timeval b) {
    return (double)(b.tv_sec - a.tv_sec) +
           (double)(b.tv_usec - a.tv_usec) / 1000000.0;
}

int main(void) {
    struct rusage start, end;
    volatile unsigned long long result = 0;

    if (getrusage(RUSAGE_SELF, &start) != 0) {
        perror("getrusage (start)");
        return 1;
    }

    for (unsigned long long i = 0; i < 100000000ULL; ++i) {
        result += i % 100;
    }

    if (getrusage(RUSAGE_SELF, &end) != 0) {
        perror("getrusage (end)");
        return 1;
    }

    printf("Calculation result: %llu\n", result);
    printf("User CPU time:   %.6f seconds\n",
           timeval_diff_seconds(start.ru_utime, end.ru_utime));
    printf("System CPU time: %.6f seconds\n",
           timeval_diff_seconds(start.ru_stime, end.ru_stime));
    return 0;
}
