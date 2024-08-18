/* queue.c
 * This file implements a queue in C. This queue supports arbitrary data types
 * which can be stored in the array that is used to store the elements in the
 * queue. The queue implements a LIFO structure in which elements that were
 * least recently into the queue can be removed in O(1) time. This
 * implementation uses a circular buffer strategy in order to implement the
 * queue. The queue is statically sized. If there is not enough room in the
 * queue or the queue is empty, the queue will report underflow/overflow.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"

/* BuildQueue(int elemSize, int initialSize)
 * Builds a queue that can store initialSize number of elements of size elemSize
 */
Queue* BuildQueue(int size, int elemSize, void (*print)(const void*)) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        fprintf(stderr, "Failed to allocate memory for the queue.\n");
        exit(1);
    }
    q->base = malloc(size * elemSize);
    if (q->base == NULL) {
        fprintf(stderr, "Failed to allocate memory for the queue elements.\n");
        free(q);
        exit(1);
    }
    q->head = 0;
    q->tail = 0;
    q->size = size + 1;
    q->elemSize = elemSize;
    q->print = print;
    return q;
}

/* DeleteQueue(Queue* q)
 * Deletes the queue and all other memory associated with it.
 */
void DeleteQueue(Queue* q) {
    if (q) {
        free(q->base);
        free(q);
    }
}

/* Enqueue(Queue* q, void* x)
 * Stores the element x at the end of the queue.
 */
int Enqueue(Queue* q, void* x) {
    if (IsFull(q)) {
        return 0; // Queue is full
    }
    
    memcpy((char*)q->base + (q->tail * q->elemSize), x, q->elemSize);
    q->tail = (q->tail + 1) % q->size; // Circular increment
    return 1;
}

/* Dequeue(Queue* q)
 * Removes the first element of the queue and returns it.
 */
void* Dequeue(Queue* q) {
    if (IsEmpty(q)) {
        return NULL; // Return NULL if the queue is empty
    }
    
    void* x = (char*)q->base + (q->head * q->elemSize);
    q->head = (q->head + 1) % q->size; // Circular increment
    return x;
}

/* IsEmpty(Queue* q)
 * Checks if the queue is empty.
 */
int IsEmpty(Queue* q) {
    if (q == NULL) {
        return 1; // Queue is empty
    }
    return q->head == q->tail;
}

/* IsFull(Queue* q)
 * Checks if the queue is full.
 */
int IsFull(Queue* q) {
    if (q == NULL) {
        return 0; // Queue is not full
    }
    return (q->tail + 1) % q->size == q->head;
}

/* Peek(Queue* q)
 * Returns the first element of the queue without removing it.
 */
void* Peek(Queue* q) {
    if (q == NULL || IsEmpty(q)) {
        return NULL;
    }
    return (char*)q->base + (q->head * q->elemSize);
}

/* Print(Queue* q)
 * Prints the contents of the queue. If the queue is empty, prints that it is empty.
 */
void Print(Queue* q) {
    if (IsEmpty(q) || q == NULL) {
        printf("Queue is currently empty or is NULL\n");
    } else {
        int i = q->head;
        while (i != q->tail) {
            q->print((char*)q->base + (i * q->elemSize));
            i = (i + 1) % q->size;
        }
    }
}

