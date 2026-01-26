*This project has been created as part of the 42 curriculum by mcarapie*

## Description

In this project we will be recreating the printf() function found in <stdio.h>. We will be using variadic functions to mimic the functions.


## Instructions
compile using make all, make clean to remove .o files, make fclean to remove .a file, make re to recompile .a

**Main structure:**

One main loop, iterating through the string and incrementing the count per character outputted.

**Inside the loop:**

Check the string for an intial '%' and "cspdiuxX%" call a function that handles each conversion case, pass the va_list, string, and count into the function. (print_char, print_str, print_hexa etc.)

**Print specifier function:**

For every case, we copy the functionality of printf and per character outputted to the std output, we increment the count variable.


## Resources

[Geeksforgeeks - Variadic functions in C](https://www.geeksforgeeks.org/c/variadic-functions-in-c/
)

[Youtube - What are variadic functions (va_list) in C?](https://www.youtube.com/watch?v=oDC208zvsdg)

AI was used to arrange how i approached making the specifier function. I had it arranged from the easiest to the hardest because i took a small break from coding. I also had it link me resources on variadic functions and if certain edge cases were covered by the actual printf or not.