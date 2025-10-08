#include "bibliotheque.h"

void Affichage_polynome(polynome poly){

	 for(int i=poly.deg; i>=0 ; i-- )
    if(poly.Tab[i]>0)  printf("%.3fx^%d+",poly.Tab[i],i) ;
    else printf("%.3fx^%d\t",poly.Tab[i],i) ;
      printf("\n") ;
  
}
//on definit une fonction pour le calcul de la puissance 
float power(float x, int n) {
  if(n==0 ) return 1 ;   // au cas où on a x puissance 0 et 0 puissance 0 
  else return x*power(x,n-1); 
}
float Calcule_valeur_x(polynome poly,float x){
  float val=0 ;
 for(int i=poly.deg; i>=0 ; i-- ){
    val+=poly.Tab[i]*power(x,i) ;  // coef*x^i 
 }
 return val ;
 }

polynome Creation_Polynome(polynome p ,int deg) {
  
   p.deg= deg ;
   p.Tab=(float*)malloc((p.deg+1)*sizeof(float)) ;
  return p ;
}
polynome Saisir_Polynome(polynome poly ) {

for(int i=0 ; i< (poly.deg+1) ; i++) {
    printf("entree le coefficient a(%d) \n",i ) ; 
    scanf("%f",(poly.Tab+i)) ;
   }
   return poly ; 
}
polynome Calcul_derive(polynome p, polynome q ) {

     q.deg=p.deg-1 ;
     if(p.deg==0 && p.Tab[0]==0 ) {  //cas où p(x)=0, on ne peut pas faire de derivé 
     printf("on ne peut pas faire de derivation \n" ) ;
     return q ; 
     }
     if(q.deg==-1 ) {  // dans le cas où on a p(x)=c où c different de 0, alors p'=0
         q.deg=0 ;
         q=Creation_Polynome(q ,q.deg) ;
         q.Tab[0]=0 ;
         return q ;
     }
     q=Creation_Polynome(q ,q.deg) ;
     for(int i=q.deg; i>=0 ; i-- ){
       q.Tab[i]=(i+1)*p.Tab[i+1] ;
     
     }
    return q ; 
}
polynome Somme(polynome p, polynome q, polynome s ) {
   if( p.deg > q.deg){
     s.deg=p.deg ;
     int l=p.deg-q.deg ;  // le pointeur pour l'addition, afin de savoir exactement à partir d'où faire la somme  
     s=Creation_Polynome(s ,s.deg) ;
     for(int i=s.deg; i>=0 ; i-- ){
      if(i>l) s.Tab[i]=p.Tab[i];  //si i > l, ca veut dire que la somme des coeffs concerne uniquement les coef de p
       if(i<=l) s.Tab[i]=p.Tab[i]+q.Tab[i] ;
     }
     }
   else {
   s.deg=q.deg ;
   int l=q.deg-p.deg ;
   s=Creation_Polynome(s ,s.deg);
    for(int i=s.deg; i>=0 ; i-- ){
      if(i>l) s.Tab[i]=q.Tab[i]; //si i > l, ca veut dire que la somme des coeffs concerne uniquement les coef de q 
       if(i<=l) s.Tab[i]=p.Tab[i]+q.Tab[i] ;
     }
   }
   return s ; 

}

polynome Produit(polynome p, polynome q, polynome prod ) {
  prod.deg=p.deg+q.deg ; 
  prod=Creation_Polynome(prod ,prod.deg);
  // Initialiser le tableau résultat à zéro
    for (int i = 0; i <= prod.deg; i++) {
        prod.Tab[i] = 0;
    }

    // Produit classique (convolution)
    for (int i = 0; i <= p.deg; i++) {
        for (int j = 0; j <= q.deg; j++) {
            prod.Tab[i + j] += p.Tab[i] * q.Tab[j];
        }
    }
return prod ; 
}


