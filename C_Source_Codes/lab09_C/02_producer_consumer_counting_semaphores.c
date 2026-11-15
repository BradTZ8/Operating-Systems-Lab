// NOTE: the producer/consumer functions have no 'return' statement in the PDF listing.
// The listing is kept unchanged; see README.md ("Issues found in the PDF").
// Producer-Consumer Problem
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// Buffer size
#define BUFFER_SIZE 5

// Array buffer
int buffer[BUFFER_SIZE];

// Counter of the items inside the buffer
int count = 0;

// Three semaphores for the empty state, the full state and mutual exclusion
sem_t empty, full, mutex;

// Producer thread function
void* producer(void* arg) {
    // Loop that produces 10 items
    for (int i = 0; i < 10; i++) {
        // Decrease 'empty'; if the buffer is full, the producer blocks
        sem_wait(&empty);

        // Decrease the mutex to enter the critical section
        sem_wait(&mutex);

        // Add an item to the buffer and increase the counter
        buffer[count++] = i;

        // Print the number of the produced item
        printf("Produced: %d\n", i);

        // One second delay (optional)
        sleep (1);

        // Increase the mutex to leave the critical section
        sem_post(&mutex);

        // Increase 'full': one item was produced. If the consumer was blocked, wake it up
        sem_post(&full);
    }
}

// Consumer thread function
void* consumer(void* arg) {
    for (int i = 0; i < 10; i++) {
        // Decrease 'full'; if the buffer is empty, the consumer blocks
        sem_wait(&full);

        // Decrease the mutex to enter the critical section
        sem_wait(&mutex);

        // Remove an item from the buffer and decrease the counter
        int item = buffer[--count];

        // Print the consumed item
        printf("Consumed: %d\n", item);
        sleep (1);

        // Increase the mutex to leave the critical section
        sem_post(&mutex);

        // Increase 'empty': one item was consumed, so the producer can leave its wait
        sem_post(&empty);
    }
}

int main() {
    // Two thread variables for the producer and the consumer
    pthread_t prod, cons;

    // Initialise the 'empty' semaphore with the buffer size
    sem_init(&empty, 0, BUFFER_SIZE);

    // Initialise the 'full' semaphore with zero
    sem_init(&full, 0, 0);

    // Initialise the mutex semaphore with 1
    sem_init(&mutex, 0, 1);

    // Create the producer and consumer threads
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    // Wait for the threads to finish
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    // Clean up the semaphores
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
    return 0;
}
