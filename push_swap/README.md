*This project has been created as part of the 42 curriculum by mcarapie.*

# push_swap

## Description

`push_swap` is a 42 sorting project. The goal is to sort a list of integers with two stacks, named `a` and `b`, while printing only the stack operations used to perform the sort.

At the start of the program, stack `a` contains the input numbers and stack `b` is empty. The program must produce a valid sequence of operations that leaves stack `a` sorted in ascending order.

This implementation stores each stack as a singly linked list. Each node represents one stack element and points to the next element below it. The head of the list acts as the top of the stack, which makes push, swap, rotate, and reverse rotate operations natural to implement with pointer changes.

For sorting, the project uses:

- dedicated routines for stacks of 2 to 5 numbers
- radix sort with compressed indexes for larger inputs


## Instructions

### Compilation

Build the executable with:

```sh
make
```


Run a simple case:

```sh
./push_swap 4 1 3 2
```

Check a sorted input:

```sh
./push_swap 1 2 3 4 5 | wc -l
```

Check a random 100-number input:

```sh
ARG=$(seq -1000 1000 | shuf | head -100 | tr '\n' ' ')
./push_swap $ARG | wc -l
```

Check a random 500-number input:

```sh
ARG=$(seq -1000 1000 | shuf | head -500 | tr '\n' ' ')
./push_swap $ARG | wc -l
```

Import the 42 checker:

```sh
ARG="4 1 3 2"
./push_swap $ARG | ./checker_linux $ARG
```

With 500 random numbers and the checker:

```sh
ARG=$(seq -1000 1000 | shuf | head -500 | tr '\n' ' ')
./push_swap $ARG | ./checker_linux $ARG
```


## Resources

- [Radix Sort - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/radix-sort/): reference for radix sort as a digit-by-digit, non-comparison sorting algorithm.
- [Stack - Linked List Implementation - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/implement-a-stack-using-singly-linked-list/): reference for representing a stack with linked-list nodes where the head acts as the top.
- [Linked List Data Structure - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/linked-list-data-structure/): reference for linked-list structure, node links, and basic list behavior.

AI was used to help draft and organize this README, including the explanation of the implementation strategy, README structure, and resource descriptions. AI was also used to create tests to improve robustness of the program.
