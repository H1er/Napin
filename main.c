#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include "Nnetwork.h"
#include "Functions/costFunctions.h" 

int main ()
{
    srand(time(NULL)); //sin esto los numeros generados para los pesos y los sesgos no son aleatorios

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

    /*AddLayer(&network, 2, "paso", 0);
    AddLayer(&network, 3, "relu", 0);
    AddLayer(&network, 2, "paso", 0);*/

/* limites (llena la ram): 75 capas de 5k neuronas/capa (375k neuronas aprox) 

     con menos capas que suman el mismo numero de neuronas los resultados en cuanto a espacio ocupado son peores que con 500k de neuronas en capas de 5k


*/
//
   // ShowNetwork(network);
   
    AddLayer(&network, 2, "", 0);

    AddLayer(&network, 20, "sigmoid", 0);
    AddLayer(&network, 38, "relu", 0);
    AddLayer(&network, 20, "sigmoid", 0);
   
  
    AddLayer(&network, 4, "paso", 0);


    double input[8][2] = { {1.0,0.0}, {1.0,1.0}, {0.0,5.0}, {0.0,7.0}, {0.0,9.0}, {0.0,3.0}, {1.0,3.0}, {1.0,4.0}};
    int expected [8][4] = {{1,0,1,0}, {1,0,1,1}, {0,1,0,1}, {0,1,1,1}, {1,0,0,1}, {0,0,1,1}, {1,1,0,1}, {1,1,1,0}};

    Nnetwork* aux = &network;

   
    processInput(aux, input[0]);

    if(network->net == NULL)
    {
        printf("\n\nLa red esta a null wtf\n\n");
    }  

    ShowNetwork(network);

    //ShowOutput(network);

   /* double * otp = getoutput(network);

    for(int i=0;i<network->otplayer->numneurons;i++)
    {
       
        printf("Neurona %d: %f\n", (i+1), otp[i]);

    }

    //-----------------------------Backpropagation-----------------------------------

   // double input[8] = {1.0, 0.0, 3.0, 4.0, 2.0, 56.5, 9.0, 6.0}; */






   return 0;
}