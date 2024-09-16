//3.23г

#include <math.h>
#include <stdio.h>


// a * (e ** x - 1)` = a * e ** x


double eReLu(double a, double x) {
    if (x > 0) {
        return a * (exp(x) + 1);
    }
    if (x <= 0) {
        return 0;
    }
}



double eReLu_derivative(double a, double x) {
    if (x > 0) {
        return a * exp(x);
    }
}


int main(){
    double a, x;
    printf("Please enter the value of a: ");
    scanf("%lf", &a);
    printf("Please enter the value of x: ");
    scanf("%lf", &x);
    printf("The value of x is %.2lf\n", x);
    printf("The value of a is %.2lf\n", a);
    printf(" result: %.2lf", eReLu(a, x));
    printf(" derivative: %.2lf", eReLu_derivative(a, x));

}
