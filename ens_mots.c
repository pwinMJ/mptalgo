#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define BUFSIZE 8192
#define DICT_BLOC 1024
#define LIGNE 1024

char ** cons_liste_mots(char * fichier){
  int fd;
  int rc;
  char ** liste_mots = (char **)malloc(sizeof(char *) * DICT_BLOC);
  int taille_dict = DICT_BLOC;
  char * buf = (char *)malloc(sizeof(char)*BUFSIZE);
  char * mot_tmp = NULL;
  char * mot_coupe = NULL;
  char * i = NULL;
  char * j = NULL;
  int taille;
  int nb_mots = 0;
  char separateur = ' ';
    
  //premier argument = nom fichier
  //ouverture du fichier
  fd = open(fichier, O_RDONLY);
  if(fd < 0){
    perror("open:cons_liste_mots(char *)");
    return 0;
  }
  
  printf("\nDébut de la construction de la liste de mots...\n");

  do {

    rc = read(fd, buf, BUFSIZE);
    if(rc < 0){
      perror("read:cons_liste_mots(char *)");
      return 0;
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
	
	if(nb_mots >= taille_dict){
	  taille_dict *= 2;
	  liste_mots = (char **)realloc(liste_mots, sizeof(char *) * taille_dict);
	}
	if(liste_mots != NULL){
	  liste_mots[nb_mots] = (char *)malloc(sizeof(char) * taille);
	  liste_mots[nb_mots] = strcpy(liste_mots[nb_mots], mot_tmp);
	}else{
	  printf("erreur allocation memoire !\n");
	    return 0;
	}	
	nb_mots++;
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
  return liste_mots;
}
