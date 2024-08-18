#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "min_heap.h"

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
void TestCreateMinHeapInt();
void TestMinHeapifyInt();
void TestBuildMinHeapInt();
void TestMinHeapSortInt();

int main() {
    printf("Running TestCreateMinHeap:\n");
    TestCreateMinHeapInt();

    printf("\nRunning TestMinHeapify:\n");
    TestMinHeapifyInt();

    printf("\nRunning TestBuildMinHeap:\n");
    TestBuildMinHeapInt();

    printf("\nRunning TestMinHeapSort:\n");
    TestMinHeapSortInt();

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
void TestCreateMinHeapInt() {
    int array[] = {10, 15, 40, 50, 30, 100, 40};
    MinHeap* heap = CreateMinHeap(array, 7, sizeof(int), IntCompare, PrintInt);

    printf("Heap created with elements:\n");
    MinHeapPrint(heap);

    DeleteMinHeap(heap);
}

void TestMinHeapifyInt() {
    int array[] = {10, 15, 40, 50, 30, 100, 40};
    MinHeap* heap = CreateMinHeap(array, 7, sizeof(int), IntCompare, PrintInt);

    printf("Before MinHeapify:\n");
    MinHeapPrint(heap);

    MinHeapify(heap, 0);

    printf("After MinHeapify:\n");
    MinHeapPrint(heap);

    DeleteMinHeap(heap);
}

void TestBuildMinHeapInt() {
    int array[] = {10, 15, 40, 50, 30, 100, 40};
    MinHeap* heap = CreateMinHeap(array, 7, sizeof(int), IntCompare, PrintInt);

    printf("Before BuildMinHeap:\n");
    MinHeapPrint(heap);

    BuildMinHeap(heap);

    printf("After BuildMinHeap:\n");
    MinHeapPrint(heap);

    DeleteMinHeap(heap);
}

void TestMinHeapSortInt() {
    int array[] = {10, 15, 40, 50, 30, 100, 40};
    MinHeap* heap = CreateMinHeap(array, 7, sizeof(int), IntCompare, PrintInt);

    printf("Before MinHeapSort:\n");
    MinHeapPrint(heap);

    MinHeapSort(heap);

    printf("After MinHeapSort:\n");
    MinHeapPrint(heap);

    DeleteMinHeap(heap);
}

