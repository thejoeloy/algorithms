/* linked_list.c
 * This file contains an implementation of a single linked list. This implementation
 * supports generic data types which can be stored in the val entry of the nodes.
 * This linked list is able to service insert/delete front operations in O(1) time,
 * while deletions/insertions/gets/sets at later points in the linked list run in
 * O(n) time proportional to the length of the linked list. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

/* BuildLinkedList()
 * Allocates and builds a linked list.
*/
LinkedList* BuildLinkedList(int elemSize, void (*print)(const void*)) {
    LinkedList* ll = (LinkedList*)malloc(sizeof(LinkedList));
    ll->head = NULL;
    ll->tail = NULL;
    ll->numElems = 0;
    ll->elemSize = elemSize;
    ll->print = print;
    return ll;
}

/* DeleteLinkedList(struct LinkedList* ll)
 * Deletes all of the memory associated with a linked list.
*/
void DeleteLinkedList(LinkedList* ll) {
    Node* current = ll->head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current->val);
        free(current);
        current = next;
    }

    free(ll);
}

/* Traverse(struct LinkedList* ll)
 * Prints out the linked list.
*/
void Traverse(LinkedList* ll) {
    if (ll->numElems == 0) {
    	printf("List is empty\n");
    	return;
    }
    
    Node* ll_iter = ll->head;
    for (int i = 0; i < ll->numElems; i++) {
        ll->print(ll_iter->val);
        ll_iter = ll_iter->next;
    }
}

/* Node* CreateNode(int value)
 * Creates a node containing value
*/
Node* CreateNode(LinkedList* ll, void* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = malloc(ll->elemSize);
    memcpy(newNode->val, value, ll->elemSize); 
    newNode->next = NULL;
    return newNode;
}

/* InsertFirst(struct LinkedList* ll, int value)
 * Inserts a node with value i at the beginning of the linked list.
*/
void InsertFirst(LinkedList* ll, void* value) {
    Node* x = CreateNode(ll, value);
    x->next = ll->head;
    ll->head = x;
    ll->numElems++;
    if (ll->numElems == 1) {
        ll->tail = x;
    }
}

/* DeleteFirst(struct LinkedList* ll)
 * Deletes the first node in the linked list.
*/
void DeleteFirst(LinkedList* ll) {
    if (ll->head != NULL) {
        Node* temp = ll->head;
        ll->head = ll->head->next;
        free(temp->val);
        free(temp);
        ll->numElems--;
        if (ll->numElems == 0) {
            ll->tail = NULL;
        }
    }
}

/* InsertLast(struct LinkedList* ll, int value)
 * Inserts a node with value i at the end of the linked list. 
*/
void InsertLast(LinkedList* ll, void* value) {
    Node* x = CreateNode(ll, value);
    if (ll->tail != NULL) {
        ll->tail->next = x;
    }
    ll->tail = x;
    if (ll->numElems == 0) {
        ll->head = x;
    }
    ll->numElems++;
}

/* DeleteLast(struct LinkedList* ll)
 * Deletes the last element of the linked list. 
*/
void DeleteLast(LinkedList* ll) {
    if (ll->head != NULL) {
        if (ll->numElems == 1) {
            free(ll->head->val);
            free(ll->head);
            ll->head = NULL;
            ll->tail = NULL;
        } else {
            Node* ll_iter = ll->head;
            while (ll_iter->next != ll->tail) {
                ll_iter = ll_iter->next;
            }
            free(ll_iter->next->val);
            free(ll_iter->next);
            ll_iter->next = NULL;
            ll->tail = ll_iter;
        }
        ll->numElems--;
    }
}

/* GetAt(struct LinkedList* ll, int i)
 * Gets the node at position i of the linked list.
*/
Node* GetAt(LinkedList* ll, int i) {
    Node* ll_iter = ll->head;
    for (int j = 0; j < i; j++) {
        ll_iter = ll_iter->next;
    }
    return ll_iter;
}

/* InsertAt(struct LinkedList* ll, int value, int i)
 * Inserts a node at position i with value val into the linked list.
*/
void InsertAt(LinkedList* ll, void* value, int i) {
    if (i == 0) {
        InsertFirst(ll, value);
        return;
    }

    Node* ll_iter = ll->head;
    for (int j = 0; j < i - 1; j++) {
        ll_iter = ll_iter->next;
    }
    Node* x = CreateNode(ll, value);
    x->next = ll_iter->next;
    ll_iter->next = x;
    ll->numElems++;

    if (x->next == NULL) {
        ll->tail = x;
    }
}

/* DeleteAt(struct LinkedList* ll, int i)
 * Deletes the ith node in the linked list.
*/
void DeleteAt(LinkedList* ll, int i) {
    if (i == 0) {
        DeleteFirst(ll);
        return;
    }

    Node* ll_iter = ll->head;
    for (int j = 0; j < i - 1; j++) {
        ll_iter = ll_iter->next;
    }
    Node* temp = ll_iter->next;
    ll_iter->next = ll_iter->next->next;
    free(ll_iter->val);
    free(temp);
    ll->numElems--;

    if (ll_iter->next == NULL) {
        ll->tail = ll_iter;
    }
}
