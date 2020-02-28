#include <iostream>
#include <string>
#include <vector>

using namespace std;

int func(int record){
    if(record == 0) return 1;
    else if(record == 1) return 2;
    return 0;
}

int solution(vector<int> recordA, vector<int> recordB){
    int cnt = 0;
    for(int i = 0; i < (int)recordA.size(); i++){
        if(recordA[i] == recordB[i]) continue;
        else if(recordA[i] == func(recordB[i])) cnt += 3;
        else cnt = max(0, cnt - 1);
    }
    return cnt;
}
