#include "bibliotheque.h"

int main(void){
   polynome poly ;
   int degree ;
   printf("entrez le degree du polynome \n" ) ;
   scanf("%d",&degree) ;
   poly=Creation_Polynome(poly,degree);
   poly=Saisir_Polynome(poly ) ;
   Affichage_polynome(poly) ;
   
   // on instance le polynome derivee
   polynome q ;
   q=Calcul_derive(poly, q );
   printf("dérivée du polynome\n") ;
    Affichage_polynome(q) ;
    free(q.Tab) ;
    
    //somme de deux polynomes
    polynome s,poly_2 ;
    printf("veuillez entrer le second polynome \n") ;
    int degree_2 ;
   printf("entrez le degree du polynome \n" ) ;
   scanf("%d",&degree_2) ;
   poly_2=Creation_Polynome(poly_2,degree_2);
   poly_2=Saisir_Polynome(poly_2) ;
   Affichage_polynome(poly_2) ;
   printf("somme des deux polynomes\n") ;
    s=Somme(poly,poly_2,s );
    Affichage_polynome(s) ;
   
    //produit de deux polynomes
     s=Produit(poly,poly_2,s );
     printf("produit des deux  polynomes\n") ;
    Affichage_polynome(s) ;
   free(s.Tab) ;
    
   free(poly.Tab) ;
return 0 ;
}

/*


polynome poly ;
poly.deg=2 ;
  polynome x ;
  x=Creation_Polynome(x,2);
  float *p ;
   p=(float*)malloc((poly.deg+1)*sizeof(float)) ;
   for(int i=0 ; i< (poly.deg+1) ; i++) {
    printf("entree le coefficient a(%d) ",i ) ; 
    scanf("%f",(p+i)) ;
   }
    poly.Tab=p ;
    printf("%d\n", poly.deg) ;
    for(int i=0 ; i<poly.deg+1 ; i++ ) printf("%.3f\n",poly.Tab[i]) ;
    Affichage_polynome(poly) ;
    printf("%f\n",Calcule_valeur_x( poly,2)) ;
    
   free(p) ;
    */
