#include <ctype.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 360
#define LENGHT 12

void upr_lwr(char sentence[200]);

/*
  Maak een programma dat het gemiddelde berekend van 5 getallen, tussen de 0 en
  20, die door de gebruiker worden ingegeven. Het programma print "Geslaagd"
  indien het gemiddelde groter of gelijk aan 10 is, anders print het "Niet
  geslaagd".
*/
void averageProgram(void) {
  float average;
  float number[5] = {0, 0, 0, 0, 0};
  for (int i = 0; i < 5; i++) {
    printf("Give a number %d:", i);
    scanf("%f", &number[i]);
  }
  float number1 = number[0];
  float number2 = number[1];
  float number3 = number[2];
  float number4 = number[3];
  float number5 = number[4];
  average = (number1 + number2 + number3 + number4 + number5) / 5;

  if (average >= 10) {
    printf("You passed 😎🥳 \n");
  } else {
    printf("You Failed 😱 \n");
    printf("Your average is %.4f \n", average);
  }
}

/*
 Schrijf een programma dat de som, het product, het verschil en de deling van 2
 reële getallen, die door de gebruiker worden ingegeven, berekent en de
 resultaten print. Maak deze keer gebruik van assignment operators waarbij het
 tussentijdse resultaat wordt opgeslagen in de variabele getal1.

 Voorbeeld:
 getal1 = 5.6
 getal2 = 4.3
 5.6 + 4.3 = 9.9
 9.9 * 4.3 = 42.57
 42.57 - 4.3 = 38.27
 38.27 / 4.3 = 8.9
*/
void calculator(void) {
  float number1, number2, som, product, difference, rest = 0.0;
  int result = 0;
  printf("Geef 2 reële getallen: ");
  result = scanf("%f %f", &number1, &number2);

  som = number1 += number2;
  product = number1 *= number2;
  difference = number1 -= number2;
  rest = number1 /= number2;
  printf("de som is %f ", som);
  printf("het prodect is %f ", product);
  printf("het verschil is %f ", difference);
  printf("de rest is %f ", rest);
}

/*
  Maak een programma dat de volgende geluidsassociatie weergeeft op basis van de
  input van de gebruiker.

  Loudness in Decibels (dB)    Perception
  ==========================================
  50 or lower                  Quiet
  51-70                        Intrusive
  71-90                        Annoying
  91-110                       Very annoying
  above 110                    Uncomfortable
  ==========================================

  Je stelt de volgende vraag aan de gebruiker:
  Geef het geluidsniveau (dB) in:

  Het antwoord van het programma moet 1 van de 5 percepties zijn op basis van de
  classificatie in de linkse kolom.
*/
void decibelAlarm(void) {
  int decibels = 0;
  printf("Geef het geluidsniveau (dB) in: \n");
  (void)scanf("%d", &decibels);

  if (decibels <= 50) {
    printf(
        "Loudness in Decibels (dB)    "
        "Perception\n==========================================\n");
    printf(
        "50 or lower                  "
        "Quiet\n==========================================\n");
  } else if (decibels <= 70) {
    printf(
        "Loudness in Decibels (dB)    "
        "Perception\n==========================================\n");
    printf(
        "51-70                        "
        "Intrusive\n==========================================\n");
  } else if (decibels <= 90) {
    printf(
        "Loudness in Decibels (dB)    "
        "Perception\n==========================================\n");
    printf(
        "71-90                        "
        "Annoying\n==========================================\n");
  } else if (decibels <= 110) {
    printf(
        "Loudness in Decibels (dB)    "
        "Perception\n==========================================\n");
    printf(
        "91-110                       Very "
        "annoying\n==========================================\n");
  } else {
    printf(
        "Loudness in Decibels (dB)    "
        "Perception\n==========================================\n");
    printf(
        "above 110                    "
        "Uncomfortable\n==========================================\n");
  }
}

