# Define compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -pg -g -std=c11 -O3

# Define target executable name
TARGET = double_linked_list_test

# Define source files
SRCS = double_linked_list.c double_linked_list_test.c
OBJS = $(SRCS:.c=.o)

# Default rule to build the target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Rule to build object files from source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
