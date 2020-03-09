#include "DoubleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  TList lista;

  Create(&lista);

  for(int i=0;i<100;i++)
  {
    Add(&lista, i);
  }

  Show(lista);

}
