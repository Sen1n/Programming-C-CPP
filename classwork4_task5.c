#include <stdio.h>

unsigned double_factorial(unsigned n) {
    unsigned result = 1;
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 1) {
        for (int i = 1; i <= n; i += 2) {
            result *= i;
        }
        return result;
    } else {
        for (int i = 2; i <= n; i += 2) {

            result *= i;
        }
        return result;
    }

}

int main() {
    printf("%d\n", double_factorial(6));
}