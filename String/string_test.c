#include <stdio.h>
#include <string.h>
#include "string.h"

void test_naive_matcher();
void test_rk_matcher();
void test_kmp_matcher();

int main() {
    printf("Testing Naive Matcher\n");
    test_naive_matcher();
    printf("\nTesting RK Matcher\n");
    test_rk_matcher();
    printf("\nTesting KMP Matcher\n");
    test_kmp_matcher();
    return 0;
}

void test_naive_matcher() {
    char* T1 = "Hello Hello";
    char* P1 = "ll";
    printf("Test Case 1:\n");
    naive_matcher(T1, P1); // Expected output: Pattern appears at shift 2 and 8

    char* T2 = "abcdefg";
    char* P2 = "xyz";
    printf("Test Case 2:\n");
    naive_matcher(T2, P2); // Expected output: (No pattern found)
    
    char* T3 = "a";
    char* P3 = "a";
    printf("Test Case 3:\n");
    naive_matcher(T3, P3); // Expected output: Pattern appears at shift 0
}

void test_rk_matcher() {
    char* T1 = "Hello Hello";
    char* P1 = "ll";
    printf("Test Case 1:\n");
    rk_matcher(T1, P1, 256, 101); // Expected output: Pattern appears at shift 2 and 8

    char* T2 = "abcdefg";
    char* P2 = "xyz";
    printf("Test Case 2:\n");
    rk_matcher(T2, P2, 256, 101); // Expected output: (No pattern found)
    
    char* T3 = "a";
    char* P3 = "a";
    printf("Test Case 3:\n");
    rk_matcher(T3, P3, 256, 101); // Expected output: Pattern appears at shift 0
}

void test_kmp_matcher() {
    char* T1 = "Hello Hello";
    char* P1 = "ll";
    printf("Test Case 1:\n");
    kmp_matcher(T1, P1); // Expected output: Pattern occurs with shift 2 and 8

    char* T2 = "abcdefg";
    char* P2 = "xyz";
    printf("Test Case 2:\n");
    kmp_matcher(T2, P2); // Expected output: (No pattern found)
    
    char* T3 = "a";
    char* P3 = "a";
    printf("Test Case 3:\n");
    kmp_matcher(T3, P3); // Expected output: Pattern occurs with shift 0
}
