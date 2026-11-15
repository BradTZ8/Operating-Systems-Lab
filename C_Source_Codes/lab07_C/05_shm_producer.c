// IPC with Shared Memory; Process 1: The Producer
// producer.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define SHM_SIZE 1024 // Size of shared memory segment

int main () {
    // Create a file to be used in key production
    FILE *f = fopen("shmfile", "w");
    if (f) fclose(f);

    // Generate unique key for shared memory
    key_t key = ftok("shmfile", 65);

    // Create shared memory segment
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);

    // Attach shared memory to process address space
    char *str = (char*) shmat(shmid, NULL, 0);

    // Get input from user and write to shared memory
    printf("Producer Process; Enter data: ");
    fgets(str, SHM_SIZE, stdin);

    printf("Data is written to shared memory: %s\n", str);

    // Wait for the consumer to read data
    // Consumer will signal by writing '*' to first byte
    printf("Waiting for consumer to read data...\n");
    while (*str != '*') {
        sleep(1); // Sleep for 1 second
    }

    // Detach from shared memory
    shmdt(str);

    // Mark shared memory segment for destruction
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
