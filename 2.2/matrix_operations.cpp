#include "matrix_operarions.h"

double** matrix_identity(int n) {
    double** mat = new double* [n];
    for (int i = 0; i < n; ++i) {
        mat[i] = new double[n] {};
        mat[i][i] = 1.0;
    }
    return mat;
}

double** matrix_add(double** a, double** b, int n) {
    double** res = new double* [n];
    for (int i = 0; i < n; ++i) {
        res[i] = new double[n];
        for (int j = 0; j < n; ++j)
            res[i][j] = a[i][j] + b[i][j];
    }
    return res;
}

double** matrix_mult(double** a, double** b, int n) {
    double** res = new double* [n];
    for (int i = 0; i < n; ++i) {
        res[i] = new double[n] {};
        for (int k = 0; k < n; ++k)
            for (int j = 0; j < n; ++j)
                res[i][j] += a[i][k] * b[k][j];
    }
    return res;
}

void free_matrix(double** mat, int n) {
    for (int i = 0; i < n; ++i)
        delete[] mat[i];
    delete[] mat;
}

double** compute_B(double** A, int n, int m) {
    double** B = matrix_identity(n);
    if (m == 0) return B;

    double** current = matrix_identity(n);
    double** sum = matrix_identity(n);

    for (int k = 1; k <= m; ++k) {
        double** temp = matrix_mult(current, A, n);
        free_matrix(current, n);
        current = temp;

        double** new_sum = matrix_add(sum, current, n);
        free_matrix(sum, n);
        sum = new_sum;
    }

    free_matrix(current, n);
    free_matrix(B, n);
    return sum;
}