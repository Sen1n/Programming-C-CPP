# include <stdio.h>
# include <math.h>

int main () {
    double radius, height, area;
    printf("enter radius and height of cylinder:\n");
    printf("radius = ");
    scanf("%lf", &radius);
    printf("height = ");
    scanf("%lf", &height);
    area = M_PI * radius * radius * height;
    printf("area of cylinder = %lf", area);
}
