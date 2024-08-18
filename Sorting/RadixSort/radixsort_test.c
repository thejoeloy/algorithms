#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "radixsort.h"

// Function to print an array
void PrintArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Test function for RadixSort
void TestRadixSort() {
    // Define the size of the array and the maximum number of digits
    const int n = 50; // Size of the array
    const int maxDigitCount = 4; // To accommodate numbers up to 1000

    int A[n];
    
    // Seed random number generator
    srand(time(NULL));

    // Initialize the array A with random values between 0 and 1000
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 1001; // Numbers between 0 and 1000
    }

    // Print the original array
    printf("Original array:\n");
    PrintArray(A, n);

    // Sort the array using Radix Sort
    RadixSort(A, n, maxDigitCount);

    // Print the sorted array
    printf("Sorted array:\n");
    PrintArray(A, n);
}

int main() {
    TestRadixSort();
    return 0;
}

