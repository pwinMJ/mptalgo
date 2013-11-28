#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "affichage.c"

void  diviser_pour_regner(struct liste_mots *lm,struct liste_sol * ls,int deb,int fin, int m){
  int i,som_mots=0;
  for(i = deb;i <= fin; i++)
    som_mots=+strlen(lm->mots[i]);
  if((som_mots +fin-deb)<=m){
   
    ls=ajoute_element(ls,deb,fin);
    affiche_sol(ls);
    return;
  }
  else{
    diviser_pour_regner(lm,ls,deb,(deb+fin)/2,m);
    diviser_pour_regner(lm,ls,(deb+fin)/2+1,fin,m);
  }
return;
}

int main(int argc, char ** argv){  
  struct liste_sol * ls =NULL;
  struct liste_mots * lm=NULL;
  int i,m = 17;
  if(argc<2){
    printf("arg manquant");
    return 0;
  }
  lm=cons_liste_mots(lm,argv[1]);
  for(i = 0; i < lm->nb; i++){
    printf("%s\n", lm->mots[i]);
  }
affiche_mots(lm,ls,m);
  diviser_pour_regner(lm,ls,0,lm->nb-1,m);
  affiche_mots(lm,ls,m);  
  return 0;
}
