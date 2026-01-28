//
// Created by Vanhuljo on 10/06/2023.
//
// C programm to use operations with pointers
//
#include <stdio.h>

int main() {
  float sum, diff, mult, div, firstnumber, secondnumber;
  float *ptr1, *ptr2;

  ptr1 = &firstnumber;
  ptr2 = &secondnumber;

  printf("[Info] - Give 2 numbers to add up\n");
  (void)scanf("%f %f", ptr1, ptr2);

  /* Operations */
  sum = (*ptr1) + (*ptr2);
  diff = (*ptr1) - (*ptr2);
  mult = (*ptr1) * (*ptr2);
  div = (*ptr1) / (*ptr2);

  /* Print the results */
  printf("Sum = %.2f\n", sum);
  printf("Difference = %.2f\n", diff);
  printf("Product = %.2f\n", mult);
  printf("Quotient = %.2f\n", div);

  return 0;
}
