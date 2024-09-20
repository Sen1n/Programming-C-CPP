#include <float.h>
#include <stdio.h>
#include <math.h>
double eps = 2 * DBL_EPSILON;
int main() {
    int i = 0;
    double x, sum = 0;

    do {
        printf("a[%d] =", i++);
        scanf("%lf", &x);
        sum += x;

    } while (fabs(x) > eps);
    printf("sum = %lf\n", sum);
}