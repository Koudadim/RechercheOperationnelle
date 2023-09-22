#include<stdio.h>
#include<stdlib.h>

void SimplexPhase01(int m, int n, int nva, int nve, double* b, double**A)
{
    int i, j;
    double* x;
    x=(double*)malloc(n*sizeof(double));
    double *MinPa; // Initialisation du cout reduit donné par l'opposée de la somme des elements de b situés sur des lignes de variables auxiliaires
    *MinPa=0;
    int* TIVA;
    TIVA=(int*)malloc(nva*sizeof(int)); //  pointeur sur le Tableau des indices des variables artificielles . Ce tableau permettra de verifier la redondance
    int* TIVE;
    TIVE=(int*)malloc(nve*sizeof(int)); //  Tableau des indices des variables d'ecart
    double* cMin;
    cMin=(double*)malloc(n*sizeof(double));
    int* base;
    base=(int*)malloc(m*sizeof(int)); // Pour la saisie de la base initiale du probleme
    int* TabIndVarEcar(int )
    int* TabIndVarArt(int );
    int* BaseInitial(int );
    double* TabMinPa(int n, int nva, int nve,  int *Bi, int* TIVA, int* b, double* MinPa, double** A);
    void PrintfTabReel(int ig, int id, double* T);
    void PrintfTabEntier(int ig, int id, int* T);
    void SimplexMin(int n, int m, int* TIVA, int* TIVE,  int* base, double* MinPa, double* cMin, double* x, double** A);
    int* Bi;
    Bi=(int*)malloc(m*sizeof(int));
    Bi=BaseInitial(m); // Saisie de la base initiale et retour d'un pointeur sur celle-ci
    TIVA=TabIndVarArt(nva); // Saisie du tableau des indices des variables artificielles et retour d'un pointeur sur celui-ci
    TIVE=TabIndVarEcar(nve);//  Saisie du tableau des indices des variables d'ecart et retour d'un pointeur sur celui-ci
    cMin=TabMinPa(n, nva, nve, Bi, TIVA, b, MinPa, A); //Calcul des couts reduits associés au PL auxiliaire et retour d'un pointeur sur le tableau de ces couts
    printf("La Phase I de la methode de simplexe a deux phase:\n")
    printf("Les couts reduits dans le Pl auxiliaire:\n");
    PrintfTabReel(1, n, cMin);
    printf("La base initiale est:\n")
    PrintfTabEntier(1, m, Bi);
    printf("Le tableau des indices des variables artificielles:\n")
    PrintfTabEntier(1, nva, TIVA);
    printf("Le tableau des indices des variables d'ecart:\n")
    PrintfTabEntier(1, nve, TIVE);
    printf("Les seconds membres du probleme:\n");
    PrintfTabReel(1, n, cMin);
    base=Bi;

    for(i=1; i<=n; i++)
        x[i]=0;
    SimplexMin(n, m, TIVA, TIVE, base, MinPa, cMin, x, A);
}
