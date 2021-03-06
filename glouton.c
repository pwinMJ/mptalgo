#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "affichage.c"


struct liste_sol * glouton (struct liste_mots * lm, int m){
  
  int i, j = 0, resteligne,taillemot;
  struct liste_sol * ls = NULL;
 
  while(j < lm->nb){
    i = j;
    resteligne = m;

    //Cas du premier mot
    taillemot = strlen(lm->mots[j]);
    if(resteligne < taillemot){
      printf("Erreur:glouton():mot trop grand pour M\n");
      return NULL;
    }
    resteligne -= taillemot;
    j++;

    //Cas des mots suivants
    while(j < lm->nb){
      
      taillemot = strlen(lm->mots[j]);
      
      if(resteligne < taillemot + 1){
	break;
      }
      
      resteligne -= (taillemot + 1);
      j++;
    }

    ls = ajoute_element(ls, i, j-1);

  }
  
  return ls;
}



int main(int argc, char ** argv){
  struct timeval deb_constr,fin_constr,deb_tri,fin_tri,deb_rech,fin_rech;
  long long diff;
  struct liste_sol * ls = NULL;
  struct liste_mots * lm = NULL;
  int m;

  if(argc < 3){
    printf("usage: ./glouton <nomfichier> <M>\n");
    return 0;
  }
  m = atoi(argv[2]);

  lm = cons_liste_mots(lm, argv[1]);

  printf("lm->nb=%d\n", lm->nb);

  printf("lm=%p\n", lm);
  
  
  ls = glouton(lm, m);
  affiche_sol(ls);
  
  affiche_mots(lm, ls, m);

  return 0;
}
