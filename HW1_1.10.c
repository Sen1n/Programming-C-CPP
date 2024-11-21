#include<stdio.h>

int main() {
    int x_1, x_2, x_3, x_4, x_5;
    float a, b, c, d, e;
    printf("Enter numbers of columns: ");
    scanf("%d %d %d %d %d", &x_1, &x_2, &x_3, &x_4, &x_5);
    scanf("%f %f %f %f %f", &a, &b, &c, &d, &e);
    printf("x |%-4d|%-4d|%-4d|%-4d|%-4d|\n", x_1, x_2, x_3, x_4, x_5);
    printf("- | -- | -- | -- | -- | -- |\n");
    printf("y |%-4.1f|%-4.1f|%-4.1f|%-4.1f|%-4.1f|\n", a, b, c, d, e);
}
