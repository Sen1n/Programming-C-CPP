#include <stdio.h>
#include <math.h>

int main() {
    long double x, x_8;
   printf("enter a number within 1 to 10000:");
   scanf("%Lf", &x);
   if (x <= 10000 && x >= 0) {
       x_8 = pow(x, 8);
       printf("%20.4Le\n", x_8);
   }
   else {
        printf("invalid input, enter a number within 1 to 10000");
   }
}
