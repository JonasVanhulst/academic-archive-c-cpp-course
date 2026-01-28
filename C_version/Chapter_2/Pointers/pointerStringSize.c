//
// Created by Vanhuljo on 12/06/2023.
//
// Write a program in C to calculate the length of a string using a pointer.
//

#include <stdio.h>

#define MAX 100

int stringLenght(char* input);

int main(char* character) {
  char userInput[MAX];
  printf("\n\n Pointer : Calculate the length of the string :\n");
  printf("---------------------------------------------------\n");

  printf("Give me a string: ");
  fgets(userInput, sizeof(userInput), stdin);

  int lenght = stringLenght(&userInput);
  printf("The length of %s is %d", userInput, lenght - 1);

  return 0;
}

int stringLenght(char* input) {
  int counter = 0;

  while (*input != '\0') {
    counter++;
    input++;
  }
  return counter;
}