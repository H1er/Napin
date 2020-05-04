
#ifndef LAYER_H
#define	LAYER_H

#include <stdio.h>
#include <stdlib.h>
#include "../Perceptron.h"

typedef struct Layer * TLayer;

struct Layer
{
    neuron* neurons;
    int layerid;
    int numneurons;
    double* input;
    double* output;
    int ninputs;

    struct Layer *next;
    struct Layer *prev;
};

/* Creates an empty List  */
void Create(TLayer * plist);

struct Layer getIndex(TLayer plist, int index);

void processLayer(TLayer* layer, double* entradas);

void showLayer (TLayer lay);


void Addlayer(TLayer * plist, TLayer * otp, int numneurons, char* activation, double alpha, int ninputs, int layd);

void Show(TLayer plist);

void Destroy(TLayer * plist);


#endif	/* LAYER_H */
