#include<stdio.h>
int * TabEntier(int ig, int id)
{
    int* T=(int*)malloc((id-ig+1)*sizeof(int));
    if(T==NULL)
    {
               printf("TabEntier: Espace insuffisant!");
               exit(-1);
    }
    return T-ig;
}
