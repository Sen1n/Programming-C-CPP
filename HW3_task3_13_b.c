// // Chobotar Maksym task3_13_b
//
#include <stdio.h>

int main () {
    int a, b, c, x_1, x_2, y_1, y_2;
    printf("enter coeficients: ");
    scanf("%d %d %d", &a, &b, &c);
    // виразивши х через у маємо, що х = 1 - у або х = - 1 - у
    // далі підставимо цей х у 2-ге рівняння і маємо що у = (-c-a)/(-a+b) або y = (a-c)/(-a+b)
    // маємо, що рівняння не матиме розв'язку при -а + b = 0
    if (-a + b != 0) {
        y_1 = (-c - a) / (-a + b);
        y_2 = (a - c) / (-a + b);
        x_1 = 1 - y_1;
        x_2 = -1 - y_2;
        printf(" we have 2 solutions: (x_1, y_1), (x_2, y_2) = (%d, %d), (%d, %d)", x_1, y_1, x_2, y_2);
    } else {
        printf("this equation doesn't have any solutions");
    }


}
