#include "biblio.h"

int main(void){
  
   int n = 1000;
   int m=4;
    double min = -1.0, max = 1.0;

    char lagr[]="data_m4.txt" ;
   
    double *x = malloc(n * sizeof(double));
    
    double *sortie=malloc(n*sizeof(double)) ;

   echantillon_regulier(min, max, n, x);
  
   calcul_f(m,n,sortie,x) ;
   sauvegarde_fichier(lagr, x, sortie, n);
   affichage_graphique(lagr) ;
   
   free(sortie) ;
   free(x);
   
return 0 ;
}