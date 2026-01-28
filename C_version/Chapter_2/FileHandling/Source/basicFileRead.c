//
// Created by Vanhuljo on 10/06/2023.
//
// C program to open a file and read data from file.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  /* Variable to store user content */
  int totalRead = 0;
  int DATA_SIZE = 4000;

  char ch;
  char textString[DATA_SIZE];

  /*
   * File pointer to hold reference to our file
   * Open file in w (write) mode.
   * "data/file1.txt" is complete path to create file
   */
  FILE* fp = fopen("../FileHandling/Files/SimpleWrite.txt", "r");

  /* fopen() return NULL if last operation was unsuccessful */
  if (fp == NULL) {
    printf("[Debug] - Failed to open requested file");
    exit(EXIT_FAILURE);
  }

  while (fgets(textString, DATA_SIZE, fp) != NULL) {
    /* Total character read count */
    totalRead = strlen(textString);

    /*
     * Trim new line character from last if exists.
     */
    textString[totalRead - 1] =
        textString[totalRead - 1] == '\n' ? '\0' : textString[totalRead - 1];

    /* Print line read on cosole*/
    printf("%s\n", textString);
  }
  /* Close file to save file data */
  fclose(fp);

  return 0;
}