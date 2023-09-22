#include<stdio.h>
// Fonction de recherche de l'indice de l'element minimal positif d'un tableau reel: Pour le tableau des rapports
int IndiceMinPositifTabReel(int ig, int id, double* T)
{
    int k, i, iMin, iMax;
    double Min;
    k=ig;
    while(k<=id && T[k]<=0) // Recherche de l'indice du premier element positif du tableau
          k++;

    if(i>id)               // Si on sort de la boucle avec i>id et T[k]<=0)
            return 0;
    else                   // Sinon si on sort de la boucle avec i<=id et T[k]>0)
    {
           iMin=k;                 // considerer k comme indice du plus petit element du tableau
           Min=T[iMin];
           for(i=k; i<=id; i++)    // Recherche d'un eventuel element encore plus petit que celui consideré
           {
             if(Min>T[i] && T[i]>0)
             {
                       Min=T[i];
                       iMin=i;
             }
           }
    }

    return iMin-k+1;
}
