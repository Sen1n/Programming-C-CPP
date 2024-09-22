
#include<stdio.h>
#include<math.h>

int main() {
    int n, i = 1;
    scanf("%d",&n);
    printf("n! = ");
    while(i <= n) {
        printf("%d", i);
        ++i;
        if(i - 1 != n) {
            printf("*");
        }
    }


}