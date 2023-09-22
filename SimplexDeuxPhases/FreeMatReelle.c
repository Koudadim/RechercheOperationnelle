#include<stdio.h>
// Fonction liberant l'espace alloué au pointeur sur une matrice reelle
void FreeMatReelle(int lg, int ld, int cg, int cd, double** M)
{
     int i;
     void FreeTabReel(int ig, int id, double* T);
     for(i=lg; i<=ld; i++)
               FreeTabReel(cg, cd, M[i]);         // Suppression des colonnes
     free(M+lg);
}
