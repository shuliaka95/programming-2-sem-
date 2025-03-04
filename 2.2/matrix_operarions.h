#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

// ������� ��������� ������� ������� n x n
double** matrix_identity(int n);

// ���������� ��� ������� a � b ������� n x n
double** matrix_add(double** a, double** b, int n);

// �������� ��� ������� a � b ������� n x n
double** matrix_mult(double** a, double** b, int n);

// ����������� ������, ���������� ��� �������
void free_matrix(double** mat, int n);

// ��������� ������� B = E + A + A^2 + ... + A^m
double** compute_B(double** A, int n, int m);

#endif