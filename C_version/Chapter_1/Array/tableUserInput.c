//
// Created by Vanhuljo on 16/01/2023.
// Maak een cummulatieve tabel die bijhoudt hoe vaak een gebruiker een geheel
// getal tussen 0 en 20 ingeeft. Als een gebruiker een getal kleiner dan 0 of
// groter dan 20 ingeeft stopt het programma.
//

#include <stdio.h>

int main() {
  int getallen[21] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int getal = 0;

  while (1) {
    printf("\nGeef getal tussen 0 en 20 : ");
    scanf("%d", &getal);

    getallen[getal] += 1;
    for (int i = 0; i <= 20; i++) {
      printf("%d: ", i);
      for (int j = 0; j < getallen[i]; j++) {
        printf("*");
      }
      printf("\n");
    }
  }

  return 0;
}