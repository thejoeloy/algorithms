#include "rand_quicksort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

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
