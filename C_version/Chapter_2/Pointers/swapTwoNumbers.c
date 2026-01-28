//
// Created by Vanhuljo on 10/06/2023.
//
// C program to swap 2 pointers
#include <stdio.h>

float swap(float* a, float* b);

int main(char* character) {
  float firstnumber, secondnumber;

  printf("[Info] - Give 2 numbers to add up\n");
  (void)scanf("%f %f", &firstnumber, &secondnumber);

  /* Print the results */
  printf("[Numbers] - before swap 1) %f  2) %f\n", firstnumber, secondnumber);

  swap(&firstnumber, &secondnumber);

  return 0;
}

float swap(float* a, float* b) {
  float swapping;

  swapping = *a;
  *a = *b;
  *b = swapping;

  printf("[Numbers] - after swap 1) %f  2) %f", *a, *b);
}