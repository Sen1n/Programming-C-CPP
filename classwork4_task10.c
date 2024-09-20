#include <stdio.h>

int main () {
    float a;
    int i = 0, b = 0;
    scanf("%f",&a);
    while (a != 0) {
        a /= 2;
        i += 1;
        b = 1 + a == 1? 1 : 0;
        if (b == 1) {
            break;
        }
    }
    printf("%.25lf\n",a);
}
