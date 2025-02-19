#include <cmath>
#include "func.h"

// Функция для интегрирования: t / sqrt(x^3 + 1 + s)
double function(double x, double t, double s) {
    return t / (std::sqrt(pow(x, 3) + 1) + s);
}

// Метод трапеций
double trapezoidal(double (*func)(double, double, double), double a, double b, int n, double t, double s) {
    double h = (b - a) / n;
    double sum = 0.5 * (func(a, t, s) + func(b, t, s));

    for (int i = 1; i < n; ++i) {
        sum += func(a + i * h, t, s);
    }
    return sum * h;
}

// Интегрирование с критерием двойного пересчёта
double integrate(double (*func)(double, double, double), double a, double b, double eps, int& iterations, double t, double s) {
    int n = 1;
    double prev, curr = trapezoidal(func, a, b, n, t, s);
    iterations = 0;

    do {
        prev = curr;
        n *= 2;
        curr = trapezoidal(func, a, b, n, t, s);
        iterations++;
    } while (fabs(curr - prev) > eps);

    return curr;
}