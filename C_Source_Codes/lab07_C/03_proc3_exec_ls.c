//proc3.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        // Child Process
        printf("Child process will run ls command \n");
        execlp("ls", "ls", "-l", NULL);
        return 1;
    }
    else {
        // Parent Process
        printf("Parent Process: waiting for child termination\n");
        wait(NULL);
        printf("Child Process Has terminated\n");
    }
    return 0;
}
