#include <stdio.h>
#include <math.h>


double poly(double x, int n) {
    double res = 0;
    while (n > 0) {
        res += n * pow(x, n);
        --n;
    }
    return res;
}

int main () {
    double x;
    int n;
    printf("%lf\n", poly(3, 3));
}
