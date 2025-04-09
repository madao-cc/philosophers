# Philosophers

> **Objective:** Solve the classic "Dining Philosophers" problem using multithreading, mutexes, and synchronization primitives in C, exploring concurrent programming and process management.

## Table of Contents

- [Project Overview](#project-overview)
- [Problem Description](#problem-description)
- [Compilation](#compilation)
- [Usage](#usage)
- [Program Arguments](#program-arguments)
- [Rules and Constraints](#rules-and-constraints)
- [Implementation Details](#implementation-details)
- [Testing and Debugging](#testing-and-debugging)
- [Learning Outcomes](#learning-outcomes)
- [Acknowledgments](#acknowledgments)

---

## Project Overview

The **Philosophers** project addresses the "Dining Philosophers Problem," a classic synchronization problem illustrating concurrency issues such as deadlocks, race conditions, and starvation in concurrent programming.

Your implementation uses threads (`pthread`) and mutexes to synchronize philosophers who alternately eat, think, and sleep.

---

## Problem Description

Five philosophers sit at a round table with a bowl of spaghetti. Each philosopher has one fork between them and their neighbor. Philosophers alternate between:

- **Eating:** requires two forks (one from each side).
- **Thinking:** doesn’t require forks.
- **Sleeping:** resting period after eating.

The primary goal is to design a solution that avoids:

- **Deadlocks:** philosophers waiting indefinitely.
- **Starvation:** philosophers never eating.
- **Race Conditions:** unsafe concurrent access to shared resources.

---

## Compilation

Compile the project with:
```bash
make
```

This generates an executable, typically named:
- `philo` for threaded implementation.

---

## Usage

Run the program with arguments specifying the simulation settings:
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

**Example:**
```bash
./philo 5 800 200 200 7
```

---

## Program Arguments

| Argument                                      | Description                                      | Example |
| --------------------------------------------- | ------------------------------------------------ | ------- |
| `number_of_philosophers`                      | Number of philosophers at the table              | `5`     |
| `time_to_die` (milliseconds)                  | Max time a philosopher can go without eating     | `800`   |
| `time_to_eat` (milliseconds)                  | Time spent eating                                | `200`   |
| `time_to_sleep` (milliseconds)                | Time spent sleeping                              | `200`   |
| `[number_of_times_each_philosopher_must_eat]` | *(Optional)* How many times each philosopher eats| `7`     |

*If omitted, philosophers eat indefinitely.*

---

## Rules and Constraints

- Each philosopher is a separate thread.
- Forks are shared resources protected by mutexes.
- Philosophers pick forks sequentially, first the lower-numbered, then the higher-numbered, to avoid deadlocks.
- Monitor thread checks if any philosopher starves (`time_to_die` exceeded) and stops the simulation immediately.

---

## Implementation Details

**Thread and Mutex Management:**
- Philosophers: implemented as individual threads (`pthread_create`).
- Forks: represented by mutexes (`pthread_mutex_t`).

**Philosopher lifecycle:**
```
while (alive)
{
    think();
    take_forks();
    eat();
    put_forks();
    sleep();
}
```

**Synchronization:**
- Mutexes avoid concurrent access to forks.
- Carefully ordered fork acquisition prevents deadlocks.
- Separate monitoring thread for detecting starvation.

---

## Testing and Debugging

- **Edge cases to test:**
  - A single philosopher.
  - Philosophers starving if times are set incorrectly.
  - Philosophers eating only once (`number_of_times_each_philosopher_must_eat = 1`).

- Use debugging tools:
  - Valgrind (memory leaks)
  - Helgrind (thread errors)
  - ThreadSanitizer (race conditions)

**Example debug test:**
```bash
valgrind --tool=helgrind ./philo 5 800 200 200 3
```

---

## Learning Outcomes

By completing this project, you gain:

- Proficiency in **multithreading** and **mutexes** (`pthread`).
- Understanding of **concurrent programming** and synchronization challenges.
- Experience avoiding **deadlocks** and handling **starvation**.
- Skills in debugging and managing concurrency-related errors.

---

## Acknowledgments

The Philosophers project is part of the curriculum at 42 School, teaching core principles of concurrent programming, synchronization, and thread management in C.

---

This README serves as both detailed documentation for external readers and a comprehensive personal reference to revisit essential concepts and implementations.
