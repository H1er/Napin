#include <stdlib.h>
#include <string.h>
#include "Perceptron.h"
#include "Functions/activationFunctions.h"

void init (neuron* perceptron, char* activ, double alfa, double bias, int ninp, double* weights)
{
    neuron percep = malloc(sizeof(struct perceptron));
    percep->activation = malloc(sizeof(activ));
    percep->pesos= malloc(sizeof(weights));


    strcpy(percep->activation, activ);
    percep->nentradas = ninp;
    percep->pesos = weights;
    percep->sesgo = bias;
    percep->alpha = alfa;
    *perceptron = percep;

    printf("---\n");
   /**  printf("mostrar\n\n");
    //printf("\t sesgo: %f", percep->sesgo);
   
    printf("Peso e1 -- %f--\n", percep->pesos[0]);
    printf("Peso e2 -- %f-- \t activacion: %s\n", percep->pesos[1], percep->activation);
    //printf("Peso e3 -- %f--\n", percep->pesos[2]);**/
}

void procesarInputs(neuron percep, double* entradas)
{
    double sum=0;

    for(int i=0;i<percep->nentradas;i++)
    {
        sum += entradas[i]*percep->pesos[i];
    }

    printf("\nSuma de entradas *pesos = %f\n", sum);

    sum+=percep->sesgo;

    percep->salida = calculate(percep->activation, sum, percep->alpha);

}

void mostrarpercep(neuron n)
{
    printf("mostrar\n");
    
    printf("\t sesgo: %f\n", n->sesgo);
    printf("\t F. activacion: %s\n\n", n->activation);

    for (int  i = 0; i < n->nentradas; i++)
    {
        printf("Peso e%d -- %f--\n",i, n->pesos[0]);
        
    }  
   
}