/*
  Schrijf een programma dat een plaats vraagt aan de gebruiker en bepaald welke
  prijs overeenkomt met de ingegeven plaats. Plaats    Prijs
  ================
    1        1000
    2         250
    3         100
    4          50
    5          50
    > 5         0
  Maak hierbij gebruik van de conditionele operator (? :).
*/
void seatPrice(void) {
  int price, seat = 0;
  printf("Geef een gewenste zitplaats in:");
  scanf("%d", &seat);

  price = seat == 1   ? 1000
          : seat == 2 ? 250
          : seat == 3 ? 100
          : seat == 4 ? 50
          : seat == 5 ? 50
                      : 0;

  if (price == 0) {
    printf("Your seat is free 💸");
  } else {
    printf(
        "Plaats    Prijs\n================\n  %d    =  "
        "%d💰\n================\n",
        seat, price);
  }
}

/*
  Maak een programma dat bepaalt of een character ingegeven door de gebruiker
  een hoofdletter is of een kleine letter is. Voorbeeld
  =========
  Geef een karakter in: B
  Het character B is Upper Case

  Geef een karakter in: t
  Het character t is Lower Case

  Geef een karakter in: &
  Het character & is geen letter
*/
void charCapitalChecker(void) {
  char character;
  printf("Give a character:");
  scanf("%c", &character);

  if (islower(character)) {
    printf("var1 = |%c| is lowercase character\n", character);
  } else {
    printf("var1 = |%c| is uppercase character\n", character);
  }
}

/*
 * Maak een programma, van scratch, dat de geboorte datum van een persoon neemt
 * en het volgende doet. Als de geboorte datum voor 1987 is          print
 * "Dinosaurus". Als de geboorte datum na 1987 is            print "Baby". Als
 * de geboorte datum gelijk is aan 1987 is print "Birthyear of God".
 *
 *       | "Dinosaurus"         if X < 1987
 * |X| = | "Baby"               if X > 1987
 *       | "Birthyear of God"   if X = 1987
 *
 * Om input te krijgen gebruik de volgende snippet code.
 * int geboorte_jaar = 0;
 * (void)scanf("%d", &geboorte_jaar);
 *
 * Om de output te printen kan je printf("..."); in de truthy statement block
 * gebruiken.
 */
void dinoYear(void) {
  int birthYear;

  printf("Give me your birth year");
  scanf("%d", &birthYear);

  if (birthYear < 1987) {
    printf("Dinosaurus ");
  } else if (birthYear > 1987) {
    printf("Baby 🤡 ");
  } else if (birthYear == 1987) {
    printf("Birthyear of God 🤐😮");
  }
}

// Zorg dat het programma stopt na 10 pogingen of wanneer 21 werd ingegeven…
void programStop(void) {
  int n, counter = 0;
  printf("Give some numbers");
  (void)scanf("%d", &n);

  if (n == 21) exit(1);

  while (n != 21 && counter < 10) {
    printf("U gaf als getal %d : %d in\n", counter, n);
    counter++;
    (void)scanf("%d", &n);
  }
  printf("\n");
}

/*
  Schrijf een programma dat de volledige ASCII tabel uit print (char dec hex
  octal). De even waarden in de linkse kolom. De oneven waarden in de rechtse
  kolom. De eerste 32 waarden en 127 hebben geen printbaar karakter, print
  hiervoor een “spatie” char dec   hex | char dec   hex | char dec   hex | char
  dec   hex
    -------------------------------------------------------------------
        0     0 |        1   0x1 |        2   0x2 |        3   0x3 |
        4   0x4 |        5   0x5 |        6   0x6 |        7   0x7 |
        8   0x8 |        9   0x9 |       10   0xa |       11   0xb |
        12   0xc |       13   0xd |       14   0xe |       15   0xf |
        16  0x10 |       17  0x11 |       18  0x12 |       19  0x13 |
        20  0x14 |       21  0x15 |       22  0x16 |       23  0x17 |
        24  0x18 |       25  0x19 |       26  0x1a |       27  0x1b |
        28  0x1c |       29  0x1d |       30  0x1e |       31  0x1f |
        32  0x20 |   !   33  0x21 |   "   34  0x22 |   #   35  0x23 |
    $   36  0x24 |   %   37  0x25 |   &   38  0x26 |   '   39  0x27 |
    (   40  0x28 |   )   41  0x29 |   *   42  0x2a |   +   43  0x2b |
    ,   44  0x2c |   -   45  0x2d |   .   46  0x2e |   /   47  0x2f |
    0   48  0x30 |   1   49  0x31 |   2   50  0x32 |   3   51  0x33 |
    4   52  0x34 |   5   53  0x35 |   6   54  0x36 |   7   55  0x37 |
    8   56  0x38 |   9   57  0x39 |   :   58  0x3a |   ;   59  0x3b |
    <   60  0x3c |   =   61  0x3d |   >   62  0x3e |   ?   63  0x3f |
    @   64  0x40 |   A   65  0x41 |   B   66  0x42 |   C   67  0x43 |
    etc
*/
void asciiTable(void) {
  int counter = 0;
  printf(
      "char dec   hex | char dec   hex | char dec   hex | char dec   hex\n"
      "-------------------------------------------------------------------\n");
  while (counter <= 126) {
    for (int i = 0; i < 4; i++) {
      printf("  %c  %3d  %#4x | ",
             counter <= 32    ? ' '
             : counter == 127 ? ' '
                              : counter,
             counter, counter);
      counter++;
    }
    printf("\n");
  }
}

