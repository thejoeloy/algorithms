/* min_priority_queue.c
 * This file contains an implementation of a min priority queue. The min priority queue
 * extends the min binary heap to support operations such as insertion, decreasing the
 * value of a key, and removing the minimum value from the priority queue while maintaining
 * the min heap property. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "min_priority_queue.h"

/* CreateMinHeap(void* A, int size, int elemSize, int (*compare)(const void*, const void*),
 * void(*print)(void*))
 * Creates a min heap from the elements in A. Takes in a function pointer to a comparison function
 * and a printing function that are used in the implementation.
*/
MinHeap* CreateMinHeap(void* A, int size, int elemSize, void* maxElem, int (*compare)(const void*, const void*), void (*print)(const void*)) {
	MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
	if (heap == NULL) {
        perror("Failed to allocate MinHeap");
        exit(EXIT_FAILURE);
    }
    
	heap->A = malloc(elemSize * size);
	if (heap->A == NULL) {
        perror("Failed to allocate heap array");
        exit(EXIT_FAILURE);
    }
	
	memcpy(heap->A, A, elemSize * size);
	heap->elemSize = elemSize;
	heap->length = size;
	heap->size = size;
	
	heap->maxElem = malloc(elemSize);  // Allocate memory for maxElem
    if (heap->maxElem == NULL) {
        perror("Failed to allocate memory for maxElem");
        exit(EXIT_FAILURE);
    }
    memcpy(heap->maxElem, maxElem, elemSize);
	
	heap->compare = compare;
	heap->print = print;
	return heap;
}

/* DeleteMinHeap(MinHeap* heap)
 * Deletes all of the memory associated with the min heap.
*/
void DeleteMinHeap(MinHeap* heap) {
	free(heap->maxElem);
	free(heap->A);
	free(heap);
}

/* ResizeMinPriorityQueue(MinHeap* pq)
 * Increases space of the priority queue by a factor of 2. Exits the program if there is not
 * enough space.
*/
void ResizeMinPriorityQueue(MinHeap* pq) {
	void* tmp = realloc(pq->A, 2 * pq->size * pq->elemSize);
	if (tmp == NULL) {
		perror("Failed to resize array\n");
		exit(EXIT_FAILURE);
	}
	pq->A = tmp;
	pq->size = 2 * pq->size;
}

/* MinHeapParent(int i)
 * Returns the parent of node i.
*/
int MinHeapParent(int i) {
	return (i - 1) / 2;
}

/* MinHeapLeft(int i)
 * Returns the index of the left child of element i.
*/
int MinHeapLeft(int i) {
	return 2 * i + 1;
}

/* MinHeapRight(int i)
 * Returns the index of the right child of element i.
*/
int MinHeapRight(int i) {
	return 2 * i + 2;
}

/* MinHeapify(MinHeap* heap, int i)
 * Restores the min heap property of the heap at index i.
*/
void MinHeapify(MinHeap* heap, int i) {
	int l = MinHeapLeft(i);
	int r = MinHeapRight(i);
	int smallest;
	
	if (l < heap->size && heap->compare((char*)heap->A + (l * heap->elemSize), (char*)heap->A + (i * heap->elemSize)) < 0) {
		smallest = l;
	}
	else  {
		smallest = i;
	}
	
	if (r < heap->size && heap->compare((char*)heap->A + (r * heap->elemSize), (char*)heap->A + (smallest * heap->elemSize)) < 0) {
		smallest = r;
	}
	
	if (smallest != i) {
		void* tmp = malloc(heap->elemSize);
		memcpy(tmp, (char*)heap->A + (i * heap->elemSize), heap->elemSize);
		memcpy((char*)heap->A + (i * heap->elemSize), (char*)heap->A + (smallest * heap->elemSize), heap->elemSize);
		memcpy((char*)heap->A + (smallest * heap->elemSize), tmp, heap->elemSize);
		
		free(tmp);
		MinHeapify(heap, smallest); 
	}
}

