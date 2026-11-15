// IPC with Shared Memory; Process 2: The Consumer
// consumer.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define SHM_SIZE 1024 // Size of shared memory segment

int main() {
    // Generate the same key as producer
    key_t key = ftok("shmfile", 65);

    // Get existing shared memory segment
    int shmid = shmget(key, SHM_SIZE, 0666);

    // Attach shared memory to process address space
    char *str = (char*) shmat(shmid, NULL, 0);

    // Wait for producer to write data
    // Check if first byte contains data (not null)
    printf("Consumer Process; Waiting for data...\n");
    while (*str == 0) {
        sleep(1); // Sleep for 1 second
    }

    // Read and display data from shared memory
    printf("Data read from shared memory: %s\n", str);

    // Signal producer by '*' that writing is finished
    *str = '*';

    // Detach from shared memory
    shmdt(str);

    return 0;
}
