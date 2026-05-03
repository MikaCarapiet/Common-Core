*This project has been created as part of the 42 curriculum by mcarapie.*

# Minitalk

## Description

Minitalk is a small client/server communication program written in C.
The client sends a string to the server using only UNIX signals, and the
server prints the received message.

The project uses `SIGUSR1` and `SIGUSR2` to transmit each character bit by bit.

## Instructions

Compile the project:

```sh
make
```

Start the server first:

```sh
./server
```

The server prints its PID. Use that PID to send a message from the client:

```sh
./client <server_pid> "Hello minitalk"
```

Clean object files:

```sh
make clean
```

Remove object files and executables:

```sh
make fclean
```

Rebuild the project:

```sh
make re
```

Build with debug flags:

```sh
make debug
```

## Resources

Reference documentation:

- `man signal`
- `man sigaction`
- `man kill`
- `man getpid`
- `man pause`
- `man usleep`

Helpful tutorials:

- [GeeksforGeeks: Signals in C language](https://www.geeksforgeeks.org/c/signals-c-language/)
- [GeeksforGeeks: Communication between two processes using signals in C](https://www.geeksforgeeks.org/c/signals-c-set-2/)
- [GeeksforGeeks: fork system call and process IDs in C](https://www.geeksforgeeks.org/fork-system-call/)
- [Beej's Guide to Unix IPC: Signals](https://beej.us/guide/bgipc/html/split/signals.html)

AI was used to help review the project against the subject requirements,
suggest test cases, and identify small issues such as README compliance,
Makefile target order, and incorrect `write` lengths.