/*
  Maak een programma dat het volgende print:
  0
  0 1
  0 1 2
  0 1 2 3
  0 1 2 3 4
  0 1 2 3 4 5
  0 1 2 3 4 5 6
  0 1 2 3 4 5 6 7
  0 1 2 3 4 5 6 7 8
  0 1 2 3 4 5 6 7 8 9
  0 1 2 3 4 5 6 7 8
  0 1 2 3 4 5 6 7
  0 1 2 3 4 5 6
  0 1 2 3 4 5
  0 1 2 3 4
  0 1 2 3
  0 1 2
  0 1
  0
*/
void piramid(void) {
  int width;
  printf("Give me the length of you flagg");
  scanf("%d", &width);

  for (int i = 0; i < width; i++) {
    for (int j = 0; j <= i; j++) {
      printf("%d", j);
    }
    printf("\n");
  }

  for (int i = width - 2; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
      printf("%d", j);
    }
    printf("\n");
  }
}

// Schrijf met behulp van een for-loop een programma dat enkel de oneven
// getallen tussen 1 en 10 afprint door gebruik te maken van het continue
// statement.
void continueLoop(void) {
  for (int i = 0; i <= 10; i++) {
    if (i % 2 != 0) {
      printf("%d\n", i);
    }
  }
}

// Volgend programma moet 2 vierkanten tekenen, eentje van 40 op 60 gevuld met +
// tekens, en eentje van 60 op 40 gevuld met * tekens.
void drawBloks(void) {
  for (int i = 0; i <= 40; i++) {
    for (int j = 0; j <= 60; j++) {
      printf("&");
    }
    printf("\n");
  }

  for (int i = 0; i <= 60; i++) {
    for (int j = 0; j <= 40; j++) {
      printf("$");
    }
    printf("\n");
  }
}

/*
  Schrijf een programma dat de gebruiker om een karakter vraagt en als dit
  karakter een letter is dit karakter omzet naar lower case als het een upper
  case karakter is en vice versa. Maak gebruik van de tolower() en toupper()
  functie. https://cplusplus.com/reference/cctype/tolower/
  https://cplusplus.com/reference/cctype/toupper/
*/
void upperLowercase(void) {
  char character;
  printf("Give me a character: ");
  scanf("%c", &character);

  if (islower(character)) {
    printf("je hebt een lowercase\n");
    printf("je letter in upper |%c|", toupper(character));
  } else {
    printf("het is een upper\n");
    printf("je letter in upper |%c|", tolower(character));
  }
}

/*Maak een lookup tabel voor de sinus functie. Het idee is dat je de sinuswaarde
   elke graden sampelt en dit van 0 graden tot 360 graden. Bijvoorbeeld:
    ```
    sin[0]  = 0
    sin[30] = 1/2
    sin[90] = 1
    ...
    ```
*/
double sinusLookUp(void) {
  float lookUp[SIZE];

  for (int j = 0; j <= SIZE; j++) {
    lookUp[j] = sin(j * M_PI / 180);
  }

  printf(
      "|                        SINUSVALUES                             |\n"
      "+----------------------------------------------------------------+\n");

  for (int i = 0; i <= SIZE; i++) {
    printf("sin[%.3d] =  %.3f  ", i, lookUp[i]);
    if (i % 3 == 0) printf("\n");
  }
}

