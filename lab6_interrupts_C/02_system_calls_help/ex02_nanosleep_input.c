#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <time.h>

int main(void) {
    int seconds;
    struct timespec request;

    printf("Enter sleep duration (seconds): ");
    if (scanf("%d", &seconds) != 1 || seconds < 0) {
        fprintf(stderr, "Invalid duration. Enter a non-negative integer.\n");
        return 1;
    }

    request.tv_sec = seconds;
    request.tv_nsec = 0;

    puts("Process is sleeping...");
    if (nanosleep(&request, NULL) == 0) {
        puts("Process resumed!");
    } else {
        perror("nanosleep");
        return 1;
    }
    return 0;
}
