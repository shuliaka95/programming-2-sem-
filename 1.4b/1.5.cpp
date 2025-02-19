#include <iostream>
#include "func.h"

int main() {
    setlocale(LC_ALL, "Rus");
    int iterations;
    double eps = 1e-6;

    // Часть (a): Решение уравнения (x - 1)^3 - 1 на [0, 3]
    double root_a = bisection(equation_a, 0, 3, eps, iterations);
    std::cout << "Корень для уравнения (x - 1)^3 - 1: " << root_a << ", f(x) = " << equation_a(root_a)
        << ", Итерации: " << iterations << std::endl;

    // Часть (b): Решение уравнения sx - cos^2(πx) при s ∈ [1, 3] с шагом 1
    std::cout << "\nРешение уравнения sx - cos^2(πx):\n";
    for (double s = 1; s <= 3; s += 1) {
        double root_b = bisection(equation_b, -1, 0.7, eps, s, iterations);
        std::cout << "s = " << s << ", Корень: " << root_b << ", f(x) = " << equation_b(root_b, s)
            << ", Итерации: " << iterations << std::endl;
    }

    return 0;
}
