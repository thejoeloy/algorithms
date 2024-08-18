# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Files
SRCS = min_heap.c min_heap_test.c
OBJS = $(SRCS:.c=.o)
EXEC = min_heap_test

# Default target
all: $(EXEC)

# Rule to link the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Rule to compile .c files into .o files
%.o: %.c min_heap.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove generated files
clean:
	rm -f $(OBJS) $(EXEC)
