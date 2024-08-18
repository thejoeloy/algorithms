#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct DynamicArray {
    void* arr;
    int numElems;
    int elemSize;
    int size;
    void (*printFunc)(const void*); // Function pointer for printing elements
} DynamicArray;

// Function prototypes
DynamicArray* CreateDynamicArray(int numElems, int elemSize, void (*printFunc)(const void*));
void BuildDynamicArray(DynamicArray* s, void* src, int numElems, int elemSize);
void PrintDynamicArray(const DynamicArray* s);
int LenDynamicArray(const DynamicArray* s);
void* GetAtDynamicArray(const DynamicArray* s, int i);
void SetAtDynamicArray(DynamicArray* s, int i, void* x);
void ResizeDynamicArray(DynamicArray* s);
void InsertAtDynamicArray(DynamicArray* s, int i, void* x);
void DeleteAtDynamicArray(DynamicArray* s, int i);
void InsertLastDynamicArray(DynamicArray* s, void* x);
void DeleteLastDynamicArray(DynamicArray* s);
void DeleteDynamicArray(DynamicArray* s);

#endif // DYNAMIC_ARRAY_H
