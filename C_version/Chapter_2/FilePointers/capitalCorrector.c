//
// Created by Vanhuljo on 11/06/2023.
//
// Open een door arguments to main meegeven bestand zowel in lezen als schrijven
// modus en zorg ervoor dat elke zin start met een hoofdletter.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void game_menu() {
  printf(
      "\nUsage :  [-f correct-file] \n"
      "Options:\n"
      "  -f correct-list          give the files to correct ");
}

void fileCorrecting(FILE* inputFile, FILE* exportFile) {
  int capitalizeNext = 1;
  int ch;

  while ((ch = fgetc(inputFile)) != EOF) {
    if (capitalizeNext && ch >= 'a' && ch <= 'z') {
      ch = ch - 'a' + 'A';
      capitalizeNext = 0;
    }
    if (ch == '.' || ch == '!' || ch == '?') {
      capitalizeNext = 1;
    }
    fputc(ch, exportFile);
  }
}

int main(int argc, char* argv[]) {
  char filePath[256];

  if (argc == 1 || strcmp(argv[1], "-help") == 0) {
    game_menu();
    exit(EXIT_FAILURE);
  } else {
    // Loop through all arguments
    for (int i = 1; i < argc; i++) {
      // Checking for Json files
      while (argv[i][0] != '-') {
        char filePath[256];
        // Compose file path of loaded card & load it
        snprintf(filePath, sizeof(filePath), "%s%s",
                 "../ClassExersises/FilePointers/Files/", argv[i]);
        FILE* inputFile = fopen(filePath, "r");

        if (inputFile == NULL) {
          printf("\nThe file %s does not exist !", argv[i]);
          exit(EXIT_FAILURE);
        } else {
          printf("[DEBUG] - Successfully loaded file: %s with address %p \n",
                 argv[i], inputFile);
        }

        FILE* exportFile = fopen(filePath, "a");

        if (exportFile == NULL) {
          printf("\nThe file %s does not exist !", argv[i]);
          exit(EXIT_FAILURE);
        } else {
          printf("[DEBUG] - Successfully loaded file: %s with address %p \n",
                 argv[i], exportFile);
        }

        // Setting every first letter of the sentence to upper
        fileCorrecting(inputFile, exportFile);

        // Free memory of files
        fclose(inputFile);
        fclose(exportFile);

        break;
      }
    }
  }
  return 0;
}