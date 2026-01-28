//
// Created by Vanhuljo on 12/06/2023.
//
// Write a program in C to count the number of vowels and consonants in a string
// using a pointer.
//

#include <stdio.h>

#define MAX 100

int main() {
  char str1[50];
  char* pt;
  int ctrV, ctrC;
  printf("\n\n Pointer : Count the number of vowels and consonants :\n");
  printf("----------------------------------------------------------\n");
  printf(" Input a string: ");
  fgets(str1, sizeof str1, stdin);

  // assign address of str1 to pt
  pt = str1;

  ctrV = ctrC = 0;
  while (*pt != '\0') {
    if (*pt == 'A' || *pt == 'E' || *pt == 'I' || *pt == 'O' || *pt == 'U' ||
        *pt == 'a' || *pt == 'e' || *pt == 'i' || *pt == 'o' || *pt == 'u')
      ctrV++;
    else
      ctrC++;
    pt++;  // pointer is increasing for searching the next character
  }

  printf(" Number of vowels : %d\n Number of consonants : %d\n", ctrV,
         ctrC - 1);
  return 0;
}