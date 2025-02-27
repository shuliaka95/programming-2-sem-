#include "func.h"
// Реализация уравнения (x-1)^3 - 1
double equation_a(double x) {
    return std::pow(x - 1, 3) - 1;
}

// Реализация уравнения s*x - cos²(πx)
double equation_b(double x, double s) {
    const double pi = 3.141592653589793;
    return s * x - std::pow(std::cos(pi * x), 2);
}