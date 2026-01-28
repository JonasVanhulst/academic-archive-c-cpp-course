//
// Created by Vanhuljo on 16/01/2023.
//
// Maak een wachtwoord generator die een willekeurig wachtwoord genereert van 10
// karakters. Zorg ervoor dat het wachtwoord minstens 1 hoofdletter, 1 cijfer en
// 1 speciaal teken ( !"#$%&'()*+ ) bevat.
//
// ```
// Het gegenereerde wachtwoord is: lDw5dF#3!*
// ```
// srandom(time(NULL)); // Correct seeding function for random()

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_6 10

char password[SIZE_6];

int main() {
  srand(time(NULL));
  for (int i = 0; i < SIZE_6; i++) {
    password[i] = "ABCDEFGHIJKLMNOP1234568/*£+=:;"[rand() % 26];
  }

  printf(
      "+--------------------------------+\n|Your Password is: %s    "
      "|\n+--------------------------------+\n",
      password);
  return 0;
}
