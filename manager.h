void loopRead(Product *s[], int count); //readProduct함수 반복(제품 전체 출력)
int selectDataNo(Product *s[], int count); //데이터 수정, 삭제 시 번호 선택 함수
void saveData(Product *s[], int count); 
int loadData(Product *s[]);
void Search(Product *s[], int cui);
void searchName(Product *s[], int curi);
void searchCost(Product *s[], int curi);
void searchStar(Product *s[], int curi);
void searchS_Cost(Product *s[], int curi);
void searchReview(Product *s[], int curi);
void searchEvent(Product *s[], int curi);
