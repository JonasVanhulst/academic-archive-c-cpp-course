//
// Created by Vanhuljo on 10/06/2023.
//
// Schrijf een programma waarbij van een lijst getallen het minimum, het
// maximum, het gemiddelde en de mediaan berekend kan worden. Print de lijst met
// nummers af voordat je de functie oproept en nadat je de functie hebt
// opgeroepen.
//

#include <stdio.h>

#define MAX_SIZE 100

void statistiek(int* numbers, int size, int* min, int* max, int* average,
                int* median) {
  // Sorteer de getallen
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (numbers[j] > numbers[j + 1]) {
        int temp = numbers[j];
        numbers[j] = numbers[j + 1];
        numbers[j + 1] = temp;
      }
    }
  }

  // Bepaal het minimum en maximum
  *min = numbers[0];
  *max = numbers[size - 1];

  // Bepaal het gemiddelde
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += numbers[i];
  }
  *average = sum / size;

  // Bepaal de mediaan
  if (size % 2 == 0) {
    *median = (numbers[size / 2 - 1] + numbers[size / 2]) / 2;
  } else {
    *median = numbers[size / 2];
  }
};

int main() {
  int array[MAX_SIZE];
  int sizeOfArray, number;
  int* ptr = array;
  int min, max, average, median;

  printf("[Info] - Give me the size of your array\n");
  (void)scanf("%d", &sizeOfArray);

  for (int i = 0; i < sizeOfArray; i++) {
    printf("[Array] - number %d : ", i);
    (void)scanf("%d", &ptr[i]);
  }

  printf("[Array] - numbers:  ");
  for (int i = 0; i < sizeOfArray; i++) {
    printf("%d ", ptr[i]);
  }

  statistiek(ptr, sizeOfArray, &min, &max, &average, &median);

  printf("\n\n[Statistics]\n");
  printf("Minimum: %d\n", min);
  printf("Maximum: %d\n", max);
  printf("Gemiddelde: %d\n", average);
  printf("Mediaan: %d\n", median);

  return 0;
}