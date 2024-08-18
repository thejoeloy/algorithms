#include <stdio.h>
#include <stdlib.h>
#include "radixsort.h"

// Helper function to get the digit at a specific place value
int GetDigit(int number, int digitPlace) {
    return (number / digitPlace) % 10;
}

void RadixSort(int A[], int n, int d) {
    // Temporary array for the sorted output
    int *B = (int *)malloc(n * sizeof(int));
    if (B == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Maximum digit value for decimal digits (0-9)
    int k = 9;

    // Perform counting sort for each digit place
    int digitPlace = 1;
    for (int i = 0; i < d; i++) {
        // Create a temporary array to hold the digits
        int *C = (int *)malloc((k + 1) * sizeof(int));
        if (C == NULL) {
            printf("Memory allocation failed\n");
            free(B);
            return;
        }

        // Initialize counting array C
        for (int j = 0; j <= k; j++) {
            C[j] = 0;
        }

        // Count occurrences of each digit
        for (int j = 0; j < n; j++) {
            int digit = GetDigit(A[j], digitPlace);
            C[digit]++;
        }

        // Calculate cumulative counts
        for (int j = 1; j <= k; j++) {
            C[j] += C[j - 1];
        }

        // Build the output array based on digit counts
        for (int j = n - 1; j >= 0; j--) {
            int digit = GetDigit(A[j], digitPlace);
            B[C[digit] - 1] = A[j];
            C[digit]--;
        }

        // Copy sorted array back to A
        for (int j = 0; j < n; j++) {
            A[j] = B[j];
        }

        // Free the counting array
        free(C);

        // Move to the next digit place (10^i)
        digitPlace *= 10;
    }

    // Free the temporary array
    free(B);
}

