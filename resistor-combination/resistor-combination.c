#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "resistor-combination.h"
#include "../helper.h"

int main(int argc, char ** argv) {

	if (argc != 5) {
		printf("Invalid number of arguments\n");
		return EXIT_FAILURE;
	}

	// get desired resistor value and convert to double
	char *ptr;
	double desired_value = strtod(argv[1], &ptr);

	printf("Desired value: %f\n", desired_value);

	// series only
	for (int i = 0; i < (sizeof(E3) / sizeof(E3[0])); i++) { // one resistor deep

		for (int j = 0; j < (sizeof(E3) / sizeof(E3[0])); j++) { // two resistors

			for (int k = 0; k < (sizeof(E3) / sizeof(E3[0])); k++) { // three resistors

				// check if current combination of 3 resistors is within 10% tolerance
				if (fabs((E3[i] + E3[j] + E3[k] - desired_value) / desired_value) <= 0.1) {
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
}