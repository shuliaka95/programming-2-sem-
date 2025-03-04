#include <iostream>
#include "matrix_operarions.h"

int main() {
	int n = 2, m = 2;
	double** A = new double*[n];
	for (int i = 0; i < n; ++i) A[i] = new double[n];
	A[0][0]=1; A[0][1]=2; A[1][0]=3; A[1][1]=4;
	     
	double** B = compute_B(A, n, m);
	     
	for (int i = 0; i < n; ++i) {
	    for (int j = 0; j < n; ++j)
	         std::cout << B[i][j] << " ";
	         std::cout << "\n";
	     }
	     
	free_matrix(A, n);
	free_matrix(B, n);
	return 0;
}