#include <stdio.h>
#include "Types.h"
#include "Predicat.h"
#include "Polygone.h"
#include "Polygone.c"
#include "Predicat.c"
#include "testsPolygone.h"
#include "testsPolygone.c"

int main() {
  printf("Start test data:\n");
  Polygone p1, p2;
  printf("Enter first polygon:\n");
  printf("Enter second polygon:\n");
  float perimeter1 = perimeterPolygone(&p1);
  float perimeter2 = perimeterPolygone(&p2);
  printf("Perimeter of the first polygon: %.2f\n", perimeter1);
  printf("Perimeter of the second polygon: %.2f\n", perimeter2);
  freePolygone(&p1);
  freePolygone(&p2);
  testInputPolygone();
  testVectors();
  return 0;
}
