#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stddef.h>

typedef int (*Comparator)(const void*, const void*);

int cmp_int(const void* a, const void* b);
int cmp_flt(const void* a, const void* b);
int cmp_ch(const void* a, const void* b);
int cmp_str(const void* a, const void* b);

void QuickSort(void* A, int p, int r, Comparator cmp, int elemSize);
int Partition(void* A, int p, int r, Comparator cmp, int elemSize);

#endif // QUICKSORT_H
