#include<stdio.h>
#include<stdlib.h>

void Afficher_matrice(int taille, float ** matrice) ;
void Triangle(int taille, float **Mat) ;
float** Allocation(int taille, float **Mat) ;
void Free_Alloc(int taille, float **Mat);
float ** IdentityMat(int taille, float **Mat) ;
void Inverser_matrice(int taille, float ** matrice, float ** matrice_inv);
void Identite(int taille, float ** Mat, float ** Matinv, float ** MatI);
int main(){
    float **mat,**mat_inv, **mat_id, **temp ;
    int  n;
     printf("Entrez la taille du tableau \n");
     scanf("%d",&n) ;
 /*
 
 Remarque : j'ai eu une erreur lorsque j'ai écrit la fonction Allocation en void 
Le code est executé mais n'affiche pas le resultat
Pourquoi ? 
Bien vrai que je reserve des espaces mémoire de la matrice, cependant 
je dois faire une affectation de variable afin que la variable **mat ait la 
meme valeur que la variable locale de la fonction  allocation.

voir ca comme affectation (passage par valeur ) a=f(a) en C 
un pointeur c'est une variable avant tout donc il faut faire une affectation pour
que la valeur de la variable en fonction soit égale à la variable dehors la fonction
////// Parce que je ne passe pas l'adresse de **p du coup je dois faire l'affectation
//// en gros je fais un passage par valeur 

Du coup j'ai du redefinir ma fonction Allocation

 */
     mat=Allocation(n, mat) ;
     Triangle(n ,mat );
     Afficher_matrice(n, mat);
     mat_inv=Allocation(n,mat_inv);
      //Allocation pour conserver la matrice avant calcul de l'inverse vu qu'elle
      //sera modifié
      temp=Allocation(n,temp); 
      Triangle(n,temp);
     Inverser_matrice(n,mat,mat_inv);
     printf("\nL'inverse est: \n");
      Afficher_matrice(n,mat_inv);
      printf("\nmatrice apres operation\n");
       Afficher_matrice(n,mat);
      //Allocation de la matrice inverse calculé 
      mat_id=Allocation(n,mat_id); 
      Identite(n,temp,mat_inv,mat_id) ; 
      printf("\nMatrice identitaire apres calcule de l'inverse est :\n") ;
      Afficher_matrice(n, mat_id);
     Free_Alloc(n,mat); 
      Free_Alloc(n,mat_inv);
      Free_Alloc(n,mat_id);
      Free_Alloc(n,temp); 
    return 0 ;
}
float ** IdentityMat(int taille, float **Mat) {
   for(int i=0; i<taille; i++){
     for(int j=0; j<taille; j++){
      if(i==j) Mat[i][j]=1 ;
      else Mat[i][j]=0 ;
   }
   }
   return Mat ;
}
void Inverser_matrice(int taille, float ** matrice, float ** matrice_inv){
   matrice_inv=IdentityMat(taille,matrice_inv);
   printf("\nLa matrice identitaire est :\n");
   Afficher_matrice(taille, matrice_inv);
   for (int k=0 ; k<taille ; k++){
    for(int i=1; i<taille; i++){
        for(int j=0 ; j<taille; j++){
            float var=matrice[i][j] ;
            if(i!=j){ //pour épargner le pivot
          matrice[i][j]+=(-1*matrice[k][k])*var ;
          matrice_inv[i][j]+=(-1*matrice_inv[k][k])*var ;
            }
    }
    }
}

    // cette ligne a été ajouté pour que le resultat concorde avec la pratique
     for(int i=0 ; i<taille ; i++){
        for(int j=0 ; j<taille ; j++){
          if( (i+j)%2==0 && i!=j)  matrice_inv[i][j]*=-1 ;
        }
     } 
        
}
void Identite(int taille, float ** Mat, float ** Matinv, float ** MatI){
      for(int l=0; l< taille; l++){
        for(int c=0 ; c< taille ; c++){
            float v=0 ;
            for(int k=0 ; k<taille; k++)
               v+=Mat[l][k]*Matinv[k][c];
        MatI[l][c]=v;
        }
      }
}
float ** Allocation(int taille, float **Mat){
    Mat=(float **)calloc(taille,sizeof(float*)) ;
    for (int i=0; i< taille ; i++){
        Mat[i]=(float *) calloc(taille,sizeof(float)) ;
    }

     //printf("j'ai fini l'allocation ") ;
    // Triangle(taille ,Mat ); 
     return Mat ;
}
void Free_Alloc(int taille, float **Mat){
    for(int i=0; i< taille ; i++){
        free(Mat[i]) ;
    }
    free(Mat) ;
}
void Afficher_matrice(int taille, float ** matrice) {
 for(int i=0;i<taille;i++){
 for(int j=0;j<taille;j++){
    printf("%d \t",(int)matrice[i][j]);
 }
 printf("\n");
 }
}
 
void Triangle(int taille, float **Mat) {
    for(int i=0 ;i<taille; i++){
        for(int j=0;j<taille ; j++){
            if (j>i) Mat[i][j]=0 ;
            else{
           if(i==j) Mat[i][j]=1 ;
           else{
             Mat[i][j]=Mat[i-1][j-1]+Mat[i-1][j];
              
           }
           }
        }
    }
    // Afficher_matrice(taille,Mat );

}