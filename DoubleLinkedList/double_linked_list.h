#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

typedef struct Node {
    void* val;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct DoubleLinkedList {
    struct Node* head;
    struct Node* tail;
    int numElems;
    int elemSize;
    void (*print)(const void*);
} DoubleLinkedList;

DoubleLinkedList* BuildDoubleLinkedList(int elemSize, void (*print)(const void*));
Node* CreateNode(DoubleLinkedList* ll, void* val);
void Traverse(DoubleLinkedList* dll);
Node* GetAt(DoubleLinkedList* dll, int i);
void InsertFirst(DoubleLinkedList* dll, void* val);
void DeleteFirst(DoubleLinkedList* dll);
void InsertLast(DoubleLinkedList* dll, void* val);
void DeleteLast(DoubleLinkedList* dll);
void InsertAt(DoubleLinkedList* dll, void* val, int i);
void DeleteAt(DoubleLinkedList* dll, int i);
void DeleteDoubleLinkedList(DoubleLinkedList* dll);

#endif // DOUBLE_LINKED_LIST_H
