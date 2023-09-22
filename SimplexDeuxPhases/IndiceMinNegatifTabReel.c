#include<stdio.h>
// Fonction de recherche de l'indice de l'element minimal negatif d'un tableau reel: Pour le tableau des rapports
int IndiceMinNegatifTabReel(int ig, int id, double* T)
{
    int i, j, iMin;
    double Min;

    iMin=-1;
    Min=T[ig];
    for(i=ig; i<=id; i++)
        if(T[i]<0 && T[i]<Min)
        {
            Min=T[i];
            iMin=i;
        }
    return iMin;
}
