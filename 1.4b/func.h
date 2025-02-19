#pragma once
double equation_a(double x);
double equation_b(double x, double s);
double bisection(double (*func)(double), double a, double b, double eps, int& iterations);
double bisection(double (*func)(double, double), double a, double b, double eps, double s, int& iterations);