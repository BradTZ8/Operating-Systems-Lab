# Experiment 08 — Threads

## Description
Experiment 8 covers **multithreaded programming with POSIX threads (pthread)**: why threads are useful, creating and
joining threads, detached threads, cancelling, passing an argument to a thread and returning a result, running several
threads with the same function, the **race condition** caused by a shared static buffer, a private dynamic buffer per
thread, and nested threads.

## Source Files

| File | Original name in the PDF | Description | Status |
|------|--------------------------|-------------|--------|
| `01_thread1_create_and_join.c` | `thread1.c` | Creates one thread, prints from both threads and joins it. | Complete program |
| `02_thread4_argument_and_return_value.c` | `thread4.c` | Passes an `int` to a thread through `void *`; the thread returns `2 × number` in `malloc`ed memory collected by `pthread_join`. | Complete program (reads an integer from stdin) |
| `03_thread6_same_function_two_threads.c` | `thread6.c` | Two threads run the same function with different string arguments. | Complete program |
| `04_thread7_shared_static_buffer_race.c` | `thread7.c` | Two threads fill one shared static buffer — demonstrates a race condition (mixed contents). | Complete program |
| `05_thread8_dynamic_buffer_per_thread.c` | `thread8.c` | Each thread allocates its own buffer with `malloc` — no sharing, no mixing. | Complete program |
| `06_thread9_nested_threads.c` | `thread9.c` | A thread creates and joins another (nested) thread. | Complete program |

### Fragments that are documented but *not* extracted as files
These code pieces appear in the PDF as illustrations only (they are incomplete, not independent programs):

```c
/* 1) returning a local (automatic) buffer: WRONG — dangling pointer */
void *thread_function ( void *)
{
    char buffer [ 64 ] ;
    // Fill up the buffer with something good.
    return buffer;
}

/* 2) static buffer: avoids the dangling pointer but is shared by all threads running the function */
void *thread_function ( void *)
{
    static char buffer [ 64 ] ;
    // Fill up the buffer with something good.
    return buffer ;
}

/* 3) making a thread detached */
pthread_detach(thread);
```
(In fragments 1 and 2 the parameter has no name, which is not valid in a function *definition* before C23.)

## Compilation and Execution

```bash
gcc 01_thread1_create_and_join.c               -o thread1 -pthread && ./thread1
gcc 02_thread4_argument_and_return_value.c     -o thread4 -pthread && ./thread4      # type an integer
gcc 03_thread6_same_function_two_threads.c     -o thread6 -pthread && ./thread6
gcc 04_thread7_shared_static_buffer_race.c     -o thread7 -pthread && ./thread7
gcc 05_thread8_dynamic_buffer_per_thread.c     -o thread8 -pthread && ./thread8
gcc 06_thread9_nested_threads.c                -o thread9 -pthread && ./thread9
```

Run `thread1` and `thread7` several times: the output order / buffer contents vary because thread scheduling is
non-deterministic.

## Requirements
- GCC and a Linux environment with the POSIX thread library (glibc)
- Compiler flag `-pthread` (not needed with glibc 2.34 or newer, but recommended on all systems)
- The PDF suggests `sudo apt-get install libpthread-stubs0-dev`; it is normally not required