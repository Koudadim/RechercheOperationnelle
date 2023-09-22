#include<stdio.h>
void PrintfTabMatReelle(int lg, int ld, int cg, int cd, double** M)
{
     int i, j;
     // Affichage d'une matrice de reels: Pour afficher la matrice des contraintes
     for(i=lg; i<=ld; i++)
     {
       for(j=cg; j<=cd; j++)
           printf("%lf", *(M[i]+j));
       printf(" \n");
     }
}
