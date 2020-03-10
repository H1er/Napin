#include <stdio.h>
#include <stdlib.h>
#include "Perceptron.h"
#include "DataStructures/DoubleLinkedList.h"

int main ()
{
    printf("--------------------------Funcionamiento del perceptron simple--------------------------\n");

    double pesos [2]= {1,1};
    double inputs[2] ={0,0};

    printf("\n\t---Perceptron con funcionamiento de una puerta OR---\n\nEntradas: %f, %f\n",inputs[0], inputs[1]);
    neuron n1 ;//= malloc(sizeof (struct perceptron));
   // printf("0\n");
    init(&n1, "paso", 0, -0.5, 2, pesos);

    mostrarpercep(n1);
    procesarInputs(n1, inputs);

    printf("\nLa salida de la neurona es %f\n\n", n1->salida);

    printf("--------------------------Fin prueba perceptron--------------------------\n"); //probar capas desde fuera del directorio DataStructures




   return 0;
}