#include "mergesort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

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
