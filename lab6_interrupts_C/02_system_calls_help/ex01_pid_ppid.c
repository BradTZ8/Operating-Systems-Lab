#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t pid = getpid();
    pid_t ppid = getppid();

    printf("Process ID (PID): %d\n", (int)pid);
    printf("Parent Process ID (PPID): %d\n", (int)ppid);
    return 0;
}
