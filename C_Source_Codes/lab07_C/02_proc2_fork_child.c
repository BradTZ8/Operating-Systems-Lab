//proc2.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        // Child Process Code goes here
        printf("Child Process PID: %d, PPID: %d\n", getpid(), getppid());
    }
    else {
        // Parent Process Code goes here
        printf("Parent Process PID: %d, Child Process PID: %d \n", getpid(), pid);
        wait(NULL); // Parent waits till the Child terminates.
    }
    return 0;
}
