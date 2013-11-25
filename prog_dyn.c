#include <stdlib.h>
#include <stdio.h>
#include "liste_solution.c"
#include "ens_mots.c"
#define ESPACE ' '
#define CHAR_FIN_LIGNE '*'

/*
struct liste_sol * prog_dyn(char ** liste_mots, int max){
  struct liste_sol * ls = NULL;
  int res = 0;
  
  return ls;
}
*/

//TODO
void affiche_mots(char ** liste_mots, struct liste_sol * ls, int max){
  int i, taille_mot, reste_ligne ,ecrits;
  char buf[max+3];
  char * buf_cour;

  buf[0] = '|';
  buf[max+1] = '|';
  buf[max+2] = '\n';
 
  
  while(ls != NULL){
    
    reste_ligne = max;
    buf_cour = buf+1;
    
    for(i = ls->i; i <= ls->j; i++){
      if(ls->i < i){
	*buf_cour = ESPACE;
	buf_cour++;
	reste_ligne--;
      }
      taille_mot = strlen(liste_mots[i]);
      if(reste_ligne < taille_mot){
	printf("erreur:affiche_mots():taille mot trop grande\n");
	return;
      }
      buf_cour = strncpy(buf_cour, liste_mots[i],taille_mot); 
      reste_ligne -= taille_mot;
      buf_cour += taille_mot;
    }
    for(i=(max-reste_ligne)+1; i <= max; i++){
      buf[i] = CHAR_FIN_LIGNE;
    }
    
    ecrits = write(STDOUT_FILENO, buf, max+3);
    if(ecrits < 0){
      perror("write:affiche_mots()");
      return;
    }
    
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
  ls = ajoute_element(ls , 0, 1);
 
  ls = ajoute_element(ls,  2, 3);
  ls = ajoute_element(ls,  4, 4);

  affiche_mots(liste_mots, ls, 10);
  
  free(liste_mots);
  free(ls);
  return 0;
}
