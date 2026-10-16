# Philosophers

A concurrency and synchronization project developed as part of the 42 School curriculum.

## 📖 About

**Philosophers** is a project based on the classic *Dining Philosophers Problem*, designed to introduce concurrent programming, threads, mutexes, and resource sharing.

Several philosophers sit around a table. Each philosopher alternates between eating, thinking, and sleeping. To eat, a philosopher must acquire two forks, while avoiding deadlocks and ensuring that the simulation follows the specified rules.

The goal is to build a reliable simulation while managing shared resources and monitoring the philosophers' states.

## 🎯 Objectives

- Understand threads and concurrent execution.
- Implement synchronization using mutexes.
- Manage shared resources safely.
- Prevent data races and deadlocks.
- Monitor philosopher states and detect deaths.
- Handle command-line arguments and invalid inputs.
- Manage memory and clean up resources correctly.

## 🍝 Simulation Rules

Each philosopher follows a cycle of activities:

| State | Description |
| ----- | ----------- |
| `Thinking` | The philosopher is thinking. |
| `Eating` | The philosopher has acquired the required forks and is eating. |
| `Sleeping` | The philosopher is resting before thinking again. |
| `Died` | The philosopher has exceeded the allowed time without eating. |

The simulation uses a shared table where forks are resources between neighboring philosophers. Synchronization is required to prevent conflicting access and keep the simulation consistent.

Depending on the configuration, the simulation can stop when a philosopher dies or when every philosopher has eaten the required number of times.

## 🛠️ Technologies

- **Language:** C
- **Concurrency:** POSIX threads (`pthreads`)
- **Synchronization:** Mutexes
- **Build system:** Make
- **Environment:** Unix / Linux
- **Version control:** Git

## 🚀 Getting Started

### Prerequisites

You need a C compiler, `make`, and a Unix/Linux environment with POSIX thread support.

### Compilation

Clone the repository and enter the project directory:

```bash
git clone https://github.com/julienroh/philosophers.git
cd philosophers
```

Compile the project:

```bash
make
```

This should generate the `philo` executable.

### Usage

Run the simulation with the following arguments:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Arguments:

| Argument | Description |
| -------- | ----------- |
| `number_of_philosophers` | Number of philosophers at the table |
| `time_to_die` | Maximum time in milliseconds a philosopher can go without eating |
| `time_to_eat` | Time in milliseconds required to eat |
| `time_to_sleep` | Time in milliseconds spent sleeping |
| `number_of_times_each_philosopher_must_eat` | Optional number of meals required before the simulation ends |

Example:

```bash
./philo 5 800 200 200
```

This starts a simulation with five philosophers, an 800 ms time-to-die limit, 200 ms to eat, and 200 ms to sleep.

You can also specify a meal limit:

```bash
./philo 5 800 200 200 7
```

In this example, the simulation can stop once every philosopher has eaten seven times, provided no philosopher dies first.

## 🧹 Available Make Commands

| Command | Description |
| ------- | ----------- |
| `make` | Compile the project |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and the executable |
| `make re` | Rebuild the project from scratch |

## 📁 Project Structure

```text
philosophers/
├── includes/
│   └── philo.h
├── src/
│   ├── main.c
│   ├── init.c
│   ├── routine.c
│   ├── monitor.c
│   └── utils.c
├── Makefile
└── README.md
```

*Adjust the file names and directories to match your actual project structure.*

## 🧠 Skills Developed

- C programming and memory management
- Multithreading and concurrent execution
- Mutexes and resource synchronization
- Race condition and deadlock prevention
- Time management and simulation monitoring
- Input validation and error handling
- Compilation and project organization with Make

## 👤 Author

**Julien Roh**

[GitHub Profile](https://github.com/julienroh)
