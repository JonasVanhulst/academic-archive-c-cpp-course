//
// Created by Vanhuljo on 16/01/2023.
//
// Maak een 2x3 matrix door gebruik te maken van een 2D array. Initialiseer deze
// array met willekeurige gehele getallen. Print dit resultaat. Bereken
// vervolgens de getransponeerde matrix. Print ook dit resultaat.
//

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int a = rand() % 100 + 1;
  int b = rand() % 100 + 1;
  int c = rand() % 100 + 1;
  int d = rand() % 100 + 1;
  int e = rand() % 100 + 1;
  int ab = rand() % 100 + 1;

  int array[2][3] = {{a, b, ab}, {c, d, e}};

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d\t", array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  printf("\n");
  int waarde[3][2] = {{a, b}, {ab, c}, {d, e}};

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%d\t", waarde[i][j]);
    }
    printf("\n");
  }
  return 0;
}