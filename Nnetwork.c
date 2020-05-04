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
    int cont=0;
 

    while(nnet!= NULL)
    {
        
        processLayer(&nnet, input);

        nnet = nnet->next;
    }

  
}

void AddLayer(Nnetwork* net, int numneurons, char* activation, double alpha)
{
    Addlayer(&((*net)->net), numneurons, activation, alpha, (*net)->ninputs, ((*net)->nlayers));
    (*net)->nlayers++;
}

void ShowNetwork(Nnetwork net)
{
    printf("\n------Network Structure and info------\n\n\n");
    Show(net->net);
    printf("--------------------------------------\n\n\n");
}