#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    printf("enter two numbers: ");
    scanf("%d%d", &a, &b);
    if (a > 0 && b > 0) {
        c = sqrt((a * a) + (b * b));
        printf("hypothenuse = %d", c);
    }

}