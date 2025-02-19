#pragma once
double function(double x, double t, double s);
double trapezoidal(double (*func)(double, double, double), double a, double b, int n, double t, double s);
double integrate(double (*func)(double, double, double), double a, double b, double eps, int& iterations, double t, double s);
