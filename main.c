#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <float.h>

int main(int argc, char **argv)
{
    if (argc < 3) {
        printf("Not enough arguments.\nUsage: %s <root_index> <number1> [number2 ...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Validate and parse root index
    char *endptr;
    long root_index = strtol(argv[1], &endptr, 10);

    if (argv[1] == endptr || root_index <= 0 || root_index > INT_MAX) {
        printf("Error: The first argument must be a positive integer.\n");
        return EXIT_FAILURE;
    }

    // Validate radicands
    for (int i = 2; i < argc; i++) {
        char *rad_endptr;
        strtod(argv[i], &rad_endptr);
        if (argv[i] == rad_endptr) {
            printf("Error: Argument %d ('%s') is not a valid double.\n", i, argv[i]);
            return EXIT_FAILURE;
        }
    }

    // Compute and print roots
    for (int i = 2; i < argc; i++) {
        double radicand = strtod(argv[i], NULL);

        // Handle domain error for even roots of negative numbers
        if (radicand < 0 && root_index % 2 == 0) {
            printf("Cannot compute even root of negative number: %g\n", radicand);
            continue;
        }

        double result = pow(radicand, 1.0 / root_index);
        printf("The %ld-th root of %g is %g\n", root_index, radicand, result);
    }

    return EXIT_SUCCESS;
}
