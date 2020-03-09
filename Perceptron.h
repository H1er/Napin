#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <stdio.h>
#include <stdlib.h>

typedef struct perceptron* neuron;

struct perceptron{

    char* activation;
    double alpha;
    int nentradas;
    double sesgo;
    double salida;
    double* pesos; // en el metodo init // = (double*) malloc(nentradas*sizeof(double));
  
};

void mostrarpercep(neuron n);

void procesarInputs(neuron percep, double* entradas);

void init (neuron* percep, char* activ, double alfa, double bias, int ninp, double* weights);

#endif