#include <iostream>
#include "matrix_operarions.h"

int main() {
    int n, m;
    std::cout << "Enter matrix size (n): ";
    std::cin >> n; // Ввод размера матрицы
    if (n <= 0) {
        std::cout << "Invalid size!\n";
        return 1;
    }

    double** A = matrix_input(n); // Ввод матрицы A

    std::cout << "Enter power (m): ";
    std::cin >> m; // Ввод степени m
    if (m < 0) {
        std::cout << "Invalid power!\n";
        free_matrix(A, n);
        return 1;
    }

    double** B = compute_B(A, n, m); // Вычисление матрицы B

    // Вывод результата
    std::cout << "\nResult matrix B:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            std::cout << B[i][j] << " ";
        std::cout << "\n";
    }

    // Освобождение памяти
    free_matrix(A, n);
    free_matrix(B, n);
    return 0;
}