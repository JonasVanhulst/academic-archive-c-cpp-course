//
// Created by Vanhuljo on 10/06/2023.
//
//
// C program to write this source code into file.
//

#include <stdio.h>
#include <stdlib.h>

int copyFile(FILE* fPtr1, FILE* fPtr2);

int main() {
  /* Variable to create file paths */
  char filePath[100] = "../FileHandling/Files/SourceCode.txt";

  /* Variable to read files */
  FILE* filePointer;
  FILE* sourcePointer;

  /* opening files */
  filePointer = fopen(filePath, "w");
  sourcePointer = fopen(__FILE__, "r");

  /* fopen() return NULL if last operation was unsuccessful */
  if (filePointer == NULL) {
    printf("[Debug] - Failed to open requested file");
    exit(EXIT_FAILURE);
  }

  copyFile(sourcePointer, filePointer);

  /* Close file to save file data */
  fclose(filePointer);
  fclose(sourcePointer);

  /* Success message */
  printf("[Info] - File has been written.");

  return 0;
}
int copyFile(FILE* fPtr1, FILE* fPtr2) {
  char character1;
  /* Read single character from file */
  character1 = fgetc(fPtr1);
  do {
    /* Print character read on console */
    fputc(character1, fPtr2);

    character1 = fgetc(fPtr1);

  } while (character1 !=
           EOF); /* Repeat this if last read character is not EOF */
}