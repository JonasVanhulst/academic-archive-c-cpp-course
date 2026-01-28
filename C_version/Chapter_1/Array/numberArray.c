//
// Created by Vanhuljo on 16/01/2023.
//
// Genereer 20 willekeurige gehele getallen tussen -500 en 500 die je opslaat in
// een array. Bereken dan de som, het minimum, het maximum en het gemiddelde van
// deze 20 willekeurige gehele getallen.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// srandom(time(NULL)); // Correct seeding function for random()

#define SIZE_7 20

int getallen[SIZE_7];

int main() {
  srand(time(NULL));
  for (int i = 0; i < SIZE_7; i++) {
    getallen[i] = "-500 to 500"[rand() % 10];
  }

  printf("%d\n", getallen);
  return 0;
}