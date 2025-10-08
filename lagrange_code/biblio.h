#ifndef BIBLIO_h
#define BIBLIO_h
#include<stdio.h>
#include <stdlib.h>
typedef struct {
    int deg;        
    float *Tab;  
} polynome;


void Affichage_polynome(polynome *poly) ;
void Saisir_Polynome(polynome *p ) ;
void Creation_Polynome(polynome *p ,int deg) ;
float power(float x, int n) ;
double Pm(double x, polynome* poly);
void calcul_polynome(int n, double * ech_x, double * ech_poly, polynome* poly);
void echantillon_regulier(double min, double max, int n, double * echantillon);
void affichage_graphique(char* nom_fichier) ;
void sauvegarde_fichier(char *nom_fichier, double *abscisses, double *ordonnees, int n);

/*
double polynome_lagrange(int n,int indice, double* x, double x_x) ;
void calcul_polynome_lagrange(int n,double *x, double *sortie, double *b) ;
*/
//double polynome_lagrange(int n,int indice, double* x, double x_x, double *b);
//void calcul_polynome_lagrange(int n,double *x, double *sortie, double *b) ;

double calcul_lgx(int n,int indice, double* x, double x_x);
void lacet(double *lg,int n,double *x);

double polynome_lagrange(polynome *p, double *lg, double xx);
 
void calcul_polynome_lagrange(polynome *p, double *sortie, double *xl,double *x,int m, int n);


#endif