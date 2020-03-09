#include <stdio.h>
#include <stdlib.h>
#include "Perceptron.h"

int main ()
{
    double pesos [2]= {1,1};
    double inputs[2] ={0,0};
    neuron n1 ;//= malloc(sizeof (struct perceptron));
   // printf("0\n");
    init(&n1, "paso", 0, -0.5, 2, pesos);

    mostrarpercep(n1);
    procesarInputs(n1, inputs);

    printf("\nLa salida de la neurona es %f\n\n", n1->salida);

   return 0;
}