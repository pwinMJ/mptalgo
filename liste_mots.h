struct liste_mots{
  unsigned int nb;
  char ** mots;
};

struct liste_mots * cons_liste_mots(struct liste_mots * lm, char * fichier);
