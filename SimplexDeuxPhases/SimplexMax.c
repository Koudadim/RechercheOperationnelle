#include<stdio.h>
#include<stdlib.h>

void SimplexMax(int n, int m, double* cMax, double* b, double* c, double* x, int* base, double** A)
{
     int i, j, iMax, iMin, k;
     double pivot, coef;
     double rapport[m]; // Declaration du tableau des rapports

     int IndiceMaxTabReel(int ig, int id, double* T);
     int IndiceMinPositifTabReel(int ig, int id, double* T);
     void PrintfTabEntier(int ig, int id, int* T);
     void PrintfTabReel(int ig, int id, double* T);
     void PrintfTabMatReelle(int lg, int ld, int cg, int cd, double** M);

     printf("Matrice des contraintes initiale:\n");
     PrintfTabMatReelle(1, m, 1, n, A);
     printf("La base initiale est: \n");
     PrintfTabEntier(1, m, base);
     printf("Tableau c des coefficients de la fonction objectif: \n");
     PrintfTabReel(1, n, c);          // Affichage du tableau des coefficients de la fonction objectif
     iMax=IndiceMaxTabReel(1, n, c);  // Recherche de l'indice  du plus grand des coefficients de la fonction objectif
     printf(" Indice iMax du tableau des coefficients de la fonction objectif: %d ", iMax);

     // Tant qu'il existe un element strictement positif dans le tableau des coefficients de la fonction objectif on repete les iterations de l'algorithme
     k=1; // Pour le comptage du des tableaux generés lors de l'execution de l'algothme
     while(c[iMax]>0)
     {
         // Remplissage du tableau des rapport
         for(i=1; i<=n; i++)
         {
               if(A[i][iMax]>0)
                   rapport[i]=b[i]/A[i][iMax];
               else
                   rapport[i]=-1;
         }

         // Recherche de l'indice iMin du plus petit element du tableau des rapports
         iMin=IndiceMinPositifTabReel(1, m, rapport);
         // La variable dindice iMin sort de la base et celle d'indice iMax prend sa place
         if(iMin==0)
                {
                    printf("Le probleme lineaire admet une solution non bornee!!\n");
                    exit(-1);
                }
         else
                base[iMin]=iMax;

         pivot=A[iMin][iMax];

         // On multiplie la ligne du pivot par 1/pivot
         for(j=1; j<n; j++)
            A[iMin][j]/=pivot;

        // Calcul des autres lignes
        for(i=1; i<=m; i++)
            {
                if(i!=iMin)
                    {
                        coef=A[i][iMax];
                        for(j=1; j<=n; j++)
                            A[i][j]-=coef*A[iMin][j];
                        b[i]-=coef*b[iMin];

                        coef=c[iMax];
                        for(j=0; j<n; j++)
                            c[j]-=coef*A[iMin][j];

                        *cMax-=coef*b[iMin];
                    }
            }

            printf("Matrice des contraintes N %d", k);
            PrintfTabMatReelle(1, m, 1, n, A);
            printf("Tableau des coefficients N %d \n", k);
            PrintfTabReel(1, n, c);
            printf("Tableau des seconds membres N %d\n", k);
            PrintfTabReel(1, m, b);
            printf("La base N %d", k);
            PrintfTabEntier(1, m, base);

            k++;
            iMax=IndiceMaxTabReel(1, n, c); // Recherche de l'indice d'un eventuel plus grand element positif dde c;
     }

    // Mise à jour des solutions du probleme
    for(i=1; i<=n; i++)
        x[i]=0;
    for(i=0; i<=n; i++)
        x[base[i]]=b[i];
}
