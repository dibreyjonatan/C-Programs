#include "headers.h"

int main() {
     char nom[] ="data.txt" ;
     FILE* fich=fopen(nom,"w") ;
     if( fich==NULL ) {
     
     printf("erreur data opening\n") ;
     return 1 ;
     }
     for( float i=0 ; i<1000 ;i++) 
     fprintf(fich,"%f %f\n",i,sin(i/(2*PI))*exp(-0.01*i)) ;
     
     fclose(fich) ; 
     affichage_graphique(nom) ;
    return 0;
}

