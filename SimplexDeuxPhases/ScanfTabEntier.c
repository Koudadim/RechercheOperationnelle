#include<stdio.h>

void ScanfTabEntier(int ig, int id, int *T, FILE* fichier)
{
     int i;
     // Saisie du tableau d'entiers a partir d'un fichier texte: Pour la base realisable
     for(i=ig; i<=id; i++)
               fscanf(fichier, "%d", T+i);
}
