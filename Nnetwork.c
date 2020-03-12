#include <stdlib.h>
#include <stdio.h>
#include "Nnetwork.h"
#include "DataStructures/DoubleLinkedList.h"

void createNetwork(Nnetwork* net, int ninputs)
{
    *net = malloc(sizeof(struct network));
    Create(&((*net)->net));
    (*net)->ninputs = ninputs;
    (*net)->nlayers = 0;
}

void processInput(Nnetwork* net2, double* input)
{
    TLayer nnet = (*net2)->net;
   // TLayer aux = (*net2)->net;

    while(nnet!= NULL)
    {
        //printf("L");
        processLayer(&nnet, input);

        nnet = nnet->next;
    }

   // (*net2)->net = aux; 
}

void AddLayer(Nnetwork* net, int numneurons, char* activation, double alpha)
{
    Addlayer(&((*net)->net), numneurons, activation, alpha, (*net)->ninputs, ((*net)->nlayers));
    (*net)->nlayers++;
}

void ShowNetwork(Nnetwork net)
{
    printf("Show");
    Show(net->net);
}