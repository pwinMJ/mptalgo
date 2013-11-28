#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "affichage.c"

struct liste_sol * diviser_pour_regner(char ** mots,int deb,int fin, int m){
  struct liste_sol * ls =NULL;
  int mil=0;
  
  // iteration 
  int iter=0;
  /*
  printf("iter = %d \n",iter);
   iter=iter+1;
  printf("iter = %d \n",iter);
  */
  printf(" (if) deb =%d , fin = %d \n",deb,fin);
  if(iter>1){
    printf("iter =%d \n",iter);
    deb++; fin--;
  }

  //CAS DE BASE
  if(fin ==deb && strlen(mots[deb])< m ){
    ls= ajoute_element(ls,deb,fin); 
    printf(" first if => mot[%d] = %s\n",deb,mots[deb]);
    deb++;
    fin--;
  }
  
  else if(deb<fin){
    mil=(fin+deb+1)/2 ;
    iter ++;
    printf("First :(deb<fin) \n mil= %d , deb = %d fin =%d \n",mil,deb,fin);
    //perror("deb> fin \n");
    diviser_pour_regner(mots,deb,mil,m);
    //diviser_pour_regner(mots,mil+1,fin,m);
    deb++;
    fin--;
    printf("SECOND :(deb<fin) \n mil= %d , deb = %d fin =%d \n",mil,deb,fin);
    printf("fin if\n");
  }
  return ls;
}
int main(int argc, char ** argv){
  struct liste_sol * ls =NULL;
  printf("\n argc = %d \n",argc);
  int deb =1,fin= argc-1;
  ls = diviser_pour_regner(argv,deb,fin,17);
  affiche_mots(argv,ls,17);
  return 0;
}
