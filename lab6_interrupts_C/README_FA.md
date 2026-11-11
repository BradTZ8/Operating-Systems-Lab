# Lab 6 — Interrupts and Signals

## Complete Code Package and Installation Guide

This package contains the source code for **Lab 6: Interrupts and Signals**. The programs are organized into separate directories according to their purpose.

## Package Contents

| File | Description |
|---|---|
| `01_basic_C/MyCode.c` | Testing GCC installation and basic C compilation |
| `02_system_calls/sys_call.c` | Examining process IDs, resource usage, system information, and `nanosleep` |
| `03_signals/signal_test.c` | Handling SIGUSR1 and SIGUSR2 and examining signal status |
| `03_signals/producer.c` | Producer process in the synchronization example |
| `03_signals/consumer.c` | Consumer process in the synchronization example |

---

## 1. Installing the Required Tools on Ubuntu

Open a terminal and run:

```bash
sudo apt update
sudo apt install build-essential gcc make strace
```

These packages provide the tools required to compile C programs, build software, and trace system calls.

## 2. Extracting the Package

After downloading the ZIP archive, extract it and enter the project directory:

```bash
unzip lab6_interrupts_C_bundle.zip
cd lab6_interrupts_C_bundle
```

## 3. Compiling and Running a Basic C Program

Navigate to the first directory:

```bash
cd 01_basic_C
```

Compile the program:

```bash
gcc -Wall -Wextra -std=c11 MyCode.c -o MyProg
```

Run it:

```bash
./MyProg
```

Expected output:

```text
testing C compiler
```

The purpose of this exercise is to verify that GCC is installed and can successfully compile and execute a basic C program.

## 4. Examining System Calls

Navigate to the system calls directory:

```bash
cd ../02_system_calls
```

Compile the source file:

```bash
gcc -Wall -Wextra -std=c11 sys_call.c -o sys_call
```

Run the program:

```bash
./sys_call
```

### Tracing System Calls with strace

To observe the system calls made by the program, execute:

```bash
strace ./sys_call
```

To display a summary of system call statistics, execute:

```bash
strace -c ./sys_call
```

The program displays information such as:

- Process ID (PID).
- User CPU time and system CPU time.
- Available memory.
- Number of running processes.

The program also uses `nanosleep` to demonstrate a system call that transfers execution from user space into the kernel.

## 5. Working with Signals

Navigate to the signals directory:

```bash
cd ../03_signals
```

Compile the program:

```bash
gcc -Wall -Wextra -std=c11 signal_test.c -o signal_test
```

Run it:

```bash
./signal_test
```

The program displays its PID. Write down this number because it will be used to send signals from another terminal.

### Sending Signals from a Second Terminal

Open another terminal and replace `PID` with the actual process ID.

Send SIGUSR1:

```bash
kill -USR1 PID
```

Send SIGUSR2:

```bash
kill -USR2 PID
```

To examine the signal-related information maintained by the Linux kernel, run:

```bash
cat /proc/PID/status | grep Sig
```

### Testing SIGINT and SIGTERM

Return to the first terminal.

Press `Ctrl+C` to send SIGINT to the running program.

According to the original example, SIGINT and SIGTERM use their default termination behavior.

You can also send SIGTERM from the second terminal:

```bash
kill -TERM PID
```

This terminates the program. Run it again if you want to repeat the experiment.

## 6. Producer–Consumer Synchronization Using Signals

This exercise demonstrates how two independent processes can coordinate their activities using signals.

First, compile both programs:

```bash
gcc -Wall -Wextra -std=c11 producer.c -o producer
gcc -Wall -Wextra -std=c11 consumer.c -o consumer
```

### Terminal 1 — Start the Consumer

Run:

```bash
./consumer
```

The consumer displays its PID.

Write down this PID. The program will ask you to enter the producer's PID.

Keep the consumer running while you start the producer in the second terminal.

### Terminal 2 — Start the Producer

Run:

```bash
./producer CONSUMER_PID
```

Replace `CONSUMER_PID` with the PID displayed by the consumer.

The producer starts and displays its own PID.

Return to Terminal 1 and enter the producer's PID when requested.

### Expected Synchronization Sequence

The communication process follows these steps:

1. The consumer sends SIGUSR1 to indicate that it is ready.
2. After receiving the readiness signal, the producer sends a notification that the data is ready.
3. The consumer processes the simulated data.
4. After processing is complete, the consumer sends SIGUSR2 to confirm completion.

**Important:** Signals in this example are used only for synchronization. They do not carry actual data between processes.

If actual data transfer is required, mechanisms such as pipes or shared memory should be used.

---

## 7. Recommended Lab Execution Order

Complete the exercises in the following order:

| Step | Exercise | Objective |
|---|---|---|
| 1 | Basic C compilation | Verify GCC installation and compile a C program |
| 2 | System calls | Examine process information and system calls using `strace` |
| 3 | Signal handling | Send SIGUSR1 and SIGUSR2 from another terminal |
| 4 | Producer–consumer | Understand process synchronization using signals |

## 8. Troubleshooting

| Error | Possible Cause | Solution |
|---|---|---|
| `gcc: command not found` | GCC is not installed | Install `build-essential` |
| `strace: command not found` | strace is not installed | Install `strace` |
| `No such file or directory` when running a program | Incorrect directory or missing executable | Check the current directory and compile the program again |
| `Operation not permitted` when using `kill` | Insufficient permissions or incorrect PID | Verify the PID and user permissions |

---
 