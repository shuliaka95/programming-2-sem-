#include "matrix_operarions.h"
#include <iostream>

// Создание единичной матрицы
double** matrix_identity(int n) {
    double** mat = new double* [n];
    for (int i = 0; i < n; ++i) {
        mat[i] = new double[n] {};    // Инициализация нулями
        mat[i][i] = 1.0;             // Диагональные элементы = 1
    }
    return mat;
}

// Умножение матриц (оптимизировано с кэшированием)
double** matrix_mult(double** a, double** b, int n) {
    double** res = new double* [n];
    for (int i = 0; i < n; ++i) {
        res[i] = new double[n] {};
        for (int k = 0; k < n; ++k) {
            double temp = a[i][k];   // Кэшируем значение для ускорения
            for (int j = 0; j < n; ++j) {
                res[i][j] += temp * b[k][j];
            }
        }
    }
    return res;
}

// Освобождение памяти
void free_matrix(double** mat, int n) {
    if (mat == nullptr) return;
    for (int i = 0; i < n; ++i) {
        delete[] mat[i];             // Удаление строк
    }
    delete[] mat;                    // Удаление массива указателей
}

// Оптимизированное вычисление B = E + A + A² + ... + A^m
double** compute_B(double** A, int n, int m) {
    if (m < 0) return nullptr;       // Некорректная степень

    double** sum = matrix_identity(n); // Начальное значение: E
    if (m == 0) return sum;

    double** current_power = matrix_identity(n); // A^0 = E
    double** temp;

    for (int k = 1; k <= m; ++k) {
        temp = matrix_mult(current_power, A, n); // A^k = A^(k-1) * A
        free_matrix(current_power, n);           // Удаляем старую степень
        current_power = temp;

        // Обновляем сумму: sum += current_power
        double** new_sum = matrix_mult(sum, matrix_identity(n), n); // Копируем sum
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                new_sum[i][j] += current_power[i][j];
            }
        }
        free_matrix(sum, n);
        sum = new_sum;
    }

    free_matrix(current_power, n);
    return sum;
}

// Ввод матрицы с клавиатуры
double** matrix_input(int n) {
    double** mat = new double* [n];
    std::cout << "Enter matrix " << n << "x" << n << ":\n";
    for (int i = 0; i < n; ++i) {
        mat[i] = new double[n];
        for (int j = 0; j < n; ++j) {
            std::cout << "Element [" << i << "][" << j << "]: ";
            std::cin >> mat[i][j];   // Ввод каждого элемента
        }
    }
    return mat;
}