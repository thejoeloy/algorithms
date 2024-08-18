#ifndef BUCKETSORT_H
#define BUCKETSORT_H

typedef struct Node {
    float value;
    struct Node* next;
} Node;

typedef struct NodeDouble {
    double value;
    struct NodeDouble* next;
} NodeDouble;

void InsertSorted(Node** head, float value);
void FreeList(Node* head);
void ListToArray(Node* head, float arr[], int* index);
void InsertionSort(Node** head);
void FloatBucketSort(float A[], int n);
void InsertSortedDouble(NodeDouble** head, double value);
void FreeListDouble(NodeDouble* head);
void ListToArrayDouble(NodeDouble* head, double arr[], int* index);
void InsertionSortDouble(NodeDouble** head);
void DoubleBucketSort(double A[], int n);

#endif // COUNTINGSORT_H
