#include <iostream>
#include <string>
#include <vector>

using namespace std;

int func_a(int n){
    int ret = 1;
    while(n > 0){
        ret *= 10;
        n--;
    }
    return ret;
}

int func_b(int n){
    int ret = 0;
    while(n > 0){
        ret++;
        n /= 10;
    }
    return ret;
}

int func_c(int n){
    int ret = 0;
    while(n > 0){
        ret += n%10;
        n /= 10;
    }
    return ret;
}

int solution(int num) {
    int next_num = num;
    while(true){
        next_num++;
        int length = func_b(next_num);
        if(length % 2)
            continue;
        int divisor = func_a(length/2);
        
        int front = next_num / divisor;
        int back = next_num % divisor;
        
        int front_sum = func_c(front);
        int back_sum = func_c(back);
        if(front_sum == back_sum)
            break;
    }
    return next_num - num;
}