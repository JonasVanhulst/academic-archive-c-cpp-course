//
// Created by Vanhuljo on 16/01/2023.
// Maak een lookup tabel voor de sinus functie. Het idee is dat je de sinuswaarde elke graden sampelt,
// en dit van 0 graden tot 360 graden.
//

#include <stdio.h>
#include <math.h>

#define SIZE 360

int getal = 0;

int main(void) {
    float lookup[SIZE];

    while (1) {
        for (int i = 0; i < SIZE; i++) {
            lookup[i] = sin(i * M_PI / 180);
        }

        printf("Geef een getal tussen de 0 en 360 in: ");
        scanf("%d", &getal);
        printf("Sinus van %d = %f\n", getal, lookup[getal]);
    }
    return 0;
}