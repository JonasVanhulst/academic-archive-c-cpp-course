//
// Created by Vanhuljo on 11/06/2023.
//
// Herschrijf oefening 1 van week 2 waarbij de struct als pointer wordt
// meegegeven aan de cumul en gemiddelde functie. Schrijf ook een nieuwe functie
// addValue() die een nieuwe datum en waarde kan toevoegen aan de struct
// statistiek die als pointer wordt meegegeven met deze functie.
//

#include <stdint.h>
#include <stdio.h>

#define MAX_WHEATER 31

struct statistiek {
  char naam[64];
  char eenheid[8];
  uint8_t aantal;
  struct {
    struct {
      uint8_t dag : 5;
      uint8_t maand : 4;
      uint16_t jaar : 15;
    } datum;
    float waarde;
  } lijst[MAX_WHEATER];
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

void addValue(struct statistiek* data, int dag, int maand, int jaar,
              float waarde) {
  if (data->aantal < MAX_WHEATER) {
    data->lijst[data->aantal].datum.dag = dag;
    data->lijst[data->aantal].datum.maand = maand;
    data->lijst[data->aantal].datum.jaar = jaar;
    data->lijst[data->aantal].waarde = waarde;
    data->aantal++;

    printf("[Info] - Data was succesfully added\n");
  } else {
    printf("Cannot add more values. Maximum limit reached.\n");
  }
};

int main() {
  struct statistiek temperatuur = {"Gemiddeld temperatuur",
                                   "°C",
                                   15,
                                   {{{15, 2, 2023}, 7.2},
                                    {{14, 2, 2023}, 6.5},
                                    {{13, 2, 2023}, 6.1},
                                    {{12, 2, 2023}, 6.8},
                                    {{11, 2, 2023}, 6.6},
                                    {{10, 2, 2023}, 4},
                                    {{9, 2, 2023}, 2.3},
                                    {{8, 2, 2023}, 1.7},
                                    {{7, 2, 2023}, 1.1},
                                    {{6, 2, 2023}, 3.7},
                                    {{5, 2, 2023}, 6.5},
                                    {{4, 2, 2023}, 8.7},
                                    {{3, 2, 2023}, 9.3},
                                    {{2, 2, 2023}, 8.2},
                                    {{1, 2, 2023}, 6.9}}};
  struct statistiek neerslag = {"Neerslag",
                                "mm",
                                15,
                                {{{15, 2, 2023}, 0},
                                 {{14, 2, 2023}, 0},
                                 {{13, 2, 2023}, 0},
                                 {{12, 2, 2023}, 0},
                                 {{11, 2, 2023}, 0},
                                 {{10, 2, 2023}, 0},
                                 {{9, 2, 2023}, 0.13},
                                 {{8, 2, 2023}, 0},
                                 {{7, 2, 2023}, 0.03},
                                 {{6, 2, 2023}, 0},
                                 {{5, 2, 2023}, 0.8},
                                 {{4, 2, 2023}, 3.4},
                                 {{3, 2, 2023}, 0.3},
                                 {{2, 2, 2023}, 0.3},
                                 {{1, 2, 2023}, 0}}};
  printf("%lu %lu\n\n", sizeof(temperatuur.lijst[0].datum), sizeof(neerslag));

  float tempatureCumul = cumul(&temperatuur);
  float rainCumul = cumul(&neerslag);

  float tempatureAverage = average(&temperatuur);
  float rainAverage = average(&neerslag);

  printf("[Tempature]\n\t - cumul = %.2f\n\t - average = %.2f\n\n",
         tempatureCumul, tempatureAverage);
  printf("[Rain]\n\t - cumul = %.2f\n\t - average = %.2f\n\n", rainCumul,
         rainAverage);

  addValue(&temperatuur, 16, 2, 2023, 34);

  return 0;
}