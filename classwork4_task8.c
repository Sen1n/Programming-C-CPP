#include <stdio.h>
#include<math.h>

int max_k(int m) {
    int k = 0;
    while (pow(4, k) <= m) {
        ++k;
    }
    return k - 1;
}
int main() {
    printf("%d\n", max_k(256));
}
