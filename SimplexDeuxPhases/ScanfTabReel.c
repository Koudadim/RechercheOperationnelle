#include<stdio.h>

void ScanfTabEntier(int ig, int id, double *T, FILE* fichier)
{
     int i;
     // Saisie du tableau de reels a partir d'un fichier texte: Pour les seconds membres, les coefficients de la fonction objectif et les rapports
     for(i=ig; i<=id; i++)
               fscanf(fichier, "%lf", T+i);
}
