#include<stdio.h>
#include<math.h>

unsigned subfactorial(){
    unsigned n;
    double subfact = 1;
    printf("n = ");
    scanf("%u", &n);
    for (int i=1; i <= n; i++){
        subfact = subfact * i + pow(-1, i);
    }
    printf("!%u = %.0f\n", n, subfact);
    return 0;
}

int main() {
    subfactorial();
}

