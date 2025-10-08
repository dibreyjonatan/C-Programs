#include<stdio.h>
#include <stdlib.h>
#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

typedef struct{
 int deg ;
  float *Tab ; //pour ses coefficients 
}polynome ;

void Affichage_polynome(polynome poly) ;
float power(float x,int n);
float Calcule_valeur_x(polynome poly,float x);
polynome Creation_Polynome(polynome p ,int deg) ;
polynome Saisir_Polynome(polynome p ) ;
polynome Calcul_derive(polynome p, polynome q ) ;
polynome Somme(polynome p, polynome q, polynome s ) ;
polynome Produit(polynome p, polynome q, polynome prod ) ;
#endif
