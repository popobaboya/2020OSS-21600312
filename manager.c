#include "product.h"
#include "manager.h"


void loopRead(Product *s[], int count){
 int i=0;

 printf("\nNo  name        weight(g)   cost  cost/10g  star  review  event\n");
 printf("=================================================================\n");
 for(i=0;i<count;i++){
   if(s[i]==NULL)
	continue;
 
   printf("%2d", i+1);
   readProduct(*s[i]);	
 }
}

int selectDataNo(Product *s[], int count){

  int num =0;

  loopRead(s, count);
  printf("\nWhich number will you select? : ");
  scanf("%d", &num);
  while(num<=0||num>count||s[num-1]==NULL)
  { printf("Enter right number : ");
    scanf("%d", &num);
  }
  
  return num;
}

void saveData(Product *s[], int count){
  FILE *fp;

  fp = fopen("product.txt", "wt");
  for(int i=0;i<count;i++){
	if(s[i] != NULL){
	  fprintf(fp, "%s %d %d %f %d %d %d\n", s[i]->name, s[i]->weight, 
	  s[i]->cost, s[i]->s_cost, s[i]->star, s[i]->review, s[i]->event);
	}
  }
}
