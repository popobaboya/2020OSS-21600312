#include "product.h"

int addProduct(Product *s){
 int i =0;
 float  j =0;
  
  getchar();
  printf("\nEnter product name : ");
  fgets(s->name,20, stdin);
  for(int i=0;i<20;i++){
	if(s->name[i]=='\n'){
	  s->name[i]='\0';
	  break;
	}
  }
  printf("Enter product weight : ");
  scanf("%d", &s->weight);
  printf("Enter product cost : ");
  scanf("%d", &s->cost);
  j = s->weight/10.0;
  s->s_cost= s->cost/j;
  printf("Enter product star(1~5) : ");
  scanf("%d", &s->star);
  while(s->star<=0||s->star>5){
    printf("Enter number between 1 to 5 : ");
    scanf("%d", &s->star);
  }
  printf("Enter product review : ");
  scanf("%d", &s->review);
    while(s->review<0){
      printf("Enter number 0 or bigger number : ");
      scanf("%d", &s->review);
    }
  printf("If there is a event enter 1, else enter 0: ");
  scanf("%d", &i);
    while(i!=1&&i!=0){
      printf("Enter number 1(event) or 0(no event) : ");
      scanf("%d", &i);
    }
  
  if(i==1){
  printf("1+1 : enter 1, 2+1 : enter 2 : ");
  scanf("%d", &s->event);
    while(s->event!=1&&s->event!=2){
      printf("Enter number 1(1+1) or 2(2+1) : ");
      scanf("%d", &s->event);
    }
  }
  else
  s->event=0;

return 1;
}

void readProduct(Product s){

 char event[4]="\0";

 if(s.event==1)
 strcpy(event, "1+1");
 else if(s.event==2)
 strcpy(event, "2+1");
 else strcpy(event, "---");

 printf("  %-11s %-10d  %-5d %-9.1f %-5d %-7d %s\n", s.name, s.weight, s.cost, s.s_cost, s.star, s.review, event);

}

int updateProduct(Product *s){
 float j=0;
   int i=0;

   getchar();
   printf("\nName? "); 
   fgets(s->name,20, stdin); 
   for(int i=0;i<20;i++){
 	if(s->name[i]=='\n'){
 	  s->name[i]='\0';
	  break;
	}
   }
   printf("Weight? ");
   scanf("%d", &s->weight);
   printf("Cost? ");
   scanf("%d", &s->cost);
   printf("Star(1~5)? ");
   j = s->weight/10.0;
   s->s_cost= s->cost/j;
   scanf("%d", &s->star);
    while(s->star<=0||s->star>5){
    printf("Enter number between 1 to 5 : ");
    scanf("%d", &s->star);
    }
   printf("Review? ");
   scanf("%d", &s->review);
    while(s->review<0){
      printf("Enter number 0 or bigger number : ");
      scanf("%d", &s->review);
    }
   printf("If there is a event enter 1, else enter 0: ");
   scanf("%d", &i);
    while(i!=1&&i!=0){
      printf("Enter number 1(event) or 0(no event) : ");
      scanf("%d", &i);
    }

   if(i==1){
   printf("1+1 : enter 1, 2+1 : enter 2: ");
   scanf("%d", &s->event);
      while(s->event!=1&&s->event!=2){
      printf("Enter number 1(1+1) or 2(2+1) : ");
      scanf("%d", &s->event);
      }
   }
   else
  s->event=0;

}

