#include<stdio.h>

int main() {
    float a, b, subtract, multiplication;
    printf("Enter two numbers:\n ");
    scanf("%f", &a);
    scanf("%f", &b);
    subtract = a - b;
    multiplication = a * b;
    printf("subtract = %.2f\n", subtract);
    printf("multipliction = %.2f\n", multiplication);
}


