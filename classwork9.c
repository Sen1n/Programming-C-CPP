 # include <stdio.h>
 # include <math.h>
 #include <stdlib.h>

 void input_sqt_matr(int n) {
     double arr[n];
     for (int i = 0; i < n; i++) {
             scanf("%lf", &arr[i]);
         }
     }

 double sum_sqrt(const double *arr, int n) {
     double sum = 0;
     double *begin = arr;
     double *end = arr + n;
     for (begin <= end; begin++;) {
         double n_arr = *begin;
         sum += pow(n_arr, 2);
     }
     return sum;
 }

 struct Stack {
     int data;
     struct Stack* addr;
 }stack;

 int input_vec(double** arr, size_t n) {
     double* arr2 = (double*)malloc(n * sizeof(*arr));
     if (arr2 == NULL) {
         return 1;
     }
     for (size_t i = 0; i < n; i++) {
         printf("Enter elems for fow %zu: \n", i);
         scanf("%lf", &arr2[i]);
     }
     *arr = arr2;
     return 0;
 }

 void delete_vec(double *arr) {
     if(!arr){free(arr);}
 }

 int subt_vec(const double *ar1, const double *ar2, double **ar3, size_t n) {
     if(ar1 == NULL || ar2 == NULL) {
         return 1;
     }
     *ar3 = (double*)malloc(n * sizeof(**ar3));
     if(*ar3 == NULL) {
         return 1;
     }
     for(size_t i = 0; i < n; i++) {
         *ar3[i] = ar1[i] - ar2[i];
     }
     return 0;
 }

 void output_vec(const double *arr, size_t n) {
     for(size_t i = 0; i < n; i++) {
         printf("%.1f ", arr[i]);
     }
     printf("\n");
 }

 void task1() {
     unsigned n;
     printf("n = ");
     scanf("%u", &n);
     double *arr;
     arr = (double *)malloc(n * sizeof(*arr));    //memory alloc
     input_sqt_matr(n);
     double res = sum_sqrt(arr, n);
     printf("res = %lf\n", res);
     free(arr);
 }

 void task2() {
     struct Stack s;
     int x, i = 0, a[100];
     do {
         struct Stack t;
         scanf("%d", &x);
         // a[i++] = x;
             // int *mem;
             // mem = malloc(sizeof(x));
             // *mem = x;
         t.data = x;
         t.addr = malloc(sizeof(stack));
         t.addr = stack.addr;
         s.addr = NULL;
         s.data = 0;
     } while(x != 0);
     struct Stack t1;
     while(s.addr != NULL) {
         x = s.data;
         s = *(s.addr);
     }
 }

 void task3() {
     size_t n;
     double *vec1, *vec2, *vec3;
     scanf("%zu", &n);
     input_vec(&vec1, n);
     output_vec(vec1, n);
     input_vec(&vec2, n);
     output_vec(vec2, n);
     subt_vec(vec1, vec2, &vec3, n);
     output_vec(vec3, n);
     delete_vec(vec1);
     delete_vec(vec2);

 }


 void output_matr1(const double *matr, size_t size);

 void output_matr2(const double **matr, size_t n) {
     for (size_t i = 0; i < n; i++) {
         for (size_t j = 0; j < n; j++) {
             printf("%lf", matr[i][j]);
         }
         printf("\n");
     }
 }

 void input_matr1(const double *matr, size_t n);

 int create_matr2(double **matr, size_t n){

     matr = (double **)calloc(n, sizeof(*matr));
     if(matr == NULL) {
         return -1;
     }
     for(size_t i  = 0; i < n; i++) {
         matr[i] = (double*)calloc(n, sizeof(double));
         if (matr[i] == NULL) {
             return -1;
         }
     }
     return 0;
 }

 int input_matr2(double **matr, size_t n) {
     for (size_t i = 0; i < n; i++) {
         for(size_t j = 0; j < n; j++) {
             scanf("%lf", &matr[i][j]);
         }
     }
     return 0;
 }

 void delete_matr1(double *matr, size_t n);

 int delete_matr2(double **matr, size_t n) {
     if(matr == NULL) {
         return -1;
     }
     for (size_t i = 0; i < n; i++) {
         free(matr[i]);
     }
     free(matr);
 }

 int mull_matr1(const double **matr1, const double **matr2, double **matr3, size_t n) {
     if(matr1 == NULL || matr2 == NULL) {
         return -1;
     }
     create_matr2(matr3, n);
     double elem = 0.0;
     for(size_t i = 0; i < n; i++) {
         for(size_t j = 0; j < n; j++) {
             for (size_t k = 0; k < n; k++) {
                 matr3[i][j]+= matr1[i][j] * matr2[k][j];
             }
         }
     }
 }

 void task4() {
     size_t n;
     scanf("%zu", &n);
     double **matr1, *matr2, *matr3;
     create_matr2(matr1, n);
     printf("matr1: ");
     create_matr2(matr2, n);
     printf("matr2: ");
     input_matr2(matr1, n);
     printf("matr3: ");
     input_matr2(matr2, n);
     output_matr2(matr1, n);
     output_matr2(matr2, n);
     mull_matr1(matr1, matr2, matr3, n);
     output_matr2(matr3, n);
     delete_matr2(matr1, n);
     delete_matr2(matr2, n);
     delete_matr2(matr3, n);
 }

