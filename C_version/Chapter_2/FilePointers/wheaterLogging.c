//
// Created by Vanhuljo on 11/06/2023.
//
// Herschrijf oefening 1 van week 7.
// Bij elke AddValue() call wordt de value toegevoegd aan een logbestand (i.e.
// append). De naam van dit logbestand (i.e. "neerslag.log", "temperatuur.log")
// wordt als parameter meegegeven aan de functieoproep. Het logbestand moet dus
// steeds open en dicht gedaan worden om de nieuwe waarde te kunnen toevoegen.
// Als de maand verwijderd wordt, bereken dan eerst de cumul en gemiddelde van
// temperatuur en neerslag van die maand en schrijf dit naar
// "samenvatting_jaar_maand.log" waarbij jaar en maand getallen zijn.
//

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WHEATER 31

struct date {
  uint8_t dag : 5;
  uint8_t maand : 4;
  uint16_t jaar : 15;
};

struct record {
  struct date datum;
  float waarde;
};

struct statistiek {
  char* naam;
  char* eenheid;
  uint8_t aantal;
  struct record* lijst;
};

void game_menu() {
  printf(
      "\nUsage : [-d Date] [-T Temperature] [-R Rain]\n"
      "Options:\n"
      "  -d date              Date for the data.\n"
      "  -T temperature       Data for temperature.\n"
      "  -R rain              Data for rain.\n");
}

float cumul(struct statistiek* data, char filePath[50]) {
  float sum = 0.0;

  for (int i = 0; i < data->aantal; i++) {
    sum = sum + data->lijst[i].waarde;
  }

  FILE* filePointer = fopen(filePath, "a");
  if (filePointer == NULL) {
    printf("File doesn't exist!\n");
    exit(EXIT_FAILURE);
  }
  fprintf(filePointer, "De som van %d/%d/%d is : %f\n", data->lijst->datum.dag,
          data->lijst->datum.maand, data->lijst->datum.jaar, sum);
  fclose(filePointer);
  return sum;
};

float average(struct statistiek* data, char filePath[50]) {
  float sum = 0.0;
  float average = 0.0;

  for (int i = 0; i < data->aantal; i++) {
    sum = sum + data->lijst[i].waarde;
  }
  average = sum / data->aantal;

  FILE* filePointer = fopen(filePath, "a");
  if (filePointer == NULL) {
    printf("File doesn't exist!\n");
    exit(EXIT_FAILURE);
  }
  fprintf(filePointer, "the average van %d/%d/%d is : %f\n",
          data->lijst->datum.dag, data->lijst->datum.maand,
          data->lijst->datum.jaar, average);
  fclose(filePointer);
  return average;
};

void freeDataMemory(struct statistiek* data) {
  free(data->eenheid);
  free(data->lijst);
  free(data->naam);
  free(data);
}

char game_menu_translate_option(char* option) {
  if (strcasecmp("Date", option) == 0) return 'd';
  if (strcasecmp("Temperature", option) == 0) return 't';
  if (strcasecmp("Rain", option) == 0) return 'r';
  return '\0';
}

struct statistiek* createStatistiek(char* naam, char* eenheid) {
  struct statistiek* data =
      (struct statistiek*)calloc(1, sizeof(struct statistiek));
  data->naam = (char*)calloc(strlen(naam) + 1, sizeof(char));
  strcpy(data->naam, naam);
  data->eenheid = (char*)calloc(strlen(eenheid) + 1, sizeof(char));
  strcpy(data->eenheid, eenheid);
  return data;
}