/*
 Maak een cummulatieve tabel die bijhoudt hoe vaak een gebruiker een geheel
 getal tussen 0 en 20 ingeeft. Als een gebruiker een getal kleiner dan 0 of
 groter dan 20 ingeeft stopt het programma en wordt de cumulatieve tabel als
 volgt geprint: 0: *** 1: ** 2: **** 3: * 4: ****** 5: **** 6: ***** 7: * 8:
 ********* 9: ************ 10: ******** 11:
 ******************************************** 12:
 ************************************** 13: **********************************
    14: ***************
    15: *************************************
    16: ******************************************
    17: ***************************************
    18: ********************************************
    19: *******
    20: ****
*/
void pressedValuesTabel(void) {
  int getallen[21] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int getal = 0;

  while (1) {
    printf("\nGeef getal tussen 0 en 20 : ");
    (void)scanf("%d", &getal);
    printf("\n");

    if (getal == 21) {
      exit(1);
    } else {
      getallen[getal] += 1;
      for (int i = 0; i <= 20; i++) {
        printf("%.2d: ", i);
        for (int j = 0; j < getallen[i]; j++) {
          printf("*");
        }
        printf("\n");
      }
    }
  }
}
/*
 Maak een programma dat 200 willekeurige gehele getallen genereert tussen de 1
 en de 52. Elke keer dat er een willekeurig getal wordt gegenereerd kijk je of
 dit getak al is opgenomen in de array. Als dit niet het geval is resize je de
 array naar de juiste grootte en voeg je het getal toe aan de array. Print je
 resultaat op het einde van je programma. De volgende unieke willekeurige
 getallen werden er gegenereerd: 12
 5
 32
 45
 15
 4
 50
*/
void numbsGenerator(void) {
  int h;
  int a[200];
  int number = 200;

  printf(" \n Entered elements of an array: \n ");

  for (int i = 0; i <= 200; i++) {
    a[i] = rand() % 52 + 1;
  }

  /**
   * for loop to delete the dubble values
   */
  for (int i = 0; i < number; i++) {
    for (int j = i + 1; j < number; j++) {
      if (a[i] == a[j]) {
        for (int k = j; k < number; k++) {
          a[k] = a[k + 1];
        }
        j--;
        number--;
      }
    }
  }

  /**
   * for loop to set the numbers in chronological order
   */
  for (int i = 0; i < number; ++i) {
    for (int j = i + 1; j < number; ++j) {
      if (a[i] > a[j]) {
        h = a[i];
        a[i] = a[j];
        a[j] = h;
      }
    }
  }
  /**
   * for loop to print the array
   */
  printf("array[]: \n");
  for (int i = 0; i < number; i++) {
    printf("|%.2d|\n", a[i]);
  }
  printf("\n");
  return 0;
}

/*
* Maak een 2x3 matrix door gebruik te maken van een 2D array.
* Initialiseer deze array met willekeurige gehele getallen.
* Print dit resultaat. Bereken vervolgens de getransponeerde matrix.
* Print ook dit resultaat.
    De 2x3 matrix is:
    3 5 9
    4 3 8

    De getransponeerde matrix is:
    3 4
    5 3
    9 8
*/
void matrix(void) {
  int a = rand() % 10;
  int b = rand() % 10;
  int c = rand() % 10;
  int d = rand() % 10;
  int e = rand() % 10;
  int ab = rand() % 10;

  int array[2][3] = {{a, b, ab}, {c, d, e}};
  printf("The 2X3 matrix: \n");

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d\t", array[i][j]);
    }
    printf("\n");
  }

  printf("\n");
  printf("The transformed matrix: \n");

  int waarde[3][2] = {{a, c}, {b, d}, {ab, e}};

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%d\t", waarde[i][j]);
    }
    printf("\n");
  }
  return 0;
}

