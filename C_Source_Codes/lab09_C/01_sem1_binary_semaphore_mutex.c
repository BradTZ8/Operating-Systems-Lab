// NOTE: the thread function below has no 'return' statement in the PDF listing.
// The listing is kept unchanged; see README.md ("Issues found in the PDF").
//Sem1.c
#include <stdio.h> // Standard input-output library
#include <pthread.h> // POSIX thread library
#include <semaphore.h> // Semaphore library
#include <unistd.h> // POSIX operating system API

// Define a binary semaphore named mutex
sem_t mutex;

// Thread function definition
void* thread(void* arg) {
    // Decrease the semaphore value; if it is 0 the thread blocks
    sem_wait(&mutex);

    // Print a message: the thread entered the critical section
    printf("\n The thread has entered the critical section \n");

    // Sleep 4 seconds to simulate the time the real work would take
    sleep(4);

    // Print a message: the thread leaves the critical section
    printf("\nExiting thread\n");

    // Increase the semaphore value so other threads may enter the critical section
    sem_post(&mutex);
}

int main() {
    // Give the mutex the initial value 1
    sem_init(&mutex, 0, 1);

    // Define two thread variables
    pthread_t t1, t2;

    // Create the first thread
    pthread_create(&t1, NULL, thread, NULL);
    sleep(2);

    // Create the second thread
    pthread_create(&t2, NULL, thread, NULL);

    // Wait for the threads to terminate
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Clean up the semaphore
    sem_destroy(&mutex);
    return 0;
}
