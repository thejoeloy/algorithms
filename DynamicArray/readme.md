# Dynamic Array 
This is a C implementation of a generic dynamic array. This dynamic array 
supports arbitray data types and has test code in all of the built in data 
types of C. The code can readily be extended to work for user defined data 
types. The implementation use dynamically allocated memory. 

## Operations Supported
- CreateDynamicArray : Creates a dynamically allocated array with numElems 
elements of size elemSize. 
- BuildDynamicArray : Copies the elements from src into the dynamic array
- PrintDynamicArray : Prints out the elements contained in the array.
- LenDynamicArray : Returns the number of elements contained in the 
dyanmic array
- GetAtDynamicArray : Returns the value at the ith index of the array
- SetAtDynamicArray : Sets the value at the ith index of the array to x.
- ResizeDynamicArray : Increases the size of the array by a factor of 2. 
Used as a helper function for insert to ensure that there is enough space 
to store the new element
 - InsertAtDynamicArray : Inserts the element x at the ith index of the 
array. The elements from i to the end of the array must be shifted over to 
accomadate the new element
- DeleteAtDynamicArray : Deletes the element at index i of the array and 
shifts the elements to the right of the element over by 1.
- InsertLastDynamicArray : Inserts the element x at the end of the array
- DeleteLastDynamicArray : Deletes the element at the end of the dynamic 
array
- DeleteDynamicArray : Deletes all of the memory associated with the 
dynamic array.

