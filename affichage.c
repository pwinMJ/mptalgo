#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "liste_solution.c"
#include "liste_mots.c"

#define ESPACE ' '
#define CHAR_FIN_LIGNE '*'

void affiche_mots(struct liste_mots * lm, struct liste_sol * ls, int max){
  int i, taille_mot, reste_ligne ,ecrits;
  char buf[max+3];
  char contour[max+3];
  char * buf_cour;

  for(i = 0; i < max+2; i++){
    contour[i]= '-';
  }
  contour[max+2] = '\n';
  ecrits = write(STDOUT_FILENO, contour, max+3);
  if(ecrits < 0){
    perror("write:affiche_mots()");
    return;
  }
  
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
      taille_mot = strlen(lm->mots[i]);
      if(reste_ligne < taille_mot){
	printf("Erreur:affiche_mots():mot trop grand: %s\n", lm->mots[i]);
	return;
      }
      buf_cour = strncpy(buf_cour, lm->mots[i],taille_mot); 
      if (buf_cour == NULL){
	printf("Erreur:affiche_mots(): strncpy()\n");
	return;
      }
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
  
  ecrits = write(STDOUT_FILENO, contour, max+3);
  if(ecrits < 0){
    perror("write:affiche_mots()");
    return;
  }
  
  return;
}
