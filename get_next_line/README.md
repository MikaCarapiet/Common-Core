*This project has been created as part of the 42 curriculum by mcarapie*

## Description

In this project we will be creating a function that returns a line read from the file descriptor.


## Instructions 

create an example.txt and compile using cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=N

The GNL takes in the file descriptor as its parameter and checks if it is negative (error with file). it sets the line as NULL and then checks if there is a leftover string from a previous read. if True then we check if there is a newline in the leftover if there is then we extract it and assign it to the line and return it. If there is no newline, we assign the value to line and set leftover to NULL. If there is no leftover at all we call a helper function that fills the line, assign the return value of that function to the line.

**INSIDE FILL_LINE_BUFFER**

we loop through and read the file buffersize by buffersize and we made so that the buffer has enough space for the null terminator as that is how we will be able to duplicate the buffer into the line if there is no new line found in the buffer and line is null. if line is not null we concatenate the line and buffer using a temporary string so that we do not lose the line pointer and end up with a memory leak. we free the temp after use. if there is a new line in the buffer, we extract the line and modify the leftover variable if there is. we return the line value

**INSIDE EXTRACT_LINE**

we search the buffer for the new lign and assign its value to the newline_pos variable. we get the length of the line by doing pointer arithmetic and add 1 for indexing. create a substring starting from the start of the buffer to the new line character. if the line is null then assign substring to line. if there is a line, use temp to safely join the 2 strings together. free temp and buffer line once done. if there is still a leftover after the new line, we duplicate the remaining string back to the leftover variable. we return the line.

**INSIDE EXTRACT_LEFTOVER**

we have a non-NULL string that contains a newline in leftover so we use ft_strchr to find the position it is located in then we get the length of the line we need to return by doing pointer arithmetic and add 1 because of the indexing, we make a substring starting from the start of leftover until the '\n'. if there is still a leftover after the new line, we must use a temp to safely duplicate the remaining string back to the leftover variable and free temp. if not, we free leftover and assign it to null. we return the line.


### Resources

[understanding get_next_line (english subtitles)](https://www.youtube.com/watch?v=-Mt2FdJjVno)

AI was used to help me wrap my head around the concept of buffer_size, I had it generate a main file that contained useful printf statements to help visualize what would happen when the buffer size was changed during compilation.
