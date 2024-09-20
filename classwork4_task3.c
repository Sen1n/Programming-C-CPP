#include <stdio.h>
#include <math.h>

double poly_1(double x, int n) {
    double res = 1, a;
    while (n != 0) {
        a = pow(x, n);
        --n;
        res += a;

    }
    return res;
}

double poly_2(double x, double y, int n) {
    double res = 1, a;
    while (n != 0) {
        a = pow(x, 2 * n) * pow(y, n);
        --n;
        res += a;

    }
    return res;
}

int main() {
    double x, y;
    int n;
    printf("polynomial_1: ");
    printf("%lf\n", poly_1(2, 3));
    printf("polynomial_2: ");
    printf("%lf\n", poly_2(1, 2, 4));
}