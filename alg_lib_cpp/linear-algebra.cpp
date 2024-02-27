// linear-algebra.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <random>
#include <algorithm>
#include <ctime>
#include <x86intrin.h>

#define UNROLL (4)
#define BLOCKSIZE 32
#define N 3
using namespace std;

void nmm(int n, double A[N][N], double B[N][N], double C[N][N]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}


}

void dgemm(int n, double* A, double* B, double* C) {
	for (int i = 0; i < n; i += UNROLL * 4) {
		for (int j = 0; j < n; j++) {
			__m256d c[4];
			for (int x = 0; x < UNROLL; x++) {
				c[x] = _mm256_load_pd(C + i + x * 4 + j * n);
			}

			for (int k = 0; k < n; k++) {
				__m256d b = _mm256_broadcast_sd(B + k + j * n);
				for (int x = 0; x < UNROLL; x++) {
					c[x] = _mm256_add_pd(c[x], _mm256_mul_pd(_mm256_load_pd(A + n * k + x * 4 + i), b));
				}
			}

			for (int x = 0; x < UNROLL; x++) {
				_mm256_store_pd(C + i + x * 4 + j * n, c[x]);
			}
		}
	}
}

void do_block(int n, int si, int sj, int sk, double* A, double* B, double* C) {
	for (int i = si; i < si + BLOCKSIZE; i += UNROLL * 4) {
		for (int j = sj; j < sj + BLOCKSIZE; j++) {
			__m256d c[4];
			for (int x = 0; x < UNROLL; x++) {
				c[x] = _mm256_load_pd(C + i + x * 4 + j * n);
			}

			for (int k = sk; k < sk + BLOCKSIZE; k++) {
				__m256d b = _mm256_broadcast_sd(B + k + j * n);
				for (int x = 0; x < UNROLL; x++) {
					c[x] = _mm256_add_pd(c[x], _mm256_mul_pd(_mm256_load_pd(A + n * k + x * 4 + i), b));
				}
			}

			for (int x = 0; x < UNROLL; x++) {
				_mm256_store_pd(C + i + x * 4 + j * n, c[x]);
			}
		}
	}
}

void dgemm_cache_blocking(int n, double* A, double* B, double* C) {
	for (int sj = 0; sj < n; sj += BLOCKSIZE) {
		for (int si = 0; si < n; si += BLOCKSIZE) {
			for (int sk = 0; sk < n; sk += BLOCKSIZE) {
				do_block(n, si, sj, sk, A, B, C);
			}
		}
	}
}

int main(int argc, char** argv) {
	cout << "Main program is running" << endl;
	
	int n = 3;
	/*
	double A[N][N] = {1, 0, 0, 0, 2, 0, 0, 0, 3};
	double B[N][N] = {1, 0, 0, 0, 2, 0, 0, 0, 3};
	double C[N][N] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	*/
	double *A, *B, *C;
	int m, n, k, i, j;
	
	dgemm(n, A, B, C);

	for (int i = 0; i < m*n; i++) {
		cout << C[i] << endl;
	}

	return 0;
}
