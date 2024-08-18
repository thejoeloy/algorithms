# Compiler
CC = gcc

# Compiler flags
CFLAGS = -g -pg -Wall -Wextra -std=c11 -O3

# Target executable
TARGET = rb_tree_test

# Source files
SRCS = rb_tree.c rb_tree_test.c

# Object files
OBJS = $(SRCS:.c=.o)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean up generated files
clean:
	rm -f $(TARGET) $(OBJS)
