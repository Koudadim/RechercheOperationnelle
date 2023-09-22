#include<stdio.h>
#include<stdlib.h>

double ** TabEntier(int lg, int ld, int cg, int cd)
{
    double* TabReel(int ig, int id);
    double** M;
    M=(double*)malloc((ld-lg+1)*sizeof(double*));
    if(M==NULL)
    {
               printf("MatReelle: Espace insuffisant!");
               exit(-1);
    }
    int i;;
    M-=lg;
    for(i=lg; i<=ld; i++)
    {
              M[i]=TabReel(cg, cd);
    }
    return M;
}
