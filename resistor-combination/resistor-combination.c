#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "resistor-combination.h"
#include "../helper.h"
#include "../list.h"

int main(int argc, char ** argv) {

	if (argc != 5) {
		printf("Invalid number of arguments\n");
		return EXIT_FAILURE;
	}

	// get desired resistor value and convert to double
	char *ptr;
	double desired_value = strtod(argv[1], &ptr);

	printf("Desired value: %f\n", desired_value);

	// create LL for valid resistor combinations
	ResistorLL * valid = (ResistorLL *) malloc(sizeof(ResistorLL));
	valid->head = (ResistorNode *) malloc(sizeof(ResistorNode));
	valid->head->next = NULL;
	ResistorNode * head = valid->head;

	// series only
	for (int i = 0; i < (sizeof(E3) / sizeof(E3[0])); i++) { // one resistor deep

		for (int j = 0; j < (sizeof(E3) / sizeof(E3[0])); j++) { // two resistors

			for (int k = 0; k < (sizeof(E3) / sizeof(E3[0])); k++) { // three resistors

				// check if current combination of 3 resistors is within 10% tolerance
				if (fabs((E3[i] + E3[j] + E3[k] - desired_value) / desired_value) <= 0.1) {

					if (head == NULL) {
						head = (ResistorNode *) malloc(sizeof(ResistorNode));
						head->next = NULL;
					}

					head->values = malloc(3 * sizeof(double));
					head->values[0] = E3[i];
					head->values[1] = E3[j];
					head->values[2] = E3[k];
					qsort(head->values, 3, sizeof(double), dcompare);
					printListNode(head);
					head = head->next;

					printf("Value found (3): %f + %f + %f = %f (%f)\n", E3[i], E3[j], E3[k], (E3[i] + E3[j] + E3[k]), fabs((E3[i] + E3[j] + E3[k] - desired_value) / desired_value));
				}
			}

			// check if current combination of 2 resistors is within 10% tolerance
			if (fabs((E3[i] + E3[j] - desired_value) / desired_value) <= 0.1) {
				printf("Value found (2): %f + %f = %f (%f)\n", E3[i], E3[j], (E3[i] + E3[j]), fabs((E3[i] + E3[j] - desired_value) / desired_value));
			}
		}

		// check if current combination of 1 resistor is within 10% tolerance
		if (fabs((E3[i] - desired_value) / desired_value) <= 0.1) {
			printf("Value found (1): %f = %f (%f)\n", E3[i], (E3[i]), fabs((E3[i] - desired_value) / desired_value));
		}
	}

	printListNode(valid->head);

	// free memory
	while (head->next != NULL) {

		ResistorNode * temp = head;
		head = head->next;
		free(temp);
	}
	free(head);
	free(valid);
}