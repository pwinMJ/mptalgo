#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int glouton ( char** mots, int nbmots,int m){
  int i = 1;
  int taille;
  while(i < nbmots ){ 
   
    taille = m;  
    //cas du premier mot de la ligne
     if(strlen(mots[i]) <= m && taille>0){
      taille=taille - strlen(mots[i]);   
      printf("%s",mots[i]);      
      i++;
    }    
     if(i==nbmots) {
       printf("\n");
       break;
     }
     //cas des autres mots
     while(strlen(mots[i]) <= taille && taille>0){
  printf(" %s",mots[i]);
  if (strlen(mots[i])<taille )
    taille=taille - ( strlen(mots[i])) - 1;      
  i++;
  
  //condition darret
  if(i==nbmots) break;
       }//fin while
     printf("\n");
  }
  return 0;
}



int main(int argc, char ** argv){
  //printf("argc  %d \n",argc); 
  glouton(argv, argc, 17);
  return 0;
}
