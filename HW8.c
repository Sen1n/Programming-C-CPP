#include <stdio.h>
// 8.20 - зсунути стовпці матриці на k стовпців управо
void task8_20()
{
    int k;
    printf("enter k: ");
    scanf("%d", &k);
    int mat_0[3][3] = {
        {1, 2, 3},
        {4, 5, 6},   
        {7, 8, 9}
    };
    int mat_1[3][3];
    k = k % 3;  

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int new_col = (j + k) % 3;
            mat_1[i][new_col] = mat_0[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("a[%d][%d] = %d\n", i, j, mat_1[i][j]);
        }
    }
}

int main()
{
    task8_20();
}
//матриці при різних значеннях k:
// k = 1
// 3 1 2
// 6 4 5
// 9 7 8

// k = 2
// 2 3 1
// 5 6 4
// 8 9 7

// k = 3 (те саме, що k = 0)
// 1 2 3
// 4 5 6
// 7 8 9

