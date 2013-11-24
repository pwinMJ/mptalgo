#include <stdlib.h>
#include <stdio.h>
#include "liste_solution.c"
#include "ens_mots.c"

/*
struct liste_sol * prog_dyn(char ** liste_mots, int max){
  struct liste_sol * ls = NULL;
  int res = 0;
  
  return ls;
}
*/

//TODO: A METTRE DANS main.c
void affiche_mots(char ** liste_mots, struct liste_sol * ls/*, int max*/){
  int i;
  while(ls != NULL){
    for(i = ls->i; i <= ls->j; i++){
      printf("%s ",liste_mots[i]);
    }
    printf("\n");
    ls = ls->suivant;

  }
  return;
}

int main(int argc, char ** argv){
  if (argc < 2){
    printf("usage: ./main <fichier>\n");
    return 0;
  }

  char ** liste_mots = cons_liste_mots(argv[1]);
  /*while(*liste_mots != NULL){
    printf("%s\n", *liste_mots);
    liste_mots++;
  }*/

  struct liste_sol * ls = NULL;
  ls = ajoute_element(ls , 0, 2);
  ls = ajoute_element(ls,  3, 5);
  ls = ajoute_element(ls,  6, 17);
  affiche_mots(liste_mots, ls /*, int max*/);
  
  free(ls);
  return 0;
}
