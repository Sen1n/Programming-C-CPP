#include <stdio.h>

int main() {
    float c, f;
    printf("Enter temperature in celcius:");
    scanf("%f", &c);
    f = (9*c)/5 + 32;
    printf("F=%.3f\n", f);
}