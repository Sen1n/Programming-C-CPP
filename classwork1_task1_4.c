#include <stdio.h>

int main() {
    const float y = 6.673E-11;
    float m1, m2, r;
    double F;
    printf("Enter the value of m1: ");
    scanf("%f", &m1);
    printf("Enter the value of m2: ");
    scanf("%f", &m2);
    printf("Enter the value of r: ");
    scanf("%f", &r);
    F = (y * m1 * m2) / (r * r);
    printf("The value of F= %.3e\n", F);
}
