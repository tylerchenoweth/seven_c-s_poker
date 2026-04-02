# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# Default target
all: main

# Link everything into the executable "main"
main: main.c  print_hand.c  prepare_game.c  gameplay.c hand_stuff.c  db_crud.c  constants.c
	$(CC) $(CFLAGS) -o main main.c print_hand.c gameplay.c prepare_game.c hand_stuff.c db_crud.c constants.c -I.

# Clean target
clean:
	rm -f main

.PHONY: all clean