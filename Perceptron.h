#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <stdio.h>
#include <stdlib.h>

typedef struct perceptron* neuron;

typedef struct perceptron{

    int nentradas;
    double sesgo;
    double salidas;
    double* pesos; // en el metodo init // = (double*) malloc(nentradas*sizeof(double));
    /* input
     *
     * bias
     * 
     * input weights
     * 
     *  
     * 
     *  
    */
};




void procesarInputs(float* entradas);






#endif