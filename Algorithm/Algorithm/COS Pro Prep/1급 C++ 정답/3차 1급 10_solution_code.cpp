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

class HairShop : public Shop {
public:
    bool reserve(Customer customer){
        if(customer.num_of_people != 1)
            return false;
        
        for(auto r: reserve_list)
            if(r.time == customer.time)
                return false;
        reserve_list.push_back(customer);
        return true;
    }
};

class Restaurant : public Shop {
public:
    bool reserve(Customer customer){
        if(customer.num_of_people < 2 || customer.num_of_people > 8)
            return false;
        
        int count = 0;
        for(auto r: reserve_list)
            if(r.time == customer.time)
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