#include <stdio.h>
#include <math.h>

long factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
}

double poly(float x, unsigned n) {
    float result = 1;
    if (x < 1 && x > -1){
    while (n >= 1) {
        result += pow(x, n) / factorial(n);
        --n;
    }
} else return 0;
    return result;

}


int main() {
    printf("%lf", poly(0.5, 2));
}
