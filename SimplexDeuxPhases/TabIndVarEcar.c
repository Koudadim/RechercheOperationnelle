#include<stdio.h>
// Une fonction qui repere les indices de variables d'ecart dans le tableau initial
int* TabIndVarEcar(int nve)
{
    int i;
    int *T;
    T=(int*)malloc(nve*sizeof(int));
    for(i=0; i<nve; i++)
        scanf("%d", T[i]);
    return T;
}
