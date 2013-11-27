#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "affichage.c"


struct liste_sol * glouton ( char** mots, int nbmots,int m){
  int i = 1,deb,fin;
  int taille;
  struct liste_sol * ls;
    printf("i1=%d \n",i);
      while(i < nbmots ){ 
    deb =i;  
    taille = m;  
    //cas du premier mot de la ligne
    printf("i2=%d",i);
    if(strlen(mots[i]) <= m && taille>0){
      taille=taille - strlen(mots[i]);   
      //printf("%s",mots[i]);      
      i++;
    }
    
    if(i==nbmots) {
      // printf("\n");
      break;
    }
    //cas des autres mots
    printf("i3=%d",i);
    while( (strlen(mots[i]) +1) <= taille){
      //printf(" %s",mots[i]);
      //if (strlen(mots[i])<taille )
      taille=taille - ( strlen(mots[i])) - 1;      
      i++;     
      printf("fin = %d",fin);
      //condition darret
      if(i==nbmots) break;
    }//fin while
      fin=i-1;
      ls=ajoute_element(ls,deb,fin);
  }
    
  return ls;
}



int main(int argc, char ** argv){
  struct liste_sol*ls=NULL; 
  printf("argc =%d\n",argc);
  ls= glouton(argv, argc, 17);
  //affiche_sol(ls);
  //affiche_mots(argv,ls,17);
  return 0;
}
