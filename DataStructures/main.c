#include "DoubleLinkedList.h"
#include "../Perceptron.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  TLayer lista;

  Create(&lista);

  //void AddLayer(TLayer * plist, int numneurons, char* activation, double alpha, int ninputs)

   /*neuron n;
  double pesos [2]= {1,1};
 init(&n, "sigmoid", 0, -1.5, 2, pesos);

  printf("init done\n");*/

  AddLayer(&lista, 4, "paso", 0,4,1); //Se añaden las capas
  AddLayer(&lista, 8, "sigmoid", 0,0,2);
  AddLayer(&lista, 8, "relu", 0,0,3);
  AddLayer(&lista, 4, "tanh", 0,0,4);
  AddLayer(&lista, 2, "paso", 0,0,5);
  //Destroy(&lista);
  Show(lista);

  return 0;

  
}
