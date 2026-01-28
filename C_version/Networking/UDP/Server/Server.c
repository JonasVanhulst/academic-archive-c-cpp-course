#ifdef _WIN32
#define _WIN32_WINNT _WIN32_WINNT_WIN7
#include <stdio.h>     //for fprintf, perror
#include <stdlib.h>    //for exit
#include <string.h>    //for memset
#include <time.h>      //for timeseeds
#include <unistd.h>    //for close
#include <winsock2.h>  //for all socket programming
#include <ws2tcpip.h>  //for getaddrinfo, inet_pton, inet_ntop
void OSInit(void) {
  WSADATA wsaData;
  int WSAError = WSAStartup(MAKEWORD(2, 0), &wsaData);
  if (WSAError != 0) {
    fprintf(stderr, "WSAStartup errno = %d\n", WSAError);
    exit(-1);
  }
}
void OSCleanup(void) { WSACleanup(); }
#define perror(string) \
  fprintf(stderr, string ": WSA errno = %d\n", WSAGetLastError())
#else
#include <arpa/inet.h>   //for htons, htonl, inet_pton, inet_ntop
#include <errno.h>       //for errno
#include <netdb.h>       //for getaddrinfo
#include <netinet/in.h>  //for sockaddr_in
#include <stdio.h>       //for fprintf, perror
#include <stdlib.h>      //for exit
#include <string.h>      //for memset
#include <sys/socket.h>  //for sockaddr, socket, socket
#include <sys/types.h>   //for size_t
#include <unistd.h>      //for close
int OSInit(void) {}
int OSCleanup(void) {}
#endif

#define WANTED_PACKAGE 2
#define SENDING_PACKAGE 10

int initialization();
void execution(int internet_socket);
void cleanup(int internet_socket);

int main(int argc, char* argv[]) {
  //////////////////
  // Initialization//
  //////////////////

  OSInit();

  int internet_socket = initialization();

  /////////////
  // Execution//
  /////////////

  execution(internet_socket);

  ////////////
  // Clean up//
  ////////////

  cleanup(internet_socket);

  OSCleanup();

  return 0;
}

int initialization() {
  // Step 1.1
  struct addrinfo internet_address_setup;
  struct addrinfo* internet_address_result;
  memset(&internet_address_setup, 0, sizeof internet_address_setup);
  internet_address_setup.ai_family = AF_UNSPEC;
  internet_address_setup.ai_socktype = SOCK_DGRAM;
  internet_address_setup.ai_flags = AI_PASSIVE;
  int getaddrinfo_return = getaddrinfo(NULL, "24042", &internet_address_setup,
                                       &internet_address_result);
  if (getaddrinfo_return != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(getaddrinfo_return));
    exit(1);
  }

  int internet_socket = -1;
  struct addrinfo* internet_address_result_iterator = internet_address_result;
  while (internet_address_result_iterator != NULL) {
    // Step 1.2
    internet_socket = socket(internet_address_result_iterator->ai_family,
                             internet_address_result_iterator->ai_socktype,
                             internet_address_result_iterator->ai_protocol);
    if (internet_socket == -1) {
      perror("socket");
    } else {
      // Step 1.3
      int bind_return =
          bind(internet_socket, internet_address_result_iterator->ai_addr,
               internet_address_result_iterator->ai_addrlen);
      if (bind_return == -1) {
        close(internet_socket);
        perror("bind");
      } else {
        break;
      }
    }
    internet_address_result_iterator =
        internet_address_result_iterator->ai_next;
  }

  freeaddrinfo(internet_address_result);

  if (internet_socket == -1) {
    fprintf(stderr, "socket: no valid socket address found\n");
    exit(2);
  }

  return internet_socket;
}

void execution(int internet_socket) {
  // Step 2.1

  int randomNumbers[SENDING_PACKAGE];
  int counter, randomNumber1 = 0;
  int number_of_bytes_received, number_of_bytes_send1,
      number_of_bytes_received_data = 0;

  char buffer[1000];
  char dataBuffer[1000];

  struct sockaddr_storage client_internet_address;
  socklen_t client_internet_address_length = sizeof client_internet_address;
  number_of_bytes_received =
      recvfrom(internet_socket, buffer, (sizeof buffer) - 1, 0,
               (struct sockaddr*)&client_internet_address,
               &client_internet_address_length);
  buffer[number_of_bytes_received] = '\0';
  if (number_of_bytes_received == -1) {
    perror("recvfrom");
  } else if (strcmp(buffer, "GO") == 0) {
    printf("Received Start: %s \n", buffer);

    // Step 2.2
    srand(time(NULL));  // time seed for random generation

    int counter = 0;
    int teller = 0;

    while (counter != WANTED_PACKAGE)  // to send the packets the user wants to.
    {
      for (int i = 0; i < SENDING_PACKAGE; i++) {
        randomNumber1 = rand() % 100 + 1;
        randomNumber1 = htonl(randomNumber1);
        randomNumbers[i] = randomNumber1;

        number_of_bytes_send1 = sendto(
            internet_socket, (const char*)&randomNumber1, sizeof(randomNumber1),
            0, (struct sockaddr*)&client_internet_address,
            client_internet_address_length);
      }
      for (int i = 0; i < 3; i++) {
        number_of_bytes_received_data =
            recvfrom(internet_socket, dataBuffer, (sizeof dataBuffer) - 1, 0,
                     (struct sockaddr*)&client_internet_address,
                     &client_internet_address_length);
        if (i == 2) {
          dataBuffer[number_of_bytes_received_data] = '\0';
          printf("%d) Received Largest Element : %d\n", counter, *dataBuffer);

          printf("\t\t ->Max is correct! \n");
        }
      }
      counter++;
    }
    number_of_bytes_send1 = sendto(internet_socket, "OK", 4, 0,
                                   (struct sockaddr*)&client_internet_address,
                                   client_internet_address_length);
  } else {
    printf("No Valid Chose !");
    exit(EXIT_FAILURE);
  }

  // Step 2.2
  int number_of_bytes_send = 0;
  number_of_bytes_send = sendto(internet_socket, "Hello UDP world!", 16, 0,
                                (struct sockaddr*)&client_internet_address,
                                client_internet_address_length);
  if (number_of_bytes_send == -1) {
    perror("sendto");
  }
}

void cleanup(int internet_socket) {
  // Step 3.1
  close(internet_socket);
}