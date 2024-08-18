#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct LinkedList {
    struct Node* head;
    struct Node* tail;
    int len;
} LinkedList;

void Traverse(LinkedList* ll);
Node* GetAt(LinkedList* ll, int i);
void InsertFirst(LinkedList* ll, int value);
void DeleteFirst(LinkedList* ll);
void InsertLast(LinkedList* ll, int value);
void DeleteLast(LinkedList* ll);
void InsertAt(LinkedList* ll, int value, int i);
void DeleteAt(LinkedList* ll, int i);
LinkedList* BuildLinkedList();
void DeleteLinkedList(LinkedList* ll);

#endif // LINKED_LIST_H
