#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"

void DoubleLinkedListLargeTestInt();
void DoubleLinkedListTestInt();
void DoubleLinkedListTestFloat();
void DoubleLinkedListTestChar();
void DoubleLinkedListTestString();

void PrintInt(const void* data);
void PrintFloat(const void* data);
void PrintChar(const void* data);
void PrintString(const void* data);

int main() {
    DoubleLinkedListLargeTestInt();
    //DoubleLinkedListTestFloat();
    //DoubleLinkedListTestChar();
    //DoubleLinkedListTestString();
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

void DoubleLinkedListLargeTestInt() {
    printf("Testing Large Integer Linked List\n");
    DoubleLinkedList* dll = BuildDoubleLinkedList(sizeof(int), PrintInt);
	int frontElemsLim = 1000000;
	int endElemsLim = 2000000;
	int deleteLim = 500000;
    // Insert 1000 elements at the front
    for (int i = 0; i < frontElemsLim; i++) {
        //printf("Inserting %d at the beginning.\n", i);
        InsertFirst(dll, &i);
        // Optionally, you might want to print the list size or a summary.
        // Traverse(dll);
    }

    // Insert 1000 elements at the end
    for (int i = frontElemsLim; i < endElemsLim; i++) {
        //printf("Inserting %d at the end.\n", i);
        InsertLast(dll, &i);
        // Optionally, you might want to print the list size or a summary.
        // Traverse(dll);
    }

    // Delete 500 elements from the front
    for (int i = 0; i < deleteLim; i++) {
        //printf("Deleting the first element.\n");
        DeleteFirst(dll);
        // Optionally, you might want to print the list size or a summary.
        // Traverse(dll);
    }

    // Delete 500 elements from the back
    for (int i = 0; i < deleteLim; i++) {
        //printf("Deleting the last element.\n");
        DeleteLast(dll);
        // Optionally, you might want to print the list size or a summary.
        // Traverse(dll);
    }

    // Clean up
    DeleteDoubleLinkedList(dll);
}

void DoubleLinkedListTestInt() {
    printf("Testing Integer Linked List\n");
    DoubleLinkedList* dll = BuildDoubleLinkedList(sizeof(int), PrintInt);

    // Test InsertFirst
    for (int i = 1; i <= 5; i++) {
        printf("Inserting %d at the beginning.\n", i);
        InsertFirst(dll, &i);
        Traverse(dll);
    }

    // Test DeleteFirst
    for (int i = 1; i <= 5; i++) {
        printf("Deleting the first element.\n");
        DeleteFirst(dll);
        Traverse(dll);
    }

    // Test InsertLast
    for (int i = 1; i <= 5; i++) {
        printf("Inserting %d at the end.\n", i);
        InsertLast(dll, &i);
        Traverse(dll);
    }

    // Test DeleteLast
    for (int i = 1; i <= 5; i++) {
        printf("Deleting the last element.\n");
        DeleteLast(dll);
        Traverse(dll);
    }

    // Edge cases
    // Insert into an empty list
    DoubleLinkedList* emptyList = BuildDoubleLinkedList(sizeof(int), PrintInt);
    printf("Printing an empty list\n");
    Traverse(emptyList);

    // Delete From Empty List
    printf("Attempting to delete the first element from an empty list.\n");
    DeleteFirst(emptyList);
    printf("Attempting to delete the last element from an empty list.\n");
    DeleteLast(emptyList);

    // Inserting into an empty list
    int value = 100;
    printf("Inserting %d into an empty list.\n", value);
    InsertFirst(emptyList, &value);
    Traverse(emptyList);
    DeleteLast(emptyList);
    Traverse(emptyList);

    // Clean up
    DeleteDoubleLinkedList(emptyList);
    DeleteDoubleLinkedList(dll);
}

void DoubleLinkedListTestFloat() {
    printf("Testing Float Linked List\n");
    DoubleLinkedList* dll = BuildDoubleLinkedList(sizeof(float), PrintFloat);

    // Test InsertFirst
    for (float i = 1.1; i <= 5.1; i += 1.0) {
        printf("Inserting %.1f at the beginning.\n", i);
        InsertFirst(dll, &i);
        Traverse(dll);
    }

    // Test DeleteFirst
    for (float i = 1.1; i <= 5.1; i += 1.0) {
        printf("Deleting the first element.\n");
        DeleteFirst(dll);
        Traverse(dll);
    }

    // Test InsertLast
    for (float i = 1.1; i <= 5.1; i += 1.0) {
        printf("Inserting %.1f at the end.\n", i);
        InsertLast(dll, &i);
        Traverse(dll);
    }

    // Test DeleteLast
    for (float i = 1.1; i <= 5.1; i += 1.0) {
        printf("Deleting the last element.\n");
        DeleteLast(dll);
        Traverse(dll);
    }

    // Edge cases
    // Insert into an empty list
    DoubleLinkedList* emptyList = BuildDoubleLinkedList(sizeof(float), PrintFloat);
    printf("Printing an empty list\n");
    Traverse(emptyList);

    // Delete From Empty List
    printf("Attempting to delete the first element from an empty list.\n");
    DeleteFirst(emptyList);
    printf("Attempting to delete the last element from an empty list.\n");
    DeleteLast(emptyList);

    // Inserting into an empty list
    float value = 100.1;
    printf("Inserting %.1f into an empty list.\n", value);
    InsertFirst(emptyList, &value);
    Traverse(emptyList);
    DeleteLast(emptyList);
    Traverse(emptyList);

    // Clean up
    DeleteDoubleLinkedList(emptyList);
    DeleteDoubleLinkedList(dll);
}

void DoubleLinkedListTestChar() {
    printf("Testing Char Linked List\n");
    DoubleLinkedList* dll = BuildDoubleLinkedList(sizeof(char), PrintChar);

    // Test InsertFirst
    for (char i = 'A'; i <= 'E'; i++) {
        printf("Inserting %c at the beginning.\n", i);
        InsertFirst(dll, &i);
        Traverse(dll);
    }

    // Test DeleteFirst
    for (char i = 'A'; i <= 'E'; i++) {
        printf("Deleting the first element.\n");
        DeleteFirst(dll);
        Traverse(dll);
    }

    // Test InsertLast
    for (char i = 'A'; i <= 'E'; i++) {
        printf("Inserting %c at the end.\n", i);
        InsertLast(dll, &i);
        Traverse(dll);
    }

    // Test DeleteLast
    for (char i = 'A'; i <= 'E'; i++) {
        printf("Deleting the last element.\n");
        DeleteLast(dll);
        Traverse(dll);
    }

    // Edge cases
    // Insert into an empty list
    DoubleLinkedList* emptyList = BuildDoubleLinkedList(sizeof(char), PrintChar);
    printf("Printing an empty list\n");
    Traverse(emptyList);

    // Delete From Empty List
    printf("Attempting to delete the first element from an empty list.\n");
    DeleteFirst(emptyList);
    printf("Attempting to delete the last element from an empty list.\n");
    DeleteLast(emptyList);

    // Inserting into an empty list
    char value = 'Z';
    printf("Inserting %c into an empty list.\n", value);
    InsertFirst(emptyList, &value);
    Traverse(emptyList);
    DeleteLast(emptyList);
    Traverse(emptyList);

    // Clean up
    DeleteDoubleLinkedList(emptyList);
    DeleteDoubleLinkedList(dll);
}

void DoubleLinkedListTestString() {
    printf("Testing String Linked List\n");
    DoubleLinkedList* dll = BuildDoubleLinkedList(sizeof(char*), PrintString);

    // Test InsertFirst
    char* strings[] = {"Hello", "World", "Linked", "List", "Test"};
    for (int i = 4; i >= 0; i--) {
        printf("Inserting \"%s\" at the beginning.\n", strings[i]);
        InsertFirst(dll, &strings[i]);
        Traverse(dll);
    }

    // Test DeleteFirst
    for (int i = 0; i < 5; i++) {
        printf("Deleting the first element.\n");
        DeleteFirst(dll);
        Traverse(dll);
    }

    // Test InsertLast
    for (int i = 0; i < 5; i++) {
        printf("Inserting \"%s\" at the end.\n", strings[i]);
        InsertLast(dll, &strings[i]);
        Traverse(dll);
    }

    // Test DeleteLast
    for (int i = 0; i < 5; i++) {
        printf("Deleting the last element.\n");
        DeleteLast(dll);
        Traverse(dll);
    }

    // Edge cases
    // Insert into an empty list
    DoubleLinkedList* emptyList = BuildDoubleLinkedList(sizeof(char*), PrintString);
    printf("Printing an empty list\n");
    Traverse(emptyList);

    // Delete From Empty List
    printf("Attempting to delete the first element from an empty list.\n");
    DeleteFirst(emptyList);
    printf("Attempting to delete the last element from an empty list.\n");
    DeleteLast(emptyList);

    // Inserting into an empty list
    char* value = "Inserted";
    printf("Inserting \"%s\" into an empty list.\n", value);
    InsertFirst(emptyList, &value);
    Traverse(emptyList);
    DeleteLast(emptyList);
    Traverse(emptyList);

    // Clean up
    DeleteDoubleLinkedList(emptyList);
    DeleteDoubleLinkedList(dll);
}
