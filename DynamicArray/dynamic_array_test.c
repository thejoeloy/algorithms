#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"

void PrintInt(const void* p);
void PrintFloat(const void* p);
void PrintChar(const void* p);
void PrintString(const void* p);
void DynamicArrayIntTest();
void DynamicArrayFloatTest();
void DynamicArrayCharTest();
void DynamicArrayStringTest();

int main() {
    DynamicArrayIntTest();
    DynamicArrayFloatTest();
    DynamicArrayCharTest();
    DynamicArrayStringTest();
    return 0;
}

void PrintInt(const void* p) {
    printf("%d\n", *(int*)p);
}

void PrintFloat(const void* p) {
    printf("%.2f\n", *(float*)p);
}

void PrintChar(const void* p) {
    printf("%c\n", *(char*)p);
}

void PrintString(const void* p) {
    printf("%s\n", *(char**)p);
}

void DynamicArrayIntTest() {
    int numElems = 5;
    int elemSizeInt = sizeof(int);

    // Test with integers
    DynamicArray* s1 = CreateDynamicArray(numElems, elemSizeInt, PrintInt);
    int nums[5] = {1, 2, 3, 4, 5};
    BuildDynamicArray(s1, nums, numElems, elemSizeInt);
    printf("Initial integer array:\n");
    PrintDynamicArray(s1);

    // Perform 15 insertions and deletions

    int val = 6;
    InsertLastDynamicArray(s1, &val);
    printf("After insertion at end:\n");
    PrintDynamicArray(s1);

    DeleteAtDynamicArray(s1, 2);
    printf("After deletion at index 2:\n");
    PrintDynamicArray(s1);

    int val2 = 69;
    InsertAtDynamicArray(s1, 2, &val2);
    printf("After insertion at index 2:\n");
    PrintDynamicArray(s1);

    int val3 = 99;
    InsertLastDynamicArray(s1, &val3);
    printf("After insertion at end:\n");
    PrintDynamicArray(s1);

    DeleteLastDynamicArray(s1);
    printf("After deletion at end:\n");
    PrintDynamicArray(s1);

    int val4 = 42;
    InsertAtDynamicArray(s1, 0, &val4);
    printf("After insertion at index 0:\n");
    PrintDynamicArray(s1);

    int val5 = 84;
    InsertAtDynamicArray(s1, 4, &val5);
    printf("After insertion at index 4:\n");
    PrintDynamicArray(s1);

    DeleteAtDynamicArray(s1, 1);
    printf("After deletion at index 1:\n");
    PrintDynamicArray(s1);

    int val6 = 75;
    InsertLastDynamicArray(s1, &val6);
    printf("After insertion at end:\n");
    PrintDynamicArray(s1);

    int val7 = 23;
    InsertAtDynamicArray(s1, 2, &val7);
    printf("After insertion at index 2:\n");
    PrintDynamicArray(s1);

    DeleteAtDynamicArray(s1, 0);
    printf("After deletion at index 0:\n");
    PrintDynamicArray(s1);

    DeleteAtDynamicArray(s1, 2);
    printf("After deletion at index 2:\n");
    PrintDynamicArray(s1);

    int val8 = 11;
    InsertAtDynamicArray(s1, 1, &val8);
    printf("After insertion at index 1:\n");
    PrintDynamicArray(s1);

    int val9 = 22;
    InsertLastDynamicArray(s1, &val9);
    printf("After insertion at end:\n");
    PrintDynamicArray(s1);

    int val10 = 33;
    InsertLastDynamicArray(s1, &val10);
    printf("After insertion at end:\n");
    PrintDynamicArray(s1);

    DeleteLastDynamicArray(s1);
    printf("After deletion at end:\n");
    PrintDynamicArray(s1);

    DeleteLastDynamicArray(s1);
    printf("After deletion at end:\n");
    PrintDynamicArray(s1);

    DeleteDynamicArray(s1);
}

