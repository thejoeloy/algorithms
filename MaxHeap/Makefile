# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I.

# Target binary
TARGET = max_heap_test

# Object files
OBJS = max_heap.o max_heap_test.o

# Library target
LIBRARY = libmax_heap.a

# Rules
all: $(TARGET) $(LIBRARY)

# Build the test executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Build the library
$(LIBRARY): max_heap.o
	ar rcs $(LIBRARY) max_heap.o

# Compile the library object file
max_heap.o: max_heap.c max_heap.h
	$(CC) $(CFLAGS) -c max_heap.c

# Compile the test object file
max_heap_test.o: max_heap_test.c max_heap.h
	$(CC) $(CFLAGS) -c max_heap_test.c

# Clean up build files
clean:
	rm -f $(TARGET) $(LIBRARY) $(OBJS)

.PHONY: all clean
