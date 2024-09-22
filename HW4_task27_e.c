# include <stdio.h>
# include <math.h>
# define eps 1e-6

long double find_pi() {
    long double pi, sum, term;
    int i = 0;
    sum = 0.0;
    do {
        term = pow(-1, i) / (pow(3, i) * (2 * i + 1));
        sum += term;  //
        i++;
    } while (fabsl(term) > eps);
    pi = 2 * pow(3, 0.5) * sum;
    return pi;
}


int main() {
    long double pi = find_pi();
    printf("%Lf\n", pi);
}