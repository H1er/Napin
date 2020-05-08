#include "costFunctions.h"
#include <math.h>


double calculatecost(char*name, double actual, double expected)
{
    if(!strcmp(name, "cuadratic"))
    {
        return cuadratic(actual, expected);
    }
    else
    {
        printf("");
        exit(-1);
    }
}

double cuadraticsquare (double actual, double expected)
{
    return pow(expected-actual, 2);
}

