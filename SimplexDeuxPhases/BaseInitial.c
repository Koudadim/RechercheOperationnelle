#include<stdio.h>

// Fonction pour recuperer la base initiale du PL

int* BaseInitial(int m)
{
    int i;
    int Bi[m];
    for(i=0; i<m; i++)
        scanf("%d", Bi[i]);
    return Bi;
}
