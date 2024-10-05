# include <stdio.h>
# include <math.h>
# define N_5 3
# define N_7 2
typedef int MTYPE;

double matr[N_7][N_7]; // global variable

void input_sqt_matr(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matr[i][j]);
        }
    }
}


void input_matrix(double matrix[25][25], int m, int n) {
    for (int i = 0; i < m; i++) {
        printf("matrix[%d] = ", i);
        for (int j = 0; j < n; j++) {
            scanf("%lf ", &matrix[i][j]); // пробіл в lf, щоб не скастило до int
        }
    }
}


void output_matrix(double matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2lf\t ", matrix[i][j]);

        }
        printf("\n");
    }
}

void task1() {
    unsigned M, N;
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printf("M = ");
    scanf("%u", &M);
    printf("N = ");
    scanf("%u", &N);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (matrix[i][j] == M) {
                matrix[i][j] = N;
            }
        }
    }
    output_matrix(matrix);
}

void task2() {
    double matrix[3][3] = {{1.0, 2, 3}, {4, 5, 6}, {7, 8, 9}}, a;
    int i, j;
    output_matrix(matrix);
    printf("i = ");
    scanf("%d", &i);
    printf("j = ");
    scanf("%d", &j);
    printf("a = ");
    scanf("%lf", &a);
    if (i < 3 && j < 3) {
        for(int i_ = 0; i_ < 3; i_++) {
            for(int j_ = 0; j_ < 3; j_++) {
                matrix[i][j] = a;
            }
        }
        output_matrix(matrix);
    }
}

void task3() {
    double matrix[3][3];
    int m, n;
    printf("m = ");
    scanf("%d", &m);
    printf("n = ");
    scanf("%d", &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
    output_matrix(matrix);
}


void task4() {
    unsigned int m, n;
    printf("m = ");
    scanf("%d", &m);
    printf("n = ");
    scanf("%d", &n);
    double matrix[m][n];
    input_matrix(matrix, m, n);

}

void transpose_task5() {
    const MTYPE m1[N_5][N_5] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    MTYPE m2[N_5][N_5];
    for (int i = 0; i < N_5; i++) {
        for (int j = 0; j < N_5; j++) {
            m2[i][j] = m1[j][i];
        }
    }
    output_matrix(m2);
}


void task6() {
    int M, N, k;
    double A[100][100], counter = 0;
    printf("k = ");
    scanf("%d", &k);
    printf("M = ");
    scanf("%d", &M);
    printf("N = ");
    scanf("%d", &N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (i - j == k) {
                counter += A[i][j];
            }
        }
    }
    printf("%lf", counter);

}


double rec_det_task7(int n, unsigned S1, unsigned S2, int k) {
    double S = 0;
    if (k == n) return 1;

    for (int i = 0; i < n; i++) {
        if ((S1 >> i) & 1) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if ((S2 >> j) & 1) {
                continue;
            }

            int sign = -2 * ((i + j) % 2 == 0) ? 1 : -1;
            S += sign * matr[i][j] * rec_det_task7(n, S1 | (1 << i), S2 | (1 << j), k + 1);
        }
    }
    return S;
}


