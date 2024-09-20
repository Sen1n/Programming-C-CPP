#include <stdio.h>
#include <math.h>

double nested_sqrt(double n, int iterations) {
    double result = n;
    for (int i = 0; i < iterations; i++) {
        result = sqrt(3 * n + result);
    }
    return result;
}

int main() {
    printf("nested sqrt: %f\n", nested_sqrt(5, 5));
}


