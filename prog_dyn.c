#include <math.h>
#include "affichage.c"

struct liste_sol * progdynrec(struct liste_mots * lm, 
			      struct liste_sol * ls, int m, int ** valopt, int i, int reste){
  int taillemot, r1 = -1, r2 = -1, res = -1;
  if(i == lm->nb){
    valopt[i][reste] = 0;
    return ls;
  }
  if(i < lm->nb){
    //if reste=m
    
    taillemot = strlen(lm->mots[i]);
    if(taillemot < 0){
      printf("Erreur:progdynrec():strlen()\n",taillemot);
      return NULL;
    }
    //Cas ou l'on choisit de mettre le mot sur la ligne
    if(reste = m){
      ls = progdynrec(lm,ls,m,valopt,i+1,reste-taillemot);
      r1 = valopt[i+1][reste-taillemot];
    }else{
      if(taillemot < reste){
	ls = progdynrec(lm,ls,m,valopt,i+1,reste-taillemot-1);
	r1 = valopt[i+1][reste-taillemot-1];
      }
    }
    
    //Cas ou l'on choisit pas de mettre le mot sur la ligne
    ls = progdynrec(lm,ls,m,valopt,i,m);
    r2 = valopt[i][m] + ((int)pow((double)reste, 3));
    
    if(0 <= r1) {
      res = r1;
    }
    if(0 <= r2){
      if (r2 < res)
	res = r2;
    } 
    valopt[i][reste] = res;
    
  }else{
    printf("Erreur:progdynrec():erreur d'indice\n");
    return NULL;
  }
  return ls;
}

struct liste_sol * progdyn(struct liste_mots * lm, int m){
  struct liste_sol * ls = NULL;
  int i, j;
  int ** valopt = NULL;

  //Declaration du tableau pour la récursion dynamique
  valopt = (int **)malloc(sizeof(lm->nb+1));
  if(valopt == NULL){
    printf("Erreur:progdyn():malloc()\n");
    return NULL;
  }
  for(i = 0; i <= lm->nb; i++){
    valopt[i] = (int *)malloc(sizeof(m+1));
    if(valopt[i] == NULL){
      printf("Erreur:progdyn():malloc()\n");
      return NULL;
    }
  }
  //Initialisation du tableau pour la récursion dynamique
  for(i = 0; i <= lm->nb; i++){
    for(j = 0; j <= m; j++){
      valopt[i][j] = -1;
    }
  }

  ls = progdynrec(lm, m, valopt);

  //printf("La somme totale d'espaces en fin de ligne est: %d",res);
  return ls;
}


//TODO


int main(int argc, char ** argv){
  int m = 17;
  int i;
  struct liste_mots * lm = NULL;
  struct liste_sol * ls = NULL;
  

  if (argc < 2){
    printf("usage: ./prog_dyn <fichier>\n");
    return 0;
  }

  lm = cons_liste_mots(lm, argv[1]);
  /*
    valopt = (int **)malloc(sizeof(int *)*lm->nb);
    for(i = 0; i < lm->nb; i++){
    valopt[i] = (int *)malloc(sizeof(int) *(m+1));
    }
  */

  for(i=0; i < lm->nb; i++){
    printf("%s\n", lm->mots[i]);
  }

  ls = progdyn(lm, m);

  printf("\n");

  affiche_sol(ls);

  printf("\n");

  affiche_mots(lm, ls, m);
  /*
    for(i = 0; i < lm->nb; i++){
    for(j = 0; j < m+1; j++){
    valopt[i][j] = -53;
    }
    }
    printf("valopt[0][0]=%d\n", valopt[0][0]);
    progdyn(lm,m,valopt);
    printf("valopt[0][0]=%d\n", valopt[0][0]);
  */
  free(lm);
  free(ls);
  return 0;
}