void addValue(struct statistiek* data, int dag, int maand, int jaar,
              float waarde, char filePath[50]) {
  if (data->aantal < MAX_WHEATER) {
    data->lijst = (struct record*)realloc(
        data->lijst, (data->aantal + 1) * sizeof(struct record));
    data->lijst[data->aantal].waarde = waarde;
    data->lijst[data->aantal].datum.dag = dag;
    data->lijst[data->aantal].datum.maand = maand;
    data->lijst[data->aantal].datum.jaar = jaar;
    data->aantal++;

    printf("[Info] - Data was succesfully added\n");

    FILE* filePointer = fopen(filePath, "a");
    if (filePointer == NULL) {
      printf("File doesn't exist!\n");
      exit(EXIT_FAILURE);
    }
    fprintf(filePointer, "De data van %d/%d/%d is : %f\n",
            data->lijst->datum.dag, data->lijst->datum.maand,
            data->lijst->datum.jaar, waarde);
    fclose(filePointer);
  } else {
    printf("Cannot add more values. Maximum limit reached.\n");
  }
}

int main(int argc, char* argv[]) {
  int day, month, year;

  struct statistiek* neerslag = NULL;
  struct statistiek* temperatuur = NULL;

  float tempatureAverage, tempatureCumul, rainAverage, rainCumul, rain,
      temperature;

  neerslag = createStatistiek("Neerslag", "mm");
  temperatuur = createStatistiek("Gemiddelde temperatuur", "°C");

  if (argc == 1 || strcmp(argv[1], "-help") == 0) {
    game_menu();
    exit(EXIT_FAILURE);
  } else {
    char option;
    bool processingArguments = false;

    // Loop door alle argumenten
    for (int i = 1; i < argc; i++) {
      if (argv[i][0] == '-') {
        option = (argv[i][1] == '-') ? game_menu_translate_option(&argv[i][2])
                                     : argv[i][1];
        switch (option) {
          case 'D':
          case 'd':
            if (i + 1 < argc) {
              for (int d = i + 1; d < argc; d++) {
                if (argv[d][0] == '-') {
                  break;
                }
                printf("Argument after -d: %s\n", argv[d]);
                sscanf(argv[d], "%d/%d/%d", &day, &month, &year);
                break;
              }
            } else {
              printf("[ERROR] - Missing argument(s) after -d option\n");
              exit(EXIT_FAILURE);
            }
            break;
          case 'T':
          case 't':
            if (i + 1 < argc) {
              processingArguments = true;
            } else {
              printf("[ERROR] - Missing argument(s) after -t option\n");
              exit(EXIT_FAILURE);
            }
            break;
          case 'R':
          case 'r':
            if (i + 1 < argc) {
              processingArguments = true;
            } else {
              printf("[ERROR] - Missing argument(s) after -r option\n");
              exit(EXIT_FAILURE);
            }
            break;
          default:
            printf("[ERROR] - Invalid Menu option %s detected\n", argv[i]);
            exit(EXIT_FAILURE);
        }
      } else if (processingArguments) {
        if (option == 'T' || option == 't') {
          temperature = atof(argv[i]);
          printf("Temperature: %f\n", temperature);
          addValue(temperatuur, day, month, year, temperature,
                   "../ClassExersises/FilePointers/Files/temperatuur.log");
        } else if (option == 'R' || option == 'r') {
          rain = atof(argv[i]);
          printf("Rain: %f\n", rain);
          addValue(neerslag, day, month, year, rain,
                   "../ClassExersises/FilePointers/Files/neerslag.log");
        }
      }
    }
  }

  rainCumul =
      cumul(neerslag,
            "../ClassExersises/FilePointers/Files/samenvatting_jaar_maand.log");
  rainAverage = average(
      neerslag,
      "../ClassExersises/FilePointers/Files/samenvatting_jaar_maand.log");
  tempatureCumul =
      cumul(temperatuur,
            "../ClassExersises/FilePointers/Files/samenvatting_jaar_maand.log");
  tempatureAverage = average(
      temperatuur,
      "../ClassExersises/FilePointers/Files/samenvatting_jaar_maand.log");

  printf("[Rain]\n\t - cumul = %.2f\n\t - average = %.2f\n\n", rainCumul,
         rainAverage);
  printf("[Tempature]\n\t - cumul = %.2f\n\t - average = %.2f\n\n",
         tempatureCumul, tempatureAverage);

  freeDataMemory(neerslag);
  freeDataMemory(temperatuur);

  return 0;
}