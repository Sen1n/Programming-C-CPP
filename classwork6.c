#include <math.h>
#include <stdio.h>
#include <stdint.h>

void task1() {
    unsigned char n;
    scanf("%hhu",&n);
    // unsigned long long - щоб усе вмістилося
    unsigned long long m = 1 << n;
    printf("%llu", m);
}

void task2() {
    int n;
    unsigned k;
    scanf("%d",&n);
    scanf("%u",&k);
    printf("%d", n | (1 << k));
}

void task3() {
    unsigned char n;
    scanf("%hhu",&n);
    // unsigned long long - щоб усе вмістилося
    unsigned long long m;
    scanf("%llu",&m);
    printf("%llu", m &~(1 << n));
}

void task4() {
    unsigned n, b1, b2, b3, b4, m;
    scanf("%u",&n);
    b1 = n & 0xFF; // n&255
    b2 = n >> 8 & 0xFF;
    b3 = n >> 16 & 0xFF;
    b4 = n >> 24;
    m = (b1<<24) | (b3<<16) | (b2<<8) | b4;
    printf("%u", m);
    printf("%x", m);
}

void task5() {
    // sizeof() - к-сть бітів
    int n;
    unsigned cnt = 0;
    printf("n = ");
    scanf("%d",&n);
    unsigned max_count = 0;
    while (n & 1) {
        n>>=1;
        cnt++;
    }
    n>>=1;
    if(max_count < cnt) {
        max_count = cnt;
    }
    printf("%u", max_count);

}

int divisor2(unsigned n) {
    int k = 1;
    while (n % k == 0) {
        k *= 2;
    }
    return k;
}
void task6() {

    unsigned y_1, y_2, n;
    // for (unsigned i = 0; i < 1 << 32 - 1; ++i) {
    //     if (!((i & (i - 1)))) {
    //         // припускаємо, що індекси степенів 2 будуть false
    //         printf("%u\t", i);
    //     }
    // }
    // printf("\n");
    for (unsigned i = 0; i < 1 << 32 - 1; ++i) {
        if (divisor2(i) != (-i) & i) {
            printf("%u not work", i);
        }
    }
}

void task7() {
    uint16_t x = 0x0001;
    printf("%s-endian\n", *((uint8_t *) &x) ? "little" : "big");

}

void task27() {
    unsigned long long n, k;
    printf("n = ");
    scanf("%llu",&n);
    printf("k = ");
    scanf("%llu",&k);
    unsigned long long p = n ^ k;
    int i = 0;
    while (p)
        if (p & (1 << i)) {
            printf("%d\n", i);
        }
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
