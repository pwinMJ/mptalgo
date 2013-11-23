#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<string.h>
#define T 1024

int glouton ( char** mots, int nbmots,int m);

int main(int argc, char *argv[]){
  char buf[T];
  int fd,n,ligne;
  if(argc<3){
    printf("usage:- glouton <file> <linelength>\n");
    exit(0);
  }
//M=ligne
  ligne=atoi(argv[2]);
  if(ligne < 2){
    printf("invalid length line\n");
    exit(EXIT_FAILURE);
  }
  
  fd=open(argv[1],O_RDONLY);
  if(fd<0){
    perror("open file failed\n");
    exit(0);
  }

  while(1){
    n=read(fd,buf,T);
    if(n<0){
	perror("read file failed\n");
	exit(EXIT_FAILURE);
    }else{
      if(n>0){
	
      }else{

	break;
      }
    }
 
  }


  return 0;
}



int glouton ( char** mots, int nbmots,int m){
  //m: taille de la ligne
  //nbmots : nbmots dans la list

  int deb,i = 0;
  int taille = m;	
  
  while(i < nbmots){

    taille = m;
    //deb : l'indice du premier mot de la liste achaque iteration
    deb=i;
    //cas du premier mot de la ligne
    if(strlen(mots[i]) <= m){
      taille=taille - strlen(mots[i]);
      i++;
    }
    else
      //mots trop long
      printf("ce mots %s est plus long que la ligne ",mots[i]); 
      
    //cas des mots suivants
      while(strlen(mots[i]) <= taille ){
	taille=taille - strlen(mots[i])-1;      
	i++;
      }
    printf("%s",mots[deb]);
    deb++;
    while(deb<i){
      printf(" %s",mots[deb]);
    }    
  }
  return 0;
  
  
} 

