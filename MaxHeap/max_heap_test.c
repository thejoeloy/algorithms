#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "max_heap.h"

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
void TestCreateMaxHeapInt();
void TestMaxHeapifyInt();
void TestBuildMaxHeapInt();
void TestMaxHeapSortInt();

int main() {
    printf("Running TestCreateMaxHeap:\n");
    TestCreateMaxHeapInt();

    printf("\nRunning TestMaxHeapify:\n");
    TestMaxHeapifyInt();

    printf("\nRunning TestBuildMaxHeap:\n");
    TestBuildMaxHeapInt();

    printf("\nRunning TestMaxHeapSort:\n");
    TestMaxHeapSortInt();

    return 0;
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
void TestCreateMaxHeapInt() {
    int array[] = {10, 15, 40, 50, 30, 100, 40};
    MaxHeap* heap = CreateMaxHeap(array, 7, sizeof(int), IntCompare, PrintInt);

    printf("Heap created with elements:\n");
    MaxHeapPrint(heap);

    DeleteMaxHeap(heap);
}

void TestMaxHeapifyInt() {
    int array[] = {10, 15, 40, 50, 30, 100, 40};
    MaxHeap* heap = CreateMaxHeap(array, 7, sizeof(int), IntCompare, PrintInt);

    printf("Before MaxHeapify:\n");
    MaxHeapPrint(heap);

    MaxHeapify(heap, 0);

    printf("After MaxHeapify:\n");
    MaxHeapPrint(heap);

    DeleteMaxHeap(heap);
}

void TestBuildMaxHeapInt() {
    int array[] = {10, 15, 40, 50, 30, 100, 40};
    MaxHeap* heap = CreateMaxHeap(array, 7, sizeof(int), IntCompare, PrintInt);

    printf("Before BuildMaxHeap:\n");
    MaxHeapPrint(heap);

    BuildMaxHeap(heap);

    printf("After BuildMaxHeap:\n");
    MaxHeapPrint(heap);

    DeleteMaxHeap(heap);
}

void TestMaxHeapSortInt() {
    int array[] = {10, 15, 40, 50, 30, 100, 40};
    MaxHeap* heap = CreateMaxHeap(array, 7, sizeof(int), IntCompare, PrintInt);

    printf("Before MaxHeapSort:\n");
    MaxHeapPrint(heap);

    MaxHeapSort(heap);

    printf("After MaxHeapSort:\n");
    MaxHeapPrint(heap);

    DeleteMaxHeap(heap);
}


