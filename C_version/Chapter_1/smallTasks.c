#include <stdint.h>
#include <stdio.h>

/*
 * # Oefening 1
 * program rotary 13 encoder:
 * wanneer er een woord ingeeft gaat die dat vervangen door het getal dat 13
 * plaatsen achter het letter staat en kunnen decoden
 *
 * # Oefening 1.2
 * program een piramide boven naar onder (1  ster  vanboven naar meerdere met
 * ingegeven lijnen groot)
 *
 * # Oefening 1.2
 * fibonatichi
 *
 * # Oefening 2
 * pariteitsgenerator, geef een getal in en programmeer dat het even of oneven
 * maakt en je print de uitkomst als binair
 *
 */

/*
 * function to create the numbers to an binairy value.
 */
void print_byte(uint8_t byte) {
  static const char* nibble_lookup[16] = {
      [0x0] = "0000", [0x1] = "0001", [0x2] = "0010", [0x3] = "0011",
      [0x4] = "0100", [0x5] = "0101", [0x6] = "0110", [0x7] = "0111",
      [0x8] = "1000", [0x9] = "1001", [0xA] = "1010", [0xB] = "1011",
      [0xC] = "1100", [0xD] = "1101", [0xE] = "1110", [0xF] = "1111"};
  printf("%s %s", nibble_lookup[byte >> 4], nibble_lookup[byte & 0x0F]);
}

void print_bits(uint64_t data, uint8_t bits) {
  while (bits-- > 0) {
    (void)putchar(((data >> bits) & 0x1) + '0');
  }
}

void rotaryEncoderString(void) {
  int operatorChoice;
  char encoding[20], encoder[20], decoding[20];

  // Asks the user for what operation needs to be done.
  printf("WHAT OPERATOR WILL YOU DO?: \n\t - 1: Encoding \n\t - 2: Decoding");
  (void)scanf("%d", &operatorChoice);

  switch (operatorChoice) {
    case 1:
      getchar();  // getchar to fix the right letter-input.
      printf(
          "THIS WILL ADD 13 PLACES AND GIVES THE FINAL NUMBER.\n GIVE ME YOU "
          "LETTER: ");
      (void)scanf("%s", &encoding);

      // +13 to set the letter 13 place forward in the ascii tabel
      for (int i = 0; encoding[i] != '\0'; i++) {
        if (encoding[i] >= 'a' && encoding[i] <= 'z') {
          encoding[i] = encoding[i] + 13;
        } else if (encoding[i] >= 'A' && encoding[i] <= 'Z') {
          encoding[i] = encoding[i] + 13;
        }
      }
      printf("De nieuwe zin is: ");
      puts(encoding);
      break;
    case 2:
      getchar();  // getchar to fix the right letter-input.
      printf(
          "THIS WILL RETURN 13 PLACES AND GIVES THE FINAL NUMBER.\n GIVE ME "
          "YOU LETTER: ");
      fgets(decoding, 20, stdin);

      // -13 to set the letter 13 place back in the ascii tabel
      for (int i = 0; decoding[i] != '\0'; i++) {
        if (decoding[i] >= 'a' && decoding[i] <= 'z') {
          decoding[i] = decoding[i] - 13;
        } else if (decoding[i] >= 'A' && decoding[i] <= 'Z') {
          decoding[i] = decoding[i] - 13;
        }
      }
      printf("De nieuwe zin is: ");
      puts(decoding);
      break;
  }
}

void christmasTree(void) {
  int LENGHT;
  char sign;

  printf("HOW BIG DO YOU WANT THE TREE?");
  (void)scanf("%d", &LENGHT);
  printf("WHAT SIGN DO YOU LIKE (* $ % @)?");
  getchar();
  (void)scanf("%c", &sign);

  for (int i = 0; i < LENGHT; i++) {
    for (int k = i; k <= LENGHT; k++) {
      printf(" ");
    }
    for (int j = 0; j <= i; j++) {
      printf("%c ", sign);
    }
    printf("\n");
  }
}

void fibonatchi(void) {
  int startNumber = 0;
  int userMax = 0;
  int lastSaved = 0;
  int telled = 1;

  // 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597,
  // 2584, 4181, 6765, 10946, ...

  printf("GIVE ME YOUR MAX NUMBER");
  (void)scanf("%d", &userMax);
  printf("%d ", lastSaved);

  while (lastSaved < userMax) {
    printf("%d ", telled);
    startNumber = telled;
    telled += lastSaved;
    lastSaved = startNumber;
  }
}

void paritySet(void) {
  int userInputNumber, evenParity, oddParity, userOperator;
  int countr = 0;

  // asks user to give the start number
  printf("GIVE ME A NUMBER: ");
  (void)scanf("%d", &userInputNumber);

  printf("\nYOUR INPUT IS THE NUMBER %d\n", userInputNumber);

  // print_byte is setting the start number into an binary value.
  printf("YOUR NUMBER IN BINARY: ");
  print_byte(userInputNumber);

  // to check if the userinput is even or odd
  printf(userInputNumber % 2 == 0 ? " is even." : " is odd.");

  printf("WHAT DO YOU WANT TO MAKE?\n\t - 1: EVEN\n\t - 2: ODD");
  (void)scanf("%d", &userOperator);

  switch (userOperator) {
    case 1:
      // Adds a 1 to set a 1 prioritybit
      if (userInputNumber % 2 == 0) {
        putchar('1');
      } else {
        putchar('0');
      }
      print_byte(userInputNumber);
      break;
    case 2:
      // Adds a 0 to set a 0 prioritybit
      if (userInputNumber % 2 != 0) {
        putchar('1');
      } else {
        putchar('0');
      }
      print_byte(userInputNumber);
      break;
  }
}

int main() {
  int menuChoise;

  printf(
      "GIVE ME YOUR CHOICE\n\t - 1: RotaryEncoder\n\t - 2: ParitySet\n\t - 3: "
      "christmastree\n\t - 4: fibonacci\n");
  (void)scanf("%d", &menuChoise);

  switch (menuChoise) {
    case 1:
      getchar();
      rotaryEncoderString();
      break;
    case 2:
      paritySet();
      break;
    case 3:
      christmasTree();
      break;
    case 4:
      fibonatchi();
      break;
  }
  return 0;
}
