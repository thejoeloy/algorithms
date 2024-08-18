#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bucketsort.h"

// Function to insert a new value into a sorted linked list
void InsertSorted(Node** head, float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->value >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL && current->next->value < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to free the memory of a linked list
void FreeList(Node* head) {
    Node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

// Function to convert a linked list to an array
void ListToArray(Node* head, float arr[], int* index) {
    Node* current = head;
    while (current != NULL) {
        arr[(*index)++] = current->value;
        current = current->next;
    }
}

// Insertion sort for the linked list bucket
void InsertionSort(Node** head) {
    Node* sorted = NULL;
    Node* current = *head;
    while (current != NULL) {
        Node* next = current->next;
        InsertSorted(&sorted, current->value);
        current = next;
    }
    FreeList(*head);
    *head = sorted;
}

void FloatBucketSort(float A[], int n) {
    // 1. Create an array of buckets
    Node** B = (Node**)malloc(n * sizeof(Node*));
    if (B == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // 2. Initialize each bucket as an empty list
    for (int i = 0; i < n; i++) {
        B[i] = NULL;
    }

    // 3. Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)floor(n * A[i]);
        if (bucketIndex >= n) bucketIndex = n - 1; // Edge case handling
        InsertSorted(&B[bucketIndex], A[i]);
    }

    // 4. Sort each bucket and concatenate results
    int index = 0;
    for (int i = 0; i < n; i++) {
        InsertionSort(&B[i]);
        ListToArray(B[i], A, &index);
        FreeList(B[i]);
    }
    
    // Free the bucket array
    free(B);
}

void InsertSortedDouble(NodeDouble** head, double value) {
    NodeDouble* newNode = (NodeDouble*)malloc(sizeof(NodeDouble));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->value >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        NodeDouble* current = *head;
        while (current->next != NULL && current->next->value < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to free the memory of a linked list for doubles
void FreeListDouble(NodeDouble* head) {
    NodeDouble* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

// Function to convert a linked list to an array for doubles
void ListToArrayDouble(NodeDouble* head, double arr[], int* index) {
    NodeDouble* current = head;
    while (current != NULL) {
        arr[(*index)++] = current->value;
        current = current->next;
    }
}

// Insertion sort for the linked list bucket for doubles
void InsertionSortDouble(NodeDouble** head) {
    NodeDouble* sorted = NULL;
    NodeDouble* current = *head;
    while (current != NULL) {
        NodeDouble* next = current->next;
        InsertSortedDouble(&sorted, current->value);
        current = next;
    }
    FreeListDouble(*head);
    *head = sorted;
}

void DoubleBucketSort(double A[], int n) {
    // 1. Create an array of buckets
    NodeDouble** B = (NodeDouble**)malloc(n * sizeof(NodeDouble*));
    if (B == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // 2. Initialize each bucket as an empty list
    for (int i = 0; i < n; i++) {
        B[i] = NULL;
    }

    // 3. Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)floor(n * A[i]);
        if (bucketIndex >= n) bucketIndex = n - 1; // Edge case handling
        InsertSortedDouble(&B[bucketIndex], A[i]);
    }

    // 4. Sort each bucket and concatenate results
    int index = 0;
    for (int i = 0; i < n; i++) {
        InsertionSortDouble(&B[i]);
        ListToArrayDouble(B[i], A, &index);
        FreeListDouble(B[i]);
    }
    
    // Free the bucket array
    free(B);
}
