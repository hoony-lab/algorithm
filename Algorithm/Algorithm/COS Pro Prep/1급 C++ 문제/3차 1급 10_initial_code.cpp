#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Customer{
public:
    int id;
    int time;
    int num_of_people;
    Customer(int id, int time, int num_of_people){
        this->id = id;
        this->time = time;
        this->num_of_people = num_of_people;
    }
};

class Shop{
protected:
    vector<Customer> reserve_list;
public:
    bool reserve(Customer customer){
        reserve_list.push_back(customer);
        return true;
    }
};

class HairShop : @@@ {
public:
    @@@{
        if(@@@ != 1)
            return false;
        
        for(auto r: reserve_list)
            if(@@@)
                return false;
        reserve_list.push_back(customer);
        return true;
    }
};

class Restaurant : @@@ {
public:
    @@@{
        if(@@@)
            return false;
        
        int count = 0;
        for(auto r: reserve_list)
            if(@@@)
                count += 1;
        if(count >= 2)
            return false;
        reserve_list.push_back(customer);
        return true;
    }
};

int solution(vector<vector<int> > customers, vector<string> shops){
    HairShop hairshop;
    Restaurant restaurant;
    
    int count = 0;
    for(int i = 0; i < shops.size(); i++){
        if(shops[i] == "hairshop"){
            if(hairshop.reserve(Customer(customers[i][0], customers[i][1], customers[i][2])))
                count += 1;
        }
        else if(shops[i] == "restaurant"){
            if(restaurant.reserve(Customer(customers[i][0], customers[i][1], customers[i][2])))
                count += 1;
        }
    }
    return count;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    vector<vector<int> > customers = {{1000, 2, 1},{2000, 2, 4},{1234, 5, 1},{4321, 2, 1}, {1111, 3, 10}};
    vector<string > shops = {"hairshop", "restaurant", "hairshop", "hairshop", "restaurant"};
    int ret = solution(customers, shops);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}