#ifndef MERGESORT_H
#define MERGESORT_H

#include <stddef.h>

typedef int (*Comparator)(const void*, const void*);

int cmp_int(const void* a, const void* b);
int cmp_flt(const void* a, const void* b);
int cmp_ch(const void* a, const void* b);
int cmp_str(const void* a, const void* b);

void MergeSort(void* A, int p, int r, Comparator cmp, int elemSize);
void Merge(void* A, int p, int q, int r, Comparator cmp, int elemSize);

#endif // MERGESORT_H
