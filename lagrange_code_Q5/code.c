#include "biblio.h"

int main(void){
   polynome poly ;
   int degree ;
   int n = 1000;
   int m=20;
    double min = -1.0, max = 1.0;

    char lagr[]="data_tchebychef_m20.txt" ;
    Creation_Polynome(&poly,m);
    double *x = malloc(n * sizeof(double));
    double *xl = malloc((m+1)* sizeof(double));
    double *sortie=malloc(n*sizeof(double)) ;
   echantillon_tchebychef(min, max, m+1, xl);  
   echantillon_regulier(min, max, n, x);
   for(int i=m; i>0; i--){
      poly.Tab[i]=1/(1+25*xl[i]*xl[i]);
      printf("x=%lf y=%lf\n",xl[i],poly.Tab[i]);
   }
   printf("%lf",polynome_lagrange(&poly,xl,0));

   calcul_polynome_lagrange(&poly,sortie,xl,x,m,n);

   /* //to fetch the original function
    
   for(int i=0; i<n; i++){
      sortie[i]=1/(1+25*x[i]*x[i]);
    //  printf("x=%lf y=%lf\n",xl[i],poly.Tab[i]);
   }*/
   sauvegarde_fichier(lagr, x, sortie, n);
   affichage_graphique(lagr) ;
   
   free(sortie) ;
   free(x);
   free(poly.Tab) ;
return 0 ;
}