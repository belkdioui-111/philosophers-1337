# Philosopher - Dining Philosophers Problem

## Table of Contents
- [Description](#description)
- [Project Structure](#project-structure)
- [Features](#features)
- [Compilation](#compilation)
- [Usage](#usage)
- [Bonus](#bonus)
- [Contributing](#contributing)
- [License](#license)

## Description
The Philosopher project is an implementation of the Dining Philosophers problem, a classic synchronization and concurrency problem. The project involves creating a program that simulates philosophers sitting at a dining table, thinking and eating, while addressing issues like deadlock, starvation, and synchronization.

## Project Structure
- **Makefile**: Compilation instructions.
- **action.c**: Implementation of actions (thinking, eating, sleeping) for philosophers.
- **check_errors_and_loading_data.c**: Code for error checking and loading initial data.
- **create_forks.c**: Creation of forks for philosophers.
- **create_philo.c**: Initialization of philosophers.
- **free_all.c**: Code for freeing allocated resources.
- **ft_atoi.c**: Custom implementation of the `atoi` function.
- **get_curr_time.c**: Function to get the current time.
- **handling_data_rice.c**: Handling data related to rice (or any other shared resource).
- **init_philo.c**: Initialization of the philosopher simulation.
- **philo.c**: Main program file.
- **philo.h**: Header file containing function prototypes and necessary includes.

## Features
- **Mandatory (Threads)**:
  - Simulation of the Dining Philosophers problem using threads.
  - Proper handling of synchronization and concurrency issues.
  - Custom implementations of functions like `atoi` and time tracking.

- **Bonus (Processes)**:
  - Additional simulation using processes.
  - Explore alternative concurrency solutions.

## Compilation
Compile the project using the provided Makefile:
```bash
make
```
## Usage
Run the compiled executable with appropriate command-line arguments:
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_to_eat]
