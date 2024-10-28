#include <stdio.h>
#include <stdlib.h>
#include "Polygone.h"
#include <math.h>
#include <string.h>
#include<stdbool.h>
#include "testsPolygone.h"

TVECT setVector(TPoint x, TPoint y){
    TVECT v = {x.x - y.x, x.y-y.y};
    return v;
}

PTYPE lengthVector(TVECT v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

TVECT addVector(TVECT v1, TVECT v2) {
    TVECT result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    return result;
}

TVECT subVector(TVECT v1, TVECT v2) {
    TVECT result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    return result;
}

PTYPE scalarMultVector(TVECT v1, TVECT v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

TVECT vectorMultVector(TVECT v1, TVECT v2) {
    TVECT result;
    result.x = v1.y * v2.x - v1.x * v2.y;
    result.y = 0;
    return result;
}

TVECT multVector(PTYPE a, TVECT v) {
    TVECT result;
    result.x = a * v.x;
    result.y = a * v.y;
    return result;
}

extern int inputPolygone(FILE* fp, Polygone* p){

    NTYPE n;
    
    if(fp)
        fscanf(fp,"%u",&n);    
    else{
        printf("N=");
        fscanf(stdin,"%u",&n);
    }

    if(n<=2) return FALSE;
    
    p->n = n;
    p->vertice = (TPoint*) malloc(n * 2 * sizeof(TPoint));
    int scan_res = 0;
    for(NTYPE i=0;i<n;i++){
        if(!fp){
            printf("x,y=");
            scan_res = fscanf(stdin,"%f %f",&p->vertice[i].x, &p->vertice[i].y);
        }
        else{
            scan_res = fscanf(fp,"%f %f",&p->vertice[i].x, &p->vertice[i].y);
        }
        if(scan_res!=2) return FALSE;
    }

    return TRUE;
}

int writePolygones(FILE* fp, Polygone* p, NTYPE n){
    return fwrite(p,sizeof(*p),n,fp);
}

int freePolygone(Polygone *p) {
    if (p != NULL) {
        free(p->vertice);
        p->vertice = NULL;
    }
    return true;
}

NTYPE conditionPolygones(FILE *fp, predicatPolygone Q, const char *fname) {
    if (fp == NULL) {
        fprintf(stderr, "Error: file pointer is NULL \n");
        return -1;
    }

    Polygone tempPolygon;
    NTYPE count = 0;

    while (fread(&tempPolygon, sizeof(Polygone), 1, fp) == 1) {
        if (Q(&tempPolygon)) {
            count++;
        }
    }

    return count;
}

float crossProduct(TPoint p1, TPoint p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

int isConvexPolygone(const Polygone* p) {
    if (p->n < 3) return false;

    bool direction = false;
    for (NTYPE i = 0; i < p->n; i++) {
        TPoint v1 = {p->vertice[(i + 1) % p->n].x - p->vertice[i].x,
                     p->vertice[(i + 1) % p->n].y - p->vertice[i].y};
        TPoint v2 = {p->vertice[(i + 2) % p->n].x - p->vertice[(i + 1) % p->n].x,
                     p->vertice[(i + 2) % p->n].y - p->vertice[(i + 1) % p->n].y};

        float crossProd = crossProduct(v1, v2);

        if (i == 0) {
            direction = (crossProd > 0);
        } else {
            if ((crossProd > 0) != direction) {
                return false;
            }
        }
    }

    return true;
}

NTYPE numberConvexPolygones(FILE* fp) {
    if (fp == NULL) return 0;

    Polygone current;
    NTYPE count = 0;

    rewind(fp);

    while (fread(&current, sizeof(Polygone), 1, fp) == 1) {
        if (isConvexPolygone(&current)) count++;
    }
    return count;
}

PTYPE perimeterPolygone(const Polygone* p) {
    PTYPE sum = 0;
    for (NTYPE i = 0; i < p->n; i++) {
        TPoint start = p->vertice[i];
        TPoint end = p->vertice[(i + 1) % p->n];
        TVECT side = setVector(start, end);
        sum += lengthVector(side);
    }
    return sum;
}

int maxPerimeterPolygone(FILE* fp, Polygone* p) {
    if (fp == NULL) {
        fprintf(stderr, "Error: file pointer is NULL \n");
        return -1;
    }

    rewind(fp);

    Polygone tempPolygon;
    PTYPE maxPerimeter = 0;

    while (fread(&tempPolygon, sizeof(Polygone), 1, fp) == 1) {
        PTYPE currentPerimeter = perimeterPolygone(&tempPolygon);
        if (currentPerimeter > maxPerimeter) {
            maxPerimeter = currentPerimeter;
            *p = tempPolygon;
        }
    }

    printf("Max perimeter: %.2f\n", maxPerimeter);
    return (int)maxPerimeter;
}


int deletePolygonesFile(FILE* fp, NTYPE k){
    if (fp == NULL){
        fprintf(stderr, "Error: file is NULL \n");
        return -1;
    }
    FILE *temp_fp = fopen("temp.dat", "wb");
    if (temp_fp == NULL){
        fprintf(stderr, "Error: couldn't open the temp.dat \n");
        return -1;
    }
    NTYPE r;
    int index=0, deleted=0;
    while (1) {
        if (fread(&r, sizeof(NTYPE), 1, fp) != 1) break;
        if (index != k) {
            fwrite(&r, sizeof(NTYPE), 1, temp_fp);
        }
        else{
            deleted = 1;
        }
        index++;
    }
    fclose(fp);
    fclose(temp_fp);

    if (deleted) {
        remove("polygones.dat");
        rename("temp.dat", "polygones.dat");
        return TRUE;
    } else {
        remove("temp.dat");
        return FALSE;
    }
}

// виведення багатокутника за індексом k
void showPolygoneFile(FILE* fp, NTYPE k) {
    if (fp == NULL) {
        fprintf(stderr, "Error: file is NULL \n");
    }

    int num;
    NTYPE index = 0;
    printf("The polygone at index %u:\n", k);
    while (1) {
        if (fread(&num, sizeof(int), 1, fp) != 1) break;
        if (index == k) {
            printf("%d ", num);
        }
        index++;
        if (index > k) break;
    }
    printf("\n");
}

// виведення всіх багатокутників з файлу
void showPolygonesFile(FILE* fp) {
    if (fp == NULL) {
        fprintf(stderr, "Error: file is NULL \n");
        return;
    }

    int num;
    printf("All polygones:\n");
    while (1) {
        if (fread(&num, sizeof(int), 1, fp) != 1) break;
        printf("%d ", num);
    }
    printf("\n");
}

// перевірка чи є такий багатокутник у файлі
int isPresentPolygone(FILE* fp, const Polygone* p) {
    Polygone temp;
    if (fp == NULL){
        fprintf(stderr, "Error: file is NULL\n");
        return -1;
    }
    while (1) {
        if (fread(&temp, sizeof(Polygone), 1, fp) != 1) break;
        int count_side = p->n;
        if (temp.n != count_side) {
            continue;
        }
        int res = 1; 
        for (NTYPE i = 0; i < p->n; i++) {
            TVECT a = {temp.vertice[i].x, temp.vertice[i].y};
            TVECT b = {p->vertice[i].x, p->vertice[i].y};
            if (!isEqual2(a, b)) {
                res = 0;
                break;
            }
        }
        if (res) {
            return 1;
        }
    }
    return -1;
}

PTYPE areaPolygone(const Polygone* p) {
    if (p->n < 3) return 0.0; // площа багатокутника з менше ніж 3 вершин дорівнює 0

    PTYPE area = 0.0;
    TPoint origin = p->vertice[0]; // перша вершина

    // перебір усіх трикутників, що утворюються з першою вершиною
    for (NTYPE i = 1; i < p->n - 1; i++) {
        TPoint a = p->vertice[i];
        TPoint b = p->vertice[i + 1];

        // площа трикутника
        area += 0.5 * fabs(origin.x * (a.y - b.y) + a.x * (b.y - origin.y) + b.x * (origin.y - a.y));
    }

    return area;
}


// знаходження багатокутника з мінімальною площею у файлі
int minAreaPolygone(FILE* fp, Polygone* p) {
    if (!fp || feof(fp)) return FALSE; // перевірка на правильність вхідних даних

    NTYPE numPolygons;
    fread(&numPolygons, sizeof(NTYPE), 1, fp); // зчитування к-сті багатокутників

    if (numPolygons == 0) return FALSE;

    PTYPE minArea = INFINITY; // початкове значення площі
    Polygone minPolygon; 

    for (NTYPE i = 0; i < numPolygons; i++) {
        fread(p, sizeof(Polygone), 1, fp); // зчитування наступного багатокутника

        PTYPE area = areaPolygone(p); 
        if (area < minArea) {
            minArea = area;
            minPolygon = *p; // збереження багатокутника з новою мінімальною площею
        }
    }

    printf("Polygon with minimum area: \n");
    printf("Vertices: %u\n", minPolygon.n);
    for (NTYPE i = 0; i < minPolygon.n; i++) {
        printf("(%f, %f)\n", minPolygon.vertice[i].x, minPolygon.vertice[i].y);
    }
    printf("Area: %f\n", minArea);

    return TRUE;
}


// кут між трьох точок A, B, C
static double angleBetweenPoints(TPoint A, TPoint B, TPoint C) {
    double ABx = B.x - A.x;
    double ABy = B.y - A.y;
    double ACx = C.x - A.x;
    double ACy = C.y - A.y;

    double dotProduct = ABx * ACx + ABy * ACy;
    double magAB = sqrt(ABx * ABx + ABy * ABy);
    double magAC = sqrt(ACx * ACx + ACy * ACy);

    return acos(dotProduct / (magAB * magAC));
}

// чи т p всередині багатокутника poly? (через суму кутів)
static int isPointInsidePolygon(const Polygone* poly, TPoint p) {
    double angleSum = 0.0;

    for (NTYPE i = 0; i < poly->n; i++) {
        TPoint v1 = poly->vertice[i];
        TPoint v2 = poly->vertice[(i + 1) % poly->n];
        angleSum += angleBetweenPoints(p, v1, v2);
    }

    return fabs(angleSum - 2 * M_PI) < 1e-5;
}

// pointsPolygones
extern NTYPE pointsPolygones(FILE* fp, TPoint p) {
    if (!fp) return 0;

    rewind(fp);  // повертаємося на початок файлу
    unsigned int numPolygons;
    fread(&numPolygons, sizeof(unsigned int), 1, fp);  // зчит к-сть багатокутників

    NTYPE count = 0;
    Polygone poly;

    for (unsigned int i = 0; i < numPolygons; i++) {
        fread(&poly.n, sizeof(NTYPE), 1, fp);
        poly.vertice = (TPoint*) malloc(poly.n * sizeof(TPoint));
        fread(poly.vertice, sizeof(TPoint), poly.n, fp);

        if (isPointInsidePolygon(&poly, p)) {
            count++;
        }

        free(poly.vertice); 
    }

    return count;
}

int isEqualPolygone(const Polygone* p1,const Polygone* p2) {
    if (p1->n != p2->n) {
        return FALSE;
    }
    for (NTYPE i = 0; i < p1->n; i++) {
        if (p1->vertice[i].x != p2->vertice[i].x || p1->vertice[i].y != p2->vertice[i].y) {
            return FALSE;
        }
    }
    return TRUE;
}
