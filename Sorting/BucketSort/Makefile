# Define compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -lm

# Define file names
TARGET = bucketsort_test
SRC = bucketsort.c bucketsort_test.c
OBJ = $(SRC:.c=.o)

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets
.PHONY: all clean

