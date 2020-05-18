#ifndef NNETWORK_H
#define	NNETWORK_H

#include "DataStructures/Layer.h"

typedef struct network* Nnetwork;

struct network
{
    int nlayers;
    int ninputs;
    TLayer net;
    TLayer otplayer;
    double* output;
};

void createNetwork(Nnetwork* net, int ninputs);

void processInput(Nnetwork* net, double* input);


void AddLayer(Nnetwork* net, int numneurons, char* activation, double alpha);

void ShowNetwork(Nnetwork net);

void ShowOutput(Nnetwork net);

void updatdeWeights(Nnetwork* net);

void backprop(Nnetwork* net, double learning_rate, double* expected);

double* getoutput(Nnetwork net);


#endif /* NNETWORK_H */
