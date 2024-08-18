# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g -pg -O3

# Target executable
TARGET = dynamic_array_test

# Source files
SRCS = dynamic_array.c dynamic_array_test.c

# Object files
OBJS = $(SRCS:.c=.o)

# Build target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule for compiling .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets
.PHONY: all clean
