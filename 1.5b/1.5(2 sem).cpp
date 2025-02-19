#include <iostream>
#include <cmath>
#include "func.h"

int main() {
    // Данные из таблицы для 8 варианта
    double s1 = 0, s2 = 0.5, delta_s = 0.1;
    double t1 = 1, t2 = 3, delta_t = 1;
    double a = 1.3, b = 2.621;
    double eps = 1e-6;

    std::cout << "s\t t\t Int\t\t k_iter\n";

    for (double s = s1; s <= s2; s += delta_s) {
        for (double t = t1; t <= t2; t += delta_t) {
            int iterations;
            double result = integrate(function, a, b, eps, iterations, t, s);
            std::cout << s << "\t " << t << "\t " << result << "\t " << iterations << "\n";
        }
    }

    return 0;
}
