//
// Created by Vanhuljo on 21/02/2023.
// Schrijf een programma dat de statistische gegevens van het KMI kan verwerken.
// Bron :
// https://www.meteo.be/nl/klimaat/klimaat-van-belgie/recente-waarnemingen-te-ukkel
// Start met de gegevens die staan in
// https://www.meteo.be/resources/climatology/uccle_month/Ukkel_waarnemingen.txt
// en verzamel die in een struct per maand per gegevenstype (i.e. gemiddelde
// temperatuur en neerslag). Maak een functie dat de cumul en een functie dat
// gemiddelde kan berekenen van een meegegeven struct.
//
// Hier alvast een start voor de eerste 15 dagen :
//
#include <stdint.h>
#include <stdio.h>

#pragma pack(1)
#define totalDay 20

float rain_average, temp_average;

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
  } lijst[31];
};

void calculateAverage(struct statistiek temperatuur) {}

void calculateCumul(struct statistiek neerslag) {}

int main(void) {
  struct statistiek temperatuur = {
      "Gemiddeld temperatuur",
      "°C",
      totalDay,
      {{{20, 2, 2023}, 7},    {{19, 2, 2023}, 8.5}, {{18, 2, 2023}, 9.9},
       {{17, 2, 2023}, 10.6}, {{16, 2, 2023}, 8.7}, {{15, 2, 2023}, 7.2},
       {{14, 2, 2023}, 6.5},  {{13, 2, 2023}, 6.1}, {{12, 2, 2023}, 6.8},
       {{11, 2, 2023}, 6.6},  {{10, 2, 2023}, 4},   {{9, 2, 2023}, 2.3},
       {{8, 2, 2023}, 1.7},   {{7, 2, 2023}, 1.1},  {{6, 2, 2023}, 3.7},
       {{5, 2, 2023}, 6.5},   {{4, 2, 2023}, 8.7},  {{3, 2, 2023}, 9.3},
       {{2, 2, 2023}, 8.2},   {{1, 2, 2023}, 6.9}}};

  struct statistiek neerslag = {
      "Neerslag",
      "mm",
      totalDay,
      {{{20, 2, 2023}, 0},   {{19, 2, 2023}, 0},   {{18, 2, 2023}, 2.5},
       {{17, 2, 2023}, 0.4}, {{16, 2, 2023}, 0.5}, {{15, 2, 2023}, 0},
       {{14, 2, 2023}, 0},   {{13, 2, 2023}, 0},   {{12, 2, 2023}, 0},
       {{11, 2, 2023}, 0},   {{10, 2, 2023}, 0},   {{9, 2, 2023}, 0.13},
       {{8, 2, 2023}, 0},    {{7, 2, 2023}, 0.03}, {{6, 2, 2023}, 0},
       {{5, 2, 2023}, 0.8},  {{4, 2, 2023}, 3.4},  {{3, 2, 2023}, 0.3},
       {{2, 2, 2023}, 0.3},  {{1, 2, 2023}, 0}}};

  printf("%lu %lu\n\n", sizeof(temperatuur.lijst[0].datum), sizeof(neerslag));

  printf(
      "--------------------------------------------------------------\n\t"
      "Cumul en Gemiddelde voor de huidige maand\t"
      "\n--------------------------------------------------------------\n");

  for (int i = 0; i < temperatuur.aantal; i++) {
    float waarde = temperatuur.lijst[i].waarde;
    temp_average += waarde;
  }
  temp_average /= temperatuur.aantal;
  printf("%f", temp_average);

  printf("\n--------------------------\n");

  for (int i = 0; i < neerslag.aantal; i++) {
    float regen = neerslag.lijst[i].waarde;
    rain_average += regen;
  }
  printf("%f", rain_average);

  return 0;
}