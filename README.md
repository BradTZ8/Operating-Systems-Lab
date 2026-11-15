# Operating Systems Laboratory — Linux

\<p align="center">   \<strong>A Hands-on Learning Resource for Operating Systems\</strong> \</p>

\<p align="center">   \<a href="[https://github.com/BradTZ8/Operating-Systems-Lab](https://github.com/BradTZ8/Operating-Systems-Lab)">     \<img src="[https://img.shields.io/badge/Platform-Linux-FCC624?logo=linux&logoColor=black](https://img.shields.io/badge/Platform-Linux-FCC624?logo=linux\&logoColor=black)" alt="Linux">   \</a>   \<a href="[https://jupyter.org/](https://jupyter.org/)">     \<img src="[https://img.shields.io/badge/Jupyter-Notebook-F37626?logo=jupyter&logoColor=white](https://img.shields.io/badge/Jupyter-Notebook-F37626?logo=jupyter\&logoColor=white)" alt="Jupyter">   \</a>   \<a href="[https://www.python.org/](https://www.python.org/)">     \<img src="[https://img.shields.io/badge/Python-3.x-3776AB?logo=python&logoColor=white](https://img.shields.io/badge/Python-3.x-3776AB?logo=python\&logoColor=white)" alt="Python">   \</a>   \<a href="[https://gcc.gnu.org/](https://gcc.gnu.org/)">     \<img src="[https://img.shields.io/badge/C-GCC-A8B9CC?logo=c&logoColor=black](https://img.shields.io/badge/C-GCC-A8B9CC?logo=c\&logoColor=black)" alt="C">   \</a> \</p>

---

## About This Project

**Operating Systems Laboratory** is an interactive educational repository designed to introduce students to fundamental operating system concepts through practical experiments, Linux commands, shell scripting, and C programming.

The repository combines theoretical explanations with hands-on exercises to help students understand how operating systems work and how their underlying mechanisms can be observed and explored in practice.

The materials are organized into nine experiments, covering Linux fundamentals, system administration, shell scripting, interrupts, processes, threads, and synchronization mechanisms.

### Learning Objectives

By working through these experiments, students will learn how to:

- Install, configure, and work with Linux environments.
- Understand Linux commands and shell operations.
- Write and execute Bash scripts.
- Explore processes, process creation, and inter-process communication.
- Understand interrupts, signals, and system calls.
- Develop multithreaded applications using POSIX Threads.
- Implement synchronization mechanisms using semaphores.
- Compile, execute, debug, and analyze C programs in Linux.

---

## Table of Contents

