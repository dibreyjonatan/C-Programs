#include "biblio.h"

int main() {
    double a = -1.0, b = 1.0; 
    int n = 10;  // J'ai renommé 'nombre' en 'n' pour correspondre
    
    // CORRECTION : appel correct de la fonction
    structSubdivision* subdiv = subdivision_intervalle(a, b, n);
    afficher_subdivision(subdiv);
    structQuadrature *q ;
    q= malloc(sizeof(structQuadrature)) ;
    lecture_fichier( q,"Quadratures/trapeze.txt") ; 
    
    structEchantillonnage_fonction *p ;
    p=malloc(sizeof(structEchantillonnage_fonction)) ;
    calcul_echantillonnage(p , *q, *subdiv) ;
    
    double I= calcul_integral(*p) ;
    printf("la valeur de l'integral est : %lf\n",I) ;
    
    AffichageGnuplot(*p);
    liberer_memoire_sub(subdiv);
    liberer_memoire_quad(q);
   
   
    return 0;
}
