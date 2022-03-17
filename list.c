#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

// print contents of LL
void printListNode(ResistorNode * head) {
  // printf("h1\n");
  ResistorNode * p = head;
  // printf("h2\n");
  printf("printListNode: ");
  while (p != NULL) // the linked list must end with NULL
    {
      printf("%f, %f, %f\n", p->values[0], p->values[1], p->values[2]);
      // printf("h3\n");
      if (p->next != NULL)
        p = p->next;
      else return;
    }
  // printf("\n");
}

// create node
ResistorNode * buildNode(double values[]) {

  ResistorNode * node = NULL;
  node = (ResistorNode *) malloc(sizeof(ResistorNode));

  // node->values = values;
  printf("here\n");
  // memcpy(node->values, values, 3 * sizeof(double));
  node->values = malloc(3 * sizeof(double));
  node->values[0] = values[0];
  node->values[1] = values[1];
  node->values[2] = values[2];
  node->next = NULL;
  printf("here2\n");

  return node;
}

// insert node (check for duplicates)
void insertUniqueNode(ResistorNode ** head, ResistorNode ** node_to_insert) {

  if (head == NULL) {

    head = node_to_insert;

  } else {
    
    ResistorNode * p = (ResistorNode *) head;
    while (p->next != NULL) {
      if (memcmp(p->values, ((ResistorNode *) node_to_insert)->values, sizeof(p)) == 0) return;
      p = p->next;
    }
    
    p->next = (ResistorNode *) node_to_insert;
  }
}