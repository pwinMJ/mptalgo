#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include "ens_mots.h"
#define BUFSIZE 8192
#define DICT_BLOC 1024
#define LIGNE 1024

struct liste_mots{
  unsigned int nb;
  char ** mots;
};


struct liste_mots * cons_liste_mots(struct liste_mots * lm, char * fichier){
  int fd;
  int rc;
  
  int taille_dict = DICT_BLOC;
  char * buf = (char *)malloc(sizeof(char)*BUFSIZE);
  char * mot_tmp = NULL;
  char * mot_coupe = NULL;
  char * i = NULL;
  char * j = NULL;
  int taille;  
  char separateur = ' ';
  
  lm = (struct liste_mots *)malloc(sizeof(struct liste_mots));
  lm->nb = 0;
  lm->mots = (char **)malloc(sizeof(char *) * DICT_BLOC);

  //premier argument = nom fichier
  //ouverture du fichier
  fd = open(fichier, O_RDONLY);
  if(fd < 0){
    perror("open:cons_liste_mots(struct liste_mots *, char *)");
    return NULL;
  }
  
  printf("\nDébut de la construction de la liste de mots...\n");

  do {

    rc = read(fd, buf, BUFSIZE);
    if(rc < 0){
      perror("read:cons_liste_mots(struct liste_mots *, char *)");
      return NULL;
    }
    if(rc == 0) break;


    i = buf;
    while( (j = index(i, separateur)) && j-buf+1<=rc ){
      *j = '\0';
      
      if(*i != '\0'){
    
	if(mot_coupe){
	  mot_coupe = strcat(mot_coupe, i);
	  taille = strlen(mot_coupe)+1;
	  if(mot_coupe != NULL){
	    mot_tmp = (char *)malloc(sizeof(char)*taille);
	    mot_tmp = strcpy(mot_tmp, mot_coupe);
	    mot_coupe = NULL;
	  }
	}else{
	  taille = strlen(i)+1;
	  if(taille > 0){
	    mot_tmp = (char *)malloc(sizeof(char)*taille);
	    mot_tmp = strcpy(mot_tmp, i);
	  }
	}
	
	if(lm->nb >= taille_dict){
	  taille_dict *= 2;
	  lm->mots = (char **)realloc(lm->mots, sizeof(char *) * taille_dict);
	}
	if(lm->mots != NULL){
	  lm->mots[lm->nb] = (char *)malloc(sizeof(char) * taille);
	  lm->mots[lm->nb] = strcpy(lm->mots[lm->nb], mot_tmp);
	}else{
	  printf("erreur allocation memoire !\n");
	  return NULL;
	}
	lm->nb++;
      }
      
      
	
      
      if(j-buf+1<rc){
	i=j+1;	
      }else{
	i=j;
      }
    }
    
    if(*i != '\0'){
      mot_coupe = (char *)malloc(sizeof(char)*LIGNE);
      mot_coupe = strcpy(mot_tmp, i);
    }
    
  }while(rc > 0);
  
  printf("Fin de la construction de l'ensemble de mots\n\n");

  return lm;
}
