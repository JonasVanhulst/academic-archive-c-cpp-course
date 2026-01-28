//
// Created by Vanhuljo on 10/06/2023.
//
// C program to copy a file into another file.
//

#include <stdio.h>
#include <stdlib.h>

/* Function declaration */
int copyFile(FILE* fPtr1, FILE* fPtr2);

int main() {
  /* Variable to create file paths */
  char filePath1[100] = "../FileHandling/Files/ToCopyFile.txt";
  char filePath2[100] = "../FileHandling/Files/CopiedFile.txt";

  /* Variable to read files */
  FILE* filePointer1;
  FILE* filePointer2;

  /*
   * File pointer to hold reference to our file
   * Open file in r (read) mode.
   * Open file in w (write) mode.
   */
  filePointer1 = fopen(filePath1, "r");
  filePointer2 = fopen(filePath2, "w");

  /* fopen() return NULL if last operation was unsuccessful */
  if (filePointer1 == NULL || filePointer2 == NULL) {
    printf("[Debug] - Failed to open requested file");
    exit(EXIT_FAILURE);
  }

  /* Copy the files with eachoter */
  copyFile(filePointer1, filePointer2);

  /* Close file to save file data */
  fclose(filePointer1);
  fclose(filePointer2);

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
