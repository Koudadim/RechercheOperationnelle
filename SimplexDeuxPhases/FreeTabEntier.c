#include<stdio.h>
// Fonction liberant l'espace allou� au pointeur sur un tableau d'entiers
void FreeTabEntier(int ig, int id, int* T) 
{
     free(T+ig);
}
