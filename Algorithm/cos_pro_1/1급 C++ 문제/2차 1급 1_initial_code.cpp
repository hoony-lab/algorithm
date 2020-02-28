#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Book{
public:
    virtual int get_rental_price(int day) = 0;
};

class ComicBook : @@@{
public:
    @@@{
        int cost = 500;
        day -= 2;
        if(day > 0)
            cost += @@@;
        return cost;
    }
};

class Novel : @@@{
public:
    @@@{
        int cost = 1000;
        day -= 3;
        if(day > 0)
            cost += @@@;
        return cost;
    }
};

int solution(vector<string> book_types, int day) {
    Book* books[50];
    int length = book_types.size();
    for(int i = 0; i < length; ++i){
        if(book_types[i] == "comic")
            books[i] = new ComicBook();
        else if(book_types[i] == "novel")
            books[i] = new Novel();
    }
    
    int total_price = 0;
    for(int i = 0; i < length; ++i)
        total_price += books[i]->get_rental_price(day);
    
    return total_price;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    vector<string> book_types = {"comic", "comic", "novel"};
    int day = 4;
    int ret = solution(book_types, day);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}