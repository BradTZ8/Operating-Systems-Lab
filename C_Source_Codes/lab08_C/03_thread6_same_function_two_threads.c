//thread6.c
//Multi threading: create two threads, both threads use the same function.
#include <stdio.h>
#include <pthread.h>

// Function to be executed by the threads
void* print_message(void* arg) {
    char* message = (char*)arg;
    printf("%s\n", message);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Messages to be printed by the threads
    char* message1 = "Hello from Thread 1!";
    char* message2 = "Hello from Thread 2!";

    // Create two threads
    pthread_create(&thread1, NULL, print_message, (void*)message1);
    pthread_create(&thread2, NULL, print_message, (void*)message2);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both threads have finished execution.\n");
    return 0;
}
