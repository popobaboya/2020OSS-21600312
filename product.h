    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

    typedef struct{  //구조체 선언
        char name[20];  //제품명
        int weight;  //중량(숫자)
        int cost;    //가격(숫자)
        float s_cost;  //표준가격
        int star;   //별점수(1~5)
        int review;  //리뷰 개수
        int event; //1+1 또는 2+1 행사가 있는 경우 사용
    } Product;

    int addProduct(Product *s); //제품을 추가하는 함수
    void readProduct(Product s); // 하나의 제품 출력 함수
    int updateProduct(Product *s); // 데이터 수정 함수
    void saveData(Product *s[], int count); //파일입력 함수
    int loadData(Product *s[]); //파일출력 함수
    void Search(Product *s[], int curi); //검색함수, 검색방법을 물어보고 해당하는 함수를 호출 
    void searchName(Product *s[], int curi); //이름을 이용한 검색 함수
    void searchCost(Product *s[], int curi); //가격을 이용한 검색 함수
    void searchStar(Product *s[], int curi); //별점수를 이용한 검색 함수
    void searchS_Cost(Product *s[], int curi); //표준가격을 이용한 검색 함수, 사용자가 입력한 값을 기준으로 높거나 낮은 제품 출력
    void searchReview(Product *s[], int curi); //리뷰 개수를 이용한 검색 함수, 사용자가 입력한 값을 기준으로 높거나 낮은 제품 출력
    void searchEvent(Product *s[], int curi); //행사를 이용한 검색 함수
