# include <stdio.h>
# include <math.h>

int main() {
    double a, b, c, p = 0, S = 0;
    printf("enter a, b, c values: ");
    scanf("%f%f%f", &a, &b, &c);
    if (a + b > c && b + c > a && a + c > b) {
        p = (a+b+c)/2;
        S = sqrt(p*(p-a)*(p-b)*(p-c));
    }
    printf("the square of triangle = %lf", S);
}