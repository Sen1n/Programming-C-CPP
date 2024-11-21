#include <stdio.h>
#include <math.h>

int main() {
    double number, result;

    printf("enter num from 0 to 10000: ");
    scanf("%lf", &number);

    if (number < 0 || number > 10000) {
        return 1;
    }

    result = pow(number, 8);
    printf("%.20g\n", result);
    printf("%.4g\n", result);  
}
