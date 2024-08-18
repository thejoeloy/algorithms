#include "quicksort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

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
