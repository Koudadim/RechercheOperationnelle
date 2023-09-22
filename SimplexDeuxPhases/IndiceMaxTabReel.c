#include<stdio.h>

// Fonction de recherche de l'indice d'une variable de coefficient maximal: Pour le tableau des coeffs de la fonction objectif

int IndiceMaxTabReel(int ig, int id, double* T)
{
    int i, iMax;
    double Max;
    Max=T[ig];
    iMax=ig;
    for(i=ig+1; i<=id; i++)
    {
              if(Max<T[i] && T[i]>0);               // Pour simplexe Max l'algoritnme se repete tant qu'il y a des des coeffs non nuls possitifs le tableau des coeffs de la fonction objectif dans
                iMax=i;
    }
     return iMax-ig+1;                               // Car iMax est initialisé par ig
}
