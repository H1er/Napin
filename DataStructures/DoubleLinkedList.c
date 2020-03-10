#include "DoubleLinkedList.h"
#include "../Perceptron.h"
#include <string.h>

/* Creates an empty List */
void Create(TLayer * plist)
{
  *plist=NULL;
}

void AddLayer(TLayer * plist, int numneurons, char* activation, double alpha, int ninputs, int layd)
{
  TLayer ptr; 
  TLayer aux = (TLayer)malloc(sizeof(struct Layer));

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
      init(&(aux->neurons[i]), activation, alpha, (double)((rand()%100)/100), ninputs, NULL) ;
    }
  }
  else //resto de capas
  {
    aux->ninputs = ptr->numneurons; 
    while((ptr->next != NULL))    //ir al final de la cola e insertar
    {
    	ptr = ptr->next;
    }

    for(int i=0;i<numneurons;i++)
    {
      init(&(aux->neurons[i]), activation, alpha, (double)((rand()%100)/100), ptr->numneurons, NULL) ;
    }

    ptr->next = aux;
    aux->prev = ptr;
    aux->next = NULL;
  }
}

void showLayer (TLayer lay)
{
  printf("\n----------Layer %d----------\n", lay->layerid);
  printf("Numero de neuronas: %d\n", lay->numneurons);
  printf("Funcion activacion: %s\n", lay->neurons[0]->activation);
  printf("-------------------------\n");
}

void Show(TLayer  plist)
{
  while (plist!= NULL)
  {
    showLayer(plist);
    plist = plist->next;
  }
  printf("\n");
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
