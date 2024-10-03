#include <stdio.h>

void task7_9v() {
    unsigned n;
    printf("n = ");
    scanf("%u", &n);
    double arr[n], max;
    for (int i = 1; i < n; i+=2) {
        //почав індексацію з 1, щоб додававши 2, проходив по елементам з парним індексом
        // 0 індекс відповідає а1 згідно з умовою, 1->2, ...
        scanf("%lf", &arr[i]);
        printf("arr[%d] = %lf\n", i, arr[i]);
    }
    max = arr[1];
        for (int j = 1; j < n; j+=2) {
            if (arr[j] > max) {
                max = arr[j];
            }
    }
    printf("maximum = %lf\n", max);
}


void task7_17() {
    double mark = 0, average;
    unsigned n, counter_of_marks = 0, cur_max, cur_min, length;
    printf("n = ");
    scanf("%u", &n);
    double arr[n], max;
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%lf", &arr[i]);
        printf("arr[%d] = %lf", i, arr[i]);
        printf("\n");
        mark += arr[i];
        counter_of_marks++;
    }
    // length = sizeof(arr) / sizeof(arr[0]);
    // printf("mark = %lf\n", mark);
    cur_max = arr[0];
    cur_min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > cur_max) {
            cur_max = arr[i];
        }
        if (arr[i] < cur_min) {
            cur_min = arr[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == cur_max && counter_of_marks > 0) {
            mark -= arr[i];
            counter_of_marks--;

        }
        if (arr[i] == cur_min && counter_of_marks > 0) {
            mark -= arr[i];
            counter_of_marks--;
        }
    }
    if (counter_of_marks > 0) {
        average = mark / counter_of_marks;
        printf("counter_of_marks = %u\n", counter_of_marks);
        printf("mark = %lf\n", mark);
        printf("average = %lf\n", average);
    }

}



int main() {
    // task7_9v();
    task7_17();
}