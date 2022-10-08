# 42 Get Next Line

## About the project

The aim of this project is to make you code a function that returns a line, read from a file descriptor._

This project will not only allow you to add a very convenient function to your collection, but it will also make you learn a highly interesting new concept in C programming: static variables.

You will understand how files are opened, read and closed in an OS, and how they are interpreted by a programming language for further analysis.
This task is crucial to understand for a future programmer since much of the time is based on manipulating files for data management and persistence.
This project consists of coding a function that returns one line at a time from a text file.

## Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Using it in your code**

To use the function in your code, simply include its header:

```C
#include "get_next_line.h"
```

and, when compiling your code, add the source files and the required flag:

```shell
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```

## Testing

You can edit test.txt files to put another text if you wish to test out the cases.
Then simply run this command (change "xx" with desired buffer size) :

```shell
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c && ./a.out
```

Or you can also use this third party tester to fully test the project

* [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester)
