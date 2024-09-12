#include <stdio.h>
#include <math.h>


double find_square(double AB, double BC, double AC) {
    double p;
    p = (AB + BC + AC) / 2;
    return sqrt(p * (p - AB)*(p - BC) * (p - AC));
}


double find_length(double x, double y){
    return sqrt(x * x + y * y);
}


int main() {
    double A_1, A_2, B_1, B_2, C_1, C_2, AB, BC, AC, x_AB, x_BC, x_AC, y_AB, y_BC, y_AC;
    printf("enter coordinates of A:");
    scanf("%lf%lf", &A_1, &A_2);
    printf("\n");
    printf("enter coordinates of B:");
    scanf("%lf%lf", &B_1, &B_2);
    printf("\n");
    printf("enter coordinates of C:");
    scanf("%lf%lf", &C_1, &C_2);
    printf("\n");
    x_AB = (B_1 - A_1);
    y_AB = (B_2 - A_2);
    x_BC = (C_1 - B_1);
    y_BC = (C_2 - B_2);
    x_AC = (C_1 - A_1);
    y_AC = (C_2 - A_2);
    AB = find_length(x_AB, y_AB);
    printf("\n AB = %lf\n", AB);
    BC = find_length(x_BC, y_BC);
    printf("\n BC = %lf\n", BC);
    AC = find_length(x_AC, y_AC);
    printf("\n AC = %lf\n", AC);
    if (AB + BC > AC && AB + AC > BC && BC + AC > AB) {
        printf("square of triangle = %lf", find_square(AB, BC, AC));
    } else {
        // якщо трикутник не існує
        printf("these points do not form a triangle.\n");
    }
}
