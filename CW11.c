#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void writeArrayToFile(const char *filename, float *array, int length) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("error opening file for writing\n");
        return;
    }
    for (int i = 0; i < length; i++) {
        fprintf(file, "%.2f ", array[i]);
    }
    fclose(file);
}


void readArrayFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("error opening file for reading\n");
        return;
    }
    float number;
    int first = 1;
    while (fscanf(file, "%f", &number) != EOF) {
        if (!first) {
            printf(", ");
        }
        printf("%.2f", number);
        first = 0;
    }
    fclose(file);
}


void task1() {
    int length;
    printf("enter the length of the array: ");
    scanf("%d", &length);

    float *array = (float *)malloc(length * sizeof(float));
    if (array == NULL) {
        printf("memory allocation failed\n");
        return;
    }

    printf("enter the elements of the array:\n");
    for (int i = 0; i < length; i++) {
        scanf("%f", &array[i]);
    }

    char filename[100];
    printf("enter the filename to save the array: ");
    scanf("%s", filename);

    writeArrayToFile(filename, array, length);
    printf("array saved to file '%s'\n", filename);

    printf("contents of the file:\n");
    readArrayFromFile(filename);
    printf("\n");

    free(array);
}


void filterNumbers(const char *fileF, const char *fileG, float a) {
    FILE *fIn = fopen(fileF, "r");
    FILE *fOut = fopen(fileG, "w");

    if (fIn == NULL) {
        printf("error opening input file '%s' for reading\n", fileF);
        return;
    }
    if (fOut == NULL) {
        printf("error opening output file '%s' for writing\n", fileG);
        fclose(fIn);
        return;
    }

    float number;
    while (fscanf(fIn, "%f", &number) != EOF) {
        if (fabs(number) < a) {
            fprintf(fOut, "%.2f ", number);
        }
    }

    fclose(fIn);
    fclose(fOut);
}

void removeNumbers(const char *fileF, float a) {
    FILE *fIn = fopen(fileF, "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (fIn == NULL) {
        printf("Error opening input file '%s' for reading\n", fileF);
        return;
    }
    if (tempFile == NULL) {
        printf("error creating temporary file for writing\n");
        fclose(fIn);
        return;
    }

    float number;
    while (fscanf(fIn, "%f", &number) != EOF) {
        if (fabs(number) >= a) {
            fprintf(tempFile, "%.2f ", number);
        }
    }

    fclose(fIn);
    fclose(tempFile);


    if (remove(fileF) != 0) {
        printf("error deleting original file '%s'.\n", fileF);
    } else if (rename("temp.txt", fileF) != 0) {
        printf("error renaming temporary file to '%s'.\n", fileF);
    }
}


void task2() {
    char fileF[100], fileG[100];
    float a;

    printf("enter the filename for input (F): ");
    scanf("%s", fileF);

    printf("enter the filename for output (G): ");
    scanf("%s", fileG);

    printf("enter the threshold value (a > 0): ");
    scanf("%f", &a);

    if (a <= 0) {
        printf("the threshold value must be greater than 0.\n");
        return;
    }
    filterNumbers(fileF, fileG, a);
    printf("filtered numbers have been saved to '%s'\n", fileG);
    removeNumbers(fileF, a);
    printf("updated file '%s' with numbers removed\n", fileF);
}

typedef struct {
    int id;             
    float x1, y1;      
    float x2, y2;      
} Rectangle;


void writeRectanglesToFile(const char *filename, Rectangle *rectangles, int count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("error opening file for writing\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %.2f %.2f %.2f %.2f\n", rectangles[i].id, rectangles[i].x1, rectangles[i].y1, rectangles[i].x2, rectangles[i].y2);
    }
    fclose(file);
}