void passwordGenerator(void) {
  int i = 0;
  int randomizer = 0;
  srand((unsigned int)(time(NULL)));

  char numbers[] = "0123456789";
  char letter[] = "abcdefghijklmnoqprstuvwyzx";
  char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
  char symbols[] = "!@#$^&*?£§%:.=+-";
  char password[LENGHT];

  randomizer = rand() % 4;

  printf("| Your new password       ");

  for (i = 0; i < LENGHT; i++) {
    if (randomizer == 1) {
      password[i] = numbers[rand() % 10];
      randomizer = rand() % 4;
      printf("%c", password[i]);
    } else if (randomizer == 2) {
      password[i] = symbols[rand() % 8];
      randomizer = rand() % 4;
      printf("%c", password[i]);
    } else if (randomizer == 3) {
      password[i] = LETTER[rand() % 26];
      randomizer = rand() % 4;
      printf("%c", password[i]);
    } else {
      password[i] = letter[rand() % 26];
      randomizer = rand() % 4;
      printf("%c", password[i]);
    }
  }
  return 0;
}

/*
 * Genereer 20 willekeurige gehele getallen tussen -500 en 500 die je opslaat in
 * een array. Bereken dan de som, het minimum, het maximum en het gemiddelde van
 * deze 20 willekeurige gehele getallen.
 */
void calculationOfRandArr(void) {
  srand(time(NULL));

  int arrays[20];
  int som = 0;
  float average = 0;

  for (int i = 0; i <= 20; i++) {
    arrays[i] = -500 + rand() % (1000);
  }

  for (int i = 0; i <= 20; i++) {
    som = som + arrays[i];
    average = som / 20;
    printf("%d\n", arrays[i]);
  }

  int min = 0, max = 0;

  if (20 == 1) {
    min = max = arrays[0];
  }
  if (arrays[0] > arrays[1]) {
    max = arrays[0];
    min = arrays[1];
  } else {
    max = arrays[1];
    min = arrays[0];
  }

  for (int i = 2; i < 20; i++) {
    if (arrays[i] > max)
      max = arrays[i];
    else if (arrays[i] < min)
      min = arrays[i];
  }

  printf("the sum is %d\n", som);
  printf("the average is %.1f\n", average);
  printf(" Minimum element: %d\n", min);
  printf(" Maximum element: %d\n", max);

  return 0;
}

/* Schrijf een programma dat een gebruiker om zijn naam vraagt.
 * Deze naam inleest en opslaat in een string en vervolgens terug afdrukt.
 * Zorg ervoor dat spaties in de naam ook toegelaten zijn.
 * (HINT: [fgets()](https://cplusplus.com/reference/cstdio/fgets/))
    Gebruikersnaam: Wout Swinkels
    Ingegeven gebruikersnaam: Wout Swinkels
 */
void usernameString(void) {
  char userName[200];

  printf("Hello, what's your name\n");
  fgets(userName, 200, stdin);
  printf("%s", userName);
  return 0;
}

/*
 * Schrijf een programma dat een gebruiker een reeks namen laat ingeven.
 * Als de gebruiker het woord <em>stop</em> ingeeft dien je de lijst met namen
 alfabetisch te ordenen en af te drukken.
 * Druk ook apart af welke de langste en korste naam is en uit hoeveel karakters
 deze zijn opgebouwd. Geef een naam: Wout Bryan Bart Stef Pieter-Jan Brent Jo
    stop

    De namen lijst in alfabetische volgorde is:
    Bart
    Brent
    Bryan
    Jo
    Pieter-Jan
    Stef
    Wout

    De langste naam is Pieter-Jan en is opgebouwd uit 10 karakters.
    De korste naam is Jo en is opgebouwd uit 2 karakters.
 */
void listOfUserName(void) {
  char temp[8];
  printf("Please enter put FILE_NAME (foo1, 2, or 3), ls, or exit: \n");

  do {
    (void)scanf(" %s", zin[woord++]);
  } while (strcmp(zin[woord - 1], "over") != 0);
}

void textCappitalToLower(void) {
  char input[500];

  printf("Welcome!\n");
  printf("\nGeef een zin: ");

  fgets(input, 500, stdin);

  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] >= 'a' && input[i] <= 'z') {
      input[i] = input[i] - 32;
    } else if (input[i] >= 'A' && input[i] <= 'Z') {
      input[i] = input[i] + 32;
    }
  }
  printf("De nieuwe zin is: ");
  puts(input);
  return 0;
}

