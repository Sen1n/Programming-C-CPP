 #include <stdio.h>

void task6_16() {
    unsigned n;
    printf("n = ");
    scanf("%d", &n);
    while (n) {
        if (n % 2 == 0) {
            printf("Y");
        }else {
            printf("X");
        }
        n /= 2;
     }
 }
 
 
 
 
 /* у 6.21 умова змінена - молодший і найстраший біт встановити в 1.
 найстарший значущий біт(1) поміняти в 0 а молодший біт встановити в 1
знайти зліва 1 і замінити її на 0*/
void task6_21() {
    unsigned int num;
    printf("eter num: ");
    scanf("%u", &num);

    num |= 1;

    //найстарший значущий біт
    unsigned int msb = 1 << (sizeof(num) * 8 - 1);
    while (!(num & msb) && msb) {
        msb >>= 1; 
    }

    
    if (msb) {
        num &= ~msb; 
    }

    printf("modified: %u\n", num);
}

int main() {
    // task6_21();
    // task6_16();

 }