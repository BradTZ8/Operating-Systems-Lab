//thread4.c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to be executed by the new thread
void* thread_function(void* arg) {
    int number = *((int*)arg); // Cast the argument
    int* result = malloc(sizeof(int)); // Allocate memory for the result
    *result = number * 2; // Example computation: double the number
    return (void*)result; // Return the result as a void pointer
}

int main() {
    pthread_t thread_ID; // Declare a thread identifier
    int number; // The integer to be passed to the thread
    int* thread_result; // Pointer to store the result from the thread

    // Get the integer from the user
    printf("Enter an integer: ");
    scanf("%d", &number);

    // Create a new thread that will run 'thread_function'
    pthread_create(&thread_ID, NULL, thread_function, &number);

    // Wait for the thread to terminate and get the result
    pthread_join(thread_ID, (void**)&thread_result);

    // Print the result
    printf("Thread returned value: %d\n", *thread_result);

    // Free the allocated memory
    free(thread_result);
    return 0;
}
