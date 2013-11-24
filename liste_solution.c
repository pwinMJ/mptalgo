struct liste_sol{
  int i;
  int j;
  struct liste_sol * suivant;
};

 struct liste_sol * alloue_element(struct liste_sol * ls){
   ls = malloc(sizeof(struct liste_sol));
  return ls;
}

struct liste_sol * ajoute_element(struct liste_sol * ls, int i, int j){
  struct liste_sol * tmp = ls;
  while(tmp->suivant != NULL){
    tmp = tmp->suivant;
  }
  tmp->suivant = alloue_element(tmp->suivant);
  tmp->suivant->i = i;
  tmp->suivant->j = j;
  return tmp->suivant;
}

void affiche(struct liste_sol * ls){
  while(ls != NULL){
    printf("i=%d j=%d *p=%p\n", ls->i, ls->j, ls->suivant);
    ls = ls->suivant;
  }
  return;
}

