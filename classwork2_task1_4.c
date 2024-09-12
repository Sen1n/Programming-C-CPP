#include <stdio.h>
#include <math.h>
// пункт г Чоботар Максим
// x_9 + x_3 + 1 = x_3 * (x_6 + 1) + 1
// всього 5 операцій множення
double task4(double x) { //декларація функції
    double x_3;
    x_3 = x * x * x;
    double y = x_3 * ((x_3 * x_3) + 1) + 1;
    return y;
}
int main() {
    double x;
    double y;
    printf("enter x:");
    scanf("%lf", &x);
    y = task4(x);
    printf("polynomial value of = %lf", y);
}