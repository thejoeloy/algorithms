# Max Binary Heap
A generic C implementation of a max priority queue. The priority queue 
builds on top of the max binary heap implementation. The priority queue 
adds opertaions for getting the maximum value, removing the maximum value, 

## Operations Supported
- CreateMaxHeap : Creaates an empty binary heap that can contain size 
elements of size elemSize. 
- DeleteMaxHeap : Deletes all of the memory associated with the heap
- MaxHeapParent : Returns the parent of the ith element in the heap
- MaxHeapLeft : Returns the left child of the ith element in the heap
- MaxHeapRight : Returns the right child of the ith element in the heap
- MaxHeapify : Used to restore the max heap property for a given index 
- BuildMaxHeap : Builds a max heap which obeys the max heap properties
- MaxHeapSort : Sorts all of the elements in the max heap in descending 
order
- MaxHeapPrint : Prints out all of the elements in the max binary heap
- ResizeMaxPriorityQueue :
- HeapMaximum : Returns the largest element stored in the priority queue
- MaxHeapExtractMax : Extracts the largest element stored in the priority 
queue
- MaxHeapIncreaseKey : Increases the key in the max priority queue to the 
new value contained in i, as long as i is greater than the original key
- MaxHeapInsert : Inserts the key into its proper location in the priority 
queue
