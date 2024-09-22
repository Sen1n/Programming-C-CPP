#include<stdio.h>
#include<math.h>

double sin_n(double x, unsigned n) {
    double res, a;
    for (int i = 0; i < n; ++i) {
        a = sin(x);
        x = a;
    }
    return a;

}

int main() {
    double x;
    unsigned n;
    scanf("%lf" "%u", &x, &n);
    printf("%.3lf\n", sin_n(x, n));
}