/*
void DynamicArrayIntTest() {
    int numElems = 5;
    int elemSizeInt = sizeof(int);

    // Test with integers
    DynamicArray* s1 = CreateDynamicArray(numElems, elemSizeInt, PrintInt);
    int nums[5] = {1, 2, 3, 4, 5};
    BuildDynamicArray(s1, nums, numElems, elemSizeInt);
    printf("Initial integer array:\n");
    PrintDynamicArray(s1);

    int val = 6;
    InsertLastDynamicArray(s1, &val);
    printf("After insertion at end:\n");
    PrintDynamicArray(s1);

    DeleteAtDynamicArray(s1, 2);
    printf("After deletion at index 2:\n");
    PrintDynamicArray(s1);

    int val2 = 69;
    InsertAtDynamicArray(s1, 2, &val2);
    printf("After insertion at index 2:\n");
    PrintDynamicArray(s1);

    DeleteDynamicArray(s1);
}
*/
void DynamicArrayFloatTest() {
    int numElems = 5;
    int elemSizeFloat = sizeof(float);

    // Test with floats
    DynamicArray* s2 = CreateDynamicArray(numElems, elemSizeFloat, PrintFloat);
    float floats[5] = {1.10, 2.20, 3.30, 4.40, 5.50};
    BuildDynamicArray(s2, floats, numElems, elemSizeFloat);
    printf("Initial float array:\n");
    PrintDynamicArray(s2);

    float valFloat = 6.60;
    InsertLastDynamicArray(s2, &valFloat);
    printf("After insertion at end:\n");
    PrintDynamicArray(s2);

    DeleteAtDynamicArray(s2, 2);
    printf("After deletion at index 2:\n");
    PrintDynamicArray(s2);

    float valFloat2 = 69.69;
    InsertAtDynamicArray(s2, 2, &valFloat2);
    printf("After insertion at index 2:\n");
    PrintDynamicArray(s2);

    DeleteDynamicArray(s2);
}

void DynamicArrayCharTest() {
    int numElems = 5;
    int elemSizeChar = sizeof(char);

    // Test with chars
    DynamicArray* s4 = CreateDynamicArray(numElems, elemSizeChar, PrintChar);
    char chars[5] = {'a', 'b', 'c', 'd', 'e'};
    BuildDynamicArray(s4, chars, numElems, elemSizeChar);
    printf("Initial char array:\n");
    PrintDynamicArray(s4);

    char valChar = 'z';
    InsertLastDynamicArray(s4, &valChar);
    printf("After insertion at end:\n");
    PrintDynamicArray(s4);

    DeleteAtDynamicArray(s4, 2);
    printf("After deletion at index 2:\n");
    PrintDynamicArray(s4);

    char valChar2 = 'y';
    InsertAtDynamicArray(s4, 2, &valChar2);
    printf("After insertion at index 2:\n");
    PrintDynamicArray(s4);

    DeleteDynamicArray(s4);
}

void DynamicArrayStringTest() {
    int numElems = 5;

    // Define an array of string pointers
    char* strings[5] = {
        "hello\0",
        "world\0",
        "this\0",
        "is\0",
        "test\0"
    };

    // Create the dynamic array with string pointers
    DynamicArray* s3 = CreateDynamicArray(numElems, sizeof(char*), PrintString);

    // Pass the array of string pointers directly to BuildDynamicArray
    BuildDynamicArray(s3, strings, numElems, sizeof(char*));
    printf("Initial string array:\n");
    PrintDynamicArray(s3);

    // Test Insertion and Deletion
    char* newStr = "array";
    InsertLastDynamicArray(s3, &newStr);
    printf("After insertion at end:\n");
    PrintDynamicArray(s3);

    DeleteAtDynamicArray(s3, 2);
    printf("After deletion at index 2:\n");
    PrintDynamicArray(s3);

    char* str2 = "again";
    InsertAtDynamicArray(s3, 2, &str2);
    printf("After insertion at index 2:\n");
    PrintDynamicArray(s3);

    // Delete the dynamic array
    DeleteDynamicArray(s3);
}

