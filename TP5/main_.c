#include "biblio.h"

int main() {
    double a = -1.0, b = 1.0; 
    int n = 10;  // J'ai renommé 'nombre' en 'n' pour correspondre
    
    
    structSubdivision* subdiv = subdivision_intervalle(a, b, n);
    afficher_subdivision(subdiv);
    structQuadrature q ;
    
    lecture_fichier( &q,"Quadratures/trapeze.txt") ; 
    
    structEchantillonnage_fonction p ;
    
    calcul_echantillonnage(&p , q, *subdiv) ;
    
    double I= calcul_integral(p) ;
    printf("la valeur de l'integral est : %lf\n",I) ;
    
    AffichageGnuplot(p);
    liberer_memoire_sub(subdiv);
    liberer_memoire_quad(&q);
    liberer_memoire_Ench_fonction(p) ;
   
   
    return 0;
}
