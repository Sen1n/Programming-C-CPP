#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void task9_a(){
    int r = 3, c = 4, i, j, count, k;

    int *arr[r];
    for (i = 0; i < r; i++)
        arr[i] = (int *)malloc(c * sizeof(int));

    count = 0;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            arr[i][j] = ++count;

    printf("initial array:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    k = 1; //додаємо рядок після другого рядка (індекс 1)

    int *new_arr[r + 1];
    for (i = 0; i < r + 1; i++)
        new_arr[i] = (int *)malloc(c * sizeof(int));

    count = 100; 
    for (i = 0; i < r + 1; i++) {
        if (i <= k) {
            for (j = 0; j < c; j++)
                new_arr[i][j] = arr[i][j];
        } else if (i == k + 1) {
           
            for (j = 0; j < c; j++)
                new_arr[i][j] = count;
        } else {
 
            for (j = 0; j < c; j++)
                new_arr[i][j] = arr[i - 1][j];
        }
    }
    printf("\narray after adding a new row:\n");
    for (i = 0; i < r + 1; i++) {
        for (j = 0; j < c; j++)
            printf("%d ", new_arr[i][j]);
        printf("\n");
    }

    //звільнення пам'яті
    for (i = 0; i < r; i++)
        free(arr[i]);
    for (i = 0; i < r + 1; i++)
        free(new_arr[i]);
}


void task8(){
    int times, sum_of_elements = 0;
    double arithmetic_mean, dispersion, sum_of_squared_deviations = 0, difference = 0;
    int* ptr; 
    int size; 
    printf("enter times you want enter vector: ");
    scanf("%d", &times);
    for(int i = 0; i < times; i++){
        printf("\nenter size of arr: "); 
        scanf("%d", &size); 

        ptr = (int*)malloc(size * sizeof(int)); 
    

        if (ptr == NULL) { 
            printf("memory not allocated.\n"); 
        } 
 
            for (int j = 0; j < size; ++j) { 
                scanf("%d", &ptr[j]);
                sum_of_elements += ptr[j];

            } 
            arithmetic_mean = sum_of_elements / size;
            /*Дисперсія є середньою величиною з квадратів
            відхилень окремих значень ознаки від їхньої
            середньої арифметичної.*/
            for(int i = 0; i < size; i++){
                difference = (ptr[i] - arithmetic_mean);
                sum_of_squared_deviations += pow(difference, 2);
            } 
            dispersion = sum_of_squared_deviations / size;
            printf("elements of the array are: "); 
            for (int k = 0; k < size; ++k) { 
                printf("%d, ", ptr[k]); 
            } 

            printf("\narithmetic mean = %.2lf\n", arithmetic_mean);
            printf("dispersion = %.2lf\n", dispersion);
            free(ptr);
    }
} 



int main(){
    // task9_a();
    task8();
    // example - 24, 38, 16, 30, 40, 20 - arithmetic mean = 28.00 ; dispersion = 78.67 for times = 1, size = 6
}
