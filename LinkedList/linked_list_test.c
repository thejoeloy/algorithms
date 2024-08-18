#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void LinkedListLargeTestInt();
void LinkedListTestInt();
void LinkedListTestFloat();
void LinkedListTestChar();
void LinkedListTestString();

void PrintInt(const void* data);
void PrintFloat(const void* data);
void PrintChar(const void* data);
void PrintString(const void* data);

int main() {
    LinkedListLargeTestInt();
    //LinkedListTestInt();
    //LinkedListTestFloat();
    //LinkedListTestChar();
    //LinkedListTestString();
    return 0;
}

void PrintInt(const void* data) {
    printf("%d\n", *(int*)data);
}

void PrintFloat(const void* data) {
    printf("%.2f\n", *(float*)data);
}

void PrintChar(const void* data) {
    printf("%c\n", *(char*)data);
}

void PrintString(const void* data) {
    printf("%s\n", *(char**)data);
}

void LinkedListLargeTestInt() {
    printf("Testing Large Integer Linked List\n");
    LinkedList* ll = BuildLinkedList(sizeof(int), PrintInt);
	int frontElemsLim = 10000;
	int endElemsLim = 20000;
	int deleteLim = 5000;
    // Insert 1000 elements at the front
    for (int i = 0; i < frontElemsLim; i++) {
        //printf("Inserting %d at the beginning.\n", i);
        InsertFirst(ll, &i);
        // Optionally, you might want to print the list size or a summary.
        // Traverse(dll);
    }

    // Insert 1000 elements at the end
    for (int i = frontElemsLim; i < endElemsLim; i++) {
        //printf("Inserting %d at the end.\n", i);
        InsertLast(ll, &i);
        // Optionally, you might want to print the list size or a summary.
        // Traverse(dll);
    }

    // Delete 500 elements from the front
    for (int i = 0; i < deleteLim; i++) {
        //printf("Deleting the first element.\n");
        DeleteFirst(ll);
        // Optionally, you might want to print the list size or a summary.
        // Traverse(dll);
    }

    // Delete 500 elements from the back
    for (int i = 0; i < deleteLim; i++) {
        //printf("Deleting the last element.\n");
        DeleteLast(ll);
        // Optionally, you might want to print the list size or a summary.
        // Traverse(dll);
    }

    // Clean up
    DeleteLinkedList(ll);
}

void LinkedListTestInt() {
    LinkedList* ll = BuildLinkedList(sizeof(int), PrintInt);

    for (int i = 1; i <= 5; i++) {
        printf("Inserting %d at the beginning.\n", i);
        InsertFirst(ll, &i);
        Traverse(ll);
    }

    for (int i = 1; i <= 5; i++) {
        printf("Deleting the first element.\n");
        DeleteFirst(ll);
        Traverse(ll);
    }

    for (int i = 1; i <= 5; i++) {
        printf("Inserting %d at the end.\n", i);
        InsertLast(ll, &i);
        Traverse(ll);
    }

    printf("Deleting the last element.\n");
    DeleteLast(ll);
    Traverse(ll);

    DeleteLinkedList(ll);
}

void LinkedListTestFloat() {
    LinkedList* ll = BuildLinkedList(sizeof(float), PrintFloat);

    for (float i = 1.1; i <= 5.5; i += 1.1) {
        printf("Inserting %.1f at the beginning.\n", i);
        InsertFirst(ll, &i);
        Traverse(ll);
    }

    for (float i = 1.1; i <= 5.5; i += 1.1) {
        printf("Deleting the first element.\n");
        DeleteFirst(ll);
        Traverse(ll);
    }

    for (float i = 1.1; i <= 5.5; i += 1.1) {
        printf("Inserting %.1f at the end.\n", i);
        InsertLast(ll, &i);
        Traverse(ll);
    }

    printf("Deleting the last element.\n");
    DeleteLast(ll);
    Traverse(ll);

    DeleteLinkedList(ll);
}

void LinkedListTestChar() {
    LinkedList* ll = BuildLinkedList(sizeof(char), PrintChar);

    for (char c = 'A'; c <= 'E'; c++) {
        printf("Inserting %c at the beginning.\n", c);
        InsertFirst(ll, &c);
        Traverse(ll);
    }

    for (char c = 'A'; c <= 'E'; c++) {
        printf("Deleting the first element.\n");
        DeleteFirst(ll);
        Traverse(ll);
    }

    for (char c = 'A'; c <= 'E'; c++) {
        printf("Inserting %c at the end.\n", c);
        InsertLast(ll, &c);
        Traverse(ll);
    }

    printf("Deleting the last element.\n");
    DeleteLast(ll);
    Traverse(ll);

    DeleteLinkedList(ll);
}

void LinkedListTestString() {
    LinkedList* ll = BuildLinkedList(sizeof(char*), PrintString);

    char* strs[] = {"Hello", "World", "Linked", "List", "Test"};
    
    for (int i = 0; i < 5; i++) {
        printf("Inserting \"%s\" at the beginning.\n", strs[i]);
        InsertFirst(ll, &strs[i]);
        Traverse(ll);
    }

    for (int i = 0; i < 5; i++) {
        printf("Deleting the first element.\n");
        DeleteFirst(ll);
        Traverse(ll);
    }

    for (int i = 0; i < 5; i++) {
        printf("Inserting \"%s\" at the end.\n", strs[i]);
        InsertLast(ll, &strs[i]);
        Traverse(ll);
    }

    printf("Deleting the last element.\n");
    DeleteLast(ll);
    Traverse(ll);

    DeleteLinkedList(ll);
}
