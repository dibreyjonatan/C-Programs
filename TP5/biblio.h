#ifndef BIBLIO_H
#define BIBLIO_H
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct{ 
    double debut;  
    double fin; 
} structIntervalle; 

typedef struct{
    int nombre;
    structIntervalle* tabIntervalle;
} structSubdivision;

typedef struct{
int taille;
double* tabZeta;
double* tabOmega;
} structQuadrature;

typedef struct{
structQuadrature Quadrature_Echantillonnage;
structSubdivision Subdivision_Echantillonnage;
double** matriceFonctionEchantillonnee;
} structEchantillonnage_fonction;

// retourne Subdivision* au lieu de double
structSubdivision* subdivision_intervalle(double debut, double fin, int n);
void afficher_subdivision(structSubdivision* sub); 
void liberer_memoire_sub(structSubdivision* sub);
void lecture_fichier(structQuadrature *p, char* nom_fich );
void liberer_memoire_quad(structQuadrature* q); 

double CalculFonction(double x) ;
void calcul_echantillonnage(structEchantillonnage_fonction *p , structQuadrature cw, structSubdivision q ) ;

double calcul_integral( structEchantillonnage_fonction p ) ;

void AffichageGnuplot(structEchantillonnage_fonction Echantillonnage_fonction) ;
void liberer_memoire_Ench_fonction(structEchantillonnage_fonction p) ;
#endif
