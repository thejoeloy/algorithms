#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    void* val;
    struct Node* next;
} Node;

typedef struct LinkedList {
    struct Node* head;
    struct Node* tail;
    int numElems;
    int elemSize;
    void (*print)(const void*);
} LinkedList;

LinkedList* BuildLinkedList(int elemSize, void (*print)(const void*));
Node* CreateNode(LinkedList* ll, void* value);
void Traverse(LinkedList* ll);
Node* GetAt(LinkedList* ll, int i);
void InsertFirst(LinkedList* ll, void* value);
void DeleteFirst(LinkedList* ll);
void InsertLast(LinkedList* ll, void* value);
void DeleteLast(LinkedList* ll);
void InsertAt(LinkedList* ll, void* value, int i);
void DeleteAt(LinkedList* ll, int i);
void DeleteLinkedList(LinkedList* ll);

#endif // LINKED_LIST_H
