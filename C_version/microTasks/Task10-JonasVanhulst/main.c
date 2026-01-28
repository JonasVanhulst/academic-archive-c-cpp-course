// Fix me !
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArrayWithRandom(int* array, int size);
void printArray(int* array, int size);
void sortArray(int* array, int size);
void sort(int* lhs, int* rhs);
void swap(int* lhs, int* rhs);

int main() {
  int seed;
  (void)scanf("%d", &seed);
  srand(seed ? seed : time(NULL));
  int array[42];
  fillArrayWithRandom(array, sizeof(array) / sizeof(int));
  printf("\nVoor sort :\n");
  printArray(array, sizeof(array) / sizeof(int));
  sortArray(array, sizeof(array) / sizeof(int));
  printf("\nNa sort :\n");
  printArray(array, sizeof(array) / sizeof(int));
  return 0;
}

void fillArrayWithRandom(int* array, int size) {
  for (int i = 0; i < size; i++) {
    array[i] = (rand() % 42096);
  }
}

void printArray(int* array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%5d\n", array[i]);
  }
}

void sortArray(int* array, int size) {
  for (int max = size - 1; max > 0; max--) {
    for (int i = 0; i < max; i++) {
      sort(&array[i], &array[i + 1]);
    }
  }
}

void sort(int* lhs, int* rhs) {
  if (*lhs > *rhs) {
    swap(lhs, rhs);
  }
}

void swap(int* lhs, int* rhs) {
  int temp = *lhs;
  *lhs = *rhs;
  *rhs = temp;
}
