#include "affichage.c"

int progdynrec(struct liste_mots * lm, int m, int ** val_opt){
  
  return 0;
}

struct liste_sol * progdyn(struct liste_mots * lm, int m){
  struct liste_sol * ls = NULL;
  int res = 0;
  
  

  printf("La somme totale d'espaces en fin de ligne est: %d",res);
  return ls;
}


//TODO


int main(int argc, char ** argv){
  //int m = 17;
  int i;
  struct liste_mots * lm = NULL;
  struct liste_sol * ls = NULL;
  if (argc < 2){
    printf("usage: ./prog_dyn <fichier>\n");
    return 0;
  }
  lm = cons_liste_mots(lm, argv[1]);
  for(i=0; i < lm->nb; i++){
    printf("%s\n", lm->mots[i]);
  }


  free(lm);
  free(ls);
  return 0;
}
