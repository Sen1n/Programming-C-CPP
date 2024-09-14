// Chobotar Maksym 2.17 - d

#include <stdio.h>
#include <math.h>

double gauss(double x) {
    return exp(-x*x);
}

double gauss_derivative(double x) {
    return 2 * -x * exp(-x*x);
}

int main() {
    double x;
    printf("enter your x:");
    scanf("%lf", &x);
    printf("gauss: %lf\n", gauss(x));
    printf("gauss_derivative: %lf\n", gauss_derivative(x));
    printf("%lf\n", gauss(1));
    printf("%lf\n", gauss_derivative(1));
}
