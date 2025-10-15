#include "biblio.h"

// CORRECTION : retourne Subdivision*
structSubdivision* subdivision_intervalle(double a, double b, int n){
    structSubdivision* sub = malloc(sizeof(structSubdivision));// Allouer la mémoire pour la structure subdivisio
     sub->nombre = n; // (*sub).nombre = n
    
    sub->tabIntervalle = malloc(n * sizeof(structIntervalle));

    double longueur = (b - a) / n;

    // CORRECTION : calcul correct des intervalles
    for(int i = 0; i < n; i++) {
        sub->tabIntervalle[i].debut = a + i * longueur;
        sub->tabIntervalle[i].fin = a + (i + 1) * longueur;
    }
    return sub;
}

void afficher_subdivision(structSubdivision* sub){
    // SUPPRIMER cette ligne : Subdivision *sub; <- déjà en paramètre !
    printf("Subdivision avec %d intervalles:\n", sub->nombre);

    for (int i = 0; i < sub->nombre; i++) {
        printf("Intervalle %d: [%lf, %lf]\n", i, 
               sub->tabIntervalle[i].debut, 
               sub->tabIntervalle[i].fin);
    }
} 

void liberer_memoire_sub(structSubdivision* sub){
    free(sub->tabIntervalle);
    free(sub);
}

void lecture_fichier( structQuadrature *p, char* nom_fich ) {
	double zeta,omega ; int length,i=0 ; 
	  
	FILE *file=fopen(nom_fich,"r") ;
	 if(file==NULL) printf("couldnot open file \n") ;
	 else {
		 
		 fscanf(file,"%d",&length)==1 ;   //pour lire la taille qui est sur la premier ligne
			 p->taille=length;
	          p->tabOmega=malloc( p->taille *sizeof(double)) ;
	          p->tabZeta=malloc( p->taille *sizeof(double)) ;		 
		 
		 while(fscanf(file,"%lf %lf",&zeta, &omega)== 2) 
		 {
			 p->tabOmega[i]=omega ;
			 p->tabZeta[i]=zeta ;
			 i++ ;
		 }
		 printf("\n La methode de Quadrature choisit a Zeta et Omega comme suit : \n") ;
		 printf("la taille est %d\n",length) ;
		 for( int i=0 ; i < p->taille ; i++){
		 printf("%lf\t",p->tabZeta[i] ) ; 
		    printf("%lf\n",p->tabOmega[i] ) ;
		    
		 }
		 fclose(file) ;
	 }
}

void liberer_memoire_quad(structQuadrature* q){
    free(q->tabOmega);
    free(q->tabZeta);
    free(q);
}
double CalculFonction(double x) {
	return exp(-x) ; //on met la fonction constante pour tester
}
void calcul_echantillonnage(structEchantillonnage_fonction *p , structQuadrature cw, structSubdivision q ) {
	p->Quadrature_Echantillonnage=cw ;
	p->Subdivision_Echantillonnage=q ;
	 int xij ;
	 int t=cw.taille ;
	 int n=q.nombre ;

	p->matriceFonctionEchantillonnee=(double ** )malloc(n*sizeof(double*)) ;
	for(int i=0  ; i< n ; i++)
     	p->matriceFonctionEchantillonnee[i]=(double *) malloc(t*sizeof(double)) ;

	for( int i=0 ; i <= n-1 ; i++ ) {
	  for(int j=0 ; j<=t-1 ; j++){	
		  xij= (1-cw.tabZeta[j])*q.tabIntervalle[i].debut + cw.tabZeta[j]*q.tabIntervalle[i].fin  ;
		  p->matriceFonctionEchantillonnee[i][j]=CalculFonction(xij) ;
	  }
	}
	printf("\nLa Matrice des echantillons est : \n");
	for( int i=0 ; i <= n-1 ; i++ ) {
	  for(int j=0 ; j<=t-1 ; j++){	
		
		  printf("%lf\t",p->matriceFonctionEchantillonnee[i][j]);
	  }
	  printf("\n") ;
	}
	
}
double calcul_integral( structEchantillonnage_fonction p ) {
	 int t= p.Quadrature_Echantillonnage.taille;
	 int n = p.Subdivision_Echantillonnage.nombre ;
	  double I=0,som;
	 for (int i=0 ; i<= n-1 ; i++ ){
		 som=0 ;
	  for( int j=0 ; j <= t-1 ; j++) {
         som+= p.Quadrature_Echantillonnage.tabOmega[j]* p.matriceFonctionEchantillonnee[i][j] ;
	  }	 
	  I+= (p.Subdivision_Echantillonnage.tabIntervalle[i].fin - p.Subdivision_Echantillonnage.tabIntervalle[i].debut )*som ;
	 }
	 return I ; 
}

void AffichageGnuplot(structEchantillonnage_fonction p){

FILE *reel=fopen("courbe_ligne.dat","w") ;
FILE *approx=fopen("courbe_integration_boxes.dat","w") ;
// je vais utiliser le debut pour chaque truc
// pour afficher la courbe je vais utiliser xij
    int t= p.Quadrature_Echantillonnage.taille;
	 int n = p.Subdivision_Echantillonnage.nombre ;
	 double xij ;
	 for (int i=0 ; i<= n-1 ; i++ ){
		 fprintf(reel,"%lf %lf\n",p.Subdivision_Echantillonnage.tabIntervalle[i].fin , CalculFonction(p.Subdivision_Echantillonnage.tabIntervalle[i].fin)) ;
	  for( int j=0 ; j <= t-1 ; j++) {
	     xij= (1-p.Quadrature_Echantillonnage.tabZeta[j])*p.Subdivision_Echantillonnage.tabIntervalle[i].debut +    p.Quadrature_Echantillonnage.tabZeta[j]*p.Subdivision_Echantillonnage.tabIntervalle[i].fin ;
               fprintf(approx,"%lf %lf\n",xij ,p.matriceFonctionEchantillonnee[i][j] ) ;
	 }
	 }
fclose(reel) ;
fclose(approx) ;

}
