#include <stdio.h>
#include <stdlib.h> 
#include "Nnetwork.h" 
#include "Perceptron.h"
//#include "DataStructures/DoubleLinkedList.h"

int main ()
{
   /* printf("--------------------------Funcionamiento del perceptron simple--------------------------\n");

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
*/


//-------------------------------Inicio prueba de composición de la red y procesamiento hacia delante de datos--------------------------------
    Nnetwork network;
   

    createNetwork(&network, 2);

    AddLayer(&network, 1, "paso", 0);
    AddLayer(&network, 2, "relu", 0);
    AddLayer(&network, 1, "paso", 0);

   // ShowNetwork(network);

   /*AddLayer(&network, 256, "paso", 0);
    AddLayer(&network, 300, "paso", 0);
    AddLayer(&network, 500, "paso", 0);
    AddLayer(&network, 150, "paso", 0);
    AddLayer(&network, 8, "paso", 0);*/

    double input[2] = {1.0, 0.0};
    Nnetwork* aux = &network;
    processInput(aux, input);

    if(network->net == NULL)
    {
        printf("algo ha pasado\n");
    }


    

    ShowNetwork(network);






   return 0;
}