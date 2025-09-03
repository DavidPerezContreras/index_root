#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h>
int main(int argcount, char **args)
{
    bool arguments_are_valid = true;

    if (argcount < 3)
    {
        arguments_are_valid = false;
        printf("Not enough arguments");
        exit(-1);
    }

    // Validate radicands
    for (int i = 2; i < argcount; i++)
    {
        char *endptr;
        double radicand = strtod(args[i], &endptr);

        if (args[i] == endptr)
        {
            arguments_are_valid = false;
        }
    }

    // Validate root index
    char *str = args[1];
    char *endptr;
    long value = strtol(str, &endptr, 10);

    if (str == endptr)
    {
        arguments_are_valid = false;
    }

    // Exit program if arguments are invalid
    if (!arguments_are_valid)
    {
        printf("Error parsing arguments. The first argument needs to be an integer. \nThe subsequent arguments should be doubles.");
        exit(-1);
    }

    // The first argument is the index of the root
    int root_index = strtol(args[1], NULL, 10);
    for (int i = 2; i < argcount; i++)
    {
        double radicand = strtod(args[i], NULL);
        printf("The %d-th root of %lf is %lf \n", root_index, radicand, pow(radicand, 1.0 / root_index));
    }

    return 0;
}
