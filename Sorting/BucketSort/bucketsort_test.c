#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "bucketsort.h"

// Function to print an array of floats
void PrintFloatArray(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

// Function to print an array of doubles
void PrintDoubleArray(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%lf ", arr[i]);
    }
    printf("\n");
}

// Test function for FloatBucketSort
void TestFloatBucketSort() {
    // Define the size of the array
    const int n = 20; // Example size

    // Seed random number generator
    srand(time(NULL));

    // Initialize the float array with random values between 0 and 1
    float A[n];
    for (int i = 0; i < n; i++) {
        A[i] = (float)rand() / RAND_MAX; // Random float between 0 and 1
    }

    // Print the original array
    printf("Original float array:\n");
    PrintFloatArray(A, n);

    // Sort the array using FloatBucketSort
    FloatBucketSort(A, n);

    // Print the sorted array
    printf("Sorted float array:\n");
    PrintFloatArray(A, n);
}

// Test function for DoubleBucketSort
void TestDoubleBucketSort() {
    // Define the size of the array
    const int n = 20; // Example size

    // Seed random number generator
    srand(time(NULL));

    // Initialize the double array with random values between 0 and 1
    double A[n];
    for (int i = 0; i < n; i++) {
        A[i] = (double)rand() / RAND_MAX; // Random double between 0 and 1
    }

    // Print the original array
    printf("Original double array:\n");
    PrintDoubleArray(A, n);

    // Sort the array using DoubleBucketSort
    DoubleBucketSort(A, n);

    // Print the sorted array
    printf("Sorted double array:\n");
    PrintDoubleArray(A, n);
}

int main() {
    TestFloatBucketSort();
    TestDoubleBucketSort();
    return 0;
}

