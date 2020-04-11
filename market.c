#include "product.h"
#include "manager.h"

int selectMenu(){
 int menu;
 printf("\n**** Product Management ****\n");
 printf("1. Read product\n");
 printf("2. Add product\n");
 printf("3. Update product\n");
 printf("4. Delete product\n");
 printf("5. Save data\n");
 printf("0. Exit\n");
 printf("=>Which menu do you want? ");
 scanf("%d", &menu);
 return menu;
}


int main(void){

 Product *sp[30];
 int count =0, menu;
 int deleteok=0;
 int curi =0;
 
 count = loadData(sp);
 curi = count; 

 #ifdef DEBUG
 printf("\ndebug[main.c] startline\n");
 #endif 
  while(1){ 
 #ifdef DEBUG
  printf("debug[main.c] call selectMenu\n");
 #endif
  menu = selectMenu();
    if (menu == 0) break;
    if (menu == 1){
        if(count<=0){
          printf("There is no data!\n");
          continue;
        }
        else{
	#ifdef DEBUG
	printf("debug[main.c] call loopRead\n");
	#endif
        loopRead(sp, curi);
	}
    }
    
    else if (menu == 2){
        if(count==30){
        printf("Sorry, you can't add anymore!\n");
        continue;
        }
        #ifdef DEBUG
	printf("debug[main.c] call addProduct\n");
	#endif
    sp[curi] = (Product*)malloc(sizeof(Product));
    count += addProduct(sp[curi++]);
    printf("=> Added!\n");
    }
    
    else if (menu == 3){
        if(count<=0){
          printf("There is no data!\n");
          continue;
        }
	int no = selectDataNo(sp, curi);
        #ifdef DEBUG
	printf("debug[main.c] call updateProduct\n");
	#endif
    updateProduct(sp[no-1]);
    }
    
    else if (menu == 4){
        if(count<=0){
          printf("There is no data!\n");
          continue;
        }
    int no = selectDataNo(sp, curi);
    printf("Are you sure?(Yes : 1) ");
    scanf("%d", &deleteok);
    
        if(deleteok ==1){
        #ifdef DEBUG
	printf("debug[main.c] call free to array\n");
	#endif
        free(sp[no-1]);
        printf("=> Deleted!\n");
        sp[no-1]=NULL;
        count--;
        }
    }
    else if (menu == 5){
        if(count<=0){
          printf("There is no data!\n");
          continue;
        }
   	else saveData(sp, curi); 
    }	
  }

  printf("Ok, goodbye!\n");
  return 0;
}
