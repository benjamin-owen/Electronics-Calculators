#ifndef _LIST_H_
#define _LIST_H_

// ResistorNode struct
typedef struct ResistorNode {
	double * values;
	struct ResistorNode * next;
} ResistorNode;

// ResistorNode LL struct
typedef struct ResistorLL {
	ResistorNode * head;
} ResistorLL;

// print LL
void printListNode(ResistorNode * head);

#endif