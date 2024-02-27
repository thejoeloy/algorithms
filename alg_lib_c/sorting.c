#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <float.h>

typedef int (*Comparator)(const void*, const void*);

int cmp_int(const void* a, const void* b) {
  int num1 = *(int*)a;
  int num2 = *(int*)b;
  return num1 < num2;
}

int cmp_flt(const void* a, const void* b) {
  float num1 = *(float*)a;
  float num2 = *(float*)b;
  return num1 < num2;
}

int cmp_ch(const void* a, const void* b) {
  char c1 = *(char*)a;
  char c2 = *(char*)b;
  return c1 < c2;
}


int cmp_str(const void* a, const void* b) {
  const char* c1 = *(const char**)a;
  const char* c2 = *(const char**)b;
  return strcmp(c1, c2);
}

void jmergesort(void* A, int p, int r, Comparator cmp, int elemSize);
void quicksort(void* A, int p, int r, Comparator cmp, int elemSize);
void insertionsort(void* A, int size, Comparator cmp, int elemSize);
void rand_quicksort(void* A, int p, int r, Comparator cmp, int elemSize);
void jmerge(void* A, int p, int q, int r, Comparator cmp, int elemSize);
int partition(void* A, int p, int r, Comparator cmp, int elemSize);
int rand_partition(void* A, int p, int r, Comparator cmp, int elemSize);
void countingsort();

int main() {
  // Test case with an array of strings (char*)
    const int size = 7;
    char* arr[] = {
        "apple", "banana", "orange", "grape", "cherry", "pear", "kiwi"
    };

    // Print the original array
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    // Sort the array using jmergesort with cmp_str comparator
    jmergesort(arr, 0, size - 1, cmp_str, sizeof(char*));

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    return 0;
}

void insertionsort(void* A, int size, Comparator cmp, int elemSize) {
  void* key = malloc(elemSize);
  for (int j = 0; j < size; j++) {
    memcpy(key, (char*)A + (j * elemSize), elemSize);
    int i = j - 1;
    while ((i >= 0) && (cmp(key, (char*)A + (i * elemSize))) ) {
      memcpy((char*)A + ((i + 1) * elemSize), (char*)A + (i * elemSize), elemSize);
      i = i - 1;
    }
    memcpy((char*)A + ((i+1) * elemSize), key, elemSize);
  }
  free(key);
}

void jmergesort(void* A, int p, int r, Comparator cmp, int elemSize) {  
  if (p < r) {
    int q = (p+r) / 2;
    jmergesort(A, p, q, cmp, elemSize);
    jmergesort(A, q+1, r, cmp, elemSize);
    jmerge(A, p, q, r, cmp, elemSize);
  }
}

void jmerge(void* A, int p, int q, int r, Comparator cmp, int elemSize) {
  int n1 = q - p + 1;
  int n2 = r - q;
  void* L = malloc((n1+1)*elemSize);
  void* R = malloc((n2+1)*elemSize);

  for (int i = 1; i < n1 + 1; i++) {
    memcpy((char*)L + ((i-1)*elemSize), (char*)A + ((p+i-1)*elemSize), elemSize);
  }

  for (int j = 1; j < n2 + 1; j++) {
    memcpy((char*)R + ((j-1)*elemSize), (char*)A + ((q+j)*elemSize), elemSize);
  }

  //int maxValue = INT_MAX; // Use the maximum possible integer value
  //float maxValue = FLT_MAX;
  char* maxValue = "\0";
  
  memcpy((char*)L + (n1 * elemSize), &maxValue, elemSize);
  memcpy((char*)R + (n2 * elemSize), &maxValue, elemSize);
  
  int i = 0;
  int j = 0;

  for (int k = p; k < r + 1; k++) {
    if (cmp((char*)L + (i*elemSize), (char*)R + (j*elemSize))) {
      memcpy((char*)A + (k*elemSize), (char*)L + (i*elemSize), elemSize);
      i = i + 1;
    }
    else {
      memcpy((char*)A + (k*elemSize), (char*)R + (j*elemSize), elemSize);
      j = j + 1;
    }
  }
  free(L);
  free(R);
}

void quicksort(void* A, int p, int r, Comparator cmp, int elemSize) {
  if (p < r) {
    int q = partition(A, p, r, cmp, elemSize);
    quicksort(A, p, q - 1, cmp, elemSize);
    quicksort(A, q + 1, r, cmp, elemSize);
  }
}

int partition(void* A, int p, int r, Comparator cmp, int elemSize) {
  void* x = malloc(elemSize);
  memcpy(x, (char*)A + (r*elemSize), elemSize);
  int i = p - 1;

  for (int j = p; j <= r-1; j++) {
    if (cmp((char*)A + (j*elemSize), x) <= 0) {
      i += 1;
      void* temp = malloc(elemSize);
      memcpy(temp, (char*)A + (i*elemSize), elemSize);
      memcpy((char*)A + (i*elemSize), (char*)A + (j*elemSize), elemSize);
      memcpy((char*)A + (j*elemSize), temp, elemSize);
      free(temp);
    }
  }

  void* temp = malloc(elemSize);
  memcpy(temp, (char*)A + ((i+1)*elemSize), elemSize);
  memcpy((char*)A + ((i+1)*elemSize), (char*)A + (r*elemSize), elemSize);
  memcpy((char*)A + (r*elemSize), temp, elemSize);
  free(temp);
  free(x);
  return i + 1;
}

void rand_quicksort(void* A, int p, int r, Comparator cmp, int elemSize) {
  if (p < r) {
    int q = rand_partition(A, p, r, cmp, elemSize);
    rand_quicksort(A, p, q - 1, cmp, elemSize);
    rand_quicksort(A, q + 1, r, cmp, elemSize);
  }
}

int rand_partition(void* A, int p, int r, Comparator cmp, int elemSize) {
  int i = p + rand() % (r - p + 1);
  void* temp = malloc(elemSize);
  memcpy(temp, (char*)A + (i*elemSize), elemSize);
  memcpy((char*)A + (i*elemSize), (char*)A + (r*elemSize), elemSize);
  memcpy((char*)A + (r*elemSize), temp, elemSize);
  free(temp);
  return partition(A, p, r, cmp, elemSize);
}
