#include <stdio.h>
#include <stdlib.h>  
#include <math.h>
#define MAX 30

int somme(int tab[], int N) {
 int som=0 ;
for(int i=0 ; i<N ; i++)
    som+=tab[i] ;

 return som ;
 }
float moyenne(int tab[], int N){
    return somme(tab,N)/N ;
}

float ecart_type(int tab[], int N){
 float ecart=0, moy=moyenne(tab,N) ;
for(int i=0 ; i<N ; i++)
    ecart+=pow((tab[i]-moy),2) ;

 return sqrt(ecart)/sqrt(N) ;
}
int minimum(int tab[], int N){
     int min=tab[0]  ;
for(int i=0 ; i<N ; i++)
    if(min>tab[i])  min=tab[i] ;

 return min ;
}
int maximum(int tab[], int N){
   int max=tab[0]  ;
for(int i=0 ; i<N ; i++)
    if(max<tab[i])  max=tab[i] ;

 return max ;
}
int main() {
    
    int N;
     int tab[MAX] ;
    printf("Entrez le nombre de valeur à entree\n");
    scanf("%d", &N);
     for(int i=0 ;i<N; i++) {
      printf("\nentrez la valeur %d : ",(i+1) ) ;
      scanf("%d",&tab[i]) ;
     }
    printf("somme= %d ", somme(tab,N)) ;
    printf("moyenne= %f ", moyenne(tab,N)) ;
    printf("ecart type= %f ", ecart_type(tab,N)) ;
     
    
    return 0;
}