/*
 * Schrijf een programma dat een zin ingegeven door de gebruiker leest en de
 woorden afzonderlijk onder elkaar afdrukt. Geef een zin: Deze woorden dienen
 onder elkaar geprint te worden. Deze woorden dienen onder elkaar geprint te
    worden.
*/
void sentenceSplitter(void) {
  char textInput[500];

  printf("Welcome!\n");
  printf("\nGeef een zin: \n");
  fgets(textInput, 500, stdin);

  for (int i = 0; textInput[i] != '\n'; i++) {
    if (textInput[i] == ' ') textInput[i] = '\n';
  }

  printf("De nieuwe zin is: ");
  puts(textInput);
  return 0;
}

/*
 * Schrijf een programma dat nagaat of een woord ingegeven door de gebruiker een
 [palindroom](https://nl.wikipedia.org/wiki/Palindroom) is. Voorbeelden:
 racecar, kok, lepel, koortsmeetsysteemstrook, ….

    Geef een woord: PXL
    PXL is geen palindroom.
    Geef een woord: lepel
    lepel is een palindroom.
*/
void textReverser(void) {
  char userWordToCheck[20];

  printf("Give me a word: ");
  scanf("%s", userWordToCheck);

  int i, length;
  int compere = 0;
  length = strlen(userWordToCheck);

  for (i = 0; i < length; i++) {
    if (userWordToCheck[i] != userWordToCheck[length - i - 1]) {
      compere = 1;
      break;
    }
  }

  if (compere == 1) {
    printf("%s string is not a palindrome", userWordToCheck);
  } else {
    printf("%s string is a palindrome", userWordToCheck);
  }
  return 0;
}

/*
 * Schrijf een programma waarbij een kommagetal operator kommagetal wordt
 * ingegeven. Maak de switch case op basis van de operator waarbij de +, -, / en
 * * de overeenkomstige operatie uitvoert. Begin met een flowchart op te
 * stellen.
 */
void calculatorSwitch(void) {
  int firstNumber, secondNumber, thirdNumber;
  float result;
  char operator;

  printf("Which operator do you want (+,-,/,*)?: ");
  (void)scanf("%c", &operator);

  printf("Give me your first number: ");
  (void)scanf("%d", &firstNumber);
  getchar();
  printf("Give me your second number: ");
  (void)scanf("%d", &secondNumber);

  switch (operator) {
    case '+':
      result = firstNumber + secondNumber;
      printf("Your som is %f", result);
      break;
    case '-':
      result = firstNumber - secondNumber;
      printf("Your difference is %f", result);
    case '/':
      if (secondNumber == 0) {
        printf("This isn't possible!\n Give me a new number: ");
        (void)scanf("%d", &thirdNumber);
        result = firstNumber / thirdNumber;
        printf("Your result is %f", result);
      }
      result = firstNumber / secondNumber;
      printf("Your result is %f", result);
      break;
    case '*':
      result = firstNumber * secondNumber;
      printf("Your difference is %d", result);
      break;
  }
  return 0;
}

/*
 * Schrijf een programma dat het aantal dagen berekent tussen twee gegeven
 * datums (steeds dag, maand, dag, maand). Geef een melding als de datums niet
 * in de juiste volgorde staan. Maak gebruik van een enum voor de maanden om de
 * code leesbaar te houden. Maak gebruik van een switch case in een aparte
 * functie om het aantal dagen in een maand terug te geven. Begin met een
 * flowchart op te stellen.
 */
void calendar(void) {
  char* months[] = {"jan", "feb", "mar", "apr", "may", "jun",
                    "jul", "aug", "sep", "oct", "nov", "dec"};
  char str[4];
  int startingDay, deadlineDay, timeToDeadline, monthToDeadline, i, k, month1,
      month2 = 0;

  printf("\n");
  printf("Give me Your Current Month (type first 3 letters): ");
  scanf("%s", str);
  printf("\n");
  printf("|        %s       |\n--------------------\n", str);

  for (int j = 1; j <= 31; j++) {
    printf("%.2d ", j);
    if (j % 7 == 0) {
      printf("\n");
    }
  }

  printf("\n\nGive me your current day: ");
  (void)scanf("%d", &startingDay);

  for (i = 0; i < 12; i++) {
    if (!strcmp(str, months[i])) {
      month1 = (i + 1);
      printf("\n\nYour current date is:\n %.2d / %.2d / 2023 ", startingDay,
             month1);
    }
  }

  printf("\n\n\t - Give me your deadline day and month:");
  (void)scanf("%d %s", &deadlineDay, str);
  for (k = 0; k < 12; k++) {
    if (!strcmp(str, months[k])) {
      month2 = (k + 1);
      printf("\n\nYour deadline is:\n %.2d / %.2d / 2023 ", deadlineDay,
             month2);
      timeToDeadline = (deadlineDay - startingDay);
      monthToDeadline = (month2 - month1);

      printf("\n\n\t - You still have %.2d days and %d months", timeToDeadline,
             monthToDeadline);
    }
  }
}

