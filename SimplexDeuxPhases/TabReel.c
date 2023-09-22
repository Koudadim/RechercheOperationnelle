#include<stdio.h>
int * TabReel(int ig, int id)
{
    double* T=(double*)malloc((id-ig+1)*sizeof(double));
    if(T==NULL)
    {
               printf("TabReel: Espace insuffisant!");
               exit(-1);
    }
    return T-ig;
}
