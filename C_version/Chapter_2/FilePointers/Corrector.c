// Created by Vanhuljo on 18/04/2023.
//
// Open een door arguments to main meegeven bestand zowel in lezen
// als schrijven modus en zorg ervoor dat elke zin start met een hoofdletter.
//
//https://replit.com/@JonasVanhulst/MustyWornExternalcommand#main.c

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000

int main(int argc, char *argv[]) {
    char inputFilename[MAX_SIZE];
    char outputFilename[MAX_SIZE];
    char Line[MAX_SIZE];

    FILE *inputFile;
    FILE *outputFile;

    strcpy(inputFilename, argv[1]);
    strcpy(outputFilename, argv[2]);

    inputFile = fopen(inputFilename, "r");
    outputFile = fopen(outputFilename, "w");

    while (fgets(Line, MAX_SIZE, inputFile)) {
        for (int i = 0; i < strlen(Line); i++) {
            if (i == 0 || (i > 0 && Line[i - 1] == '.')) {
                Line[i] = toupper(Line[i]);
            }
        }
        fputs(Line, outputFile);
    }
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}