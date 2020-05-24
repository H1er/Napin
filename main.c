#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <math.h>
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
   

    createNetwork(&network, 3);

    /*AddLayer(&network, 2, "paso", 0);
    AddLayer(&network, 3, "relu", 0);
    AddLayer(&network, 2, "paso", 0);*/


//
   // ShowNetwork(network);
   
    AddLayer(&network, 3, "sigmoid", 0);
  // AddLayer(&network, 8, "relu", 0);
 //AddLayer(&network, 8, "relu", 0);
 
    AddLayer(&network, 4, "relu", 0);


    AddLayer(&network, 8, "sigmoid", 0);

    //numbers in binary from 0 to 7
    double input[8][3] = {{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};
    //the neuron in position n turns to 1, being n the binary number introduced  in the input
    double expected[8][8] = {{1,0,0,0,0,0,0,0},{0,1,0,0,0,0,0,0},{0,0,1,0,0,0,0,0},{0,0,0,1,0,0,0,0},{0,0,0,0,1,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,1}};
    

   
        
   
    Nnetwork* aux = &network;

    if(network->net == NULL)
    {
        printf("\n\nnetwork is null wtf\n\n");
    }  
  //processInput(aux, input[1]);
  //ShowOutput(network);



  //-------------------------------Training and backpropagation--------------------------------

    double lr = 3;
    int epochs = 1000000;

    for(int j=0;j<epochs;j++)
    {
        printf("\tEpoch %d \n",j);

        if(j%10000 == 0)
        {
            lr= (int)lr/2;
        }
        
        for(int i=0;i<8;i++)
        {
           // printf("\n------------------------\n");
            processInput(&network, input[i]);
            //ShowOutput(network);
            //printf("expected en %d:  %f\n", i, expected[i]);
            backprop(&network, lr, expected[i]);
            //ShowOutput(network);
            //printf("------------------------\n\n\n\n");

        }
    }

    printf("\n");

        for(int i=0;i<8;i++)
        {

            printf("Expected en la salida %d: \n", i);
            processInput(&network, input[i]);
            ShowOutput(network);
            
            
        }
   

    printf("\n\n\n");

   

  
    //-----------------------------Backpropagation-----------------------------------



   return 0;
}
