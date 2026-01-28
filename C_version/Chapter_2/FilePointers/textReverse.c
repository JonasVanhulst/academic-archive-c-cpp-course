//
// Created by Vanhuljo on 11/06/2023.
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

void fileReverse(FILE* inputFile, FILE* exportFile, long fileSize,
                 char* buffer) {
  // Het bestand omkeren
  buffer = "de";

  // Het omgekeerde bestand schrijven
  fprintf(exportFile, buffer);
}

int main(int argc, char* argv[]) {
  char filePath[256];
  char* buffer = NULL;

  long fileSize;

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

        FILE* exportFile = fopen(filePath, "w");

        if (exportFile == NULL) {
          printf("\nThe export file %s could not be opened!", filePath);
          exit(EXIT_FAILURE);
        } else {
          printf("[DEBUG] - Successfully loaded file: %s with address %p \n",
                 argv[i], exportFile);
        }

        // Het bestandsgrootte bepalen
        fseek(inputFile, 0, SEEK_END);
        fileSize = ftell(inputFile);
        rewind(inputFile);

        // De benodigde hoeveelheid geheugen reserveren
        buffer = (char*)malloc(fileSize);
        if (buffer == NULL) {
          printf("Failed to allocate memory for input file: %s\n", inputFile);
          exit(EXIT_FAILURE);
        }

        // Setting every first letter of the sentence to upper
        fileReverse(inputFile, exportFile, fileSize, buffer);

        // Free memory of files
        free(buffer);
        fclose(inputFile);
        fclose(exportFile);

        break;
      }
    }
  }
  return 0;
}