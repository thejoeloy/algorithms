# Define compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pg -g

# Define target executable name
TARGET = linked_list_test

# Define source files
SRCS = linked_list.c linked_list_test.c
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
