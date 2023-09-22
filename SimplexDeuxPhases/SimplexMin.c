#include<stdio.h>

void SimplexMin(int n, int m, int nva, int nve, int* TIVA, int* TIVE,  int* base, double*b, double* MinPa, double* cMin, double* x, double** A)
{
    int i, j, i0, j0, k0, iMinN, iMinP, k;
    double pivot, coef;
    double* rapport;
    rapport=(double*)malloc(m*sizeof(double));
    int IndiceMinNegatifTabReel(int ig, int id, double* T);
    int IndiceMinPositifTabReel(int ig, int id, double* T);
    void PrintfTabMatReelle(int lg, int ld, int cg, int cd, double** M);
    void PrintfTabEntier(int ig, int id, int* T);
    void PrintfTabReel(int ig, int id, double* T);

    iMinN=IndiceMinNegatifTabReel(1, n, cMin);
    k=1;                                            // k: Pour compter le nombre de repetition de l'algorythme
    if(iMinN==-1)
    {
        printf("Le Probleme auxiliare est insoluble!!!!\n");
        exit(-1);
    }
    else
    {
        while(cMin[iMinN]<0)
            for(i=1; i<m; i++)
                {
                    if(A[i][iMinN]>0)
                        rapport[i]=b[i]/A[i][iMinN];
                    else
                        rapport[i]=-1;
                }

            iMinP=IndiceMinPositifTabReel(1, m, rapport);
            base[iMinP]=iMinN; // La variable d'indice iMinN entre en base et celle d'indice iMinP en sort

            pivot=A[iMinP][iMinN];

            for(j=0; j<n; j++)
                A[iMinP][j]/=pivot;

            for(i=1; i<m; i++)
                if(i!=iMinP)
                    {
                        coef=A[i][iMinN];
                        for(j=0; j<n; j++)
                            A[i][j]-=coef*A[iMinP][j];
                            cMin[j]-=cMin[iMinN]*A[iMinP][j];

                            *MinPa+=b[iMinP]*cMin[iMinN];
                    }

            printf("Matrice des contraintes N %d", k);
            PrintfTabMatReelle(1, m, 1, n, A);
            printf("Tableau des coefficients N %d \n", k);
            PrintfTabReel(1, n, cMin);
            printf("Tableau des seconds membres N %d\n", k);
            PrintfTabReel(1, m, b);
            printf("La base N %d", k);
            PrintfTabEntier(1, m, base);

            k++;
            iMinN=IndiceMinNegatifTabReel(1, n, cMin);
    }

// Verification de la presence en base d'une variable artificielle.

    for(i=1; i<=m; i++)
        for(j=1; j<=nva; j++)
            if(base[i]==TIVA[j])
            {
                k0=1;
                while(A[i][k0]==0)
                    k++;
                if(k>(n-nva-nve))
                {
                    printf("La ligne %d est redondante; on la supprime.\n ", i);
                    free(A[i]);
                    base[i]=-1;
                }
                else //
                {
                    for(j0=1; j0<=n; j0++)
                        A[i][j0]/=A[i][k0];
                    for(i0=1; i0<=m; i0++)
                        if(i0!=i)
                            {
                                coef=A[i][k0];
                                for(j0=1; j0<=n; j0++)
                                    A[i0][j0]-=coef*A[i][j0];
                                b[j0]-=b[i]*coef;

                                coef=cMin[k0];
                                if(A[i][k0]>0)
                                    {
                                        cMin[j0]-=coef*A[i][j0];
                                        *MinPa-=b[i]*coef;
                                    }
                                else
                                    {
                                        cMin[j0]+=coef*A[i][j0];
                                        *MinPa+=b[i]*coef;
                                    }

                            }
                }
            }

    if(*MinPa==0)
    {
        printf("Le probleme auxiliaire admet une solution optimale qui est:\n");

        for(i=0; i<=n; i++)
            x[base[i]]=b[i];
        for(i=1; i<=n; i++)
            printf("x[%d]= %lf \t\t", i, x[i]);
        printf("\n");
    }
    else
    {
        printf("Le probleme n'admet aucune solution!!\n");
        exit(-1);
    }

}
