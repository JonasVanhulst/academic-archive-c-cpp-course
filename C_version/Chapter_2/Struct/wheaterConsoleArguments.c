//
// Created by Vanhuljo on 11/06/2023.
//
// Herschrijf oefening 1 van week 4 waarbij data aan de struct statistiek
// temperatuur en neerslag meegegeven kan worden via argumenten naar de main.
// Hierbij maak je gebruik van de flags -d om de startdatum mee te geven en -T
// en/of -N om aan te geven dat het om de temperatuur en/of neerslag gaat.
//
// console
// ~/Oefening30$ ./main -d 1-2-2023 -T 6.9 8.2 9.3 8.7 6.5 3.7 1.1 1.7 2.3
// 4 6.6 6.8 6.1 6.5 7.2 -N 0 0.3 0.3 3.4 0.8 0 0.03 0 0.13 0 0 0 0 0 0
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

char game_menu_translate_option(char* option) {
  if (strcasecmp("Date", option) == 0) return 'd';
  if (strcasecmp("Temperature", option) == 0) return 't';
  if (strcasecmp("Rain", option) == 0) return 'r';
  return '\0';
}

void game_menu() {
  printf(
      "\nUsage : [-d Date] [-T Temperature] [-R Rain]\n"
      "Options:\n"
      "  -d date              Date for the data.\n"
      "  -T temperature       Data for temperature.\n"
      "  -R rain              Data for rain.\n");
}

float cumul(struct statistiek* data) {
  float sum = 0.0;

  for (int i = 0; i < data->aantal; i++) {
    sum = sum + data->lijst[i].waarde;
  }

  return sum;
};

float average(struct statistiek* data) {
  float sum = 0.0;
  float average = 0.0;

  for (int i = 0; i < data->aantal; i++) {
    sum = sum + data->lijst[i].waarde;
  }
  average = sum / data->aantal;
  return average;
};

void freeDataMemory(struct statistiek* data) {
  free(data->eenheid);
  free(data->lijst);
  free(data->naam);
  free(data);
}

void addValue(struct statistiek* data, int dag, int maand, int jaar,
              float waarde) {
  if (data->aantal < MAX_WHEATER) {
    data->lijst = (struct record*)realloc(
        data->lijst, (data->aantal + 1) * sizeof(struct record));
    data->lijst[data->aantal].waarde = waarde;
    data->lijst[data->aantal].datum.dag =
        data->lijst[data->aantal - 1].datum.dag +
        1;  // Aantal dagen == toe te voegen datum
    data->lijst[data->aantal].datum.maand =
        data->lijst[data->aantal - 1].datum.maand;
    data->lijst[data->aantal].datum.jaar =
        data->lijst[data->aantal - 1].datum.jaar;
    data->aantal++;

    printf("[Info] - Data was succesfully added\n");
  } else {
    printf("Cannot add more values. Maximum limit reached.\n");
  }
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
              // Verwerk de datumargumenten hier
              // ...
            } else {
              printf("[ERROR] - Missing argument(s) after -d option\n");
              exit(EXIT_FAILURE);
            }
            break;
          case 'T':
          case 't':
            if (i + 1 < argc) {
              // Zet processingArguments op true
              processingArguments = true;
            } else {
              printf("[ERROR] - Missing argument(s) after -t option\n");
              exit(EXIT_FAILURE);
            }
            break;
          case 'R':
          case 'r':
            if (i + 1 < argc) {
              // Zet processingArguments op true
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
        // Verwerk argumenten na -t of -r
        // ...
        if (option == 'T' || option == 't') {
          temperature = atof(argv[i]);
          printf("Temperature: %f\n", temperature);
          addValue(temperatuur, day, month, year, temperature);
        } else if (option == 'R' || option == 'r') {
          rain = atof(argv[i]);
          printf("Rain: %f\n", rain);
          addValue(neerslag, day, month, year, rain);
        }
      }
    }
  }

  rainCumul = cumul(neerslag);
  rainAverage = average(neerslag);
  tempatureCumul = cumul(temperatuur);
  tempatureAverage = average(temperatuur);

  printf("[Rain]\n\t - cumul = %.2f\n\t - average = %.2f\n\n", rainCumul,
         rainAverage);
  printf("[Tempature]\n\t - cumul = %.2f\n\t - average = %.2f\n\n",
         tempatureCumul, tempatureAverage);

  freeDataMemory(neerslag);
  freeDataMemory(temperatuur);

  return 0;
}