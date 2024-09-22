// x_k = x ** (2k) / (2k)! k >= 0  without math<h>
#include <stdio.h>

int pow(const int x, const int k) {
    int result = 1;
    for (int i = 1; i <= k; i++) {
        result *= x;
    }
    return result;
}

int factorial(int k) {
    int result = 1;
    for (int i = 1; i <= k; i++) {
        result *= i;
    }
    return result;
}


int main() {
    int x, k;
    double x_k;
    printf("enter x and it's power k");
    scanf("%d %d", &x, &k);
    printf("%d\n", pow(x, k));
    printf("%d\n", factorial(k));
    x_k = pow(x, 2 * k) / (factorial(2 * k));
    printf("x_k = %.2lf\n", x_k);

}