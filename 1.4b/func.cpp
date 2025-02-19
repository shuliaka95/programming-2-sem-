#include <cmath>
#include "func.h"

// Функция для уравнения (x - 1)^3 - 1
double equation_a(double x) {
    return pow((x - 1), 3) - 1;
}

// Функция для уравнения sx - cos^2(πx)
double equation_b(double x, double s) {
    const double pi = 3.141592653589793;
    return s * x - cos(pi * x) * cos(pi * x);
}

// Метод половинного деления для функции без параметра
double bisection(double (*func)(double), double a, double b, double eps, int& iterations) {
    iterations = 0;
    double mid;
    while ((b - a) > eps) {
        mid = (a + b) / 2;
        iterations++;

        if (func(mid) == 0) {
            return mid; // Точный корень найден
        }

        if (func(a) * func(mid) < 0) {
            b = mid;
        }
        else {
            a = mid;
        }
    }
    return (a + b) / 2;
}

// Метод половинного деления для функции с параметром s
double bisection(double (*func)(double, double), double a, double b, double eps, double s, int& iterations) {
    iterations = 0;
    double mid;
    while ((b - a) > eps) {
        mid = (a + b) / 2;
        iterations++;

        if (func(mid, s) == 0) {
            return mid; // Точный корень найден
        }

        if (func(a, s) * func(mid, s) < 0) {
            b = mid;
        }
        else {
            a = mid;
        }
    }
    return (a + b) / 2;
}