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
	  fprintf(fp, "%d %d %f %d %d %d %s\n",s[i]->weight, 
	  s[i]->cost, s[i]->s_cost, s[i]->star, s[i]->review, s[i]->event, s[i]->name);
	}
  }
  printf("Successfully saved!\n");
}

int loadData(Product *s[]){
  int count = 0;
  FILE *fp;

  fp = fopen("product.txt", "rt");
  if(fp == NULL){
	printf("=> There is no file!\n");
	return 0;
  }
  for(;;count++){
	s[count] = (Product*)malloc(sizeof(Product));
	fscanf(fp, "%d %d %f %d %d %d %[^\n]s\n",&s[count]->weight,&s[count]->cost,
&s[count]->s_cost,&s[count]->star, &s[count]->review, &s[count]->event, s[count]->name);
  	if(feof(fp)) break;
  } 
  fclose(fp);
  printf("=> Loding scccess!\n");

  return count;
}

void Search(Product *s[],int curi){
 int menu;
 printf("\n**** Search menu ****\n");
 printf("1. Name\n");
 printf("2. Cost\n");
 printf("3. Standard cost\n");
 printf("4. Star\n");
 printf("5. Review\n");
 printf("6. Event\n");
 printf("0. Exit\n");
 printf("=>Which menu do you want? ");
 scanf("%d", &menu);
 
 if(menu==1){
	searchName(s, curi);	
 }
 else if(menu==2){
	searchCost(s, curi);	
 }
 else if(menu==3){
	searchS_Cost(s, curi);	
 }
 else if(menu==4){
//	searchStar(s, curi);	
 }
 else if(menu==5){
//	searchReview(s, curi);	
 }
 else if(menu==6){
//	searchEvent(s, curi);	
 }
 else if(menu==0){
 	return;
 }
 
}
void searchName(Product *s[], int curi){
 int scount =0;
 char search[20];

 rewind(stdin);
 getchar();
 printf("Enter a name to search : ");
 scanf("%[^\n]s", search);

 printf("\nNo  name        weight(g)   cost  cost/10g  star  review  event\n");
 printf("=================================================================\n");
 for(int i=0; i<curi; i++){
	if(s[i]!=NULL){
		if(strstr(s[i]->name, search)){
			printf("%2d", i+1);
			readProduct(*s[i]);
			scount++;	
		}
	}
 }
 if(scount==0) printf("=> No data found\n");
}
void searchCost(Product *s[], int curi){
 int scount =0;
 int search =0;

 printf("Enter a cost to search : ");
 scanf("%d", &search);
 while(search<0){
 	printf("Enter 0 or bigger :");
	scanf("%d", &search);
 }

 printf("\nNo  name        weight(g)   cost  cost/10g  star  review  event\n");
 printf("=================================================================\n");
 for(int i=0; i<curi; i++){
	if(s[i]!=NULL){
		if(s[i]->cost== search){
			printf("%2d", i+1);
			readProduct(*s[i]);
			scount++;	
		}
	}
 }
 if(scount==0) printf("=> No data found\n");
}
void searchS_Cost(Product *s[], int curi){
 int scount=0;
 float  search=0;


 printf("Enter a standard cost to search : ");
 scanf("%d", &search);
 while(search<0){
 	printf("Enter 0 or bigger :");
	scanf("%f", &search);
 }

 printf("\nNo  name        weight(g)   cost  cost/10g  star  review  event\n");
 printf("=================================================================\n");
 for(int i=0; i<curi; i++){
	if(s[i]!=NULL){
		if(s[i]->s_cost== search){
			printf("%2d", i+1);
			readProduct(*s[i]);
			scount++;	
		}
	}
 }
 if(scount==0) printf("=> No data found\n");
}




