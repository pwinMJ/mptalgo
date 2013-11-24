#include <stdlib.h>
#include <stdio.h>
#include "liste_solution.c"
#include "ens_mots.c"
#define ESPACE ' '

/*
struct liste_sol * prog_dyn(char ** liste_mots, int max){
  struct liste_sol * ls = NULL;
  int res = 0;
  
  return ls;
}
*/

//TODO: A METTRE DANS main.c
void affiche_mots(char ** liste_mots, struct liste_sol * ls, int max){
  int i, taille_mot, taille_ligne ,ecrits;
  char buf[max+3];
  char * buf_cour;
  char espace = ' ';
  buf[0] = '|';
  buf[max+1] = '|';
  buf[max+2] = '\n';
 
  
  while(ls != NULL){
    taille_ligne = max;
    buf_cour = buf+1;
    for(i = ls->i; i <= ls->j; i++){
      buf_cour = strcpy(buf_cour, liste_mots[i]);
      taille_mot = strlen(liste_mots[i]);
      taille_ligne -= taille_mot;
      buf_cour += taille_mot;
      if(0 < taille_ligne){
	*buf_cour = espace;
	buf_cour++;
      }
    }
    for(i=(max-taille_ligne); i <= max; i++){
      buf[i] = espace;
    }
    ecrits = write(STDOUT_FILENO, buf, max+2);
    if(ecrits < 0){
      perror("write:affiche_mots()");
      return;
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

  struct liste_sol * ls = NULL;
  ls = ajoute_element(ls , 0, 2);
  ls = ajoute_element(ls,  3, 5);
  ls = ajoute_element(ls,  6, 7);
  affiche_mots(liste_mots, ls, 15);
  
  free(ls);
  return 0;
}
