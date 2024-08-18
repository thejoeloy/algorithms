#include "rand_quicksort.h"
#include <stdio.h>
#include <string.h>

int IntCmp(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    return (num1 > num2) - (num1 < num2);
}

int FloatCmp(const void* a, const void* b) {
    float num1 = *(float*)a;
    float num2 = *(float*)b;
    return (num1 > num2) - (num1 < num2);
}

int CharCmp(const void* a, const void* b) {
    char c1 = *(char*)a;
    char c2 = *(char*)b;
    return (c1 > c2) - (c1 < c2);
}

int StringCmp(const void* a, const void* b) {
    const char* c1 = *(const char**)a;
    const char* c2 = *(const char**)b;
    return strcmp(c1, c2);
}

void TestRandQuickSort() {
    printf("Testing RandQuickSort...\n");

    // Integer array
    int int_list[] = {54, 23, 87, 12, 45, 67, 98, 32, 76, 65, 43, 89, 34, 21, 78, 90, 56, 87, 45, 10};
    int size_int = sizeof(int_list) / sizeof(int);
    printf("Original integer array: ");
    for (int i = 0; i < size_int; i++) {
        printf("%d ", int_list[i]);
    }
    printf("\n");

    RandQuickSort(int_list, 0, size_int - 1, IntCmp, sizeof(int));

    printf("Sorted integer array: ");
    for (int i = 0; i < size_int; i++) {
        printf("%d ", int_list[i]);
    }
    printf("\n");

    // Float array
    float float_list[] = {3.14, 1.618, 2.718, 0.577, 1.732, 1.414, 1.333, 2.236, 2.645, 0.693};
    int size_float = sizeof(float_list) / sizeof(float);
    printf("Original float array: ");
    for (int i = 0; i < size_float; i++) {
        printf("%.3f ", float_list[i]);
    }
    printf("\n");

    RandQuickSort(float_list, 0, size_float - 1, FloatCmp, sizeof(float));

    printf("Sorted float array: ");
    for (int i = 0; i < size_float; i++) {
        printf("%.3f ", float_list[i]);
    }
    printf("\n");

    // Char array
    char char_list[] = "sortingtest";
    int size_char = sizeof(char_list) - 1;
    printf("Original char array: %s\n", char_list);

    RandQuickSort(char_list, 0, size_char - 1, CharCmp, sizeof(char));

    printf("Sorted char array: %s\n", char_list);

    // String array
    const char* str_list[] = {"banana\0", "apple\0", "grape\0", "kiwi\0", "orange\0", "pear\0", "peach\0", "plum\0"};
    int size_str = sizeof(str_list) / sizeof(str_list[0]);
    printf("Original string array:\n");
    for (int i = 0; i < size_str; i++) {
        printf("%s\n", str_list[i]);
    }

    RandQuickSort((void*)str_list, 0, size_str - 1, StringCmp, sizeof(char*));

    printf("Sorted string array:\n");
    for (int i = 0; i < size_str; i++) {
        printf("%s\n", str_list[i]);
    }
}


int main() {
    TestQuickSort();
    TestInsertionSort();
	TestMergeSort();
	TestRandQuickSort();
    return 0;
}
