#include <stdio.h>
#include <math.h>
#include <float.h>

#define EPS 1e-6 


void task5_13b() {
    double a1 = 1, b1 = 1, ak = 0, bk = 0, Pn = 1, mul = 0;
    int n;

    printf("n = ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        ak = (sqrt(b1) + a1) / 5.0;
        bk = (2.0 * b1) + (5.0 * a1 * a1);
        if (bk > 1e10) {
            printf("bk has grown too large at iteration %d\n", i + 1);
            break;
        }

        mul = ak * bk;
        printf("iteration %d: ak = %lf, bk = %lf, mul = %lf\n", i + 1, ak, bk, mul);
        Pn *= mul;
        a1 = ak;
        b1 = bk;
    }
    
    printf("p = %lf\n", Pn);
}


 

void task5_17a() {
    int k = 0;
    double x, x_new, sum = 0, factorial = 1, x_power = 1;
    printf("x = ");
    scanf("%lf", &x);

    do {
        x_new = fabs(x_power / (2 * factorial));

        sum += x_new;
        k++;
        x_power *= x * x;             
        factorial *= k;               
    } while (x_new > EPS);

    printf("sum = %lf\n", sum);
}


int main() {
    // task5_13b();
    task5_17a();
}