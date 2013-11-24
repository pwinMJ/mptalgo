#include <stdlib.h>
#include <stdio.h>
#include "liste_solution.c"

char ** prog_dyn(int nb_mots, char ** liste_mots, int m){
  
  return liste_mots;
}


void affiche_mots(int nb_mots, char ** liste_mots ){
  
}

int main(int argc, char ** argv){

  struct liste_sol * ls = NULL;
  //int taille_ls;

  ls = alloue_element(ls);
  ls->i =1;
  ls->j= 2;
  ls->suivant = (struct liste_sol *) 3;
  ls->suivant = alloue_element(ls->suivant);
  ls->suivant->i = 3;
  ls->suivant->j = 4;
    
  ajoute_element(ls, 7, 8);
  ajoute_element(ls,  7, 8);
ajoute_element(ls,  7, 8);
ajoute_element(ls,  7, 8);

 affiche(ls);
  
  return 0;
}
