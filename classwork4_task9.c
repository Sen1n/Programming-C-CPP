#include <math.h>
#include <stdio.h>

int min_r(int n) {
    int r = 0, a, res;
    a = n;
    for(int i = 0; i < a; i++) {
        if (pow(2, i) <= a) {
            r += 1;
        }

    }
    return r;
}
int main() {
    int r;
    r = min_r(5);
    printf("%lf\n", pow(2, r));
}
