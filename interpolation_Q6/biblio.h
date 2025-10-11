#ifndef BIBLIO_h
#define BIBLIO_h
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

void echantillon_regulier(double min, double max, int n, double * echantillon);
void affichage_graphique(char* nom_fichier) ;
void sauvegarde_fichier(char *nom_fichier, double *abscisses, double *ordonnees, int n);

void calcul_f(int m,int n, double *y,double *x);
#endif
