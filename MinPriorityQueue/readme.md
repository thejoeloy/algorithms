# Min Priority Queue
A generic C implementation of a min priority queue. The priority queue 
builds on top of the min binary heap implementation. The priority queue 
adds implementations for operations that can insert values, remove the 
minimum value, and decrease the size of the key. 

## Operations Supported
- CreateMinHeap : Creaates an empty binary heap that can contain size 
elements of size elemSize. 
- DeleteMinHeap : Deletes all of the memory associated with the heap
- MinHeapParent : Returns the parent of the ith element in the heap
- MinHeapLeft : Returns the left child of the ith element in the heap
- MinHeapRight : Returns the right child of the ith element in the heap
- MinHeapify : Used to restore the min heap property for a given index 
- BuildMinHeap : Builds a min heap which obeys the min heap properties
- MinHeapSort : Sorts all of the elements in the min heap in ascending 
order
- MinHeapPrint : Prints out all of the elements in the max binary heap
- ResizeMinPriorityQueue : Increases the size of the queue by a factor of 
2 to ensure that a newly inserted element can fit in the priority queue.
- HeapMinimum : Returns the smallest element stored in the priority queue
- MinHeapExtractMin : Extracts the smallest element stored in the priority 
queue
- MinHeapDecreaseKey : Decreases the key in the min priority queue to the 
new value contained in i, as long as i is less than the original key
- MinHeapInsert : Inserts the key into its proper location in the priority 
queue
