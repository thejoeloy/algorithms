#include "sort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

void InsertionSort(void* A, int size, Comparator cmp, int elemSize) {
    void* key = malloc(elemSize);
    for (int j = 1; j < size; j++) {
        memcpy(key, (char*)A + (j * elemSize), elemSize);
        int i = j - 1;
        while (i >= 0 && cmp(key, (char*)A + (i * elemSize)) < 0) {
            memcpy((char*)A + ((i + 1) * elemSize), (char*)A + (i * elemSize), elemSize);
            i--;
        }
        memcpy((char*)A + ((i + 1) * elemSize), key, elemSize);
    }
    free(key);
}

void MergeSort(void* A, int p, int r, Comparator cmp, int elemSize) {
    if (p < r) {
        int q = (p + r) / 2;
        MergeSort(A, p, q, cmp, elemSize);
        MergeSort(A, q + 1, r, cmp, elemSize);
        Merge(A, p, q, r, cmp, elemSize);
    }
}

void Merge(void* A, int p, int q, int r, Comparator cmp, int elemSize) {
    int n1 = q - p + 1;
    int n2 = r - q;

    void* L = malloc(n1 * elemSize);
    void* R = malloc(n2 * elemSize);

    if (L == NULL || R == NULL) {
        // Handle allocation failure if needed
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n1; i++) {
        memcpy((char*)L + (i * elemSize), (char*)A + ((p + i) * elemSize), elemSize);
    }

    for (int j = 0; j < n2; j++) {
        memcpy((char*)R + (j * elemSize), (char*)A + ((q + 1 + j) * elemSize), elemSize);
    }

    int i = 0;
    int j = 0;
    int k = p;

    while (i < n1 && j < n2) {
        if (cmp((char*)L + (i * elemSize), (char*)R + (j * elemSize)) <= 0) {
            memcpy((char*)A + (k * elemSize), (char*)L + (i * elemSize), elemSize);
            i++;
        } else {
            memcpy((char*)A + (k * elemSize), (char*)R + (j * elemSize), elemSize);
            j++;
        }
        k++;
    }

    while (i < n1) {
        memcpy((char*)A + (k * elemSize), (char*)L + (i * elemSize), elemSize);
        i++;
        k++;
    }

    while (j < n2) {
        memcpy((char*)A + (k * elemSize), (char*)R + (j * elemSize), elemSize);
        j++;
        k++;
    }

    free(L);
    free(R);
}


void QuickSort(void* A, int p, int r, Comparator cmp, int elemSize) {
    if (p < r) {
        int q = Partition(A, p, r, cmp, elemSize);
        QuickSort(A, p, q - 1, cmp, elemSize);
        QuickSort(A, q + 1, r, cmp, elemSize);
    }
}

int Partition(void* A, int p, int r, Comparator cmp, int elemSize) {
    void* x = malloc(elemSize);
    memcpy(x, (char*)A + (r * elemSize), elemSize);
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        if (cmp((char*)A + (j * elemSize), x) < 0) {
            i++;
            void* temp = malloc(elemSize);
            memcpy(temp, (char*)A + (i * elemSize), elemSize);
            memcpy((char*)A + (i * elemSize), (char*)A + (j * elemSize), elemSize);
            memcpy((char*)A + (j * elemSize), temp, elemSize);
            free(temp);
        }
    }

    void* temp = malloc(elemSize);
    memcpy(temp, (char*)A + ((i + 1) * elemSize), elemSize);
    memcpy((char*)A + ((i + 1) * elemSize), (char*)A + (r * elemSize), elemSize);
    memcpy((char*)A + (r * elemSize), temp, elemSize);
    free(temp);
    free(x);
    return i + 1;
}

void RandQuickSort(void* A, int p, int r, Comparator cmp, int elemSize) {
    if (p < r) {
        int q = RandPartition(A, p, r, cmp, elemSize);
        RandQuickSort(A, p, q - 1, cmp, elemSize);
        RandQuickSort(A, q + 1, r, cmp, elemSize);
    }
}

int RandPartition(void* A, int p, int r, Comparator cmp, int elemSize) {
    int i = p + rand() % (r - p + 1);
    void* temp = malloc(elemSize);
    memcpy(temp, (char*)A + (i * elemSize), elemSize);
    memcpy((char*)A + (i * elemSize), (char*)A + (r * elemSize), elemSize);
    memcpy((char*)A + (r * elemSize), temp, elemSize);
    free(temp);
    return Partition(A, p, r, cmp, elemSize);
}
