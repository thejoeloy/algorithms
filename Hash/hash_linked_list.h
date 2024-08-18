#ifndef HASH_LINKED_LIST_H
#define HASH_LINKED_LIST_H

// Node for doubly linked list
typedef struct Node {
    int key;
    int val;
    struct Node* next;
    struct Node* prev;
} Node;

// Doubly linked list
typedef struct LinkedList {
    Node* head;
    Node* tail;
    int len;
} LinkedList;

// Function declarations
void Traverse(LinkedList* ll);
Node* GetAt(LinkedList* ll, int i);
void InsertFirst(LinkedList* ll, int key, int val);
void DeleteFirst(LinkedList* ll);
void InsertLast(LinkedList* ll, int key, int val);
void DeleteLast(LinkedList* ll);
void InsertAt(LinkedList* ll, int key, int val, int i);
void DeleteAt(LinkedList* ll, int i);
Node* NewNode(int key, int val);
Node* Search(LinkedList* ll, int key);
void LinkedListTest();

#endif // HASH_LINKED_LIST_H


