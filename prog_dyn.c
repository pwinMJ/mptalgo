#include "math.h"
#include "affichage.c"

/*
  void progdynrec(struct liste_mots * lm, 
  struct liste_sol * ls, int m, int ** valopt, int i, int reste){
  int taillemot, penalite, r1 = -1, r2 = -1, res = -1;
  
  if(0 <= valopt[i][reste]){
  printf("CAS ARRET 1 : i= %d reste= %d m= %d\n", i, reste,m);
  //return ls;
  return;
  }
  if(i == lm->nb){
  printf("CAS ARRET 2 : i= %d reste= %d m= %d\n", i, reste,m);
  valopt[i][reste] = 0;
  //return ls;
  return;
  }
  
  if(i < lm->nb){
  //if reste=m
    
  taillemot = strlen(lm->mots[i]);
  printf("taillemot=%d\n", taillemot);

  if(taillemot < 0){
  printf("Erreur:progdynrec():strlen()=%d\n",taillemot);
  //return NULL;
  return;
  }

  //Cas ou l'on choisit de mettre le mot sur la ligne

  //Cas premier mot sur la ligne
  if(reste == m){
  if(taillemot <= reste){
  //ls = progdynrec(lm,ls,m,valopt,i+1,reste-taillemot);
  progdynrec(lm,ls,m,valopt,i+1,reste-taillemot);
  printf("i+1=%d reste-taillemot=%d\n", i+1, reste-taillemot);

  r1 = valopt[i+1][reste-taillemot];

  }else{
  printf("Erreur:progdynrec(): Le mot est trop grand pour une seule ligne\n");
  exit(0);
  }
  //Cas suite mots
  }else{
  if(taillemot < reste){


  //ls = progdynrec(lm,ls,m,valopt,i+1,reste-taillemot-1);
  progdynrec(lm,ls,m,valopt,i+1,reste-taillemot-1);
  printf("i+1=%d reste-taillemot-1=%d\n", i+1, reste-taillemot-1);
  r1 = valopt[i+1][reste-taillemot-1];

  }
  }
    
  //Cas ou l'on choisit de pas de mettre le mot sur la ligne
  if(reste < m){

  //ls = progdynrec(lm,ls,m,valopt,i,m);
  progdynrec(lm,ls,m,valopt,i,m);
  penalite = ((int)pow((double)reste, 3));
  r2 = valopt[i][m] + penalite;
  }
    
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
  //return NULL;
  return;
  }
  
  //return ls;
  return;
  }
*/

void progdynrec(struct liste_mots * lm, int i, int m, int reste, int ** valopt){
  int res = 2147483647, res2 = 2147483647,  taillemot, penalite;
  if(i >= lm->nb){
    valopt[i][reste]=0;
    return;
  }
  taillemot = strlen(lm->mots[i]);

  //on passe a une nouvelle ligne

  if(reste < m){
    penalite = (int)pow((double)reste,3);
    res = penalite;
    if(valopt[i][reste] == -1) 
      progdynrec(lm,i,m,m,valopt);
    res += valopt[i][m];
  }

  //on deduit le reste de la ligne

  //debut de ligne
  if(reste == m){
    if(valopt[i+1][reste-taillemot] == -1) 
      progdynrec(lm,i+1,m,reste-taillemot,valopt);

    res2 = valopt[i+1][reste-taillemot];    

    if(res2 < res){
      res = res2;
    }else{
      //TODO
    }
  }//reste de ligne
  else{
    if(taillemot < reste){
      if(valopt[i+1][reste-taillemot-1] == -1)
	progdynrec(lm, i+1, m, (reste-taillemot-1),valopt);

      res2 = valopt[i+1][reste-taillemot-1];
     
      if(res2 < res){
	res = res2;
      }else{
	//TODO
      }

    }else{
      //Cas ou l'on a du sauter une ligne
    }
  }
  valopt[i][reste]=res;
  return;
}

struct liste_sol * progdyn(struct liste_mots * lm, int m){
  struct liste_sol * ls = NULL;
  int i, j;
  int ** valopt = NULL;

  //Declaration du tableau pour la récursion dynamique
  valopt = (int **)malloc(sizeof(int *) * (lm->nb+1));
  if(valopt == NULL){
    printf("Erreur:progdyn():malloc()\n");
    return NULL;
  }
  for(i = 0; i <= lm->nb; i++){
    valopt[i] = (int *)malloc(sizeof(int) * (m+1));
    if(valopt[i] == NULL){
      printf("Erreur:progdyn():malloc()\n");
      return NULL;
    }
  }


  //Initialisation du tableau à -1 pour la récursion dynamique
  for(i = 0; i <= lm->nb; i++){
    for(j = 0; j <= m; j++){
      valopt[i][j] = -1;
    }
  }
  /*
    struct liste_sol * progdynrec(struct liste_mots * lm, 
    struct liste_sol * ls, int m, int ** valopt, int i, int reste){
  */
  
  //ALGO PROG DYN REC
  //ls = progdynrec(lm, ls, m, valopt, 0, m);
  //progdynrec(lm, ls, m, valopt, 0, m);
  //int prodynrec(struct liste_mots * lm, int i, int m, int reste){

  progdynrec(lm, 0, m, m, valopt);
  
  for(i = 0; i <= lm->nb; i++){
    for(j = 0; j <= m; j++){
      printf("valopt[%d][%d]=%d\n", i, j, valopt[i][j]);
    }
  }
  printf("\nLa valeur de retour est =%d\n", valopt[0][m]);
  /*
    if(valopt[0][m] == -1){
    printf("\nErreur:progdyn(): progdynrec() n'a pas renvoyé de résultat !\n");    
    }else{
    printf("\nLa somme totale d'espaces en fin de ligne est: %d\n",valopt[0][m]);
    }
  */
  return ls;
}


//TODO


int main(int argc, char ** argv){
  int m = 11;
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

  //ALGO PROG DYN
  ls = progdyn(lm, m);

  printf("\n");

  affiche_sol(ls);

  printf("\n");

  affiche_mots(lm, ls, m);
  
  free(lm);
  free(ls);
  return 0;
}
