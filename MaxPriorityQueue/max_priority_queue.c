#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include "max_priority_queue.h"

/* CreateMaxHeap(void* A, int size, int elemSize, int (*compare)(const void*, const void*),
 * void(*print)(void*))
 * Creates a max heap from the elements in A. Takes in a function pointer to a comparison function
 * and a printing function that are used in the implementation.
*/
MaxHeap* CreateMaxHeap(void* A, int size, int elemSize, void* minElem, int (*compare)(const void*, const void*), void (*print)(const void*)) {
	MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
	if (heap == NULL) {
        perror("Failed to allocate MaxHeap");
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
	heap->minElem = malloc(elemSize);  // Allocate memory for minElem
    if (heap->minElem == NULL) {
        perror("Failed to allocate memory for minElem");
        exit(EXIT_FAILURE);
    }
    memcpy(heap->minElem, minElem, elemSize);
	
	heap->compare = compare;
	heap->print = print;
	return heap;
}

/* DeleteMaxHeap(MaxHeap* heap)
 * Deletes all of the memory associated with the max heap.
*/
void DeleteMaxHeap(MaxHeap* heap) {
	free(heap->minElem);
	free(heap->A);
	free(heap);
}

/* ResizeMaxPriorityQueue(MaxHeap* pq)
 * Increases space of the priority queue by a factor of 2. Exits the program if there is not
 * enough space.
*/
void ResizeMaxPriorityQueue(MaxHeap* pq) {
	void* tmp = realloc(pq->A, 2 * pq->size * pq->elemSize);
	if (tmp == NULL) {
		perror("Failed to resize array\n");
		exit(EXIT_FAILURE);
	}
	pq->A = tmp;
	pq->size = 2 * pq->size;
}

/* MaxHeapParent(int i)
 * Returns the parent of node i.
*/
int MaxHeapParent(int i) {
	return (i - 1) / 2;
}

/* MaxHeapLeft(int i)
 * Returns the index of the left child of element i.
*/
int MaxHeapLeft(int i) {
	return 2 * i + 1;
}

/* MaxHeapRight(int i)
 * Returns the index of the right child of element i.
*/
int MaxHeapRight(int i) {
	return 2 * i + 2;
}

/* MaxHeapify(MaxHeap* heap, int i)
 * Restores the max heap property of the heap at index i.
*/
void MaxHeapify(MaxHeap* heap, int i) {
	int l = MaxHeapLeft(i);
	int r = MaxHeapRight(i);
	int largest;
	
	if (l < heap->size && heap->compare((char*)heap->A + (l * heap->elemSize), (char*)heap->A + (i * heap->elemSize)) > 0) {
		largest = l;
	}
	else  {
		largest = i;
	}
	
	if (r < heap->size && heap->compare((char*)heap->A + (r * heap->elemSize), (char*)heap->A + (largest * heap->elemSize)) > 0) {
		largest = r;
	}
	
	if (largest != i) {
		void* tmp = malloc(heap->elemSize);
		memcpy(tmp, (char*)heap->A + (i * heap->elemSize), heap->elemSize);
		memcpy((char*)heap->A + (i * heap->elemSize), (char*)heap->A + (largest * heap->elemSize), heap->elemSize);
		memcpy((char*)heap->A + (largest * heap->elemSize), tmp, heap->elemSize);
		free(tmp);
		MaxHeapify(heap, largest); 
	}
}

/* BuildMaxHeap(MaxHeap* heap)
 * Restores the max heap property of the heap.
*/
void BuildMaxHeap(MaxHeap* heap) {
	heap->size = heap->length;
	
	for (int i = heap->length / 2 - 1; i >= 0; i--) {
		MaxHeapify(heap, i);
	}
}

/* MaxHeapSort(MaxHeap* heap)
 * Sorts the elements in the max heap in descending order.
*/
void MaxHeapSort(MaxHeap* heap) {
	BuildMaxHeap(heap);
	
	for (int i = heap->length - 1; i >= 0; i--) {
		void* tmp = malloc(heap->elemSize);
		memcpy(tmp, heap->A, heap->elemSize);
		memcpy(heap->A, (char*)heap->A + (i * heap->elemSize), heap->elemSize);
		memcpy((char*)heap->A + (i * heap->elemSize), tmp, heap->elemSize);
		free(tmp);
		heap->size--;
		MaxHeapify(heap, 0); 
	}
}

/* MaxHeapPrint(MaxHeap* heap)
 * Prints out the elements contained in the max heap in heap order.
*/
void MaxHeapPrint(MaxHeap* heap) {
	for (int i = 0; i < heap->length; i++) {
		heap->print((char*)heap->A + (i * heap->elemSize));
	}
}

/* HeapMaximum(MaxHeap* pq)
 * Returns a pointer to the maximum element in the priority queue.
*/
void* HeapMaximum(MaxHeap* pq) {
	return pq->A;
}

/* MaxHeapExtractMax(MaxHeap* pq)
 * Returns a pointer to the maximum element in the priority queue and removes it from the priority
 * queue.
*/
void* MaxHeapExtractMax(MaxHeap* pq) {
	if (pq->length < 1) {
		//printf("Heap is Empty\n");
		return NULL;
	}
	
	void* maxVal = malloc(pq->elemSize);
    if (maxVal == NULL) {
        perror("Failed to allocate memory for maxVal");
        exit(EXIT_FAILURE);
    }
    
    memcpy(maxVal, pq->A, pq->elemSize);
	memcpy(pq->A, (char*)pq->A + ((pq->length - 1) * pq->elemSize), pq->elemSize);
	pq->length--;
	MaxHeapify(pq, 0);
	return maxVal;
}

/* MaxHeapIncreaseKey(MaxHeap* pq, int i, void* key)
 * Increases the value of the desired key to a larger value. Does not increase the key if the
 * new value is not larger than the value of the key.
*/
void MaxHeapIncreaseKey(MaxHeap* pq, int i, void* key) {
	if (pq->compare(key, (char*)pq->A + (i * pq->elemSize)) < 0) {
		//printf("New key is smaller than current key\n");
		return;
	}
	
	memcpy((char*)pq->A + (i * pq->elemSize), key, pq->elemSize);
	while (i > 0 && pq->compare((char*)pq->A + (MaxHeapParent(i) * pq->elemSize), (char*)pq->A + (i * pq->elemSize)) < 0) {
		void* tmp = malloc(pq->elemSize);
		memcpy(tmp, (char*)pq->A + (i * pq->elemSize), pq->elemSize);
		memcpy((char*)pq->A + (i * pq->elemSize), (char*)pq->A + (MaxHeapParent(i) * pq->elemSize), pq->elemSize);
		memcpy((char*)pq->A + (MaxHeapParent(i) * pq->elemSize), tmp, pq->elemSize);
		free(tmp);
		i = MaxHeapParent(i);
	}
}

/* MaxHeapInsert(MaxHeap* pq, void* key)
 * Inserts key into the priority queue at its proper location.
*/
void MaxHeapInsert(MaxHeap* pq, void* key) {
	if (pq->length == pq->size) ResizeMaxPriorityQueue(pq);
	
	pq->length++;
	memcpy((char*)pq->A + (pq->length * pq->elemSize), pq->minElem , pq->elemSize);	
	MaxHeapIncreaseKey(pq, pq->length - 1, key);
}

