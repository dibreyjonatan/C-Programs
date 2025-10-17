#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14


// This code is an implementation of a class in c 
// it is a class that has private functions because of the use of static 
// the use of structure with pointer fonctions enables us to have a class-like implementation in C 



// firstly, inform the compiler of the presence of complexe before putting it inside it's own definition 
/*typedef struct{
    float real ;
    float img ; 
    float (*module)(complexe z) ;
    float (*phase)(complexe z) ;
  }complexe ;
*/
//correct definition is --->

//this informs the compiler that there will be a structure complexe and i want to use it as complexe
//so you can use typedef before the existence of the complexe

typedef struct complexe complexe ; 

// je peux faire des prototypes des autres fonctions en utilisant complexe grace à la ligne 26
// si je veux definir la fonction sans prototype, je dois le faire après la definition de complexe 
static float get_real(complexe z );
static float get_img(complexe z ) ; 

// define the structure complexe 
struct complexe{
float real ;
    float img ; 
    float (*module)(complexe z) ;
    float (*phase)(complexe z) ;
    float (*attributs[2])(complexe z) ; // this an array of pointer function, it accepts functions of type float name_functions(complexe z ) ;
};
//by using static the functions used here cannot be used in another file
static float calcul_module(complexe z ){

   return ( sqrtf(z.real*z.real +z.img*z.img ) ); 
}

static float calcul_phase(complexe z){
 
     if(z.img==0 && z.real==0)
       return 0 ;
     else {
     if (z.real==0 && z.img>0 ){
       return   PI ;
       }
       else {
       if ( z.real==0 && z.img<0 )
       return -PI ;
       else{
       // quadrant are named in the anti-clockwise direction
          float x= atanf(z.img/z.real) ;
          if (z.img >0 && z.real <0 ) // second quadrante
            x= x + PI ;
          if (z.img <0 && z.real < 0 ) // third quadrante
            x=x-PI ;  
            // nothing is done for the first and fourth quadrante 
            return x ;
         }
       }
 }      
}

  
int main(){
    
      complexe z ;
      z.real=1 ;
      z.img=1 ;
      z.module=calcul_module ;  //passing address of the functions to .module pointer in complexe 
      z.phase=calcul_phase ;
      z.attributs[0]=get_real; 
      z.attributs[1]=get_img ;

      //methode 2 
     // complexe z ={ .real=1 , .img=1 , .module=calcul_module , .phase=calcul_phase } ;
       printf("partie real : %f \n",z.attributs[0](z)) ;
       printf("partie imaginaire : %f \n",z.attributs[1](z)) ;
       
       printf("module: %f\n",z.module(z) ) ;
        printf("phase: %f\n",z.phase(z) ) ;
       
 return 0 ; 
}

static float get_real(complexe z ){

   return (z.real); 
}

static float get_img(complexe z ){

   return (z.img); 
}
