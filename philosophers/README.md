*This project has been created as part of the 42 curriculum by mcarapie.*

# Philosophers

## Description

Philosophers is a version of the classic **dining philosophers** problem, used to
learn the basics of threads and mutexes in C.

A number of philosophers sit around a round table with a bowl of spaghetti in the
middle. There is one fork between each pair of neighbours, and a philosopher needs
**both** the fork on their left and the fork on their right to eat. Each philosopher
repeats the same cycle: **eat → sleep → think**. If a philosopher goes longer than
`time_to_die` milliseconds without starting a meal, they die and the simulation stops.

The goal is to keep every philosopher alive for as long as possible, without
data races, deadlocks or mixed-up output.

### How it works

- **One thread per philosopher.** Each thread runs the eat / sleep / think loop.
- **One mutex per fork.** Picking up a fork means locking its mutex, so two
  philosophers can never hold the same fork.
- **The main thread is the monitor.** It checks every philosopher's last meal time
  and stops the simulation when someone dies, or when everyone has eaten enough.
- **Two shared locks:**
  - `state_lock` protects the shared state: the stop flag, each philosopher's last
    meal time and meal count. The monitor and the philosophers both read and write
    these, so every access goes through this lock. This is also what stops a
    philosopher from dying and starting to eat at the same moment.
  - `print_lock` makes sure only one message is printed at a time, and that nothing
    is printed after a death.

### Technical choices

- **No deadlock:** every philosopher picks up the lower-numbered fork first. The
  forks are always locked in the same global order, so a circular wait is
  impossible.
- **A fair start:** even-numbered philosophers wait a moment before their first meal,
  so the odd-numbered ones get both forks first.
- **Fair turns:** after thinking, a philosopher waits a short time before reaching for
  the forks again, so a neighbour cannot be starved (this matters most with an odd
  number of philosophers).
- **Accurate timing:** sleeping is done in small steps (`usleep(500)`) while checking
  the clock and the stop flag, so philosophers wake up on time and stop quickly once
  the simulation ends.
- **Clean shutdown:** setup counts how many mutexes and threads were created, so on
  an error only those are joined and destroyed, and all memory is freed.

## Instructions

### Compile

```bash
cd philo
make
```

Other rules: `make clean` (remove object files), `make fclean` (also remove the
binary), `make re` (rebuild from scratch).

### Run

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

All times are in milliseconds, and every argument must be a positive integer.

Output format:

```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

### Examples

```bash
./philo 1 800 200 200      # one fork only: the philosopher dies at 800 ms
./philo 5 800 200 200      # nobody dies, runs until stopped with Ctrl+C
./philo 5 800 200 200 7    # stops once everyone has eaten at least 7 times
./philo 4 410 200 200      # nobody dies
./philo 4 310 200 100      # a philosopher dies
```

### Checking for data races and leaks

```bash
valgrind --tool=helgrind ./philo 4 310 200 100
valgrind --tool=drd ./philo 4 310 200 100
valgrind --leak-check=full ./philo 5 800 200 200 3
```

## Resources

- [Dining philosophers problem (Wikipedia)](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [POSIX Threads Programming (LLNL)](https://hpc-tutorials.llnl.gov/posix/)
- Manual pages: `man pthread_create`, `man pthread_join`, `man pthread_mutex_lock`,
  `man gettimeofday`, `man usleep`
- [Valgrind Helgrind manual](https://valgrind.org/docs/manual/hg-manual.html)
- [Valgrind DRD manual](https://valgrind.org/docs/manual/drd-manual.html)

### How AI was used

I used Claude (Anthropic) as a tutor while building this project. I wrote most of the
code myself, and used AI for:

- **Explanations:** threads, mutexes, casting a `void *` argument, why each lock is
  needed, and how the monitor fits in. I also asked it to quiz me on these.
- **Reviewing my code:** checking each file after I wrote it, and pointing out bugs
  such as a mutex locked twice, a missing unlock, and a wrong death formula, which I
  then fixed.
- **Testing:** writing small test programs and running the program under ThreadSanitizer,
  `leaks`, helgrind and DRD to look for data races, leaks and timing problems.
- **Understanding helgrind:** explaining the lock-order warning helgrind reported
  (forks locked in an order that forms a loop, which could cause a deadlock) and why
  locking the lower-numbered fork first removes it.
- **Changes it made at my request:** fixes to my `init.c` (setup counters and Norm
  layout), part of the argument parsing in `parse.c`, and the lock-order fix
  (lower-numbered fork first, and the short pause after thinking). I reviewed each
  change and made sure I understood it.
- **Setup:** fixing my Git and GitHub setup on macOS.
