# get_next_line
This project is about programming a function that returns a line read from a file descriptor.

## the goal:

- Repeated calls (e.g., using a loop) to the get_next_line() function should let us read the text file pointed to by the file descriptor, one line at a time.
- the function should return the line that was read. If there is nothing else to read or if an error occurred, it should return NULL.

## Bonus part :
- Develop get_next_line() using only one static variable.
- get_next_line() can manage multiple file descriptors at the same time.

## ressources :
- [Static variables in c](https://www.geeksforgeeks.org/static-variables-in-c/)
- [read(2)](https://linux.die.net/man/2/read)
- [open(2)](https://linux.die.net/man/2/open)
