//thread8.c
//multi thread , one func, dynamic memory allocation
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 100

// Function to be called by threads
void* write_to_buffer(void* arg) {
    char* str = (char*)arg;
    char* buffer = (char*)malloc(BUFFER_SIZE * sizeof(char));
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        return NULL;
    }
    for (int i = 0; i < BUFFER_SIZE - 1; ++i) {
        buffer[i] = str[i % strlen(str)];
        usleep(100); // Sleep to simulate work and increase the chance of context switch
    }
    buffer[BUFFER_SIZE - 1] = '\0';
    printf("Buffer content from thread: %s\n", buffer);
    free(buffer);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create two threads
    pthread_create(&thread1, NULL, write_to_buffer, "Thread1");
    pthread_create(&thread2, NULL, write_to_buffer, "Thread2");

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}
