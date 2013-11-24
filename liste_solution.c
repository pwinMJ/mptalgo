struct liste_sol{
  int i;
  int j;
  struct liste_sol * suivant;
};

 struct liste_sol * alloue_element(struct liste_sol * l){
   l = malloc(sizeof(struct liste_sol));
  return l;
}

struct liste_sol * ajoute_element(struct liste_sol * l, int taille, int i, int j){
  int k;
  struct liste_sol * tmp = l;
  for(k=0; k < taille; k++){
    tmp = tmp->suivant;
  }
  tmp->suivant = alloue_element(tmp->suivant);
  return tmp->suivant;
}


