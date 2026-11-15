// thread1.c : create a new thread inside another thread
/*run this code several times to observe the order of threads being executed */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to be executed by the new thread
void* thread_function(void* arg) {
    printf("Hello from new thread!\n");
    return NULL;
}

int main() {
    pthread_t thread_ID;
    printf("Hello from main thread!\n");

    // Create a new thread
    pthread_create(&thread_ID, NULL, thread_function, NULL);

    // The main program continues while the other thread executes.
    printf("Main thread is running parallel with the new thread !\n");

    // Wait for the thread to terminate.
    pthread_join(thread_ID, NULL);

    // Only the main thread is running now.
    printf("Now, only the main thread is running!\n");
    return 0;
}
