#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

// Создает единичную матрицу размера n x n
double** matrix_identity(int n);

// Складывает две матрицы a и b размера n x n
double** matrix_add(double** a, double** b, int n);

// Умножает две матрицы a и b размера n x n
double** matrix_mult(double** a, double** b, int n);

// Освобождает память, выделенную под матрицу
void free_matrix(double** mat, int n);

// Вычисляет матрицу B = E + A + A^2 + ... + A^m
double** compute_B(double** A, int n, int m);

#endif