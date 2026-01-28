//
// Created by Vanhuljo on 10/06/2023.
//
#include <stdio.h>

#define MAX_SIZE 100

int main() {
  int array[MAX_SIZE];
  int sizeOfArray, number;
  int* ptr = array;

  printf("[Info] - Give me the size of your array\n");
  (void)scanf("%d", &sizeOfArray);

  for (int i = 0; i < sizeOfArray; i++) {
    printf("[Array] - number %d : \n", i);
    (void)scanf("%d", &ptr[i]);
  }

  printf("[Array] - numbers:  ");
  for (int i = 0; i < sizeOfArray; i++) {
    printf("%d ", i[ptr]);
  }
  return 0;
}