#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void PrintInt(const void* data);
void PrintFloat(const void* data);
void PrintChar(const void* data);
void PrintString(const void* data);
// Function Declarations
void QueueTestInt();
void QueueTestFloat();
void QueueTestChar();
void QueueTestString();

int main() {
    QueueTestInt();
    QueueTestFloat();
    QueueTestChar();
    QueueTestString();
    return 0;
}

void PrintInt(const void* data) {
    printf("%d\n", *(int*)data);
}

void PrintFloat(const void* p) {
    printf("%.2f\n", *(float*)p);
}

void PrintChar(const void* p) {
    printf("%c\n", *(char*)p);
}

void PrintString(const void* p) {
    printf("%s\n", *(char**)p);
}

void QueueTestInt() {
    printf("Testing Queue with Integers:\n");

    // Create a queue for integers with an initial size of 5
    Queue* q = BuildQueue(5, sizeof(int), PrintInt);
    
    int values[] = {1, 2, 3, 4, 5};
    int i;

    // Enqueue elements
    for (i = 0; i < 5; i++) {
        if (!Enqueue(q, &values[i])) {
            printf("Failed to enqueue %d\n", values[i]);
        }
    }

    // Attempt to enqueue when full
    int overflowValue = 99;
    if (!Enqueue(q, &overflowValue)) {
        printf("Queue overflow as expected.\n");
    }

    // Print queue contents
    Print(q);

    // Dequeue elements and print them
    for (i = 0; i < 5; i++) {
        int* dequeuedValue = (int*)Dequeue(q);
        if (dequeuedValue) {
            printf("Dequeued: %d\n", *dequeuedValue);
        } else {
            printf("Queue is empty or error occurred.\n");
        }
    }

    // Print queue contents after dequeue
    Print(q);

    // Cleanup
    DeleteQueue(q);
}

void QueueTestFloat() {
    printf("Testing Queue with Floats:\n");

    // Create a queue for floats with an initial size of 5
    Queue* q = BuildQueue(5, sizeof(float), PrintFloat);

    float values[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int i;

    // Enqueue elements
    for (i = 0; i < 5; i++) {
        if (!Enqueue(q, &values[i])) {
            printf("Failed to enqueue %.2f\n", values[i]);
        }
    }

    // Attempt to enqueue when full
    float overflowValue = 9.9;
    if (!Enqueue(q, &overflowValue)) {
        printf("Queue overflow as expected.\n");
    }

    // Print queue contents
    Print(q);

    // Dequeue elements and print them
    for (i = 0; i < 5; i++) {
        float* dequeuedValue = (float*)Dequeue(q);
        if (dequeuedValue) {
            printf("Dequeued: %.2f\n", *dequeuedValue);
        } else {
            printf("Queue is empty or error occurred.\n");
        }
    }

    // Print queue contents after dequeue
    Print(q);

    // Cleanup
    DeleteQueue(q);
}

void QueueTestChar() {
    printf("Testing Queue with Chars:\n");

    // Create a queue for chars with an initial size of 5
    Queue* q = BuildQueue(5, sizeof(char), PrintChar);

    char values[] = {'a', 'b', 'c', 'd', 'e'};
    int i;

    // Enqueue elements
    for (i = 0; i < 5; i++) {
        if (!Enqueue(q, &values[i])) {
            printf("Failed to enqueue %c\n", values[i]);
        }
    }

    // Attempt to enqueue when full
    char overflowValue = 'z';
    if (!Enqueue(q, &overflowValue)) {
        printf("Queue overflow as expected.\n");
    }

    // Print queue contents
    Print(q);

    // Dequeue elements and print them
    for (i = 0; i < 5; i++) {
        char* dequeuedValue = (char*)Dequeue(q);
        if (dequeuedValue) {
            printf("Dequeued: %c\n", *dequeuedValue);
        } else {
            printf("Queue is empty or error occurred.\n");
        }
    }

    // Print queue contents after dequeue
    Print(q);

    // Cleanup
    DeleteQueue(q);
}

void QueueTestString() {
    printf("Testing Queue with Strings:\n");

    // Create a queue for strings with an initial size of 5
    Queue* q = BuildQueue(5, sizeof(char*), PrintString);

    char* values[] = {"Hello", "World", "Test", "Queue", "Strings"};
    int i;

    // Enqueue elements
    for (i = 0; i < 5; i++) {
        if (!Enqueue(q, &values[i])) {
            printf("Failed to enqueue %s\n", values[i]);
        }
    }

    // Attempt to enqueue when full
    char* overflowValue = "Overflow";
    if (!Enqueue(q, &overflowValue)) {
        printf("Queue overflow as expected.\n");
    }

    // Print queue contents
    Print(q);

    // Dequeue elements and print them
    for (i = 0; i < 5; i++) {
        char** dequeuedValue = (char**)Dequeue(q);
        if (dequeuedValue) {
            printf("Dequeued: %s\n", *dequeuedValue);
        } else {
            printf("Queue is empty or error occurred.\n");
        }
    }

    // Print queue contents after dequeue
    Print(q);

    // Cleanup
    DeleteQueue(q);
}
