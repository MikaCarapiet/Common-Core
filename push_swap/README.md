*This project has been created as part of the 42 curriculum by mcarapie.*

# push_swap

## Description

`push_swap` is a 42 sorting project. The goal is to sort a list of integers with two stacks, named `a` and `b`, while printing only the stack operations used to perform the sort.

At the start of the program, stack `a` contains the input numbers and stack `b` is empty. The program must produce a valid sequence of operations that leaves stack `a` sorted in ascending order.

This implementation stores each stack as a singly linked list. Each node represents one stack element and points to the next element below it. The head of the list acts as the top of the stack, which makes push, swap, rotate, and reverse rotate operations natural to implement with pointer changes.

For sorting, the project uses:

- dedicated routines for stacks of 2 to 5 numbers
- radix sort with compressed indexes for larger inputs

The radix sort does not sort directly on the original integer values. Instead, each value receives an index based on its sorted rank, from `0` to `n - 1`. The algorithm then sorts those indexes bit by bit, using only the allowed stack operations.

## Instructions

### Compilation

Build the executable with:

```sh
make
```

This creates:

```txt
./push_swap
```

Useful Makefile targets:

```sh
make clean      # remove object files
make fclean     # remove object files and binaries
make re         # rebuild from scratch
make debug      # build with debug symbols and AddressSanitizer
```

### Execution

Run the program with integers as separate arguments:

```sh
./push_swap 3 2 1
```

Example output:

```txt
ra
sa
```

If the numbers are already sorted, the program prints nothing:

```sh
./push_swap 1 2 3 4 5
```

### Input Rules

The program accepts only valid `int` values without duplicates.

Invalid input prints `Error` to standard error:

- non-numeric values
- values outside the `int` range
- duplicate numbers
- signs without digits, such as `+` or `-`

Examples of invalid input:

```sh
./push_swap 1 2 two
./push_swap 1 2 2
./push_swap 2147483648
```

### Allowed Operations

| Operation | Description |
| --- | --- |
| `sa` | Swap the first two elements of stack `a` |
| `sb` | Swap the first two elements of stack `b` |
| `ss` | Run `sa` and `sb` at the same time |
| `pa` | Push the top element of `b` onto `a` |
| `pb` | Push the top element of `a` onto `b` |
| `ra` | Rotate stack `a` upward |
| `rb` | Rotate stack `b` upward |
| `rr` | Run `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack `a` |
| `rrb` | Reverse rotate stack `b` |
| `rrr` | Run `rra` and `rrb` at the same time |

### Quick Tests

Build:

```sh
make re
```

Run a simple case:

```sh
./push_swap 4 1 3 2
```

Check that sorted input produces no operations:

```sh
./push_swap 1 2 3 4 5 | wc -l
```

Check a random 100-number input:

```sh
ARG="$(jot -r 100 -1000 1000 | sort -u | head -100 | tr '\n' ' ')"
./push_swap $ARG | wc -l
```

Check a random 500-number input:

```sh
ARG="$(jot -r 1000 -10000 10000 | sort -u | head -500 | tr '\n' ' ')"
./push_swap $ARG | wc -l
```

If you have the 42 checker available:

```sh
ARG="4 1 3 2"
./push_swap $ARG | ./checker_OS $ARG
```

With 500 random numbers and the checker:

```sh
ARG="$(jot -r 1000 -10000 10000 | sort -u | head -500 | tr '\n' ' ')"
./push_swap $ARG | ./checker_OS $ARG
```

## Technical Choices

### Linked Lists as Stacks

The stack is implemented with this node shape:

```c
typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;
```

The `content` field stores the original number. The `index` field stores the compressed sorted rank used by radix sort. The `next` pointer links to the next element in the stack.

Because the top of the stack is the head of the linked list:

- `push` moves the head node from one list to another
- `swap` rewires the first two nodes
- `rotate` moves the head node to the tail
- `reverse_rotate` moves the tail node to the head

### Sorting Strategy

Small stacks are handled separately:

- 2 numbers: direct two-element handling
- 3 numbers: branch-based sorting
- 4 and 5 numbers: push the minimum values to `b`, sort the remaining 3, then push back to `a`

Larger stacks use binary radix sort:

1. Assign each value a sorted index.
2. Find how many bits are needed to represent the largest index.
3. For each bit position, inspect the index at the top of stack `a`.
4. If the bit is `0`, push the value to `b` with `pb`.
5. If the bit is `1`, rotate stack `a` with `ra`.
6. Push everything from `b` back to `a` with `pa`.
7. Repeat until all bits have been processed.

## Project Structure

```txt
.
├── include/
│   ├── libft.h
│   └── push_swap.h
├── libft/
│   └── custom libft and ft_printf sources
├── src/
│   ├── main.c
│   ├── validate.c
│   ├── initialize.c
│   ├── rules1.c
│   ├── rules2.c
│   ├── sort.c
│   └── hardcode_sort.c
└── Makefile
```

## Resources

- [Radix Sort - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/radix-sort/): reference for radix sort as a digit-by-digit, non-comparison sorting algorithm.
- [Stack - Linked List Implementation - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/implement-a-stack-using-singly-linked-list/): reference for representing a stack with linked-list nodes where the head acts as the top.
- [Linked List Data Structure - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/linked-list-data-structure/): reference for linked-list structure, node links, and basic list behavior.

AI was used to help draft and organize this README, including the explanation of the implementation strategy, README structure, and resource descriptions. AI was also used to create tests to improve robustness of the program.
