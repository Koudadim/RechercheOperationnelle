#include<stdio.h>

double* TabMinPa(int n, int m,int nva, int nve,  int *baseIni, int* TIVA, int* b, double* MinPa, double** A)
{
    int i, j, k;
    double *cMin;
    cMin=(double*)malloc((n)*sizeof(double));

    for(j=1; j<=n; j++) // Initialisation des elements du tableau des couts reduits du PL auxiliaires a 0
        cMin[j]=0;

    k=TIVA[0];          // Plus petit indice de tableu des indices des variables artificielles

    // Calcul de la fonction objectif du PL auxiliaire

    for(i=1; i<=m; i++)
        if(baseIni[i]>=k)
        {
            for(j=1; j<=n; j++)
                cMin[j]-=A[i][j];
            MinPa-=b[i];
        }

    return cMin;
}
