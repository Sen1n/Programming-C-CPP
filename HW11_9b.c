#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f_in, *f_out, *f_temp;
    int num;
    int positive_count = 0, negative_count = 0;


    f_in = fopen("F.txt", "r");
    if (f_in == NULL) {
        printf("error: Unable to open file F.\n");
        return 1;
    }


    f_temp = fopen("H.txt", "w+");
    if (f_temp == NULL) {
        printf("error: Unable to create temporary file H\n");
        fclose(f_in);
        return 1;
    }


    while (fscanf(f_in, "%d", &num) != EOF) {
        if (num > 0) {
            positive_count++;
        } else if (num < 0) {
            negative_count++;
        }
        fprintf(f_temp, "%d\n", num);
    }

    if (positive_count != negative_count) {
        printf("the file does not contain an equal number of positive and negative integers\n");
        fclose(f_in);
        fclose(f_temp);
        return 1;
    }

    rewind(f_temp); //перемотка назад
    



    f_out = fopen("G.txt", "w");
    if (f_out == NULL) {
        printf("error: Unable to create file G.\n");
        fclose(f_in);
        fclose(f_temp);
        return 1;
    }

 
    while (fscanf(f_temp, "%d", &num) != EOF) {
        if (num > 0) {
            fprintf(f_out, "%d\n", num);
        }
    }


    rewind(f_temp);


    while (fscanf(f_temp, "%d", &num) != EOF) {
        if (num < 0) {
            fprintf(f_out, "%d\n", num);
        }
    }


    fclose(f_in);
    fclose(f_out);
    fclose(f_temp);

    printf("file G has been created with positive numbers first, followed by negative numbers\n");
    
}
