/* dynamic_array.c
 * This file contains an implementation of a dynamic array. The implementation
 * is generic and can support arbitrary data types. Unlike the static array,
 * the dynamic array can be resized in order to accomodate more elements. Similar
 * to the static array, the dynamic array supports insertions/deletions to the
 * end of the array in O(1) time and insertions/deletions to other points in the
 * array in O(n) time. Getting/setting elements in the array occurs in O(1) time
 * by leveraging pointer arithmetic. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"

/* CreateDynamicArray(int numElems, int elemSize, void (*printFunc)(const void*))
 * Creates a dynamic array of size numElems which holds values of size elemSize. Also takes in
 * a function pointer to a printing function used to print out the data.
*/
DynamicArray* CreateDynamicArray(int numElems, int elemSize, void (*printFunc)(const void*)) {
    DynamicArray* s = (DynamicArray*)malloc(sizeof(DynamicArray));
    if (!s) {
        perror("Failed to allocate memory for DynamicArray");
        exit(EXIT_FAILURE);
    }
    s->arr = malloc(numElems * elemSize);
    if (!s->arr) {
        perror("Failed to allocate memory for array");
        free(s);
        exit(EXIT_FAILURE);
    }
    s->numElems = 0;
    s->elemSize = elemSize;
    s->size = numElems;
    s->printFunc = printFunc; // Set the print function
    return s;
}

/* BuildDynamicArray(DynamicArray* s, void* src, int numElems, int elemSize)
 * Copies the elements of src into s. Resizes the dynamic array if src is larger than the
 * space allocated for the dynamic array.
*/
void BuildDynamicArray(DynamicArray* s, void* src, int numElems, int elemSize) {
    if (numElems > s->size) {
        ResizeDynamicArray(s);
    }
    memcpy(s->arr, src, numElems * elemSize);
    s->numElems = numElems;
}

/* PrintDynamicArray(const DynamicArray* s)
 * Prints out the elements of the dynamic array
*/
void PrintDynamicArray(const DynamicArray* s) {
    for (int i = 0; i < s->numElems; i++) {
        s->printFunc((char*)s->arr + (i * s->elemSize));
    }
}

/* LenDynamicArray(const DynamicArray* s)
 * Returns the number of elements contained in the dynamic array.
*/
int LenDynamicArray(const DynamicArray* s) {
    return s->numElems;
}

/* GetAtDynamicArray(const DynamicArray* s, int i)
 * Returns a pointer to the element at position i in the dynamic array.
*/
void* GetAtDynamicArray(const DynamicArray* s, int i) {
    if (i < 0 || i >= s->numElems) {
        fprintf(stderr, "Index out of bounds\n");
        return NULL;
    }
    return (char*)s->arr + (i * s->elemSize);
}

/* SetAtDynamicArray(DynamicArray* s, int i, void* x)
 * Sets index i in the dynamic array to x. Checks to see if i is within bounds and does nothing
 * if an invalid i is passed into the function.
*/
void SetAtDynamicArray(DynamicArray* s, int i, void* x) {
    if (i < 0 || i >= s->numElems) {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }
    memcpy((char*)s->arr + (i * s->elemSize), x, s->elemSize);
}

/* ResizeDynamicArray(DynamicArray* s)
 * Resizes the dynamic array by a factor of 2. Exits the program if there is not enough space for
 * the new array.
*/
void ResizeDynamicArray(DynamicArray* s) {
    void* tmp = realloc(s->arr, 2 * s->size * s->elemSize);
    if (tmp == NULL) {
        perror("Failed to resize array");
        exit(EXIT_FAILURE);
    }
    s->arr = tmp;
    s->size = 2 * s->size;
}

/* InsertAtDynamicArray(DynamicArray* s, int i, void* x)
 * Inserts element x at position i in the dynamic array. Resizes the array if the array is not
 * large enough to hold the new value
*/
void InsertAtDynamicArray(DynamicArray* s, int i, void* x) {
    if (i < 0 || i > s->numElems) {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }
    if (s->numElems == s->size) ResizeDynamicArray(s);
    memmove((char*)s->arr + ((i + 1) * s->elemSize),
            (char*)s->arr + (i * s->elemSize),
            (s->numElems - i) * s->elemSize);
    SetAtDynamicArray(s, i, x);
    s->numElems += 1;
}

/* DeleteAtDynamicArray(DynamicArray* s, int i)
 * Deletes the element at position i in the dynamic array. Does bounds checks to ensure that the
 * element is within the proper range.
*/
void DeleteAtDynamicArray(DynamicArray* s, int i) {
    if (i < 0 || i >= s->numElems) {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }
    memmove((char*)s->arr + (i * s->elemSize),
            (char*)s->arr + ((i + 1) * s->elemSize),
            (s->numElems - i - 1) * s->elemSize);
    s->numElems -= 1;
}

/* InsertLastDynamicArray(DynamicArray* s, void* x)
 * Inserts element x at the end of the dynamic array. Resizes the array if the array is not
 * large enough to hold the new value.
*/
void InsertLastDynamicArray(DynamicArray* s, void* x) {
    if (s->numElems == s->size) ResizeDynamicArray(s);
    memcpy((char*)s->arr + (s->numElems * s->elemSize), x, s->elemSize);
    s->numElems++;
}

/* DeleteLastDynamicArray(DynamicArray* s)
 * Deletes the last element contained in the dynamic array.
*/
void DeleteLastDynamicArray(DynamicArray* s) {
    if (s->numElems > 0) s->numElems -= 1;
}

/* DeleteDynamicArray(DynamicArray* s)
 * Deletes all of the memory associated with the dynamic array.
*/
void DeleteDynamicArray(DynamicArray* s) {
    free(s->arr);
    free(s);
}
