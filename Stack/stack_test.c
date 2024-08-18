#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "stack.h"

void StackTestInt();
void StackTestFloat();
void StackTestChar();
void StackTestString();
void PrintInt(const void* data);
void PrintFloat(const void* data);
void PrintChar(const void* data);
void PrintString(const void* data);

int main() {
    StackTestInt();
    StackTestFloat();
    StackTestChar();
    StackTestString();
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

// Test functions
void StackTestInt() {
    printf("Testing stack with integers:\n");

    stack* s = BuildStack(5, sizeof(int), PrintInt);
    int value;
    int valuesToPush[] = {10, 20, 30, 40, 50};
    
    // Push values
    for (int i = 0; i < 5; ++i) {
        value = valuesToPush[i];
        if (!Push(s, &value)) {
            printf("Failed to push %d\n", value);
        }
    }

    // Peek at top element
    printf("Peek top element: ");
    PrintInt(Peek(s));

    // Pop and print values
    printf("Popping elements:\n");
    while (!IsEmpty(s)) {
        PrintInt(Pop(s));
    }

    DeleteStack(s);
}

void StackTestFloat() {
    printf("Testing stack with floats:\n");

    stack* s = BuildStack(5, sizeof(float), PrintFloat);
    float value;
    float valuesToPush[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};

    // Push values
    for (int i = 0; i < 5; ++i) {
        value = valuesToPush[i];
        if (!Push(s, &value)) {
            printf("Failed to push %.2f\n", value);
        }
    }

    // Peek at top element
    printf("Peek top element: ");
    PrintFloat(Peek(s));

    // Pop and print values
    printf("Popping elements:\n");
    while (!IsEmpty(s)) {
        PrintFloat(Pop(s));
    }

    DeleteStack(s);
}

void StackTestChar() {
    printf("Testing stack with characters:\n");

    stack* s = BuildStack(5, sizeof(char), PrintChar);
    char value;
    char valuesToPush[] = {'A', 'B', 'C', 'D', 'E'};

    // Push values
    for (int i = 0; i < 5; ++i) {
        value = valuesToPush[i];
        if (!Push(s, &value)) {
            printf("Failed to push %c\n", value);
        }
    }

    // Peek at top element
    printf("Peek top element: ");
    PrintChar(Peek(s));

    // Pop and print values
    printf("Popping elements:\n");
    while (!IsEmpty(s)) {
        PrintChar(Pop(s));
    }

    DeleteStack(s);
}

void StackTestString() {
    printf("Testing stack with strings:\n");

    stack* s = BuildStack(5, sizeof(char*), PrintString);
    char* value;
    char* valuesToPush[] = {"Hello", "World", "Foo", "Bar", "Baz"};

    // Push values
    for (int i = 0; i < 5; ++i) {
        value = valuesToPush[i];
        if (!Push(s, &value)) {
            printf("Failed to push %s\n", value);
        }
    }

    // Peek at top element
    printf("Peek top element: ");
    PrintString(Peek(s));

    // Pop and print values
    printf("Popping elements:\n");
    while (!IsEmpty(s)) {
        PrintString(Pop(s));
    }

    DeleteStack(s);
}
