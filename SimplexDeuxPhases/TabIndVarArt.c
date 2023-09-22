#include<stdio.h>

// Fonction retournant le tableau des indices des variables artificielles

int* TabIndVarArt(int nva)
{
    int i;

    int TIVA[nva]; // Tableau pour recuperer les indices des variables
    printf("Entrer par ordre croissant les indices des variables artificielles: \n");
    for(i=0; i<nva; i++)
        scanf("%d", TIVA[i]);

    return &TIVA[0];
}
