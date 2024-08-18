#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void LinkedListTest();

int main() {
    LinkedListTest();
    return 0;
}

void LinkedListTest() {
    struct LinkedList* ll = BuildLinkedList();

    // Test InsertFirst
    for (int i = 1; i <= 5; i++) {
        printf("Inserting %d at the beginning.\n", i);
        InsertFirst(ll, i);
        Traverse(ll);
    }

    // Test DeleteFirst
    for (int i = 1; i <= 5; i++) {
        printf("Deleting the first element.\n");
        DeleteFirst(ll);
        Traverse(ll);
    }

    // Test InsertLast
    for (int i = 1; i <= 5; i++) {
        printf("Inserting %d at the end.\n", i);
        InsertLast(ll, i);
        Traverse(ll);
    }

    // Test DeleteLast
    for (int i = 1; i <= 5; i++) {
        printf("Deleting the last element.\n");
        DeleteLast(ll);
        Traverse(ll);
    }

    // Edge cases
    // Insert into an empty list
    struct LinkedList* emptyList = BuildLinkedList();
    printf("Printing an empty list\n");
    Traverse(emptyList);
    // Delete From Empty List
    printf("Deleting first from an empty list\n");
    DeleteFirst(emptyList);
    printf("Deleting last from an empty list\n");
    DeleteLast(emptyList);
    
    
    printf("Inserting 100 into an empty list.\n");
    InsertFirst(emptyList, 100);
    Traverse(emptyList);
    DeleteLinkedList(emptyList);
    
    // Clean up
    DeleteLinkedList(ll);
}
