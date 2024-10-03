#include <stdio.h>
#include <math.h>
#include <float.h>

double eps = 0.001;


void task5_13b() {
    double a1, b1, ak = 0, bk = 0, Pn, mul = 0;
    int n;
    a1 = 1;
    b1 = 1;
    Pn = 1;
    printf("n = ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ak = (sqrt(b1) + a1) / 5;
        bk = (2 * b1) + (5 * pow(a1, 2));
        mul = ak * bk;
        printf("iteration %d: ak = %lf, bk = %lf, mul = %lf\n", i+1, ak, bk, mul);
        Pn *= mul;
        a1 = ak;
        b1 = bk;
    }
    printf("p = %lf\n", Pn);
}


int factorial(int n) {
    if (n == 0) return 1;
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

void task5_17a() {
    int k = 0;
    double x, x_new, sum = 0;
    printf("x = ");
    scanf("%lf", &x);
    do {
        x_new = fabs(pow(x, 2 * k) / (2 * factorial(k)));
        sum += x_new;
        k++;
    } while (x_new > eps);

    printf("sum = %lf\n", sum);
}


int main() {
    // task5_13b();
    // task5_17a();
}

