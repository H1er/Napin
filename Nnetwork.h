#ifndef NNETWORK_H
#define	NNETWORK_H

#include "DataStructures/DoubleLinkedList.h"

typedef struct network* Nnetwork;

struct network
{
    int nlayers;
    int ninputs;
    TLayer net;
};

void createNetwork(Nnetwork* net, int ninputs);

void processInput(Nnetwork* net, double* input);


void AddLayer(Nnetwork* net, int numneurons, char* activation, double alpha);

void ShowNetwork(Nnetwork net);


#endif
