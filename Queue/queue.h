#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue {
    void* base;
    int head;
    int tail;
    int size;
    int elemSize;
    void (*print)(const void*);
} Queue;

Queue* BuildQueue(int size, int elemSize, void (*print)(const void*));
void DeleteQueue(Queue* q);
int Enqueue(Queue* q, void* x);
void* Dequeue(Queue* q);
int IsEmpty(Queue* q);
int IsFull(Queue* q);
void* Peek(Queue* q);
void Print(Queue* q);

#endif // QUEUE_H
