#ifndef MIN_PRIORITY_QUEUE_H
#define MIN_PRIORITY_QUEUE_H

typedef struct MinHeap {
	void* A;
	int elemSize;
	int length;
	int size;
	void* maxElem;
	int (*compare)(const void*, const void*);
	void (*print)(const void*);
} MinHeap;

MinHeap* CreateMinHeap(void* A, int size, int elemSize, void* maxElem, int (*compare)(const void*, const void*), void (*print)(const void*));
void DeleteMinHeap(MinHeap* heap);
int MinHeapParent(int i);
int MinHeapLeft(int i);
int MinHeapRight(int i);
void MinHeapify(MinHeap* heap, int i);
void BuildMinHeap(MinHeap* heap);
void MinHeapSort(MinHeap* heap);
void MinHeapPrint(MinHeap* heap);
void ResizeMinPriorityQueue(MinHeap* pq);
void* HeapMinimum(MinHeap* pq);
void* MinHeapExtractMin(MinHeap* pq);
void MinHeapDecreaseKey(MinHeap* pq, int i, void* key);
void MinHeapInsert(MinHeap* pq, void* key);

#endif // MIN_PRIORITY_QUEUE_H
