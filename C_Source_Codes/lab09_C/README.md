# Experiment 09 — Semaphores

## Description
Experiment 9 introduces **race conditions, synchronisation and semaphores**: binary semaphores (mutex), counting
semaphores, the POSIX semaphore API (`sem_init`, `sem_wait`, `sem_post`, `sem_destroy`) and the classical
**producer–consumer** problem solved with three semaphores (`empty`, `full`, `mutex`).

## Source Files

| File | Original name in the PDF | Description | Status |
|------|--------------------------|-------------|--------|
| `01_sem1_binary_semaphore_mutex.c` | `Sem1.c` | A binary semaphore (initial value 1) lets only one of two threads at a time enter a critical section (4 s sleep inside it). | Complete program |
| `02_producer_consumer_counting_semaphores.c` | *(no name in the PDF)* | Producer–consumer with a 5-slot buffer and the semaphores `empty` (= 5), `full` (= 0) and `mutex` (= 1); 10 items. | Complete program |

All comments of the two listings were translated from Persian to English (code unchanged).

## Compilation and Execution

```bash
gcc 01_sem1_binary_semaphore_mutex.c -o SemaphoreProg -pthread && ./SemaphoreProg      # about 8 seconds
gcc 02_producer_consumer_counting_semaphores.c -o prod_cons -pthread && ./prod_cons    # about 20 seconds
```

Where the compiler does not link the libraries automatically (as stated in the PDF):

```bash
gcc 01_sem1_binary_semaphore_mutex.c -lpthread -lrt -o SemaphoreProg
```

## Requirements
- GCC and a Linux environment with POSIX semaphores
- `-pthread` (or `-lpthread -lrt` on some compilers)
- The PDF lists `build-essential`, `manpages-dev`, `gcc`, `libc-dev`, `libpthread-stubs0-dev` for a fresh system