#pragma once
#include <cmath>
#include <iostream>
#include <iomanip>

// Объявления функций
double equation_a(double x);
double equation_b(double x, double s);

// Шаблон метода половинного деления
template<typename Func>
double bisection(Func func, double a, double b, double eps, int& iterations, double s = 0) {
    iterations = 0;
    double fa = func(a, s);
    double fb = func(b, s);

    if (fa * fb > 0) {
        std::cout << "[Ошибка] Функция не меняет знак на интервале ["
            << a << ", " << b << "]\n";
        return NAN;
    }

    double mid, fmid;
    do {
        mid = (a + b) / 2;
        fmid = func(mid, s);
        iterations++;

        if (std::abs(fmid) < eps) break;

        if (fa * fmid < 0) {
            b = mid;
            fb = fmid;
        }
        else {
            a = mid;
            fa = fmid;
        }
    } while (std::abs(b - a) > eps);

    return mid;
}