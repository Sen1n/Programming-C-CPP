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
    double a, b, c;
    printf("Enter a, b, c:");
    scanf("%lf %lf %lf", &a, &b, &c);
    double D = b * b - 4 * a * c;  
    if (D < 0) {
        printf("The equation has no real solutions.\n");
        return;
    }
    
    double y1, y2;
    if (D == 0) {
        y1 = -b / (2 * a);
        printf("The equation has one solution for y: y = %.2f\n", y1);
        if (y1 >= 0) {
            printf("Solutions for x: x1 = %.2f, x2 = %.2f\n", sqrt(y1), -sqrt(y1));
        } else {
            printf("No solutions for x.\n");
        }
    } else { // D > 0
        y1 = (-b + sqrt(D)) / (2 * a);
        y2 = (-b - sqrt(D)) / (2 * a);
        printf("The equation has two solutions for y: y1 = %.2f, y2 = %.2f\n", y1, y2);

        if (y1 >= 0) {
            printf("Solutions for x with y1: x1 = %.2f, x2 = %.2f\n", sqrt(y1), -sqrt(y1));
        } else {
            printf("No solutions for x with y1.\n");
        }
        
        if (y2 >= 0) {
            printf("Solutions for x with y2: x3 = %.2f, x4 = %.2f\n", sqrt(y2), -sqrt(y2));
        } else {
            printf("No solutions for x with y2.\n");
        }
    }
}



int main() {
    // task1();
    // task2();
    // task3();
    // task4();
    // task5();
    // task6();
    task7();
}