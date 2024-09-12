#include <math.h>
#include <stdio.h>

int main() {
    float number, ceil_1, floor_1, ceil_2, floor_2, int_part_1, fract_part_1, rounded;
    printf("enter a number:\n");
    scanf("%f", &number);
    int_part_1 = (int) number;
    printf("int_part = %f\n", int_part_1);
    fract_part_1 = number - int_part_1;
    printf("fract_part = %f\n", fract_part_1);
    ceil_2 = ceil(number);
    floor_2 = floor(number);
    printf("ceil_1 = %f\n", ceil_2);
    printf("floor_1 = %f\n", floor_2);
    rounded = round(number);
    printf("rounded = %f\n", rounded);
}
