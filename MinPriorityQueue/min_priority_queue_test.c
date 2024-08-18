#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "min_priority_queue.h"

// Function pointers for print and comparison
int IntCompare(const void* a, const void* b);
int FloatCompare(const void* a, const void* b);
int CharCompare(const void* a, const void* b);
int StringCompare(const void* a, const void* b);
void PrintInt(const void* data);
void PrintFloat(const void* data);
void PrintChar(const void* data);
void PrintString(const void* data);
// Heap Testing Functions
void TestHeapMinimumInt();
void TestMinHeapExtractMinInt();
void TestMinHeapDecreaseKeyInt();
void TestMinHeapInsertInt();
void TestLarge();

int main() {
    TestLarge();
    /*
    printf("Testing HeapMinimum:\n");
    TestHeapMinimumInt();
    printf("\n");

    printf("Testing MinHeapExtractMin:\n");
    TestMinHeapExtractMinInt();
    printf("\n");

    printf("Testing MinHeapDecreaseKey:\n");
    TestMinHeapDecreaseKeyInt();
    printf("\n");

    printf("Testing MinHeapInsert:\n");
    TestMinHeapInsertInt();
    printf("\n");
	*/
    return 0;
}

void TestLarge() {
    // Generate 10,000 random integers
    int numElements = 10000000;
    int* data = malloc(numElements * sizeof(int));
    if (data == NULL) {
        perror("Failed to allocate memory for test data");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numElements; i++) {
        data[i] = rand() % 100000000; // Random integers in range [0, 99999]
    }
    
    // Initialize heap
    int maxElem = INT_MAX;
    MinHeap* heap = CreateMinHeap(data, numElements, sizeof(int), &maxElem, IntCompare, PrintInt);

    BuildMinHeap(heap);  // Ensure min heap property is met

    // Insert additional elements
    for (int i = numElements; i < numElements + 10000; i++) {
        int newKey = rand() % 100000;
        MinHeapInsert(heap, &newKey);
    }
    
    // Decrease key of 500 random elements
    for (int i = 0; i < 5000; i++) {
        int index = rand() % heap->length;
        int newKey = rand() % 1000;  // Decrease key to a smaller value
        MinHeapDecreaseKey(heap, index, &newKey);
    }
    
    // Extract 1000 elements
    printf("Extracting 1000 elements:\n");
    for (int i = 0; i < 100000; i++) {
        int* min = (int*)MinHeapExtractMin(heap);
        if (min != NULL) {
            //printf("%d ", *min);
            free(min);
        }
    }
    //printf("\n");
    
    // Cleanup
    DeleteMinHeap(heap);
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
void TestHeapMinimumInt() {
    int data[] = {3, 5, 1, 10, 2};
    int maxElem = INT_MAX; // Provide a placeholder for maxElem
    MinHeap* heap = CreateMinHeap(data, 5, sizeof(int), &maxElem, IntCompare, PrintInt);
    
    BuildMinHeap(heap);  // Ensure min heap property is met
    
    int* min = (int*)HeapMinimum(heap);
    printf("Heap Minimum: %d\n", *min);
    
    DeleteMinHeap(heap);
}

void TestMinHeapExtractMinInt() {
    int data[] = {3, 5, 1, 10, 2};
    int maxElem = INT_MAX; // Provide a placeholder for maxElem
    MinHeap* heap = CreateMinHeap(data, 5, sizeof(int), &maxElem, IntCompare, PrintInt);
    
    BuildMinHeap(heap);  // Ensure min heap property is met
    
    int* min = (int*)MinHeapExtractMin(heap);
    printf("Extracted Min: %d\n", *min);
    free(min);
    
    MinHeapPrint(heap);
    printf("\n");
    
    DeleteMinHeap(heap);
}

void TestMinHeapDecreaseKeyInt() {
    int data[] = {3, 5, 1, 10, 2};
    int maxElem = INT_MAX; // Provide a placeholder for maxElem
    MinHeap* heap = CreateMinHeap(data, 5, sizeof(int), &maxElem, IntCompare, PrintInt);
    
    BuildMinHeap(heap);  // Ensure min heap property is met
    
    int newKey = 0;  // Decrease key to a value lower than existing ones
    MinHeapDecreaseKey(heap, 2, &newKey);
    MinHeapPrint(heap);
    printf("\n");
    
    DeleteMinHeap(heap);
}

void TestMinHeapInsertInt() {
    int data[] = {3, 5, 1, 10, 2};
    int maxElem = INT_MAX; // Provide a placeholder for maxElem
    MinHeap* heap = CreateMinHeap(data, 5, sizeof(int), &maxElem, IntCompare, PrintInt);
    
    BuildMinHeap(heap);  // Ensure min heap property is met
    
    int newKey = 0;  // Insert a new key
    MinHeapInsert(heap, &newKey);
    MinHeapPrint(heap);
    printf("\n");
    
    DeleteMinHeap(heap);
}



