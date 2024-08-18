#include <stdio.h>
#include <stdlib.h>
#include "hash_linked_list.h"

/* Traverse(LinkedList* ll)
 * Traverses the linked list and prints out the keys and values stored in each node.
*/
void Traverse(LinkedList* ll) {
    printf("Traverse\n");
    Node* ll_iter = ll->head;
    for (int i = 0; i < ll->len; i++) {
        printf("ll[%d] has key %d and value %d\n", i, ll_iter->key, ll_iter->val);
        ll_iter = ll_iter->next;
    }
}

/* NewNode(int key, int val)
 * Creates a new node with key and value stored inside.
*/
Node* NewNode(int key, int val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->val = val;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

/* InsertFirst(LinkedList* ll, int key, int val)
 * Inserts a node with values key and val into the front of the linked list.
*/
void InsertFirst(LinkedList* ll, int key, int val) {
    Node* new_node = NewNode(key, val);
    new_node->next = ll->head;
    new_node->prev = NULL;
    
    if (ll->head != NULL) {
        ll->head->prev = new_node;
    }
    ll->head = new_node;
    
    if (ll->len == 0) {
        ll->tail = new_node;
    }
    
    ll->len++;
}

/* DeleteFirst(LinkedList* ll)
 * Deletes the first node in the linked list.
*/
void DeleteFirst(LinkedList* ll) {
    if (ll->len == 0) return;

    Node* temp = ll->head;
    ll->head = ll->head->next;
    if (ll->head != NULL) {
        ll->head->prev = NULL;
    } else {
        ll->tail = NULL;
    }
    free(temp);
    ll->len--;
}

/* GetAt(LinkedList* ll, int i)
 * Returns the ith node in the linked list.
*/
Node* GetAt(LinkedList* ll, int i) {
    if (i < 0 || i >= ll->len) {
        printf("Index out of bounds\n");
        return NULL;
    }
    Node* ll_iter = ll->head;
    for (int j = 0; j < i; j++) {
        ll_iter = ll_iter->next;
    }
    return ll_iter;
}

/* InsertLast(LinkedList* ll, int key, int val)
 * Inserts a node with values key and val into the end of the linked list.
*/
void InsertLast(LinkedList* ll, int key, int val) {
    Node* new_node = NewNode(key, val);
    new_node->next = NULL;
    new_node->prev = ll->tail;
    
    if (ll->tail != NULL) {
        ll->tail->next = new_node;
    }
    ll->tail = new_node;
    
    if (ll->len == 0) {
        ll->head = new_node;
    }
    
    ll->len++;
}

/* DeleteLast(LinkedList* ll)
 * Deletes the last node in the linked list.
*/
void DeleteLast(LinkedList* ll) {
    if (ll->len == 0) return;

    Node* temp = ll->tail;
    ll->tail = ll->tail->prev;
    if (ll->tail != NULL) {
        ll->tail->next = NULL;
    } else {
        ll->head = NULL;
    }
    free(temp);
    ll->len--;
}

/* InsertAt(LinkedList* ll, int key, int val, int i)
 * Inserts a node with values key and val into the ith position of the linked list.
*/
void InsertAt(LinkedList* ll, int key, int val, int i) {
    if (i < 0 || i > ll->len) {
        printf("Index out of bounds\n");
        return;
    }
    
    if (i == 0) {
        InsertFirst(ll, key, val);
        return;
    }
    
    if (i == ll->len) {
        InsertLast(ll, key, val);
        return;
    }
    
    Node* new_node = NewNode(key, val);
    
    Node* ll_iter = GetAt(ll, i - 1);
    
    new_node->next = ll_iter->next;
    new_node->prev = ll_iter;
    ll_iter->next->prev = new_node;
    ll_iter->next = new_node;
    
    ll->len++;
}

/* DeleteAt(LinkedList* ll, int i)
 * Deletes the ith node of the linked list.
*/
void DeleteAt(LinkedList* ll, int i) {
    if (i < 0 || i >= ll->len) {
        printf("Index out of bounds\n");
        return;
    }
    
    if (i == 0) {
        DeleteFirst(ll);
        return;
    }
    
    if (i == ll->len - 1) {
        DeleteLast(ll);
        return;
    }
    
    Node* ll_iter = GetAt(ll, i - 1);
    Node* temp = ll_iter->next;
    ll_iter->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = ll_iter;
    }
    free(temp);
    
    ll->len--;
}

/* Search(LinkedList* ll, int key)
 * Searches the linked list for a node with a key value of key.
*/
Node* Search(LinkedList* ll, int key) {
    Node* ll_iter = ll->head;
    while (ll_iter != NULL) {
        if (ll_iter->key == key) {
            return ll_iter;
        }
        ll_iter = ll_iter->next;
    }
    return NULL;
}

/* LinkedListTest()
 * Tests the functionality of the linked list.
*/
void LinkedListTest() {
    LinkedList ll = {NULL, NULL, 0};

    printf("Inserting (1, 100) at the beginning...\n");
    InsertFirst(&ll, 1, 100);
    Traverse(&ll);

    printf("Inserting (2, 200) at the beginning...\n");
    InsertFirst(&ll, 2, 200);
    Traverse(&ll);

    printf("Inserting (3, 300) at the end...\n");
    InsertLast(&ll, 3, 300);
    Traverse(&ll);

    printf("Inserting (4, 400) at index 1...\n");
    InsertAt(&ll, 4, 400, 1);
    Traverse(&ll);

    printf("Getting value at index 2...\n");
    Node* node = GetAt(&ll, 2);
    if (node != NULL) {
        printf("ll[2] has key %d and value %d\n", node->key, node->val);
    }

    printf("Searching for key 3...\n");
    Node* found_node = Search(&ll, 3);
    if (found_node != NULL) {
        printf("Found key %d with value %d\n", found_node->key, found_node->val);
    } else {
        printf("Key 3 not found\n");
    }

    printf("Deleting value at index 1...\n");
    DeleteAt(&ll, 1);
    Traverse(&ll);

    printf("Deleting first value...\n");
    DeleteFirst(&ll);
    Traverse(&ll);

    printf("Deleting last value...\n");
    DeleteLast(&ll);
    Traverse(&ll);
}

