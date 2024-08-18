/* stack.c
 * This file contains an implementaion of a stack data structure. This implementation
 * is generic and can store arbitray data types in the array used to store elements of
 * the stack. The stack implements a FIFO data structure in which elements most recently
 * stored in the stack can be removed in O(1) time. The stack is statically sized.  
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "stack.h"

/*
 * BuildStack(int elemSize)
 * Creates a stack of size elemSize. Returns a pointer to the stack if the memory allocations
 * all succeed and exits if one of the stack fields cannot be allocated.
*/
stack* BuildStack(int size, int elemSize, void (*print)(const void*)) {
    stack* s = (stack*)malloc(sizeof(stack));
    if (s == NULL) {
        exit(EXIT_FAILURE); 
    }
    s->base = malloc(elemSize * size); 
    if (s->base == NULL) {
        exit(EXIT_FAILURE); 
    }
    s->top = 0;
    s->size = size;
    s->elemSize = elemSize;
    s->print = print;
    return s;
}

/*
 * DeleteStack(stack* s)
 * Frees the stack and all memory associated with it. 
 * 
*/
void DeleteStack(stack* s) {
    free(s->base);
    free(s);
}

/*
 * IsEmpty(stack* s)
 * Checks to see whether the stack is empty. 
*/
int IsEmpty(stack* s) {
    if (s->top == 0) return 1;
    else return 0;
}

/*
 * Push(stack* s, void* x)
 * Pushes the element x onto the stack.
*/
int Push(stack* s, void* x) {
    if (s->top >= s->size) {
    	return 0;    
    }
    memcpy((char*)s->base + (s->top * s->elemSize), x, s->elemSize);
    s->top++;
    return 1;
}

/*
 * Pop(stack* s, void* elemAddr)
 * Returns a pointer to the first element from the stack. If the stack
 * is empty then elemAddr is left unmodified. 
*/
void* Pop(stack* s) {
    if (IsEmpty(s)) {
        return NULL;
    }
 
    s->top--;
    return (char*)s->base + (s->top * s->elemSize);
}

/*
 * Peek(stack* s)
 * Returns the first element in the stack but does not remove it. 
*/
void* Peek(stack* s) {
	if (IsEmpty(s)) {
        return NULL;
    }
 
    return (char*)s->base + ((s->top - 1) * s->elemSize); 
}
