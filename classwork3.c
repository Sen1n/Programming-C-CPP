# include <stdio.h>
# include <math.h>
# include <stdint.h>

void task1() {
    int a, b, c, sum, inv;
    unsigned number;
    printf("Enter a number: ");
    scanf("%u", &number);
    if (number >= 100 && number <= 999) {
        a = number % 10;
        b = (number / 10) % 10;
        c = number / 100;
        printf("%d%d%d", a, b, c);
        sum = a + b + c;
        printf("%d", sum);
        inv = 100 * a + 10 * b + c;
        printf("%d", inv);
    }
}

void task2() {
    int a, b, c, p_1, p_2, p_3, p_4, p_5, p_6;
    unsigned number;
    printf("Enter a number: ");
    scanf("%u", &number);
    if (number >= 100 && number <= 999) {
        a = number % 10;
        b = (number / 10) % 10;
        c = number / 100;
        if (a != b && a != c && b != c) {
            p_1 = 100 * a + 10 * b + c;
            p_2 = 100 * b + 10 * a + c;
            p_3 = 100 * c + 10 * a + b;
            p_4 = 100 * b + 10 * c + a;
            p_5 = 100 * c + 10 * b + a;
            p_6 = 100 * c + 10 * a + b;
            printf("%d\n%d\n%d\n%d\n%d\n%d\n", p_1, p_2, p_3, p_4, p_5, p_6);
        }
        printf("%d%d%d\n", a, b, c);
    }

}

void task3() {
    long long unsigned number1, number2, number3, mul;
    printf("enter 3 nums:");
    scanf("%lld, %lld, %lld", &number1, &number2, &number3);
    if (number1 < abs(pow(2, 21)) && number2 < abs(pow(2, 21)) && number3 < abs(pow(2, 21))) {
        mul = number1 * number2 * number3 ;
        printf("%lld", mul);
    }
}

uint16_t mult(uint8_t x, uint8_t y) {
    uint16_t z = (x*y); //(int)
    return z;
}

void task4() {
    uint8_t x, y;
    uint16_t z;
    printf("Enter x, y:");
    scanf("%hhu %hhu", &x, &y);
    z = mult(x, y);
    printf("z = %hu", z);

}

void task5() {
    int a, b;
    printf("Enter a, b:");
    scanf("%d%d", &a, &b);
    if (a > b) {
        printf("%d is greater than %d", a, b);
    } else {
        printf("%d is less than %d", a, b);
    }
}

void task6() {
    int a, b, c, max_a_b, max_other_c;
    printf("Enter a, b, c:");
    scanf("%d%d%d", &a, &b, &c);
    max_a_b = a > b? a : b;
    max_other_c = max_a_b > c? max_a_b : c;
    printf("max_a_b = %d, max_other_c = %d", max_a_b, max_other_c);
}

void task7() {
    double a, b, c, discriminant, t, t_1, t_2, x, x_1_1, x_1_2, x_2_1, x_2_2, counter_of_solutions = 0;
    printf("Enter a, b, c:");
    scanf("%lf %lf %lf", &a, &b, &c);
    discriminant = b * b - 4 * a * c;
    printf("%lf\n", discriminant);
    if (discriminant == 0 && a != 0) {
        t = -b / (2 * a);
        if (t >= 0) {
            x = sqrt(t);
            printf("x = %lf", x);
            counter_of_solutions += 2;
        } else (printf("there is any solutions\n"));
    }
    if (discriminant < 0) {
        printf("we don't have any solutions in real numbers\n");
    }
    if (discriminant > 0) {
        t_1 = (-b - sqrt(discriminant)) / (2 * a);
        t_2 = (-b + sqrt(discriminant)) / (2 * a);
        if (t_1 >= 0){
            x_1_1 = sqrt(t_1);
            x_1_2 = -sqrt(t_2);
            printf("x_1_1 = %lf\n x_1_2 = %lf\n", x_1_1, x_1_2);
            counter_of_solutions += 2;
            } else (printf("there is any solutions for t_1\n"));
        if (t_2 >= 0) {
            x_2_1 = sqrt(t_2);
            x_2_2 = -sqrt(t_2);
            printf("x_2_1 = %lf\n x_2_2 = %lf\n", x_2_1, x_2_2);
            counter_of_solutions += 2;
        } else (printf("there is any solutions for t_2\n"));
        }
    printf("amount_of_solutions = %2.0lf", counter_of_solutions);
    }


int main() {
    // task1();
    // task2();
    // task3();
    // task4();
    // task5();
    // task6();
    // task7();
}