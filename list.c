#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

// print contents of LL
void printListNode(ResistorNode * head) {
  ResistorNode * p = head;
  printf("printListNode: ");
  while (p != NULL) // the linked list must end with NULL
    {
      printf("%f, %f, %f\n", p->values[0], p->values[1], p->values[2]);
      printf("here\n");
      p = p->next;
      printf("here2\n");
    }
  printf("\n");
}