/*
 * Schrijf een programma dat een bankautomaat emuleert.
 * Maak gebruik van de volgende states: Idle_State, Card_Inserted_State,
 * Pin_Entered_State, Option_Selected_State, Check_Balance_State,
 * Withdraw_Money_State, Amount_Entered_State en Eject_Card_State. Vanuit de
 * option state heb je de mogelijkheid om naar check balance state, withdraw
 * money state of eject card state. Bonus: probeer bij withdraw money state
 * nogmaals de pin te vragen voor extra verificatie door efficient met bestaande
 * code om te gaan. Begin met een flowchart op te stellen.
 */
void ATMMachine(void) {
  int Option_Selected_State, Withdraw_Money_State;
  int Pin_Entered_State = 0;
  float Check_Balance_State = 87021.21, Amount_Entered_State;

  printf("ENTER YOUR SECRET PIN NUMBER:");
  scanf("%d", &Pin_Entered_State);
  if (Pin_Entered_State != 3839) {
    printf("PLEASE ENTER VALID PASSWORD\n");
    printf("ENTER YOUR SECRET PIN NUMBER:");
    scanf("%d", &Pin_Entered_State);
  }

  while (Pin_Entered_State == 3839) {
    printf("\n******** Welcome to ATM Service **************\n");
    printf("\t - 1. Check Balance\n");
    printf("\t - 2. Withdraw Cash\n");
    printf("\t - 3. Deposit Cash\n");
    printf("\t - 4. Quit\n");
    printf("*********************************************\n\n");
    printf("Enter your choice: ");
    scanf("%d", &Option_Selected_State);
    switch (Option_Selected_State) {
      case 1:
        printf(
            "+-----------------------------------------+\n |\t        Balance "
            "State       \t  |\n |"
            " Your money on your account is %.2f $ | \n "
            "+-----------------------------------------+",
            Check_Balance_State);
        break;
      case 2:
        printf("\n ENTER THE AMOUNT TO WITHDRAW: ");
        scanf("%lu", &Withdraw_Money_State);
        printf("TO DO THIS ENTER YOUR PIN");
        scanf("%d", &Pin_Entered_State);
        if (Pin_Entered_State == 3839) {
          if (Withdraw_Money_State % 100 != 0) {
            printf("\n PLEASE ENTER THE AMOUNT IN MULTIPLES OF 100");
          } else if (Withdraw_Money_State > (Check_Balance_State - 500)) {
            printf("\n INSUFFICENT BALANCE");
          } else {
            Check_Balance_State = Check_Balance_State - Withdraw_Money_State;
            printf("\n\n PLEASE COLLECT CASH");
            printf("\n YOUR CURRENT BALANCE IS $%.2f ", Check_Balance_State);
          }
        }
        break;
      case 3:
        printf("\n ENTER THE AMOUNT TO DEPOSIT: ");
        scanf("%f", &Amount_Entered_State);
        Check_Balance_State = Check_Balance_State + Amount_Entered_State;
        printf("\nYOUR BALANCE IS $ %.2f\n", Check_Balance_State);
        break;
      case 4:
        printf("\n THANK U USING OUR ATM\n PLS TAKE YOUR CARD");
        exit(1);
        break;
    }
  }
}

int hogerLagerSpel(int searchNumber) {
  int playerGuess;
  int playerTry;
  while (playerGuess != searchNumber) {
    printf("PUT YOUR GUESS [1, 100]:\n ");
    (void)scanf("%d", &playerGuess);
    if (playerGuess == searchNumber) {
      printf("Well done you found the seed !!\n");
      break;
    }
    if (playerGuess < searchNumber) {
      printf("YOUR NUMBER IS TO LOW\n");
      playerTry++;
    } else {
      printf("YOUR NUMBER IS TO HIGH\n");
      playerTry++;
    }
  }
  return playerTry;
}

