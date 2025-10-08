#include<stdio.h>
#define MAX 100
 int lecture(float X[], float Y[]){
  int i=0 ;
 FILE* file ; 
 file=fopen("L2.txt","r");
	if(file==NULL) {
		printf("couldn't open file") ;
	}
	else{
	while (fscanf(file, "%f %f", &X[i],&Y[i]) == 2) {
        i++;
    }
 }
 fclose(file) ;
 return i ; // il reduit juste la taille des valeurs impliqué dans le calcul 
 
 }
 
float somme(float tab[], int N) {
 float som=0 ;
for(int i=0 ; i<N ; i++)
    som+=tab[i] ;

 return som ;
 }
float moyenne(float tab[], int N){
    return somme(tab,N)/N ;
}
 
float moyenne_produit(float X[], float Y[],int N ) {
  float Z[MAX] ;
  for( int i=0 ;i<N ; i++){
   Z[i]=X[i]*Y[i] ;
  }
  return moyenne(Z,N) ;

}
 void calcul_coefs(float X[], float Y[], int N, float* a, float* b){
  
    float x_moy=moyenne(X,N) ;
	float y_moy=moyenne(Y,N) ;
	float xy_moy=moyenne_produit(X,Y,N) ;
	float xx_moy=moyenne_produit(X,X,N) ;
	*a=(xy_moy-x_moy*y_moy)/(xx_moy-x_moy*x_moy) ;
	*b=(y_moy*xx_moy-x_moy*xy_moy)/(xx_moy-x_moy*x_moy) ;
 }
 // On fait affiche juste pour verifier les valeurs tirer du fichier 
 void affiche_X_Y(float X[], float Y[],int N ) {
  printf("\nles valeurs de x et y\n\n") ;
  for( int i=0 ;i<N ; i++){
   printf("%f\t%f\t",X[i],Y[i]); 
  }
  printf("\n\n") ;

}
 int main(void){
   float a,b,c ;
   int taille;
   float X[MAX], Y[MAX] ;
   taille=lecture(X,Y) ;
   printf("la taille est %d", taille ) ;
   affiche_X_Y(X,Y,taille);
   calcul_coefs(X,Y,taille,&a,&b) ;
   printf(" y= %f x + %f \n\n",a,b) ;
   printf("Entrez la valeur de x :  ") ;
   scanf("%f",&c ) ;
   printf("y= %f \n",(a*c+b));
 return 0 ;
 }
