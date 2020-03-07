#include <stdlib.h>
#include <string.h>
#include "Perceptron.h"
#include "Functions/activationFunctions.h"

void init (neuron percep, char* activ, double alfa, double bias, int ninp, double* weights)
{
    strcpy(percep->activation, activ);
    percep->nentradas = ninp;
    percep->pesos = weights;
    percep->sesgo = bias;
    percep->alpha = alfa;
}

void procesarInputs(neuron percep, double* entradas)
{
    double sum=0;
    for(int i=0;i<percep->nentradas;i++)
    {
        sum += entradas[i]*percep->pesos[i];
    }

    sum+=percep->sesgo;

    percep->salida = calculate(percep->activation, sum, percep->alpha);

}