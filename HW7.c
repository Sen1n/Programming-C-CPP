#include <stdio.h>
#include <stdlib.h>

void task7_9v() {
    unsigned n;
    printf("n = ");
    scanf("%u", &n);

    double* arr = (double*)malloc(n * sizeof(double));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    for (unsigned i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%lf", &arr[i]);
    }

    double max = arr[1];
    for (unsigned i = 1; i < n; i += 2) { 
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("max = %lf\n", max);
    free(arr);
}


void task7_17() {
    unsigned n, counter_of_marks = 0;
    double mark = 0, average;

    printf("n = ");
    scanf("%u", &n);
    double* arr = (double*)malloc(n * sizeof(double));
    if (arr == NULL) {
        printf("memory allocation failed.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%lf", &arr[i]);
        mark += arr[i];
        counter_of_marks++;
    }
    double cur_max = arr[0], cur_min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > cur_max) cur_max = arr[i];
        if (arr[i] < cur_min) cur_min = arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == cur_max && counter_of_marks > 0) {
            mark -= arr[i];
            counter_of_marks--;
            cur_max = -1; 
        }
        if (arr[i] == cur_min && counter_of_marks > 0) {
            mark -= arr[i];
            counter_of_marks--;
            cur_min = -1;  
        }
    }

    if (counter_of_marks > 0) {
        average = mark / counter_of_marks;
        printf("counter_of_marks = %u\n", counter_of_marks);
        printf("mark = %lf\n", mark);
        printf("average = %lf\n", average);
    } else {
        printf("no valid marks left to calculate an average.\n");
    }
    
    free(arr);
}

int main() {
    // task7_9v();
    task7_17();
}
