# Experiment 07 — Processes

## Description
Experiment 7 of the Operating Systems Laboratory introduces **processes**: PID / PPID, parent and child processes,
orphan and zombie processes, creating a child with `fork()`, replacing its code with `execlp()`, and three
**inter-process communication (IPC)** mechanisms — an unnamed **pipe**, **shared memory** (producer / consumer) and a
**UNIX-domain socket** (server / client).

## Source Files

| File | Original name in the PDF | Description | Status |
|------|--------------------------|-------------|--------|
| `01_proc1_get_pid_ppid.c` | `proc1.c` | Prints the PID and PPID of the current process using `getpid()` / `getppid()`. | Complete program |
| `02_proc2_fork_child.c` | `proc2.c` | Creates a child with `fork()`; the child prints its PID/PPID, the parent prints its PID and the child's PID and calls `wait(NULL)`. | Complete program |
| `03_proc3_exec_ls.c` | `proc3.c` | The child replaces its code with `ls -l` using `execlp()`; the parent waits for it. | Complete program |
| `04_pipe_parent_to_child.c` | *(no name in the PDF)* | Unnamed pipe: the parent writes a message, the child reads and prints it. | Complete program |
| `05_shm_producer.c` | `producer.c` | Shared memory, process 1: creates the segment, stores a user string, waits until the consumer writes `*`, removes the segment. | Complete program (needs the consumer) |
| `06_shm_consumer.c` | `consumer.c` | Shared memory, process 2: attaches to the segment, prints the data, signals the producer with `*`. | Complete program (needs the producer) |
| `07_socket_server.c` | `server.c` | UNIX-domain stream socket server: bind, listen, accept, read, reply `Hello from server!`. | Complete program (needs the client) |
| `08_socket_client.c` | `client.c` | UNIX-domain stream socket client: connect, send `Hello from client!`, print the reply. | Complete program (needs the server) |

### Fragments that are documented but *not* extracted as files
The PDF also shows these one-line variations of `execlp()` (modifications of `03_proc3_exec_ls.c`, not independent programs):

```c
execlp("ls", "ls", "-l", NULL);
execlp("ls", "myprog", "-l", NULL);            /* program name seen by ls becomes "myprog" */
execlp("ls", "ls", "-l", "-a", "-h", NULL);    /* several options */
```
and the general form `execlp(program, arg0, arg1, arg2, ..., NULL);`. The notebook demonstrates them with temporary
copies of `proc3.c` created by `sed`.

## Compilation and Execution

Single programs:

```bash
gcc 01_proc1_get_pid_ppid.c -o p1      && ./p1
gcc 02_proc2_fork_child.c   -o p2      && ./p2
gcc 03_proc3_exec_ls.c      -o p3      && ./p3
gcc 04_pipe_parent_to_child.c -o pipe_demo && ./pipe_demo
```

Shared memory — **two terminals, same directory, producer first**:

```bash
gcc 05_shm_producer.c -o producer
gcc 06_shm_consumer.c -o consumer
./producer      # terminal 1: type a line of text, then it waits
./consumer      # terminal 2: prints the text and signals the producer
```

Sockets — **two terminals, server first**:

```bash
gcc 07_socket_server.c -o server
gcc 08_socket_client.c -o client
./server        # terminal 1
./client        # terminal 2
```
