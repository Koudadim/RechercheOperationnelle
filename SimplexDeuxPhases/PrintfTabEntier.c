#include<stdio.h>
void PrintfTabEntier(int ig, int id, int* T)
{
     int i;
     // Affichage d'un tableau d'entier: Pour afficher la base realisable
     for(i=ig; i<=id; i++)
     {
               printf("%d", *(T+i));
               printf("     ");
     }
}
