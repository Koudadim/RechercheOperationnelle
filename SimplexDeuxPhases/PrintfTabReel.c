#include<stdio.h>
void PrintfTabReel(int ig, int id, double* T)
{
     int i;
     // Affichage d'un tableau d'entier: Pour afficher des seconds membre, des coeficients de la fonction objectif et des rapports
     for(i=ig; i<=id; i++)
     {
               printf("%lf", *(T+i));
               printf("     ");
     }
}
