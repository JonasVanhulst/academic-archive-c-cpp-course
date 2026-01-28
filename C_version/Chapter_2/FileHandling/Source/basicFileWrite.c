//
// Created by Vanhuljo on 10/06/2023.
//
// C program to create a file and write data into file.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
  /* Variable to store user content */
  int DATA_SIZE = 4000;
  char textString[DATA_SIZE];

  /*
   * File pointer to hold reference to our file
   * Open file in w (write) mode.
   * "data/file1.txt" is complete path to create file
   */
  FILE* fp = fopen("../FileHandling/Files/SimpleWrite.txt", "a");

  /* fopen() return NULL if last operation was unsuccessful */
  if (fp == NULL) {
    printf("[Debug] - Failed to open requested file");
    exit(EXIT_FAILURE);
  }

  /* Input contents from user to store in file */
  printf("Enter contents to store in file : \n");
  fgets(textString, DATA_SIZE, stdin);

  /* Write data to file */
  fprintf(fp, "\n%s", textString);

  /* Close file to save file data */
  fclose(fp);

  /* Success message */
  printf("[Info] - File has been written.");

  return 0;
}