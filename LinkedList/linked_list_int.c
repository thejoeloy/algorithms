#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/* BuildLinkedList()
 * Allocates and builds a linked list.
*/
struct LinkedList* BuildLinkedList() {
    LinkedList* ll = (LinkedList*)malloc(sizeof(LinkedList));
    ll->head = NULL;
    ll->tail = NULL;
    ll->len = 0;
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
        free(current);
        current = next;
    }

    free(ll);
}

/* Traverse(struct LinkedList* ll)
 * Prints out the linked list.
*/
void Traverse(LinkedList* ll) {
    if (ll->len == 0) {
    	printf("List is empty\n");
    	return;
    }
    
    Node* ll_iter = ll->head;
    for (int i = 0; i < ll->len; i++) {
        printf("ll[%d] is %d\n", i, ll_iter->val);
        ll_iter = ll_iter->next;
    }
}

/* Node* CreateNode(int value)
 * Creates a node containing value
*/
Node* CreateNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

/* InsertFirst(struct LinkedList* ll, int value)
 * Inserts a node with value i at the beginning of the linked list.
*/
void InsertFirst(LinkedList* ll, int value) {
    Node* x = CreateNode(value);
    x->next = ll->head;
    ll->head = x;
    ll->len++;
    if (ll->len == 1) {
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
        free(temp);
        ll->len--;
        if (ll->len == 0) {
            ll->tail = NULL;
        }
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

/* InsertLast(struct LinkedList* ll, int value)
 * Inserts a node with value i at the end of the linked list. 
*/
void InsertLast(LinkedList* ll, int value) {
    Node* x = CreateNode(value);
    if (ll->tail != NULL) {
        ll->tail->next = x;
    }
    ll->tail = x;
    if (ll->len == 0) {
        ll->head = x;
    }
    ll->len++;
}

/* DeleteLast(struct LinkedList* ll)
 * Deletes the last element of the linked list. 
*/
void DeleteLast(LinkedList* ll) {
    if (ll->head != NULL) {
        if (ll->len == 1) {
            free(ll->head);
            ll->head = NULL;
            ll->tail = NULL;
        } else {
            Node* ll_iter = ll->head;
            while (ll_iter->next != ll->tail) {
                ll_iter = ll_iter->next;
            }
            free(ll->tail);
            ll_iter->next = NULL;
            ll->tail = ll_iter;
        }
        ll->len--;
    }
}

/* InsertAt(struct LinkedList* ll, int value, int i)
 * Inserts a node at position i with value val into the linked list.
*/
void InsertAt(LinkedList* ll, int value, int i) {
    if (i == 0) {
        InsertFirst(ll, value);
        return;
    }

    Node* ll_iter = ll->head;
    for (int j = 0; j < i - 1; j++) {
        ll_iter = ll_iter->next;
    }
    Node* x = CreateNode(value);
    x->next = ll_iter->next;
    ll_iter->next = x;
    ll->len++;

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
    free(temp);
    ll->len--;

    if (ll_iter->next == NULL) {
        ll->tail = ll_iter;
    }
}