/*
    Maak het spel hoger lager waarbij een random geheel getal tussen 0 en 100
   gegenereerd wordt, en de gebruiker dit getal moet raden. Schrijf de game
   logic in een aparte functie genaamd hogerLagerSpel() die je oproept vanuit de
   main. Het return type van de functie hogerLagerSpel() dient een integer te
   zijn die aangeeft hoeveel pogingen nodig waren om het getal te raden.
*/
void searchMyNumber(void) {
  int searchNumber;
  srand(time(NULL));
  searchNumber = rand() % 100;

  int totalGuesses = hogerLagerSpel(searchNumber);
  printf(" YOU HAD %d TRY'S USED\n\n", totalGuesses + 1);
}

void print_byte(uint8_t byte) {
  static const char* nibble_lookup[16] = {
      [0x0] = "0000", [0x1] = "0001", [0x2] = "0010", [0x3] = "0011",
      [0x4] = "0100", [0x5] = "0101", [0x6] = "0110", [0x7] = "0111",
      [0x8] = "1000", [0x9] = "1001", [0xA] = "1010", [0xB] = "1011",
      [0xC] = "1100", [0xD] = "1101", [0xE] = "1110", [0xF] = "1111"};
  printf("%s %s", nibble_lookup[byte >> 4], nibble_lookup[byte & 0x0F]);
}

int main() {
  int decission;
  printf(
      "Press on: \n\t - 1 to open averageProgram\n\t - 2 to open "
      "calculator\n\t - 3 to open decibelAlarm\n\t - 4 to open seatPrice\n\t - "
      "5 to open charCapitalChecker\n\t - 6 to open dinoYear\n\t - 7 to open "
      "programStop\n\t - 8 to open asciiTable\n\t - 9 to build a Piramid\n\t "
      "- 10 to open continueLoop\n\t - 11 to draw a blok\n\t - 12 to check and "
      "replace upper/lower\n\t - 13 to see the sin look up table"
      "\n\t - 14 to your pressed values\n\t - 15 to store som values in an "
      "array\n\t - 16 to open array\n\t - 17 to create a password\n\t "
      "- 18 to calculate a array\n\t - 19 to ask username in string\n\t - 20 "
      "to list usernames\n\t - 21 to set a sentence to capital"
      "\n\t - 22 to set a sentence to splitted\n\t - 23 to reverse a "
      "sentence\n\t - 24 To calculate operators\n\t "
      "- 25 To open your calendar\n\t - 26 to go to the ATM\n\t - 27 to play a "
      "numberguess game\n");
  scanf("%d", &decission);

  switch (decission) {
    case 1:
      averageProgram();
      main();
      break;
    case 2:
      calculator();
      main();
      break;
    case 3:
      decibelAlarm();
      main();
      break;
    case 4:
      seatPrice();
      main();
      break;
    case 5:
      getchar();
      charCapitalChecker();
      main();
      break;
    case 6:
      dinoYear();
      main();
      break;
    case 7:
      programStop();
      main();
      break;
    case 8:
      asciiTable();
      main();
      break;
    case 9:
      piramid();
      main();
      break;
    case 10:
      continueLoop();
      main();
      break;
    case 11:
      drawBloks();
      main();
      break;
    case 12:
      getchar();
      upperLowercase();
      main();
      break;
    case 13:
      sinusLookUp();
      main();
      break;
    case 14:
      pressedValuesTabel();
      main();
      break;
    case 15:
      numbsGenerator();
      main();
      break;
    case 16:
      matrix();
      break;
    case 17:
      passwordGenerator();
      break;
    case 18:
      calculationOfRandArr();
      break;
    case 19:
      getchar();
      usernameString();
      break;
    case 20:
      getchar();
      listOfUserName();
      break;
    case 21:
      getchar();
      textCappitalToLower();
      break;
    case 22:
      getchar();
      sentenceSplitter();
      break;
    case 23:
      getchar();
      textReverser();
      break;
    case 24:
      getchar();
      calculatorSwitch();
      break;
    case 25:
      getchar();
      calendar();
      break;
    case 26:
      getchar();
      ATMMachine();
      break;
    case 27:
      getchar();
      searchMyNumber();
      break;
  }

  printf("\n\n\n");

  return 0;
}