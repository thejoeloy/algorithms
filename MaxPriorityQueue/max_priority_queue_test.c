#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "max_priority_queue.h"

// Function pointers for print and comparison
int IntCompare(const void* a, const void* b);
int FloatCompare(const void* a, const void* b);
int CharCompare(const void* a, const void* b);
int StringCompare(const void* a, const void* b);
void PrintInt(const void* data);
void PrintFloat(const void* data);
void PrintChar(const void* data);
void PrintString(const void* data);
// 
void TestHeapMaximumInt();
void TestMaxHeapExtractMaxInt();
void TestMaxHeapIncreaseKeyInt();
void TestMaxHeapInsertInt();
void TestLarge();

int main() {
    
    TestLarge();
    /*
    printf("Testing HeapMaximum:\n");
    TestHeapMaximumInt();
    printf("\n");

    printf("Testing MaxHeapExtractMax:\n");
    TestMaxHeapExtractMaxInt();
    printf("\n");

    printf("Testing MaxHeapIncreaseKey:\n");
    TestMaxHeapIncreaseKeyInt();
    printf("\n");

    printf("Testing MaxHeapInsert:\n");
    TestMaxHeapInsertInt();
    printf("\n");
	*/
    return 0;
}

void TestLarge() {
    // Generate 10,000 random integers
    int numElements = 100000;
    int* data = malloc(numElements * sizeof(int));
    if (data == NULL) {
        perror("Failed to allocate memory for test data");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numElements; i++) {
        data[i] = rand() % 100000000; // Random integers in range [0, 99999]
    }
    
    // Initialize heap
    int minElem = INT_MIN;
    MaxHeap* heap = CreateMaxHeap(data, numElements, sizeof(int), &minElem, IntCompare, PrintInt);

    BuildMaxHeap(heap);  // Ensure max heap property is met

    // Insert additional elements
    for (int i = numElements; i < numElements + 100000; i++) {
        int newKey = rand() % 100000;
        MaxHeapInsert(heap, &newKey);
    }
    
    // Increase key of 500 random elements
    for (int i = 0; i < 500; i++) {
        int index = rand() % heap->length;
        int newKey = rand() % 100000;
        MaxHeapIncreaseKey(heap, index, &newKey);
    }
    
    // Extract 1000 elements
    printf("Extracting 1000 elements:\n");
    for (int i = 0; i < 1000; i++) {
        int* max = (int*)MaxHeapExtractMax(heap);
        if (max != NULL) {
            printf("%d ", *max);
            free(max);
        }
    }
    printf("\n");
    
    // Cleanup
    DeleteMaxHeap(heap);
    free(data);
}

int IntCompare(const void* a, const void* b) {
    int intA = *(const int*)a;
    int intB = *(const int*)b;
    return (intA > intB) - (intA < intB);
}

int FloatCompare(const void* a, const void* b) {
    float floatA = *(const float*)a;
    float floatB = *(const float*)b;
    return (floatA > floatB) - (floatA < floatB); 
}

int CharCompare(const void* a, const void* b) {
    char charA = *(const char*)a;
    char charB = *(const char*)b;
    return (charA > charB) - (charA < charB); 
}

int StringCompare(const void* a, const void* b) {
    const char* strA = *(const char**)a;
    const char* strB = *(const char**)b;
    return strcmp(strA, strB); 
}

void PrintInt(const void* data) {
    printf("%d\n", *(int*)data);
}

void PrintFloat(const void* p) {
    printf("%.2f\n", *(float*)p);
}

void PrintChar(const void* p) {
    printf("%c\n", *(char*)p);
}

void PrintString(const void* p) {
    printf("%s\n", *(char**)p);
}

// Test functions
void TestHeapMaximumInt() {
    int data[] = {3, 5, 1, 10, 2};
    int minElem = INT_MIN; // Provide a placeholder for minElem
    MaxHeap* heap = CreateMaxHeap(data, 5, sizeof(int), &minElem, IntCompare, PrintInt);
    
    BuildMaxHeap(heap);  // Ensure max heap property is met
    
    int* max = (int*)HeapMaximum(heap);
    printf("Heap Maximum: %d\n", *max);
    
    DeleteMaxHeap(heap);
}

void TestMaxHeapExtractMaxInt() {
    int data[] = {3, 5, 1, 10, 2};
    int minElem = INT_MIN; // Provide a placeholder for minElem
    MaxHeap* heap = CreateMaxHeap(data, 5, sizeof(int), &minElem, IntCompare, PrintInt);
    
    BuildMaxHeap(heap);  // Ensure max heap property is met
    
    int* max = (int*)MaxHeapExtractMax(heap);
    printf("Extracted Max: %d\n", *max);
    free(max);
    
    MaxHeapPrint(heap);
    printf("\n");
    
    DeleteMaxHeap(heap);
}

void TestMaxHeapIncreaseKeyInt() {
    int data[] = {3, 5, 1, 10, 2};
    int minElem = INT_MIN; // Provide a placeholder for minElem
    MaxHeap* heap = CreateMaxHeap(data, 5, sizeof(int), &minElem, IntCompare, PrintInt);
    
    BuildMaxHeap(heap);  // Ensure max heap property is met
    
    int newKey = 12;
    MaxHeapIncreaseKey(heap, 2, &newKey);
    MaxHeapPrint(heap);
    printf("\n");
    
    DeleteMaxHeap(heap);
}

void TestMaxHeapInsertInt() {
    int data[] = {3, 5, 1, 10, 2};
    int minElem = INT_MIN; // Provide a placeholder for minElem
    MaxHeap* heap = CreateMaxHeap(data, 5, sizeof(int), &minElem, IntCompare, PrintInt);
    
    BuildMaxHeap(heap);  // Ensure max heap property is met
    
    int newKey = 15;
    MaxHeapInsert(heap, &newKey);
    MaxHeapPrint(heap);
    printf("\n");
    
    DeleteMaxHeap(heap);
}
