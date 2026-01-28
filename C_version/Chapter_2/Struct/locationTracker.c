//
// Created by Vanhuljo on 22/02/2023.
//
// Schrijf een programma waarbij je een struct declareert met de naam
// geolocatie.
// Deze struct bevat het land, de stad, lattitude en longitude.
// Zorg ervoor dat een gebruiker tot 10 geolocaties kan ingeven
// en deze geolocaties gesorteerd kunnen worden op basis van het land, de stad,
// lattitude en longitude. Declareer en defineer hiervoor de volgende functies:
//
//

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_NUM_GEOLOCATIONS 1

struct geolocatie {
  char land[MAX_NAME_LENGTH];
  char stad[MAX_NAME_LENGTH];
  char lattitude[MAX_NAME_LENGTH];
  char longitude[MAX_NAME_LENGTH];
};

void read_geolocaties(int total, struct geolocatie geolocaties[]) {
  printf("Enter %d geolocations:\n", MAX_NUM_GEOLOCATIONS);

  for (int i = 0; i < MAX_NUM_GEOLOCATIONS; i++) {
    printf("Geolocation %d:\n", i + 1);
    printf("Country: ");
    scanf("%s", geolocaties[i].land);
    printf("City: ");
    scanf("%s", geolocaties[i].stad);
    printf("Latitude: ");
    scanf("%s", geolocaties[i].lattitude);
    printf("Longitude: ");
    scanf("%s", geolocaties[i].longitude);
  }
}

void print_geolocaties(int total, struct geolocatie geolocaties[]) {
  printf("List of geolocations:\n");

  for (int i = 0; i < MAX_NUM_GEOLOCATIONS; i++) {
    printf("%d. Country: %s, City: %s, Latitude: %s, Longitude: %s\n", i + 1,
           geolocaties[i].land, geolocaties[i].stad, geolocaties[i].lattitude,
           geolocaties[i].longitude);
  }
}

int compare_names(char name1[], char name2[]) { return strcmp(name1, name2); }

void sort_names(int total, char names[][MAX_NAME_LENGTH]) {
  char temp[MAX_NAME_LENGTH];

  for (int i = 0; i < MAX_NUM_GEOLOCATIONS - 1; i++) {
    for (int j = i + 1; j < MAX_NUM_GEOLOCATIONS; j++) {
      if (compare_names(names[i], names[j]) > 0) {
        strcpy(temp, names[i]);
        strcpy(names[i], names[j]);
        strcpy(names[j], temp);
      }
    }
  }
}

int main() {
  char names[MAX_NAME_LENGTH][MAX_NAME_LENGTH];

  read_geolocaties(MAX_NAME_LENGTH, names);
  print_geolocaties(MAX_NAME_LENGTH, names);

  sort_names(MAX_NAME_LENGTH, names);
  printf("List of names sorted in alphabetical order:\n");
  print_geolocaties(MAX_NAME_LENGTH, names);

  return 0;
}
