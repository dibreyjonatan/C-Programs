#include "biblio.h"

void echantillon_regulier(double min, double max, int n, double * echantillon){
    //définir le pas "h"
    double pas = (max - min) / n;
    
    //Calcul des pts d'échatillons
    for (int i = 0; i < n; i++) {
        echantillon[i] = min + (i +0) * pas;
       // printf("Echantillon %d vaut %lf\n", i, echantillon[i]);
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
        }
    fprintf(gp, "e\n");  // end of data
    fflush(gp);
    pclose(gp);
}
}



void calcul_f(int m,int n, double *y,double *x){
  
  for(int i=0 ; i<n ; i++ ){
    y[i]=0 ;
    for(int j=0 ; j<=m/2 ; j++ ){
      y[i]+=pow(-25*x[i]*x[i],j);
  }
}
}
