#include "DoubleLinkedList.h"
#include "../Perceptron.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
  TLayer layers;
  srand(time(NULL));
  Create(&layers);

  //void AddLayer(TLayer * plist, int numneurons, char* activation, double alpha, int ninputs)

   /*neuron n;
  double pesos [2]= {1,1};
 init(&n, "sigmoid", 0, -1.5, 2, pesos);

  printf("init done\n");*/

  /*AddLayer(&layers, 4, "paso", 0,4,1); //Se añaden las capas con su id
  AddLayer(&layers, 8, "sigmoid", 0,0,2);
  AddLayer(&layers, 8, "relu", 0,0,3);
  AddLayer(&layers, 4, "tanh", 0,0,4);*/

  printf("Añadir layers\n");

  Addlayer(&layers, 2, "paso", 0,2,0);
  Addlayer(&layers, 3, "sigmoid", 0,2,1);
  Addlayer(&layers, 2, "relu", 0,2,2);
  //Destroy(&layers);
  double n = (double)((rand()%100))/100;
 // printf("int N = %d\n", n);
  //printf("double N = %f\n", n/100);

    printf("Mostrando layers\n");
  Show(layers);

  return 0;

  
}
