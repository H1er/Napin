
#ifndef DOUBLELINKEDLIST_H
#define	DOUBLELINKEDLIST_H

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
    int ninputs;


    struct Layer *next;
    struct Layer *prev;
};

/* Creates an empty List */
void Create(TLayer * plist);

struct Layer getIndex(TLayer plist, int index);


void AddLayer(TLayer * plist, int numneurons, char* activation, double alpha, int ninputs, int layd);

void Show(TLayer plist);

void Destroy(TLayer * plist);


#endif	/* DOUBLELINKEDLIST_H */
