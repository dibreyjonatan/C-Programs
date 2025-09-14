#include<stdio.h>

int (*p)(int,int);
int sum(int,int);
/*

void copier(X,i,Y,j,n){
   int index,inc=0; 
    for(index=i ; index < i+ n ; index++){
       Y[j+inc]=X[index] ;
       inc++ ;
}
}

*/
int main(){
    int tab[5]={7,0,3,9,4} ;
    int i,j,c,elmax ;   
     //affichage 
    printf("Avant tri :") ;
    for(i=0;i<5;i++){
        printf("%d \t",tab[i]);
    }
    //trie par selection
    for(i=0;i<5-1;i++){
        elmax=i ;
        for(j=i+1;j<5;j++){
            if(tab[elmax]<tab[j]){
                c=tab[elmax];
                tab[elmax]=tab[j];
                tab[j]=c ;
            }
        }
    }

    //affichage 
    printf("\nApres tri : ") ;
    for(i=0;i<5;i++){
        printf("%d \t",tab[i]);
    }

    typedef enum{
        false,
        true
    }bool ;
    bool data=true ;
    printf("\n%d",data) ;
    if(data==0 ) printf("je suis faux");
    else printf("je suis vrai") ;

    p=sum ;
    int res=(*p)(3,5);
    printf("%d",res) ;

    return 0 ;
}

int sum(int a, int b){
    return (a+b); 
}