#include "Layer.h"
#include "../Perceptron.h"
#include "../Functions/activationFunctions.h"
#include <string.h>
#include <time.h>

/* Creates an empty List */
void Create(TLayer * plist)
{
  *plist=NULL;
}

void Addlayer(TLayer * plist,TLayer * otp, int numneurons, char* activation, double alpha, int ninputs, int layd)
{
  TLayer ptr;
  TLayer aux = (TLayer)malloc(sizeof(struct Layer));

  aux->input = (double*) malloc(sizeof(double )*ninputs);
  aux->layerid = layd  ; //id de la capa
  aux->numneurons = numneurons;
  (aux)->neurons = (neuron*)malloc((numneurons *sizeof(struct perceptron)));

  ptr = (*plist);

  if(ptr == NULL) //primera capa
  {
	aux->prev = NULL;
    aux->ninputs = ninputs;
    (*plist) = aux;
    (*otp) = (*plist);

    for(int i=0;i<numneurons;i++)
    {
      init(&(aux->neurons[i]), activation, alpha, ((double)((rand()%100))/100)-(rand()%2), ninputs, NULL) ;
    }
  }
  else //resto de capas
  {
    while((ptr->next != NULL))    //ir al final de la cola e insertar
    {
    	ptr = ptr->next;
    }
    aux->ninputs = ptr->numneurons;

    for(int i=0;i<numneurons;i++)
    {
      init(&(aux->neurons[i]), activation, alpha, ((double)((rand()%100))/100)-(rand()%2), ptr->numneurons, NULL) ;
    }

    ptr->next = aux;
    aux->prev = ptr;
    aux->next = NULL;
    *otp = aux;
  }
}

void showLayer (TLayer lay)
{
  printf("\n--------------------Layer %d-----------------\n\n", lay->layerid);
  printf("---Neurons---> %d\n", lay->numneurons);
  printf("---Activation function-->: %s\n", lay->neurons[0]->activation);
  printf("\n\n");

  for(int i=0;i<lay->numneurons;i++)
  {
    printf("-------------Neuron %d-------------\n", i);
    
    mostrarpercep(lay->neurons[i]);
  }

  printf("\n-----------------------------------------------\n\n\n");
}

void Show(TLayer  plist)
{
  while (plist!= NULL)
  {
    //printf("1");
    showLayer(plist);
    plist = plist->next;
  }
  printf("\n");
}

void processLayer(TLayer* layer, double* entradas)
{
  double* inp;
  TLayer lay = (*layer);

  lay->output = (double*) malloc(sizeof(double)*(lay->numneurons));

  if((lay->layerid)==0) //primera capa
  {
    inp = entradas;
  }
  else
  {
    inp = (lay->prev)->output;
  }

  //printf("\nNumneurons: %d\n", layer->numneurons);
  for(int j=0;j<(lay->numneurons);j++)
  {
  
    procesarInputs(lay->neurons[j], inp);
    lay->output[j] = (lay->neurons[j])->otp;
   
  }

 // printf("---LAYER---");
  
}

/* Destroys the list and sets it to NULL */
void Destroy(TLayer * plist)
{
  TLayer ptr = (*plist);
  TLayer aux;

  while (ptr != NULL)
  {
    aux = ptr;
    ptr = ptr->next;
    free(aux);
  }

  (*plist) = NULL;
}

struct Layer getIndex(TLayer plist, int index)
{
  int cont = 0;
  while(cont<index)
  {
    plist = plist->next;
    cont++;
  }

  if (plist->next == NULL)
  {
	  printf("Error, el indice no existe");
  }

  return *plist;
}

void updateWeights(TLayer lay, int numlays, double learning_rate, double* expected)
{
  double rectif;
  double prime;
  double coa;
  double otprev;

	for(int i=0; i<lay->numneurons;i++)
	{
		for(int j=0;j<lay->neurons[i]->nentradas;j++)
		{
			neuron n = lay->neurons[i];

			if(lay->layerid == numlays-1) //capa L (ultima)
			{
        prime = (calculateprime(n->activation, n->z, n->alpha));
        coa = (2*(n->otp - expected[i]));
        otprev = (lay->prev->neurons[j]->otp);
        
				rectif = coa * prime * otprev;
         
  	  	n->pesos[j] -= (rectif * learning_rate);
        n->sesgo -= (coa*prime*learning_rate);
	
        n->bpp[0] = coa;
        n->bpp[1] = prime;
			}
      else  //capa L-n (cualquiera menos la ultima)
      {

        double sum=0;

        for(int k=0;k<lay->next->numneurons;k++)
        {
          sum += (lay->next->neurons[k]->bpp[0] * lay->next->neurons[k]->bpp[1] *  lay->next->neurons[k]->pesos[i]);
        }

        prime = (calculateprime(n->activation, n->z, n->alpha));
        coa = sum;

        n->bpp[0] = coa;
        n->bpp[1] = prime;
        n->sesgo -= ((coa*prime)*learning_rate);

        rectif = prime * coa * otprev;

        n->pesos[j] -= (rectif * learning_rate);
	   
      }
		}		
	
  
	}


}

