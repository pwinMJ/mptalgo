#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "affichage.c"
#include "ens_mots.c"

struct liste_sol * glouton (struct liste_mots * lm, int m){
  
  int i, j = 0, resteligne,taillemot;
  struct liste_sol * ls = NULL;
 
  while(j < lm->nb){
    i = j;
    resteligne = m;

    //Cas du premier mot
    taillemot = strlen(lm->mots[j]);
    if(resteligne < taillemot){
      printf("Erreur:glouton(struct liste_mots *, int)\n");
      printf("Mot trop grand pour M: %s\n", lm->mots[j]);
      return NULL;
    }
    resteligne -= taillemot;
    j++;

    //Cas des mots suivants
    while(j < lm->nb){
      
      taillemot = strlen(lm->mots[j]);
      j++;
      if(resteligne < taillemot){
	ls = ajoute_element(ls, i, j-1);
	break;
      }
      resteligne -= taillemot + 1;
    }

  }
  
  return ls;
}



int main(int argc, char ** argv){

  struct liste_sol * ls = NULL;
  struct liste_mots * lm = NULL;
  int i;
  int m = 17;

  if(argc < 2){
    printf("usage: ./glouton <nomfichier>\n");
    return 0;
  }

  lm = cons_liste_mots(lm, argv[1]);

  printf("lm->nb=%d\n", lm->nb);

  printf("lm=%p\n", lm);
  
  
  for(i = 0; i < lm->nb; i++){
    printf("%s\n", lm->mots[i]);
  }
  printf("\n");
  

  
  ls = glouton(lm, m);
  affiche_sol(ls);
  affiche_mots(lm, ls, m);
  


  return 0;
}
