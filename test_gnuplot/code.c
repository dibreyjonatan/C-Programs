#include "headers.h"
void affichage_graphique(char* nom_fichier){
   float x,y ;
FILE *gp = popen("gnuplot -persist", "w");
    if (gp == NULL) ;
    else {
    fprintf(gp, "set title 'graphical representation'\n");
    fprintf(gp, "set xlabel 'x'\n");
    fprintf(gp, "set ylabel 'y'\n");
    fprintf(gp, "plot '-' with lines title 'data'\n");

     FILE* data=fopen(nom_fichier,"r") ;
     if (data == NULL )  ;
    else{
       while(fscanf(data,"%f %f",&x,&y) == 2 ) {
       fprintf(gp, "%f %f\n", x,y);
        }
        fclose(data) ; // on ferme le fichier 
    fprintf(gp, "e\n");  // end of data
    fflush(gp);
    pclose(gp);
}
}

}
