#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Perceptron.h"
#include "Functions/activationFunctions.h"

void init (neuron* perceptron, char* activ, double alfa, double bias, int ninp, double* weights)
{
    neuron percep = malloc(sizeof(struct perceptron));
    percep->activation = malloc(sizeof(activ));
    percep->pesos;//= malloc(sizeof(ninp*sizeof(double)));

    strcpy(percep->activation, activ);
    percep->nentradas = ninp;
    //printf("Sesgo: %f\n", bias);
    if(weights != NULL) //si se da explicitamente un array de pesos
    {
        percep->pesos = malloc(sizeof(weights));
        percep->pesos = weights;
    }
    else                //si no se dan de forma explicita los pesos se inicializan aleatorios (principalmente para cargar modelos ya creados anteriormente)
    {
        percep->pesos = malloc(sizeof(double)*ninp);
         
        for(int j=0;j<ninp;j++)
        {
            percep->pesos[j] = ((double)((rand()%100))/100)-(rand()%2);
            //printf("Se añade peso: %f a la entrada %d\n",percep->pesos[j], j);
        }
    }

    percep->sesgo = bias;
    percep->alpha = alfa;
    *perceptron = percep;
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

void mostrarpercep(neuron n)
{
    printf("\n\t Sesgo: %f\n", n->sesgo);
    printf("\t F. activacion: %s\n\n", n->activation);

    for (int  i = 0; i < n->nentradas; i++)
    {
        printf("Peso e%d -- %f--\n",i, n->pesos[0]);
    }
}
