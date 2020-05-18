#include <stdlib.h>   
#include <stdio.h> 
#include "Nnetwork.h"
#include "DataStructures/Layer.h"

void createNetwork(Nnetwork* network, int ninputs)
{
    *network = malloc(sizeof(struct network));
    Create(&((*network)->net));
    (*network)->otplayer = (*network)->net;
    (*network)->ninputs = ninputs;
    (*network)->nlayers = 0;
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
    Addlayer(&((*net)->net), &((*net)->otplayer), numneurons, activation, alpha, (*net)->ninputs, ((*net)->nlayers));
    (*net)->nlayers++;
}

void ShowNetwork(Nnetwork net)
{
    printf("\n--------------------------Network Structure and info---------------------------\n\n\n");
    Show(net->net);
    printf("---------------------------------------------------------------------------------\n\n\n");
}

void ShowOutput(Nnetwork net)
{
    printf("Salidas de la red:  \n");

    for(int i=0;i<net->otplayer->numneurons;i++)
    {
        printf("Neuron %d, output: %f\n",i, net->otplayer->neurons[i]->otp);
    }

    printf("\n\n");
}


double* getoutput(Nnetwork net)
{
    if(net->otplayer->output == NULL)
    {
        printf("Error, can't get output if network has no processed input\n");
        exit(-1);
    }
    else
    {
        return net->otplayer->output;
    }
}

void backprop(Nnetwork* net, double learning_rate, double* expected)
{
    TLayer lay = (*net)->otplayer;

    for(int i=(*net)->nlayers;i>0;i--)
    {
        updateWeights(lay, (*net)->nlayers, learning_rate, expected);
        lay = lay->prev;

    }
}