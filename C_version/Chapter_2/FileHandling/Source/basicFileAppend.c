//
// Created by Vanhuljo on 10/06/2023.
//
// C program to append data into a file and read the data from the file.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFileData(FILE* filePointer);

int main() {
  /* Variable to store user content */
  int totalRead = 0;
  int DATA_SIZE = 4000;

  char ch;
  char userAnswer[DATA_SIZE];
  char textString[DATA_SIZE];
  char filePath[100] = "../FileHandling/Files/SimpleWrite.txt";

  /*
   * File pointer to hold reference to our file
   * Open file in a (append) mode.
   * "data/file1.txt" is complete path to create file
   */
  FILE* fp = fopen(filePath, "a");

  /* fopen() return NULL if last operation was unsuccessful */
  if (fp == NULL) {
    printf("[Debug] - Failed to open requested file");
    exit(EXIT_FAILURE);
  }

  /* Receiving user's reaction on the wheater */
  printf("\n[Info] - Give some reaction pls. \n\n");
  fflush(stdin);  // To clear extra white space characters in stdin
  fgets(userAnswer, DATA_SIZE, stdin);

  /* Append data to file */
  fprintf(fp, userAnswer);

  fp = freopen(filePath, "r", fp);
  readFileData(fp);

  /* Close file to save file data */
  fclose(fp);

  return 0;
}

void readFileData(FILE* filePointer) {
  char ch;

  do {
    ch = fgetc(filePointer);

    putchar(ch);

  } while (ch != EOF);
}
