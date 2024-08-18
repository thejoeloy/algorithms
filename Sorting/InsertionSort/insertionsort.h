#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <stddef.h>

typedef int (*Comparator)(const void*, const void*);

int cmp_int(const void* a, const void* b);
int cmp_flt(const void* a, const void* b);
int cmp_ch(const void* a, const void* b);
int cmp_str(const void* a, const void* b);

void InsertionSort(void* A, int size, Comparator cmp, int elemSize);

#endif // INSERTIONSORT_H
