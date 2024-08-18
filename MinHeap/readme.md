# Min Binary Heap
A generic C implementation of a min binary heap. The heap is dynamically 
allocated. A min binary heap is an implicit data structure which maintains 
the min heap properties that can be used for efficient in place sorting of 
elements. 

## Operations Supported
- CreateMinHeap : Creaates an empty binary heap that can contain size 
elements of size elemSize. 
- DeleteMinHeap : Deletes all of the memory associated with the heap
- MinHeapParent : Returns the parent of the ith element in the heap
- MinHeapLeft : Returns the left child of the ith element in the heap
- MinHeapRight : Returns the right child of the ith element in the heap
- MinHeapify : Used to restore the min heap property for a given index 
- BuildMinHeap : Builds a max heap which obeys the max heap properties
- MinHeapSort : Sorts all of the elements in the min heap in ascending 
order
- MinHeapPrint : Prints out all of the elements in the min binary heap
