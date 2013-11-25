
#include "ens_mots.c"
#include "affichage.c"

struct liste_sol * prog_dyn(char ** liste_mots, int max){
  struct liste_sol * ls = NULL;
  //int res = 0;
  
  return ls;
}


//TODO


int main(int argc, char ** argv){

  if (argc < 2){
    printf("usage: ./main <fichier>\n");
    return 0;
  }

  char ** liste_mots = cons_liste_mots(argv[1]);

  struct liste_sol * ls = NULL;
  ls = ajoute_element(ls , 0, 1);
 
  ls = ajoute_element(ls,  2, 3);
  ls = ajoute_element(ls,  4, 5);

  affiche_mots(liste_mots, ls, 10);
  
  free(liste_mots);
  free(ls);
  return 0;
}
