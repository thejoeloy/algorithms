#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "countingsort.h"

#define ARRAY_SIZE 50
#define MAX_VALUE 100  // Assumed maximum value for the range of array elements

void PrintArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void TestCountingSort() {
    int A[ARRAY_SIZE];
    int B[ARRAY_SIZE];
    int n = ARRAY_SIZE;
    int k = MAX_VALUE;  // Assuming that values are between 0 and MAX_VALUE

    // Seed random number generator
    srand(time(NULL));

    // Initialize the array A with random values between 0 and k
    for (int i = 0; i < n; i++) {
        A[i] = rand() % (k + 1);
    }

    // Print the original array
    printf("Original array:\n");
    PrintArray(A, n);

    // Sort the array using Counting Sort
    CountingSort(A, B, n, k);

    // Print the sorted array
    printf("Sorted array:\n");
    PrintArray(B, n);
}

int main() {
    TestCountingSort();
    return 0;
}

