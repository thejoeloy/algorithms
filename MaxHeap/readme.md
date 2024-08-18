# Max Binary Heap
A generic C implementation of a max binary heap. The heap is dynamically 
allocated. A max binary heap is an implicit data structure which maintains 
the max heap properties that can be used for efficient in place sorting of 
elements. 

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
