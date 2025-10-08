#include "biblio.h"

int main(void){
   polynome poly ;
   int degree ;
   int n = 1000;
   int m=4;
    double min = -1.0, max = 1.0;

    char lagr[]="data_m4.txt" ;
    Creation_Polynome(&poly,m);
    double *x = malloc(n * sizeof(double));
    double *xl = malloc((m+1)* sizeof(double));
    double *sortie=malloc(n*sizeof(double)) ;
   echantillon_regulier(min, max, m+1, xl);  
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
   //on calcul le noeud de lagrange pour m donnée

   /*printf("entrez le degree du polynome \n" ) ;
   scanf("%d",&degree) ;
   Creation_Polynome(&poly,degree);
   Saisir_Polynome(&poly ) ;
   Affichage_polynome(&poly) ;
   calcul_polynome(n, x,y, &poly);
   sauvegarde_fichier("texte.txt", x, y, n);
   //affichage_graphique(nom_fich) ;
   double *lg=malloc(n*sizeof(double)) ;
   double xx[]={-0.2,0.2,0.6} ;
   double yy[]={Pm(-0.2,&poly),Pm(0.2,&poly),Pm(0.6,&poly)} ;
   Creation_Polynome(&inter,degree);
    inter.Tab[0]=yy[0] ; inter.Tab[1]=yy[1] ; inter.Tab[2]=yy[2] ; 
    printf("%f %f %f\n", yy[0],yy[1],yy[2]);
   lacet(lg,3,x);
   printf("%lf %lf %lf\n", polynome_lagrange(&inter,3,xx,-0.2),polynome_lagrange(&inter,3,xx,0.2),polynome_lagrange(&inter,3,xx,0.6));
  
    for(int i=0; i< 3 ; i++ )
      printf("lg[%d]=%lf\n",i,lg[i]) ;
*/
   /*calcul_polynome_lagrange(n,x,sortie,y);
   sauvegarde_fichier(lagr, x, sortie, n);
   affichage_graphique(lagr) ;*/

   
   free(sortie) ;
   free(x);
    //free(y);
   free(poly.Tab) ;
return 0 ;
}