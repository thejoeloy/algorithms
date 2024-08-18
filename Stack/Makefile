# Makefile for stack implementation and test

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -pg -O3

# Target executable
TARGET = stack_test

# Source files
SRCS = stack.c stack_test.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.c stack.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets
.PHONY: all clean
