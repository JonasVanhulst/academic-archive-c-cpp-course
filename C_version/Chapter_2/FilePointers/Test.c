#include <stdio.h>  //For fopen, perror, feof, fgets, printf, getchar, fclose
#include <stdlib.h> //For atoi
#include <string.h> //For strtok

struct result {
    char *index;
    char *name;
    char *URL;
};

struct spells {
    int count;
    struct result *results;
};

int main() {
    struct spells spellList;
    FILE *filePointer = fopen("Spells.json", "r");

    if (filePointer == NULL) {
        perror("File opening failed");
    }

    char buffer[1024];    // prepare a line buffer
    char *parsing = NULL; // prepare helper pointer for strsep
    int counter = 0;      // prepare helper counter for printing

    // Keep reading file till EndOfFile is reached
    while (!feof(filePointer)) {
        // Read one line (stops on newline or eof), will return NULL on eof or fail
        if (fgets(buffer, sizeof(buffer), filePointer) == NULL) {
            break; // Stop reading
        }

        parsing = buffer;
        char *token = strsep(&parsing, "\""); // Split on comma

         // If token exists
        while (token) {
            // Print token
            token = strsep(&parsing, "\""); // Find next token

            if (token != NULL) {
                if (strcmp(token, "count") == 0) {
                    char *number = strtok(&parsing[2], ",");
                    spellList.count = atoi(number);
                    spellList.results = (struct result *)calloc(spellList.count, sizeof(struct result));
                    printf("Number = %d\n", spellList.count);
                    printf("---------------\n");
                } else if (strcmp(token, "index") == 0) {
                    char *index = strtok(&parsing[2], ",");
                    spellList.results[counter].index = (char *)calloc(strlen(index), sizeof(char));
                    strcpy(spellList.results[counter].index, index);
                    printf("index = %s\n", spellList.results[counter].index);
                } else if (strcmp(token, "name") == 0) {
                    char *name = strtok(&parsing[2], ",");
                    spellList.results[counter].name = (char *)calloc(strlen(name), sizeof(char));
                    strcpy(spellList.results[counter].name, name);
                    printf("name = %s\n", spellList.results[counter].name);
                } else if (strcmp(token, "url") == 0) {
                    char *url = strtok(&parsing[2], ",");
                    spellList.results[counter].URL = (char *)calloc(strlen(url), sizeof(char));
                    strcpy(spellList.results[counter].URL, url);
                    printf("url = %s\n", spellList.results[counter].URL);
                    printf("---------------\n");
                    counter++;
                }
            }
        }
    }
    for (int i = 0; i < spellList.count; i++) {
        free(spellList.results[i].index);
        free(spellList.results[i].name);
        free(spellList.results[i].URL);
    }
    free(spellList.results);
    return 0;
}