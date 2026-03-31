# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# Default target
all: main

# Link everything into the executable "main"
main: main.c hand_stuff.c constants.c
	$(CC) $(CFLAGS) -o main main.c hand_stuff.c constants.c -I.

# Clean target
clean:
	rm -f main

.PHONY: all clean