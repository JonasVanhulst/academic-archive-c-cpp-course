//
// Created by Vanhuljo on 12/06/2023.
//
// Write a program in C to create and display a Singly Linked List.
//

#include <stdio.h>
#include <stdlib.h>

struct nodelist {
  int numbers;            // Data of the node
  struct nodelist* next;  // Address of the next node
}* stnote;

// function to create the list
void createLinkedList(int size) {
  struct nodelist *fnnode, *temp;
  int num = 0;

  stnote = (struct nodelist*)malloc(sizeof(struct nodelist));

  // check whether the stnode is NULL and if so no memory allocation
  if (stnote == NULL) {
    printf("Memory Failed by creating\n");
    exit(EXIT_FAILURE);
  } else {
    printf("Give me your first number for node 1: ");
    (void)scanf("%d", &num);

    stnote->numbers = num;
    stnote->next = NULL;  // links the address field to NULL
    temp = stnote;

    for (int j = 2; j <= size; j++) {
      fnnode = (struct nodelist*)malloc(sizeof(struct nodelist));

      if (fnnode == NULL) {
        printf("Memory Failed by creating\n");
        exit(EXIT_FAILURE);
      } else {
        printf("Give me you %d node pls: ", j);
        (void)scanf("%d", &num);

        fnnode->numbers = num;  // links the num field of fnNode with num
        fnnode->next = NULL;    // links the address field of fnNode with NULL

        temp->next = fnnode;  // links previous node i.e. tmp to the fnNode
        temp = temp->next;
      }
    }
  }
};

// function to display the list
void displayList() {
  struct nodelist* temp;

  if (stnote == NULL) {
    printf("[Info] - Linked list is empty! \n");
    exit(EXIT_FAILURE);
  } else {
    temp = stnote;
    while (temp != NULL) {
      printf("The values are: %d \n", temp->numbers);
      temp = temp->next;
    }
  }
};

int main() {
  int nodes = 0;

  printf("Give me te nodes: ");
  (void)scanf("%d", &nodes);

  createLinkedList(nodes);
  printf("[Info] - data successfully added\n");
  displayList();

  return 0;
}