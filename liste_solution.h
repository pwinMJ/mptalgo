//si la liste est longue, peut etre modifier les int en short

/*permet d'etablir la solution d'une liste de mots 
  entre l'indice i et j pour chaque ligne
*/
struct liste_sol{
  int i;
  int j;
  struct liste_sol * suivant;
};

/*
  Alloue de la memoire pour un seul element de la liste
 */
struct liste_sol * alloue_element(struct liste_sol * ls, int i, int j);

/*
  Ajoute un couple d'indice i,j a la fin de la liste 
  Renvoie son dernier element de la liste cree
 */
 struct liste_sol * ajoute_element(struct liste_sol ls, int i, int j);

/*
Affiche les elements de la liste
*/
void affiche_sol(struct liste_sol * ls);
