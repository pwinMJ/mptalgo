#include<stdio.h>
#include<stdlib.h>
#include<string.h>




int glouton (char** mots, int nbmots,int m){
  //m: taille de la ligne
  //nbmots : nbmots dans la list
  
  int deb = 0 ,i = 0;
  int taille = m;	
  printf("i=%d , deb =%d",i,deb); 
      while(i < nbmots ){
    taille = m;
    //deb : l'indice du premier mot de la liste achaque iteration
    deb=i;
    //cas du premier mot de la ligne
    if(strlen(mots[i]) <= m){
      taille=taille - strlen(mots[i]);
      i++;
    }
    
    else
      //mots trop long
      printf("ce mots %s est plus long que la ligne ",mots[i]); 
    printf("i=%d , deb =%d",i,deb); 
    //cas des mots suivants
      printf("%s",mots[i]);
	
	while(strlen(mots[i]) <= taille  ){
	printf("%s",mots[i]);
	if (strlen(mots[i])<taille )
	  taille=taille - ( strlen(mots[i])) - 1;      
	else taille=taille - (strlen(mots[i]));
	i++;
      }
	
    //printf("%s",mots[deb]);
    deb++;
    printf("i=%d , deb =%d",i,deb); 
    /* 
    while(deb<i){
     printf(" %s",mots[deb]);
     
     }    
    */
  }
  return 0;
  
  
} 
int main(int argc, char ** argv){
  printf(" %d",argc); 
  glouton(argv, argc, 17);
  return 0;
}
