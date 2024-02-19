## Short explanation: 
- The **`get_next_line`** function reads the content of the file descriptor (**`fd`**) in chunks of a specified buffer size (**`BUFFER_SIZE`**).
- It breaks down the content into lines (until a **`'\n'`** is encountered) and returns each line one at a time. The buffer size determines how much data is read from the file at each iteration (how big the chunks are).
- Using a static variable to store the remaining characters that weren’t read in the previous call/ iteration. It is first initialized as an empty string. It should be dynamically allocate and resized if needed
- there is a reading function that is reading from the fd in chunks of the buffer size, until a newline or the end of the file is reached, the content is applied to the static variable storing it
- a extract function is used to extract the line from the static variable storing it
- the storing function is then updated (with out the extracted line)


## Subject

### Mandatory Part

- Repeated calls (e.g., using a loop) to your get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time.
- Your function should return the line that was read.
- If there is nothing else to read or if an error occurred, it should return NULL.
- Make sure that your function works as expected both when reading a file and when reading from the standard input.
- Please note that the returned line should include the terminating \n character, except if the end of file was reached and does not end with a \n character.
- Your header file get_next_line.h must at least contain the prototype of the get_next_line() function.
- Add all the helper functions you need in the get_next_line_utils.c file.
- Because you will have to read files in get_next_line(), add this option to your compiler call: -D BUFFER_SIZE=n. It will define the buffer size for read().

  <br>

Forbidden
- You are not allowed to use your libft in this project.
- lseek() is forbidden.
- Global variables are forbidden

<br>
!! Try to read as little as possible each time get_next_line() is called.  If you encounter a new line, you have to return the current
line. Don’t read the whole file and then process each line !!
<br>

### Bonus part

- Develop get_next_line() using only one static variable.
- Your get_next_line() can manage multiple file descriptors at the same time. For example, if you can read from the file descriptors 3, 4 and 5, you should be able to read from a different fd per call without losing the reading thread of each file descriptor or returning a line from another fd.
- It means that you should be able to call get_next_line() to read from fd 3, then fd 4, then 5, then once again 3, once again 4, and so forth.
- Append the _bonus.[c\h] suffix to the bonus part files.




## Heplful links: 
- https://42-cursus.gitbook.io/guide/rank-01/get_next_line
