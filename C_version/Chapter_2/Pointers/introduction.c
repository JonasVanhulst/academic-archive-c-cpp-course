//
// Created by Vanhuljo on 10/06/2023.
//
// C program to get memory address using address of operator
//

#include <stdio.h>

int main() {
  /* Simple declarations */
  char character = 'J';
  int integer = 5;
  float floating = 10.4f;
  long long biginteger = 989898989ll;

  printf("[Memory] - character %p\n", &character);
  printf("[Memory] - integer %p\n", &integer);
  printf("[Memory] - floating %p\n", &floating);
  printf("[Memory] - biginteger %p\n", &biginteger);

  /**
   * C program to create, initialize and use pointers
   */

  int num = 203;
  int* ptr;

  ptr = &num;

  printf("\n\n");
  printf("[Memory ] - Address of num = %d\n", &num);
  printf("[ Value ] - Value of num = %d\n", num);
  printf("[Memory ] - Address of ptr = %d\n", &ptr);
  printf("[Pointer] - Value of ptr = %d\n", ptr);
  printf("[Pointer] - Value pointed by ptr = %d\n", *ptr);

  return 0;
}