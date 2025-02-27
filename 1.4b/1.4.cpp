#include "func.h"


int main() {
    const double eps = 1e-6;

    std::cout << "|   s   |     x      |    f(x)     | k_iter |\n"
        << "|-------|------------|-------------|--------|\n";

    // Решение для уравнения а
    int iter_a;
    auto func_a = [](double x, double) { return equation_a(x); };
    double root_a = bisection(func_a, 0, 3, eps, iter_a);

    std::cout << std::fixed << std::setprecision(6)
        << "|  -    | " << std::setw(10) << root_a
        << " | " << std::setw(11) << equation_a(root_a)
        << " | " << std::setw(6) << iter_a << " |\n";

    // Решение для уравнения б
    for (double s = 1; s <= 3; s += 1) {
        int iter_b;
        auto func_b = [](double x, double s) { return equation_b(x, s); };
        double root_b = bisection(func_b, -1, 0.7, eps, iter_b, s);

        std::cout << "| " << std::setw(5) << s << " | " << std::setw(10) << root_b
            << " | " << std::setw(11) << equation_b(root_b, s)
            << " | " << std::setw(6) << iter_b << " |\n";
    }

    return 0;
}