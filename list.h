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

// build node
ResistorNode * buildNode(double * values);

// insert unique node
void insertUniqueNode(ResistorNode ** head, ResistorNode ** node_to_insert);

#endif