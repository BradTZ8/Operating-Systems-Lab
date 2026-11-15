//thread9.c
//nested threads: one thread creates another thread
#include <stdio.h>
#include <pthread.h>

// Function to be executed by the nested thread
void* nested_thread_function(void* arg) {
    printf("Hello from the nested thread!\n");
    return NULL;
}

// Function to be executed by the main thread
void* main_thread_function(void* arg) {
    pthread_t nested_thread;

    // Create the nested thread
    pthread_create(&nested_thread, NULL, nested_thread_function, NULL);

    // Wait for the nested thread to finish
    pthread_join(nested_thread, NULL);
    printf("Nested thread has finished execution.\n");
    return NULL;
}

int main() {
    pthread_t main_thread;

    // Create the main thread
    pthread_create(&main_thread, NULL, main_thread_function, NULL);

    // Wait for the main thread to finish
    pthread_join(main_thread, NULL);
    printf("Main thread has finished execution.\n");
    return 0;
}