void findLargestRectangle(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("error opening file for reading\n");
        return;
    }

    Rectangle rect;
    int largestId = -1;
    float largestArea = 0.0f;

    while (fscanf(file, "%d %f %f %f %f", &rect.id, &rect.x1, &rect.y1, &rect.x2, &rect.y2) != EOF) {
        float area = (rect.x2 - rect.x1) * (rect.y2 - rect.y1);
        if (area > largestArea) {
            largestArea = area;
            largestId = rect.id;
        }
    }

    fclose(file);
    
    if (largestId != -1) {
        printf("largest Rectangle ID: %d, Area: %.2f\n", largestId, largestArea);
    } else {
        printf("0 rectangles found\n");
    }
}

void deleteRectangle(const char *filename, int id) {
    FILE *file = fopen(filename, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    
    if (file == NULL || tempFile == NULL) {
        printf("error opening files.\n");
        return;
    }

    Rectangle rect;
    while (fscanf(file, "%d %f %f %f %f", &rect.id, &rect.x1, &rect.y1, &rect.x2, &rect.y2) != EOF) {
        if (rect.id != id) {
            fprintf(tempFile, "%d %.2f %.2f %.2f %.2f\n", rect.id, rect.x1, rect.y1, rect.x2, rect.y2);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(filename);
    rename("temp.txt", filename);
}


void replaceRectangle(const char *filename, int id, Rectangle newRect) {
    FILE *file = fopen(filename, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    
    if (file == NULL || tempFile == NULL) {
        printf("error opening files\n");
        return;
    }

    Rectangle rect;
    while (fscanf(file, "%d %f %f %f %f", &rect.id, &rect.x1, &rect.y1, &rect.x2, &rect.y2) != EOF) {
        if (rect.id == id) {
            fprintf(tempFile, "%d %.2f %.2f %.2f %.2f\n", newRect.id, newRect.x1, newRect.y1, newRect.x2, newRect.y2);
        } else {
            fprintf(tempFile, "%d %.2f %.2f %.2f %.2f\n", rect.id, rect.x1, rect.y1, rect.x2, rect.y2);
        }
    }

    fclose(file);
    fclose(tempFile);
    remove(filename);
    rename("temp.txt", filename);
}

int main() {
    // task1();
    task2();
    // task3a
    // |
    // V
    // V
    FILE *fileF, *fileG;
    int number;

    
    fileF = fopen("F.txt", "w");
    if (fileF == NULL) {
        printf("failed to open file F for writing.\n");
        return 1;
    }

    
    while (1) {
        printf("enter an integer (0 to exit): ");
        scanf("%d", &number);
        if (number == 0) {
            break; 
        }
        fprintf(fileF, "%d\n", number);
    }

    fclose(fileF); 

 
    fileG = fopen("G.txt", "w");
    if (fileG == NULL) {
        printf("dailed to open file G for writing\n");
        return 1;
    }

    
    fileF = fopen("F.txt", "r");
    if (fileF == NULL) {
        printf("failed to open file F for reading\n");
        fclose(fileG);
        return 1;
    }

    
    while (fscanf(fileF, "%d", &number) != EOF) {
        if (number % 2 == 0) {
            fprintf(fileG, "%d\n", number); 
        }
    }

    fclose(fileF); 
    fclose(fileG); 

    printf("File G successfully created with even numbers from file F.\n");

    //task4
    // |
    // V
    // V
    const char *filename = "rectangles.txt";
    

    Rectangle rectangles[] = {
        {1, 1.0, 1.0, 4.0, 5.0},
        {2, 2.0, 2.0, 3.0, 3.0},
        {3, 0.0, 0.0, 6.0, 4.0}
    };
    
    writeRectanglesToFile(filename, rectangles, 3); 

    
    findLargestRectangle(filename);
    deleteRectangle(filename, 2);
    
    //заміна запису про прямокутник з ID = 1
    Rectangle newRect = {1, 1.0, 1.0, 5.0, 6.0}; // нові координати
    replaceRectangle(filename, 1, newRect);
    printf("updated rectangle data:\n");
    findLargestRectangle(filename);

}
