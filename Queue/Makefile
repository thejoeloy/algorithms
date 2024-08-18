# Define compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -pg -O3

# Define target executable
TARGET = queue_test

# Define source files and object files
SRCS = queue.c queue_test.c
OBJS = $(SRCS:.c=.o)

# Default target to build the executable
all: $(TARGET)

# Rule to link object files into the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean up build artifacts
clean:
	rm -f $(TARGET) $(OBJS)
