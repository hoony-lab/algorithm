
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solution(int a, int b){
    vector<int> prime;
    int chk[100001] = {0};
    for(int i = 2; i <= 100000; i++){
        if(chk[i] == 0)
        {
            prime.push_back(i);
            chk[i] = 1;
            for(int j = i + i; j <= 100000; j+= i)
                chk[j] = 2;
        }
    }
    
    vector<int> answer{0, 0};
    for(auto x: prime){
        if(x <= 1010){
            int tmp = x*x*x;
            if(a <= tmp && tmp <= b)
                answer[1]++;
        }
        if(x <= 33333){
            int tmp = x*x;
            if(a <= tmp && tmp <= b)
                answer[0]++;
        }
    }
    return answer[0] + answer[1];
}