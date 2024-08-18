#ifndef MAX_HEAP_H
#define MAX_HEAP_H

typedef struct MaxHeap {
	void* A;
	int elemSize;
	int length;
	int size;
	int (*compare)(const void*, const void*);
	void (*print)(const void*);
} MaxHeap;

MaxHeap* CreateMaxHeap(void* A, int size, int elemSize, int (*compare)(const void*, const void*), void (*print)(const void*));
void DeleteMaxHeap(MaxHeap* heap);
int MaxHeapParent(int i);
int MaxHeapLeft(int i);
int MaxHeapRight(int i);
void MaxHeapify(MaxHeap* heap, int i);
void BuildMaxHeap(MaxHeap* heap);
void MaxHeapSort(MaxHeap* heap);
void MaxHeapPrint(MaxHeap* heap);

#endif // MAX_HEAP_H