/* BuildMinHeap(MinHeap* heap)
 * Restores the min heap property of the heap.
*/
void BuildMinHeap(MinHeap* heap) {
	heap->size = heap->length;
	
	for (int i = heap->length / 2 - 1; i >= 0; i--) {
		MinHeapify(heap, i);
	}
}

/* MinHeapSort(MinHeap* heap)
 * Sorts the elements in the min heap in ascending order.
*/
void MinHeapSort(MinHeap* heap) {
	BuildMinHeap(heap);
	
	for (int i = heap->length - 1; i >= 0; i--) {
		void* tmp = malloc(heap->elemSize);
		memcpy(tmp, heap->A, heap->elemSize);
		memcpy(heap->A, (char*)heap->A + (i * heap->elemSize), heap->elemSize);
		memcpy((char*)heap->A + (i * heap->elemSize), tmp, heap->elemSize);
		free(tmp);
		heap->size--;
		MinHeapify(heap, 0); 
	}
}

/* MinHeapPrint(MinHeap* heap)
 * Prints out the elements contained in the min heap in heap order.
*/
void MinHeapPrint(MinHeap* heap) {
	for (int i = 0; i < heap->length; i++) {
		heap->print((char*)heap->A + (i * heap->elemSize));
	}
}

/* HeapMinimum(MinHeap* pq)
 * Returns a pointer to the minimum element in the priority queue.
*/
void* HeapMinimum(MinHeap* pq) {
	return pq->A;
}

/* MinHeapExtractMin(MinHeap* pq)
 * Returns a pointer to the minimum element in the priority queue and removes it from the priority
 * queue.
*/
void* MinHeapExtractMin(MinHeap* pq) {
	if (pq->length < 1) {
		printf("Heap is Empty\n");
		return NULL;
	}
	
	void* minVal = malloc(pq->elemSize);
    if (minVal == NULL) {
        perror("Failed to allocate memory for minVal");
        exit(EXIT_FAILURE);
    }
    
    memcpy(minVal, pq->A, pq->elemSize);
	memcpy(pq->A, (char*)pq->A + ((pq->length - 1) * pq->elemSize), pq->elemSize);
	pq->length--;
	MinHeapify(pq, 0);
	return minVal;
}

/* MinHeapIncreaseKey(MinHeap* pq, int i, void* key)
 * Decreases the value of the desired key to a smaller value. Does not decrease the key if the
 * new value is not smaller than the value of the key.
*/
void MinHeapDecreaseKey(MinHeap* pq, int i, void* key) {
	if (pq->compare(key, (char*)pq->A + (i * pq->elemSize)) > 0) {
		//printf("New key is smaller than current key\n");
		return;
	}
	
	memcpy((char*)pq->A + (i * pq->elemSize), key, pq->elemSize);
	while (i > 0 && pq->compare((char*)pq->A + (MinHeapParent(i) * pq->elemSize), (char*)pq->A + (i * pq->elemSize)) > 0) {
		void* tmp = malloc(pq->elemSize);
		memcpy(tmp, (char*)pq->A + (i * pq->elemSize), pq->elemSize);
		memcpy((char*)pq->A + (i * pq->elemSize), (char*)pq->A + (MinHeapParent(i) * pq->elemSize), pq->elemSize);
		memcpy((char*)pq->A + (MinHeapParent(i) * pq->elemSize), tmp, pq->elemSize);
		free(tmp);
		i = MinHeapParent(i);
	}
}

/* MinHeapInsert(MinHeap* pq, void* key)
 * Inserts key into the priority queue at its proper location.
*/
void MinHeapInsert(MinHeap* pq, void* key) {
	if (pq->length == pq->size) ResizeMinPriorityQueue(pq);
	
	pq->length++;
	memcpy((char*)pq->A + (pq->length * pq->elemSize), pq->maxElem , pq->elemSize);	
	MinHeapDecreaseKey(pq, pq->length - 1, key);
}

