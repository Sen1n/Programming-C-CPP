#include <stdio.h>
#include <math.h>
int main() {
    float a, b, mean, geom_mean;
    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);
    mean = (a + b) / 2;
    geom_mean = sqrt(a * b);
    printf("mean = %.2f\n", mean);
    printf("geometry mean = %.2f\n", geom_mean);
}