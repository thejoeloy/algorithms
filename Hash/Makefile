# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Source files
SRCS = hash.c hash_test.c hash_linked_list.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable file
EXE = hash_test

# Default target
all: $(EXE)

# Link the executable
$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -lm

# Compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(EXE)

