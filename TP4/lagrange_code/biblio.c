#include "biblio.h"

void Affichage_polynome(polynome *poly){

	 for(int i=poly->deg; i>=0 ; i-- )
    if(poly->Tab[i]>0)  printf("%.3fx^%d+",poly->Tab[i],i) ;
    else printf("%.3fx^%d\t",poly->Tab[i],i) ;
      printf("\n") ;
  
}

void Saisir_Polynome(polynome *poly ) {

for(int i=0 ; i< (poly->deg+1) ; i++) {
    printf("entree le coefficient a(%d) \n",i ) ; 
    scanf("%f",(poly->Tab+i)) ;
   }
   //return poly ; 
}

void Creation_Polynome(polynome *p ,int deg) {
  
   p->deg= deg ;
   p->Tab=(float*)malloc((p->deg+1)*sizeof(float)) ;
  
}
float power(float x, int n) {
  if(n==0 ) return 1 ;
  else return x*power(x,n-1); 
}
double Pm(double x,polynome *poly){
  double val=0 ;
 for(int i=poly->deg; i>=0 ; i-- ){
    val+=poly->Tab[i]*power(x,i) ; 
 }
 return val ;
 }

void echantillon_regulier(double min, double max, int n, double * echantillon){
    //définir le pas "h"
    double pas = (max - min) / n;
    
    //Calcul des pts d'échatillons
    for (int i = 0; i < n; i++) {
        echantillon[i] = min + (i +0) * pas;
       // printf("Echantillon %d vaut %lf\n", i, echantillon[i]);
    }
}

void calcul_polynome(int n, double * ech_x, double * ech_poly, polynome* poly){
    // Boucle sur tous les points x qu'on veut évaluer
     
    for (int i = 0; i < n; i++) {
          
        ech_poly[i] = Pm(ech_x[i],poly);  

    }
}
void sauvegarde_fichier(char *nom_fichier, double *abscisses, double *ordonnees, int n) {
    FILE *f = NULL;
    f= fopen(nom_fichier, "w");
 
    if (f != NULL){
        for (int i = 0; i < n; i++) {
            fprintf(f,"%lf %lf\n", abscisses[i], ordonnees[i]);
        }
    }
    fclose(f);
}
void affichage_graphique(char* nom_fichier){
   double x,y ;
   
FILE *gp = popen("gnuplot -persist", "w");
    if (gp == NULL) printf("cannot open me") ;
    else {
    fprintf(gp, "set title 'graphical representation'\n");
    fprintf(gp, "set xlabel 'x'\n");
    fprintf(gp, "set ylabel 'y'\n");
    fprintf(gp, "plot '-' with lines title 'data'\n");

     FILE* data=fopen(nom_fichier,"r") ;
     if (data == NULL )  ;
    else{
       while(fscanf(data,"%lf %lf",&x,&y) == 2 ) {
       fprintf(gp,"%lf %lf\n", x,y);
        }
        fclose(data) ; // on ferme le fichier 
    fprintf(gp, "e\n");  // end of data
    fflush(gp);
    pclose(gp);
}
}
}

double calcul_lgx(int m,int indice, double* x, double x_x){
  double num=1, den=1 ;

for (int j=0; j<m+1; j++){  //m+1 à cause du nombre de points 
if(indice != j ) {
   num*=(x_x - x[j]) ;
   den*=(x[indice] - x[j]) ;
}
 
}
 return (num/den) ;

}

double polynome_lagrange(polynome *p, double *xl, double xx){
 double val=0 ;
  for(int i=p->deg; i>=0 ; i-- ){
    val+=p->Tab[i]*calcul_lgx(p->deg,i,xl,xx) ;  
 }
 return val;
}
void calcul_polynome_lagrange(polynome *p, double *sortie, double *xl,double *x,int m, int n){

  for (int i=0 ; i< n ; i++ ){
   sortie[i]=polynome_lagrange(p,xl,x[i]) ;
 }

}
