#include <stdio.h>
#include <math.h>

void task1(){
    double a, sum = 0, n = 1;
    int counter = 0;
    printf("enter a: ");
    scanf("%lf", &a);
    while (sum < a) {
        sum += 1.0 / n;
        ++n;
        ++counter;
    }
    printf("%lf\n", sum);
    printf("%d\n", counter);
}


int task2_a(int n) {
    unsigned long long F_0 = 0, F_1 = 1, F;
    int a;
    // scanf("%zu", &n);
    for(int i = 2; i < n; i++) {
        F = F_0 + F_1;
        F_0 = F_1;
        F_1 = F;
    }
    return F;

}

void task2_b() {
    int a, counter = 2;
    scanf("%d", &a);
    while (task2_a(counter) < a){
        counter += 1;
        printf("%d\n", task2_a(counter));
    }
    printf("%d\n", task2_a(counter));
    printf("%d\n", counter);
}


void task2_c() {
    int a, counter = 2;
    scanf("%d", &a);
    while (task2_a(counter) <= a){
        counter += 1;
        printf("%d\n", task2_a(counter));
    }
    printf("%d\n", task2_a(counter));
    printf("%d\n", counter);
}

void task2_d() {
    int counter = 3, sum = 1;
    while (task2_a(counter) < 1000) {
        sum += task2_a(counter);
        counter += 1;
        // if (sum > 1000) {
        //     sum -= task2_a(counter - 1);
        //     printf("%d\n", sum);
        //     break;
    }
    printf("%d\n", sum);
}

void task3() {
    unsigned n, a0, a, counter_of_steps, max_of_steps, number_with_max_steps;
    printf("Enter n: ");
    scanf("%d", &n);
    max_of_steps = 0;
    number_with_max_steps = 0;
    for (int i = 1; i < n; i++) {
        a0 = i;
        a = a0;
        counter_of_steps = 0;
        while (a != 1) {
            if (a % 2 == 0) {
                a = a / 2;
            } else {
                a = 3 * a + 1;
            }
            counter_of_steps++;
        }
        if (counter_of_steps > max_of_steps) {
            max_of_steps = counter_of_steps;
            number_with_max_steps = i;
        }
    }

    printf("Number with maximum steps: %d\n", number_with_max_steps);
    printf("Maximum steps: %d\n", max_of_steps);
}

// Функція для обчислення факторіалу
long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

void task4_a() {
    int n;
    scanf("%d", &n);
    double P_n = 1.0;
    for (int i = 1; i <= n; i++) {
        P_n *= (1 + 1.0 / factorial(i));
    }
    printf("pn=%lf\n", P_n);
}
void task4_b() {
    int n;
    scanf("%d", &n);
    double P_n = 1.0;
    for (int i = 1; i <= n; i++) {
        P_n *= (1 + (pow(-1, i+1) * i) / 2.0);
    }
    printf("pn=%lf\n", P_n);
}
void task5() {
    int x_1 = -99, x_2 = -99, x_3 = -99, x_n, k = 3;
    while (1) {
        x_n = x_1 + x_3 + 100;
        x_2 = x_3;
        x_3 = x_n;
        k++;
        if (x_n > 0) {
            break;
        }
    }

}
void task6_a() {
    double b, b_n, n, denominator_, denominator_copy, fraction, result;
    scanf("%lf", &b);
    scanf("%lf", &n);
    denominator_ = (1 / b);
    for (int i = 0; i < n; i++) {
        denominator_copy = denominator_;
        fraction = 1 / (b + denominator_copy);
        denominator_ = fraction;
    }
    result = b + fraction;
    printf("%lf\n", result);
}

void task7() {
    //  0, 1, 1/3 = a
    // 1, 0, 1/3 = b
    // 2, 4, 12 = 16 = s4
    double n, k, i, a1, a2, b1, b2, ak, bk, s = 6, pow_2 = 2;
    scanf("%lf", &n);
    a1 = b2 = 0;
    a2 = b1 = 1;
    if (n == 1) {
        printf("2\n");
    } else if (n == 2) {
        printf("16\n");
    }
    else {
        for(int i = 3; i <= n; i++) {
            bk = a2 + b2;
            b2 = bk;
            ak = a2/i + a1*bk;
            a1 = a2;
            a2 = ak;
            pow_2 *= 2;
            s += pow_2 / (ak+bk);
        }
        printf("%lf", s);
    }
}

void task8_a() {
    // t0 = 1, t1 = x/1= t0*x/1, t2=x**2/2!=t1*x/2...tk=tk-1*x/k
    double x = 0, eps, y, t;
    int i;
    printf("x = ");
    scanf("%lf", &x);
    do {
        printf("eps = ");
        scanf("%lf", &eps);
    } while (eps <= 0);
    t = 1;
    i = 1;
    y = t;
    while (t > eps) {
        t *= (x / i);
        i++;
        y+=t;
        printf("y = %lf, %lf", y, exp(x));
    }
}
void task8_b() {
    // t0 = x, t1 = x**3/(3*1), t2 = x**5/(5*3!), t3 = -x**7/(7 * 5!), tk+1/tk = -x**2 * (2k+1)/((2k-1)*(2k-1)*(2k-2))
    double x = 0, eps, y, t;
    int i;
    printf("x = ");
    scanf("%lf", &x);
    do {
        printf("eps = ");
        scanf("%lf", &eps);
    } while (eps <= 0);
    t = x - pow(-x, 3) / 3;
    i = 2;
    y = x + t;
    while (fabs(t) > eps) {
        y+=t;
        t *= (pow(-x, 2) / ((2 * i + 1) * (2 * i - 2)));
        i++;
        printf("y = %lf", y);
    }



}

int main() {
    // task1();
    // task2_a();
    // task2_b();
    // task2_c();
    // task2_d();
    // task3();
    // task4_a();
    // task4_b();
    // task5();
    // task6_a();
    // task7();
    // task8_a();
    // task8_b();
}