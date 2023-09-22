#include<stdio.h>
#include<stdlib.h>

void ScanfMatReelle(int lg, int ld, int cg, int cd, double **M, FILE* fichier)
{
     int i, j;
     // Saisie de la matrice des contraintes a partir d'un fichier texte
     for(i=lg; i<=ld; i++)
               for(j=cg; j<=cd; j++)
                   fscanf(fichier, "%lf", M[i]+j);           
}