- [Experiments](#experiments)
- [Repository Structure](#repository-structure)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Running the Notebooks](#running-the-notebooks)
- [C Source Codes](#c-source-codes)
- [Working with the Experiments](#working-with-the-experiments)
- [Safety Guidelines](#safety-guidelines)
- [Troubleshooting](#troubleshooting)
- [Contributing](#contributing)
- [Credits](#credits)

---

## Experiments

The course currently contains nine experiments organized into five Jupyter notebooks.

| No. | Experiment                             | Main Topics                                   | Notebook                                                 |
| :-: | -------------------------------------- | --------------------------------------------- | -------------------------------------------------------- |
|  01 | Linux Systems and Installation         | Linux fundamentals, installation              | [Experiments 1–3](OS_Laboratory_Experiments_1_2_3.ipynb) |
|  02 | Linux Configuration and Administration | System configuration and administration       | [Experiments 1–3](OS_Laboratory_Experiments_1_2_3.ipynb) |
|  03 | Linux Command Line                     | Terminal commands and command-line operations | [Experiments 1–3](OS_Laboratory_Experiments_1_2_3.ipynb) |
|  04 | Shell Scripting                        | Bash fundamentals and scripting               | [Experiments 4–6](OS_Laboratory_Experiments_4_5_6.ipynb) |
|  05 | Advanced Shell Scripting               | Advanced shell programming                    | [Experiments 4–6](OS_Laboratory_Experiments_4_5_6.ipynb) |
|  06 | Interrupts and Signals                 | Signals, system calls, C programming          | [Experiments 4–6](OS_Laboratory_Experiments_4_5_6.ipynb) |
|  07 | Processes                              | Process creation, management, and IPC         | [Experiment 7](OS_Laboratory_Experiments_7.ipynb)        |
|  08 | Threads                                | Multithreading and POSIX Threads              | [Experiment 8](OS_Laboratory_Experiments_8.ipynb)        |
|  09 | Semaphores                             | Synchronization and concurrency               | [Experiment 9](OS_Laboratory_Experiments_9.ipynb)        |

### Experiment Resources

The repository also includes:

- C source code examples.
- Practical Linux command demonstrations.
- Supporting images and educational figures.
- Additional source files for selected experiments.

---

## Repository Structure

```text
Operating-Systems-Lab/
│
├── README.md
│
├── OS_Laboratory_Experiments_1_2_3.ipynb
├── OS_Laboratory_Experiments_4_5_6.ipynb
├── OS_Laboratory_Experiments_7.ipynb
├── OS_Laboratory_Experiments_8.ipynb
├── OS_Laboratory_Experiments_9.ipynb
│
├── C_Source_Codes/
│   └── C programming examples
│
├── lab6_interrupts_C/
│   └── Interrupt and signal programming examples
│
└── images/
    └── Educational figures and illustrations
```

*Note: The structure above represents the main repository layout. Individual source directories may contain additional subdirectories and files.*

---

## Prerequisites

Before starting the experiments, make sure the following tools are available.

### Required Software

| Software                       | Purpose                           |
| ------------------------------ | --------------------------------- |
| Linux                          | Main environment for experiments  |
| Python 3                       | Running Jupyter                   |
| Jupyter Notebook or JupyterLab | Interactive educational materials |
| GCC                            | Compiling C programs              |
| GNU Make                       | Building programs where required  |

### Recommended Environment

A Linux distribution such as Ubuntu is recommended.

If you are using Windows, you can use:

- Windows Subsystem for Linux (WSL).
- An Ubuntu virtual machine using VirtualBox or VMware.

**Important:** Many notebook cells use Linux shell commands and Jupyter's `%%bash` magic. These cells require a suitable Linux environment and are not intended to run directly in a standard Windows command prompt.

---

## Installation

### 1. Clone the Repository

```bash
git clone https://github.com/BradTZ8/Operating-Systems-Lab.git
```

### 2. Enter the Project Directory

```bash
cd Operating-Systems-Lab
```

### 3. Install System Dependencies

On Ubuntu or Debian-based distributions:

```bash
sudo apt update
sudo apt install python3 python3-pip python3-venv build-essential
```

### 4. Create a Python Virtual Environment

```bash
python3 -m venv .venv
```

Activate it:

```bash
source .venv/bin/activate
```

### 5. Install Jupyter

```bash
python -m pip install --upgrade pip
python -m pip install notebook jupyterlab
```

---

## Running the Notebooks

Start JupyterLab from the repository root:

```bash
jupyter lab
```

Alternatively, start the classic Jupyter Notebook interface:

```bash
jupyter notebook
```

Open the desired notebook from the Jupyter interface.

### Execution Instructions

1. Open the notebook corresponding to your experiment.
2. Read the theoretical explanations before executing the code.
3. Execute cells sequentially using `Shift + Enter`.
4. Observe and analyze the outputs.
5. Complete the exercises independently.
6. Record your observations and results for your laboratory report.

**Important:** Keep the repository's directory structure intact. Some notebooks reference images and source files using relative paths.

---

## C Source Codes

This repository includes C programming examples used in operating systems experiments.

The source files can be compiled using GCC.

### Basic Compilation

```bash
gcc -Wall -Wextra -std=c11 program.c -o program
```

Execute the compiled program:

```bash
./program
```

### Multithreaded Programs

Programs using POSIX Threads should be compiled with:

```bash
gcc -Wall -Wextra -std=c11 thread.c -o thread -pthread
```

### Useful Compilation Options

| Option     | Description                     |
| ---------- | ------------------------------- |
| `-Wall`    | Enable common compiler warnings |
| `-Wextra`  | Enable additional warnings      |
| `-std=c11` | Use the C11 language standard   |
| `-o`       | Specify the output executable   |
| `-pthread` | Enable POSIX Threads support    |

---

## Working with the Experiments

For the best learning experience, follow these recommendations:

- Read the complete experiment instructions before executing commands.
- Understand what each command does instead of simply copying it.
- Modify example programs and observe how their behavior changes.
- Pay attention to compiler warnings and runtime errors.
- Complete the exercises without immediately looking at possible solutions.
- Document your observations and include relevant outputs in your lab reports.

### Suggested Learning Approach

Each experiment should be approached in three stages:

1. **Understand:** Study the theoretical concepts and explanations.
2. **Experiment:** Execute the examples and investigate their behavior.
3. **Analyze:** Answer the questions and explain the observed results.

---

## Safety Guidelines

Some experiments interact directly with operating system mechanisms, including processes, signals, kernel interfaces, and synchronization primitives.

To avoid unintended system changes:

- Prefer a virtual machine or isolated Linux environment for potentially disruptive experiments.
- Understand commands before executing them with `sudo`.
- Avoid executing unfamiliar commands that modify or delete system files.
- Do not load experimental kernel modules on production systems.
- Take a virtual machine snapshot before experiments involving kernel-level operations.
- Never run destructive commands on directories containing personal or important data.

**Warning:** Kernel-level experiments and operations involving interrupt management can affect system responsiveness or stability. Follow the specific safety instructions provided in the corresponding experiment.

---

## Troubleshooting

### Jupyter command not found

Install Jupyter inside your active Python environment:

```bash
python -m pip install notebook jupyterlab
```

### Images are not displayed

Make sure the `images/` directory is present and that you are running Jupyter from the repository root.

### Permission denied

Check the permissions of the relevant file:

```bash
ls -l filename
```

If necessary, adjust permissions for files you own:

```bash
chmod +x script.sh
```

### GCC is not installed

Install the required compiler tools:

```bash
sudo apt update
sudo apt install build-essential
```

### C program compilation errors

Check the following:

- Source file name and path.
- Required header files.
- Missing semicolons or syntax errors.
- Compiler options and library dependencies.
- Whether the program requires additional compilation flags.

---

## Contributing

Contributions and suggestions are welcome.

If you find an error or would like to improve the educational materials, you can:

1. Fork this repository.
2. Create a new branch for your changes.
3. Make your improvements.
4. Test the modified notebooks and source code.
5. Submit a Pull Request describing your changes.

For bugs or content-related issues, please use the GitHub Issues section.

When contributing, please:

- Keep explanations clear and technically accurate.
- Follow consistent formatting conventions.
- Test code examples before submitting changes.
- Avoid introducing unnecessary dependencies.
- Include references when using external educational materials.

---

## Updating the Repository

To obtain the latest version:

```bash
git pull origin main
```

If you have local modifications, commit or back them up before updating.

---

## Credits

**Course Instructors:**

- Bardia Talebian
- Amirhosein Azhdarnezhad

**Repository Maintainer:**

- [@BradTZ8](https://github.com/BradTZ8)

---

## License

No license has currently been specified for this repository.

Please contact the repository maintainer regarding permissions for redistribution, modification, or reuse of the educational materials.

---

\<p align="center">
&#x20; \<strong>Learn by Doing. Understand by Experimenting.\</strong>
&#x20; \<br>
&#x20; Operating Systems Laboratory — Linux
\</p>
