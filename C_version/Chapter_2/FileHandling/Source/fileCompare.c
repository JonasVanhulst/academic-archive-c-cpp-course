//
// Created by Vanhuljo on 10/06/2023.
//
// C program to open a file and compare data from files.
//

#include <stdio.h>
#include <stdlib.h>

/* Function declaration */
int compareFile(FILE* fPtr1, FILE* fPtr2, int* line, int* col);

int main() {
  /* Variable to create file paths */
  char filePath1[100] = "../FileHandling/Files/FileCompare_1.txt";
  char filePath2[100] = "../FileHandling/Files/FileCompare_2.txt";

  /* Variable to read files */
  FILE* filePointer1;
  FILE* filePointer2;

  /* Variable to store user content */
  int difference, line, col = 0;

  /*
   * File pointer to hold reference to our file
   * Open file in r (read) mode.
   * "data/file1.txt" is complete path to create file
   */
  filePointer1 = fopen(filePath1, "r");
  filePointer2 = fopen(filePath2, "r");

  /* fopen() return NULL if last operation was unsuccessful */
  if (filePointer1 == NULL || filePointer2 == NULL) {
    printf("[Debug] - Failed to open requested file");
    exit(EXIT_FAILURE);
  }

  /* Compare the files with eachoter */
  difference = compareFile(filePointer1, filePointer2, &line, &col);

  if (difference == 0) {
    printf("[Info] - Files are equal to eachother");
  } else {
    printf("[Info] - Files aren't equal to eachother");
    printf("[Difference] - line %d , col %d", line, col);
  }

  /* Close file to save file data */
  fclose(filePointer1);
  fclose(filePointer2);

  return 0;
}

int compareFile(FILE* fPtr1, FILE* fPtr2, int* line, int* col) {
  char character1, character2;

  // starting at line 1 and colomn 0
  *line = 1;
  *col = 0;

  do {
    /* Read single character from file */
    character1 = fgetc(fPtr1);
    character2 = fgetc(fPtr2);

    // Increment line
    if (character1 == '\n') {
      *line += 1;
      *col = 0;
    }

    // If characters aren't equal return false
    if (character1 != character2) {
      return -1;
    }

    *col += 1;

  } while (character1 != EOF &&
           character2 !=
               EOF); /* Repeat this if last read character is not EOF */

  // if end of file is reached with both files, they are equal
  if (character1 == EOF && character2 == EOF) {
    return 0;
  } else {
    return -1;
  }
}
