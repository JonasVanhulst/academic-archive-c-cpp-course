#ifdef _WIN32
#define _WIN32_WINNT _WIN32_WINNT_WIN7
#include <stdio.h>     //for fprintf, perror
#include <stdlib.h>    //for exit
#include <string.h>    //for memset
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
void OSInit(void) {}
void OSCleanup(void) {}
#endif

#define RECEIVING_PACKAGE 10

int initialization(struct sockaddr** internet_address,
                   socklen_t* internet_address_length);
void execution(int internet_socket, struct sockaddr* internet_address,
               socklen_t internet_address_length);
void cleanup(int internet_socket, struct sockaddr* internet_address);

int main(int argc, char* argv[]) {
  //////////////////
  // Initialization//
  //////////////////

  OSInit();

  struct sockaddr* internet_address = NULL;
  socklen_t internet_address_length = 0;
  int internet_socket =
      initialization(&internet_address, &internet_address_length);

  /////////////
  // Execution//
  /////////////

  execution(internet_socket, internet_address, internet_address_length);

  ////////////
  // Clean up//
  ////////////

  cleanup(internet_socket, internet_address);

  OSCleanup();

  return 0;
}

int initialization(struct sockaddr** internet_address,
                   socklen_t* internet_address_length) {
  // Step 1.1
  struct addrinfo internet_address_setup;
  struct addrinfo* internet_address_result;
  memset(&internet_address_setup, 0, sizeof internet_address_setup);
  internet_address_setup.ai_family = AF_UNSPEC;
  internet_address_setup.ai_socktype = SOCK_DGRAM;
  int getaddrinfo_return = getaddrinfo("::1", "24042", &internet_address_setup,
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
      *internet_address_length = internet_address_result_iterator->ai_addrlen;
      *internet_address = (struct sockaddr*)malloc(
          internet_address_result_iterator->ai_addrlen);
      memcpy(*internet_address, internet_address_result_iterator->ai_addr,
             internet_address_result_iterator->ai_addrlen);
      break;
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

void execution(int internet_socket, struct sockaddr* internet_address,
               socklen_t internet_address_length) {
  // Step 2.1
  char str[10];
  char buffer[50];
  char startByUser[10];

  int largestNumber = -1;  // initialize largestNumber outside the loop
  int number_of_bytes_received, number_of_bytes_send = 0;

  printf(
      " __| |____________________________________________| |__\n"
      "(__   ____________________________________________   __)\n"
      "   | |         Welcome to the UDP world           | |\n"
      "   | |                                            | |\n"
      "   | |   - To start we ask u to enter GO          | |\n"
      "   | |          - else the programm won't start   | |\n"
      "   | |                                            | |\n"
      "   | |                                            | |\n"
      "__ | |____________________________________________| |__\n"
      "(__   ____________________________________________   __)\n"
      "   | |                                            | |\n"
      "\n\n Enter : ");

  (void)scanf("%s", startByUser);
  if (strcmp(startByUser, "GO") == 0) {
    sendto(internet_socket, startByUser, sizeof(startByUser), 0,
           internet_address,
           internet_address_length);  // to start the communication send "GO"

    do {
      int largestNumberList1 = -1;
      int largestNumberList2 = -1;

      for (int i = 1; i <= RECEIVING_PACKAGE; i++) {
        number_of_bytes_received =
            recvfrom(internet_socket, buffer, sizeof(buffer) - 1, 0,
                     internet_address, &internet_address_length);
        buffer[number_of_bytes_received] = '\0';
        printf("\n\n");

        if (number_of_bytes_received == -1) {
          break;
        };

        if (strcmp(buffer, "OK") == 0) {
          printf("Received[%d]: %s\n", i, buffer);
          exit(EXIT_FAILURE);
        }

        printf("Received[%d]: %d\n", i, ntohl(*((int*)buffer)));

        int temp = ntohl(*((int*)buffer));

        if (i < RECEIVING_PACKAGE) {
          if (temp > largestNumberList1) {
            largestNumberList1 = temp;
          }
        } else {
          if (temp > largestNumberList2) {
            largestNumberList2 = temp;
          }
        }
      }

      // determine which list had the larger number
      if (largestNumberList1 > largestNumberList2) {
        largestNumber = largestNumberList1;
      } else {
        largestNumber = largestNumberList2;
      }

      // send the largest number of both lists
      for (int i = 0; i < 3; i++) {
        sendto(internet_socket, (const char*)&largestNumber,
               sizeof(largestNumber), 0, internet_address,
               internet_address_length);
      }
      printf("\n\nSecond List\n\n");
    } while (number_of_bytes_received != 0);
  } else {
    exit(EXIT_FAILURE);
  }

  // Step 2.2
}

void cleanup(int internet_socket, struct sockaddr* internet_address) {
  // Step 3.2
  free(internet_address);

  // Step 3.1
  close(internet_socket);
}