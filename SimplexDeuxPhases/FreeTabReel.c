#include<stdio.h>
// Fonction liberant l'espace allou� au pointeur sur un tableau de reels
void FreeTabEntier(int ig, int id, double* T) 
{
     free(T+ig);
}
