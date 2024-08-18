#include "insertionsort.h"
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
