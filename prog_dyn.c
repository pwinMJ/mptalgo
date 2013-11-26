
#include "ens_mots.c"
#include "affichage.c"

int prog_dyn_rec(char ** liste_mots, int max, int ** val_opt){
  
  return;
}

struct liste_sol * prog_dyn(char ** liste_mots, int max){
  struct liste_sol * ls = NULL;
  int res = 0;
  
  

  printf("La somme totale d'espaces en fin de ligne est: %d",res);
  return ls;
}


//TODO


int main(int argc, char ** argv){
  int i, j, nb_mots = 5, max = 10;
  if (argc < 2){
    printf("usage: ./prog_dyn <fichier>\n");
    return 0;
  }

  char ** liste_mots = cons_liste_mots(argv[1]);

  struct liste_sol * ls = NULL;
  ls = ajoute_element(ls , 0, 1);
 
  ls = ajoute_element(ls,  2, 3);
  ls = ajoute_element(ls,  4, 5);

  affiche_mots(liste_mots, ls, max);
  

  int ** val_opt = (int **)malloc(sizeof(int *) * nb_mots);
  for(i = 0; i < 10; i++){
    val_opt[i] = (int *)malloc(sizeof(int) * 10);
    for(j = 0; j < 10; j++){
      val_opt[i][j] = 0;
    }
  }
  
  prog_dyn_rec(liste_mots, 10, val_opt);
  
  for(i = 0; i < 10; i++){
    val_opt[i] = (int *)malloc(sizeof(int) * 10);
    for(j = 0; j < 10; j++){
      val_opt[i][j] = 0;
    }
  }
  printf("val_opt[0][0]=%d\n", val_opt[0][0]);

  free(val_opt);
  free(liste_mots);
  free(ls);
  return 0;
}
