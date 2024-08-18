#ifndef RAND_QUICKSORT_H
#define RAND_QUICKSORT_H

#include <stddef.h>

typedef int (*Comparator)(const void*, const void*);

int cmp_int(const void* a, const void* b);
int cmp_flt(const void* a, const void* b);
int cmp_ch(const void* a, const void* b);
int cmp_str(const void* a, const void* b);

void RandQuickSort(void* A, int p, int r, Comparator cmp, int elemSize);
int RandPartition(void* A, int p, int r, Comparator cmp, int elemSize);

#endif // RAND_QUICKSORT_H
