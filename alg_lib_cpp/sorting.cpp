// sorting.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <random>
#include <algorithm>
#include <ctime>

using namespace std;

template <typename T> void insertionsort(vector<T>& A, int size) {
  for (int j = 0; j < size; j++) {
    T key = A[j];
    int i = j - 1;
    while ( (i >= 0) & (A[i] > key) ) {
      A[i + 1] = A[i];
      i = i - 1;
    }
    A[i + 1] = key;
  }
}

template <typename T> vector<T> merge(vector<T>& A, int p, int q, int r) {
  // merge
	int n1 = q - p + 1;
	int n2 = r - q;
	vector<T> L(n1 + 1);
	vector<T> R(n2 + 1);

	for (int i = 1; i < n1 + 1; i++) {
		L[i - 1] = A[p + i - 1];
	}

	for (int j = 1; j < n2 + 1; j++) {
		R[j - 1] = A[q + j];
	}
	
	L[n1] = numeric_limits<T>::max();
	R[n2] = numeric_limits<T>::max();

	int i = 0;
	int j = 0;
		
	for (int k = p; k < r + 1; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i = i + 1;
		}
		else {
			A[k] = R[j];
			j = j + 1;
		}
	}
	
	return A;
}

template <typename T> vector<T> mergesort(vector<T>& A, int p, int r) {
        if (p < r) {
		int q = (p + r) / 2;
		vector<T> L = mergesort(A, p, q);
		vector<T> R = mergesort(A, q + 1, r);
		A = merge(A, p, q, r);
	}
	return A;
}


template <typename T> int partition(vector<T>& A, int p, int r) {
    T x = A[r];
    int i = p - 1;
    for (int j = p; j <= r-1; j++) {
        if (A[j] <= x) {
	    i += 1;
	    // Swap A[i] and A[j]
	    T temp = A[i];
	    A[i] = A[j];
	    A[j] = temp;
	}
    }
    // Swap A[i + 1] with A[r]
    T temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;
    return i + 1;
}

template <typename T> void quicksort(vector<T>& A, int p, int r) {
  if (p < r) {
    int q = partition(A, p, r);
    quicksort(A, p, q - 1);
    quicksort(A, q + 1, r);
  }
}

template <typename T> int rand_partition(vector<T>& A, int p, int r) {
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> distr(p, r);
    int i = distr(gen);
    T temp = A[i];
    A[i] = A[r];
    A[r] = temp;
    return partition(A, p, r);
}

template <typename T> void rand_quicksort(vector<T>& A, int p, int r) {
  if (p < r) {
    int q = rand_partition(A, p, r);
    rand_quicksort(A, p, q - 1);
    rand_quicksort(A, q + 1, r);
  }
}

// Radix sort

// bucket sort

// randomized select 

// countingsort
void countingsort(vector<int>& A, vector<int>& B, int k) {
  vector<int> C(k + 1, 0);

  for (int j = 0; j < A.size() - 1; j++) {
    C[A[j]] = C[A[j]] + 1;
  }

  for (int i = 0; i < k + 1; i++) {
    C[i] = C[i] + C[i - 1];
  }

  for (int j = A.size() - 1; j > -1; j--) {
    B[C[A[j]]] = A[j];
    C[A[j]] = C[A[j]] - 1;
  }
}

int main(int argc, char** argv) {
	cout << "Main program is running" << endl;
	
	int size = 100;
	vector<int> v(size, 0);
	random_device rd; // obtain a random number from hardware
    	mt19937 gen(rd()); // seed the generator
    	uniform_int_distribution<> distr(0, 9); // define the range
	cout << "List is :" << endl;
    	for(int i = 0; i < size; i++) {
		v[i] = distr(gen);
		cout << v[i] << endl;
	}
	
	int p = 0;
	int r = size - 1;
	rand_quicksort(v, p, r);
	
	/*
	vector<int> b(size, 0);
	countingsort(v, b, 10);
	cout << "Sorted list is :" <<  endl;
	*/
	for (int i = 0; i < size; i++) {
                cout << v[i] << endl;
        }

	

	return 0;
}
