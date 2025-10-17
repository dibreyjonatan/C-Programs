#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct{
 int x ;
 int y ;
}position ;

typedef struct{
  int z ;
  position* pos_xy ;

}space ;

typedef struct{
   char sym ;
 space* pos_xyz ;
}vector ;

int main(){

   // The definition below shows a segmentation fault because when you have nested structures with pointers * , you have to reserve memory
   // else you'll violate it 
    vector v ; 
    v.sym='A' ;
    //v.pos_xyz est equivalent en p de *p 
    v.pos_xyz=malloc(sizeof(space)) ;
    v.pos_xyz->pos_xy=malloc(sizeof(position)) ;
   v.pos_xyz->z=1 ;
   v.pos_xyz->pos_xy->x = 1 ;
    v.pos_xyz->pos_xy->y = 1 ;
   
     //analyse en utilisant gdb j'ai compris comment faire l'affichage
       // p *(v.pos_xyz->pos_xy)    --> affiche la structure position sous gdb 
       
    // Analyse deduite après utiliser gdb 
    //liberer la memoire 
    /*
    ne pas liberer l'espace memoire comme ca 
     free(v.pos_xyz) ;
     free(v.pos_xyz->pos_xy) ;  
     */
    
    //liberer le dernier étage avant de liberer le premier 
    //si non on aura un segmentation fault 
     free(v.pos_xyz->pos_xy) ;  
      free(v.pos_xyz) ;
 
 return 0 ; 
}

/*

// Trying to understand the basics of structures 

typedef struct{
 int x ;
 int y ;
}position ;

typedef struct{
  position a ; 
  
}origin ;

typedef struct{
 
 origin b ; 
}plan ;

int main (){
    int A[MAX] ;
    position pos ;
    pos.x=1 ;
    pos.y=2 ;
    position mov={.x=3, .y=4 } ;
     
    printf("%d %d\n",(pos.x-mov.x),(pos.y-mov.y)) ;
    
    printf("%x\n",&pos.x) ; 
    
    for(int i=0 ; i<MAX ; i++){
      A[i]=i%2 ;
    }
    
    //conclusion : when the nested structures have no pointers, it will never give a segfault error 
     plan t ;
     t.b.a.x=1 ;
     t.b.a.y=1 ; 
     
}

*/
