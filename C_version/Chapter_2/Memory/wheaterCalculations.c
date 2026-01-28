//
// Created by Vanhuljo on 11/06/2023.
//
// Herschrijf oefening 1 van week 3 waarbij de struct statistiek temperatuur en
// neerslag allebei op de heap gealloceerd worden. Zorg er ook voor dat de lijst
// in de struct statistiek een pointer naar een array is waarvan het geheugen
// dynamisch gealloceerd wordt. Zorg ervoor dat er geen memory leak is als je
// het programma beëindigd.
//
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

int main() {
  struct statistiek* temperatuur = NULL;
  struct statistiek* neerslag = NULL;

  temperatuur = createStatistiek("Gemiddelde temperatuur", "°C");
  neerslag = createStatistiek("Neerslag", "mm");

  printf("%lu %lu\n\n", sizeof(temperatuur->lijst[0].datum), sizeof(neerslag));

  float tempatureCumul = cumul(temperatuur);
  float rainCumul = cumul(neerslag);

  float tempatureAverage = average(temperatuur);
  float rainAverage = average(neerslag);

  /**
   * tempature data
   * return @data
   **/
  addValue(temperatuur, 16, 2, 2023, 24);
  addValue(temperatuur, 16, 2, 2023, 24);
  addValue(temperatuur, 16, 2, 2023, 24);
  addValue(temperatuur, 16, 2, 2023, 24);

  /**
   * rain data
   * return @data
   **/
  addValue(neerslag, 16, 2, 2023, 16);
  addValue(neerslag, 16, 2, 2023, 16);
  addValue(neerslag, 16, 2, 2023, 16);
  addValue(neerslag, 16, 2, 2023, 16);

  tempatureCumul = cumul(temperatuur);
  tempatureAverage = average(temperatuur);

  rainCumul = cumul(neerslag);
  rainAverage = average(neerslag);

  printf("[Tempature]\n\t - cumul = %.2f\n\t - average = %.2f\n\n",
         tempatureCumul, tempatureAverage);
  printf("[Rain]\n\t - cumul = %.2f\n\t - average = %.2f\n\n", rainCumul,
         rainAverage);
  freeDataMemory(temperatuur);
  freeDataMemory(neerslag);

  return 0;
}