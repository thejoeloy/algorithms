#ifndef STACK_H
#define STACK_H

typedef struct stack {
    void* base;
    int top;
    int size;
    int elemSize;
	void (*print)(const void*);
} stack;

stack* BuildStack(int size, int elemSize, void (*print)(const void*));
void DeleteStack(stack* s);
int IsEmpty(stack* s);
int Push(stack* s, void* x);
void* Pop(stack* s);
void* Peek(stack* s);

#endif // STACK_H
