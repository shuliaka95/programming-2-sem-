#pragma once

// Создает единичную матрицу размера n x n
double** matrix_identity(int n);

// Складывает две матрицы a и b размера n x n
double** matrix_add(double** a, double** b, int n);

// Умножает матрицу a на матрицу b (размер n x n)
double** matrix_mult(double** a, double** b, int n);

// Освобождает память, выделенную под матрицу
void free_matrix(double** mat, int n);

// Вычисляет матрицу B = E + A + A^2 + ... + A^m (оптимизированная версия)
double** compute_B(double** A, int n, int m);

// Создает матрицу n x n, заполненную данными с клавиатуры
double** matrix_input(int n);
