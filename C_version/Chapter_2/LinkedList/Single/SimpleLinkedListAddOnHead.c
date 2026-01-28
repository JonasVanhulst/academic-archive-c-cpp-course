//
// Created by Vanhuljo on 12/06/2023.
//
// Write a program in C to create a singly linked list of n nodes and count the
// number of nodes.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
  int num;               // Data of the node
  struct node* nextptr;  // Address of the node
}* stnode;

void createNodeList(int n);  // function to create the list
void insertNewNode(
    int number);     // function to insert a new node at the beginning
void displayList();  // function to display the list

int main() {
  int n, number;
  printf(
      "\n\n Linked List : Insert a new node at the beginning of a Singly "
      "Linked List:\n");
  printf(
      "------------------------------------------------------------------------"
      "------\n");
  printf(" Input the number of nodes : ");
  (void)scanf("%d", &n);
  createNodeList(n);

  printf("\n Data entered in the list are : \n");
  displayList();

  printf("\n Input data to insert at the beginning of the list : ");
  (void)scanf("%d", &number);
  insertNewNode(number);

  printf("\n Data after inserted in the list are : \n");
  displayList();

  return 0;
}

void createNodeList(int n) {
  struct node *fnNode, *tmp;
  int num, i;
  stnode = (struct node*)malloc(sizeof(struct node));
  if (stnode ==
      NULL)  // check whether the stnode is NULL and if so no memory allocation
  {
    printf(" Memory can not be allocated.");
  } else {
    // reads data for the node through keyboard
    printf(" Input data for node 1 : ");
    (void)scanf("%d", &num);
    stnode->num = num;
    stnode->nextptr = NULL;  // Links the address field to NULL
    tmp = stnode;
    // Creates n nodes and adds to linked list
    for (i = 2; i <= n; i++) {
      fnNode = (struct node*)malloc(sizeof(struct node));
      if (fnNode == NULL)  // check whether the fnnode is NULL and if so no
                           // memory allocation
      {
        printf(" Memory can not be allocated.");
        break;
      } else {
        printf(" Input data for node %d : ", i);
        (void)scanf(" %d", &num);
        fnNode->num = num;       // links the num field of fnNode with num
        fnNode->nextptr = NULL;  // links the address field of fnNode with NULL
        tmp->nextptr = fnNode;   // links previous node i.e. tmp to the fnNode
        tmp = tmp->nextptr;
      }
    }
  }
}

void insertNewNode(int number) {
  struct node* fnnode;

  fnnode = (struct node*)malloc(sizeof(struct node));

  if (fnnode == NULL) {
    printf("Memmory can't be allocated.\n");
    exit(EXIT_FAILURE);
  } else {
    fnnode->num = number;
    fnnode->nextptr = stnode;
    stnode = fnnode;
  }
}

void displayList() {
  struct node* tmp;
  if (stnode == NULL) {
    printf(" No data found in the list.");
  } else {
    tmp = stnode;
    while (tmp != NULL) {
      printf(" Data = %d\n", tmp->num);  // prints the data of current node
      tmp = tmp->nextptr;  // advances the position of current node
    }
  }
}