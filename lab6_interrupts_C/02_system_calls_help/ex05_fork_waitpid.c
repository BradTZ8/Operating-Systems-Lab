#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
    printf("Creating a new process...\n");
    fflush(stdout);

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("\nChild process:\n");
        printf("My PID: %d\n", (int)getpid());
        printf("My parent PID: %d\n", (int)getppid());
        puts("Child is working...");
        sleep(2);
        puts("Child finished!");
        fflush(stdout);
        _exit(0);
    }

    printf("\nParent process:\n");
    printf("My PID: %d\n", (int)getpid());
    printf("Child PID: %d\n", (int)pid);

    int status;
    if (waitpid(pid, &status, 0) < 0) {
        perror("waitpid");
        return 1;
    }

    if (WIFEXITED(status)) {
        printf("\nParent: Child exited with status %d.\n", WEXITSTATUS(status));
    } else {
        puts("\nParent: Child did not exit normally.");
    }
    return 0;
}
