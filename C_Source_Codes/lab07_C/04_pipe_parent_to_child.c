// pipe_parent_to_child.c  (the PDF listing has no file name; this name was chosen for the archive)
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    int fd[2];
    char message[] = "Hello from Parent!\n";
    char buffer[100];

    pipe(fd); //Create pipe

    pid_t pid = fork();

    if (pid == 0) {
        // Child Process
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer)); //Read from pipe
        printf("Child Process received this message:%s\n", buffer);
        close(fd[0]); } // Close the Read End
    else {
        // Parent Process
        close(fd[0]);
        write(fd[1], message, strlen(message)+1); //write in pipe
        close(fd[1]); // Close the Write End
        wait(NULL); }
    return 0;
}
