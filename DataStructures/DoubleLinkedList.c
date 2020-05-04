#include "DoubleLinkedList.h"
#include "../Perceptron.h"
#include <string.h>
#include <time.h>

/* Creates an empty List */
void Create(TLayer * plist)
{
  *plist=NULL;
}

void Addlayer(TLayer * plist, int numneurons, char* activation, double alpha, int ninputs, int layd)
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
    aux->ninputs = ninputs;
    (*plist) = aux;

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
  }
}

void showLayer (TLayer lay)
{
  printf("\n----------Layer %d-------\n", lay->layerid);
  printf("---Neuronas---: %d\n", lay->numneurons);
  printf("\n");

  for(int i=0;i<lay->numneurons;i++)
  {
    printf("---Neuron %d---\n", i);
    printf("Bias: %f\n", (lay->neurons[i])->sesgo);
    for(int j=0;j<(lay->neurons[i])->nentradas;j++)
    {
      printf("Peso entrada %d: %f\n",j, ((lay->neurons[i])->pesos[j]));
    }

    printf("---OUTPUT DE LA NEURONA: %f\n", lay->output[i]);
    printf("\n");
  }
  printf("Funcion activacion: %s\n", lay->neurons[0]->activation);
  printf("Entradas/neurona: %d\n", lay->ninputs);
  printf("---------------------------\n\n\n");
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
    lay->output[j] = (lay->neurons[j])->salida;
   
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
