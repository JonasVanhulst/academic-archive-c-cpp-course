//
// Created by Vanhuljo on 14/03/2023.
//www.github.com/JelleClaes2/Cprograming
//
//Schrijf een programma waarbij van een lijst getallen het minimum, het maximum, het gemiddelde en de mediaan berekend kan worden.
//Implementeer deze functionaliteit in de volgende functie:
//```c
//void statistiek(int *numbers, int size, int *min, int *max, int *average, int *median)
//```
//Print de lijst met nummers af voordat je de functie oproept en nadat je de functie hebt opgeroepen.
//Maak gebruik van de functies malloc() en memcpy() om de lijst met nummers te kopiëren.
//Sorteer vervolgens de gekopieerde lijst met nummers van klein naar groot.
//Haal uit deze gesorteerde lijst het minimum, het maximum en de mediaan.
//Het gemiddeld kan je vinden door over de lijst te itereren en zo het gemiddelde te berekenen.
//Zorg er tot slot voor dat het gealloceerde geheugen terug wordt vrijgegeven voordat je de functie verlaat.

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

#define ARRAYSIZE 10

int minValue(int *numbers);

void swap(int *xp, int *yp);

int *createRandomArray(int size);

int maxValue(int *numbers, int size);

void printArray(int *numbers, int size);

void bubbleSort(int *numbers, int size);

float medianValue(int *numbers, int size);

float averageValue(int *numbers, int size);

void statistiek(int *numbers, int size, int *min, int *max, float *average, float *median);

int main(void) {
    // set a new time seed
    srand(time(NULL));

    int *numbers = createRandomArray(ARRAYSIZE);
    int min;
    int max;
    float median;
    float average;

    printf("Randomnumbers:\n");
    printArray(numbers, ARRAYSIZE);
    statistiek(numbers, ARRAYSIZE, &min, &max, &average, &median);

    printf("\nUnSortedNumbers:\n");
    printArray(numbers, ARRAYSIZE);

    printf("\n\t -> MAX = %d\n", max);
    printf("\n\t -> MIN = %d\n", min);
    printf("\n\t -> MEDIAN = %.2f\n", median);
    printf("\n\t -> AVERAGE = %.2F\n", average);

    return 0;
}

// Creating a random array
int *createRandomArray(int size) {
    int *numbers = (int *) calloc(size, sizeof(int));

    // for loop to create the array with random numbers
    for (int i = 0; i < size; i++) {
        numbers[i] = rand() % 101;
    }
    return numbers;
}

// Printing the array
void printArray(int *numbers, int size) {
    //for loop to print out the generated array
    for (int i = 0; i < size; i++) {
        printf("numbers[%d] = [%d]\n", i, numbers[i]);
    }
}

//function to swap the values inside the arrays
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int *numbers, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (numbers[j] > numbers[j + 1])
                swap(&numbers[j], &numbers[j + 1]);
        }
    }
}

//Function to get the minimum number
int minValue(int *numbers) {
    return numbers[0];
}

//Function to get te maximum number
int maxValue(int *numbers, int size) {
    return numbers[size - 1];
}

//Function to calculate the median of the array
float medianValue(int *numbers, int size) {
    int median, top, lower = 0;

    if (size % 2 == 0) {
        top = (size + 1) / 2;
        lower = (size - 1) / 2;
        median = (numbers[top] + numbers[lower]) / (float) 2;
    } else {
        median = numbers[size / 2];
    }
    return median;
}

//Function to calculate the average
float averageValue(int *numbers, int size) {
    float averge = 0;
    for (int i = 0; i < size; i++) {
        averge += numbers[i];
    }
    return averge / size;
}

//Function to define all the references
void statistiek(int *numbers, int size, int *min, int *max, float *average, float *median) {
    int *sortedNumbers = (int *) calloc(size, sizeof(int));
    memcpy(sortedNumbers, numbers, (sizeof(int) * size));
    bubbleSort(sortedNumbers, size);
    *min = minValue(sortedNumbers);
    *max = maxValue(sortedNumbers, size);
    *average = averageValue(sortedNumbers, size);
    *median = medianValue(sortedNumbers, size);
}