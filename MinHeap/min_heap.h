#ifndef MIN_HEAP_H
#define MIN_HEAP_H

typedef struct MinHeap {
	void* A;
	int elemSize;
	int length;
	int size;
	int (*compare)(const void*, const void*);
	void (*print)(const void*);
} MinHeap;

MinHeap* CreateMinHeap(void* A, int size, int elemSize, int (*compare)(const void*, const void*), void (*print)(const void*));
void DeleteMinHeap(MinHeap* heap);
int MinHeapParent(int i);
int MinHeapLeft(int i);
int MinHeapRight(int i);
void MinHeapify(MinHeap* heap, int i);
void BuildMinHeap(MinHeap* heap);
void MinHeapSort(MinHeap* heap);
void MinHeapPrint(MinHeap* heap);
void MinHeapResize(MinHeap* heap);

#endif // MIN_HEAP_H
