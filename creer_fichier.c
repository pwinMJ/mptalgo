#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 100

int creer_fichier(FILE*f1,FILE* f2,int nb){
  char buf[LEN+1];
  int n=0;
  while(fgets(buf,LEN,f1 )!=NULL && n<= nb){
    fputs (buf,f2);
    if(buf[strlen(buf)-1]=='\n')
      fputs(" ",f2);    
    n=n+buf[strlen(buf)];
  }
  return 0;
}

int main(int argc, char**argv){
  
  FILE * f1,*f2;
  int nb=atoi(argv[argc-1]);
  printf("%d ",nb);
  if(argc>2){
    f1=fopen(argv[1],"r");
    f2=fopen("fichier2","w");  
    creer_fichier(f1,f2,nb);
    fclose(f1);
    fclose(f2);
    
  }
  else fprintf(stderr,"le fichier %s ne peut etre ouvert",argv[1]);
  
  return 0;
}

