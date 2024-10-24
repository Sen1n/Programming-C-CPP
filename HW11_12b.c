#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char name[50];
    float price;
    int age_min;
    int age_max;
} Toy;


int readToys(const char *filename, Toy toys[], int max_toys) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("error: can't open file %s.\n", filename);
        return 0;
    }

    int count = 0;
    while (count < max_toys && fscanf(file, "%s %f %d %d", toys[count].name, &toys[count].price, &toys[count].age_min, &toys[count].age_max) == 4) {
        count++;
    }

    fclose(file);
    return count;
}


void searchAndOutputToys(Toy toys[], int count, int n, int m, const char *binary_filename) {
    FILE *binary_file = fopen(binary_filename, "wb");
    if (binary_file == NULL) {
        printf("error: unable to create binary file %s\n", binary_filename);
        return;
    }


    for (int i = 0; i < count; i++) {
        if (toys[i].age_min <= m && toys[i].age_max >= n) {

            fwrite(&toys[i], sizeof(Toy), 1, binary_file);
            
            printf("name: %s, price: %.2f, age Range: %d - %d\n", toys[i].name, toys[i].price, toys[i].age_min, toys[i].age_max);
        }
    }

    fclose(binary_file);
}

int main() {

    Toy toys[100];
    

    int count = readToys("toys.txt", toys, 100);
    
    if (count == 0) {
        printf("no toys found in the file\n");
        return 1;
    }

    int n = 2; // мінімальний вік
    int m = 5; // максимальний вік


    searchAndOutputToys(toys, count, n, m, "toys.bin");
}
