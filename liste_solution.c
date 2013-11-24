struct liste_sol{
  int i;
  int j;
  struct liste_sol * suivant;
};

struct liste_sol * alloue_element(struct liste_sol * ls, int i, int j){
   ls = malloc(sizeof(struct liste_sol));
   ls->i = i;
   ls->j = j;
  return ls;
}

struct liste_sol * ajoute_element(struct liste_sol * ls, int i, int j){
  struct liste_sol * tmp = ls;
 if(ls == NULL){
   ls = alloue_element(ls,i,j);
   return ls;
 }
  while(tmp->suivant != NULL){
    
    tmp = tmp->suivant;
  }
  tmp->suivant = alloue_element(tmp->suivant,i,j);
  return ls;
}

void affiche_sol(struct liste_sol * ls){
  struct liste_sol * tmp = ls;
  while(tmp != NULL){
    printf("i=%d j=%d *p=%p\n", tmp->i, tmp->j, tmp->suivant);
    tmp = tmp->suivant;
  }
  return;
}


