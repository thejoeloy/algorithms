#ifndef MAX_PRIORITY_QUEUE_H
#define MAX_PRIORITY_QUEUE_H

typedef struct MaxHeap {
	void* A;
	int elemSize;
	int length;
	int size;
	void* minElem;
	int (*compare)(const void*, const void*);
	void (*print)(const void*);
} MaxHeap;

MaxHeap* CreateMaxHeap(void* A, int size, int elemSize, void* elemMax, int (*compare)(const void*, const void*), void (*print)(const void*));
void DeleteMaxHeap(MaxHeap* heap);
int MaxHeapParent(int i);
int MaxHeapLeft(int i);
int MaxHeapRight(int i);
void MaxHeapify(MaxHeap* heap, int i);
void BuildMaxHeap(MaxHeap* heap);
void MaxHeapSort(MaxHeap* heap);
void MaxHeapPrint(MaxHeap* heap);
void ResizeMaxPriorityQueue(MaxHeap* pq);
void* HeapMaximum(MaxHeap* pq);
void* MaxHeapExtractMax(MaxHeap* pq);
void MaxHeapIncreaseKey(MaxHeap* pq, int i, void* key);
void MaxHeapInsert(MaxHeap* pq, void* key);

#endif // MAX_PRIORITY_QUEUE_H
