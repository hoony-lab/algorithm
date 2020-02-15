#include <string>
#include <vector>

using namespace std;

long long solution(int one_day_price, int multi_day, int multi_day_price, long long n) {
    if(one_day_price * multi_day <= multi_day_price)
        return n * one_day_price;
    else
        return (n / multi_day) * multi_day_price + (n % multi_day) * one_day_price;
}