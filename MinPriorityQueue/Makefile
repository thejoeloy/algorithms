# Define the compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11 -g -pg

# Source files
SRC = min_priority_queue.c min_priority_queue_test.c

# Object files
OBJ = $(SRC:.c=.o)

# Executable name
EXE = min_priority_queue_test

# Targets
all: $(EXE)

# Build the executable
$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)

# Build object files
%.o: %.c min_priority_queue.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ) $(EXE)

# Phony targets
.PHONY: all clean
