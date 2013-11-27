#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "affichage.c"
#include "ens_mots.c"
struct liste_sol * glouton ( char** mots, int nbmots,int m){
  int i = 1,deb=0,fin=0;
  struct liste_sol * ls =NULL;
  int taille;
  while(i < nbmots ){
 
    taille = m;  
    deb=i;
    //cas du premier mot de la ligne
    if(strlen(mots[i]) <= m && taille>0){
      taille=taille - strlen(mots[i]);        
      i++;
    }    
    if(i==nbmots)  break;
    
    //cas des autres mots
    while(strlen(mots[i]) < taille && taille>0){
      taille=taille - ( strlen(mots[i])) - 1;      
      i++;
      
      //condition darret
      if(i==nbmots) break;
    }//fin while
    fin=i-1;
    ls=ajoute_element(ls,deb,fin);
  }
  return ls;
}



int main(int argc, char ** argv){
  struct liste_sol * ls =NULL;
  printf("\n argc = %d \n",argc);
  //NE MARCHE PAS 
  //char ** fich=cons_liste_mots(argv[1]);
  ls= glouton(argv, argc, 17);
  affiche_mots(argv,ls,17);
  return 0;
}
