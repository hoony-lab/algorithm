#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int INC = 0;
const int DEC = 1;

vector<int> func_a(vector<int> arr){
    int length = arr.size();
    vector<int> ret(length,0);
    ret[0] = 1;
    for(int i = 1; i < length; i++){
        if(arr[i] != arr[i-1])
            ret[i] = ret[i-1] + 1;
        else
            ret[i] = 2;
    }
    return ret;
}

vector<int> func_b(vector<int> arr){
    int length = arr.size();
    vector<int> ret(length, 0);
    ret[0] = -1;
    for(int i = 1; i < length; i++){
        if(arr[i] > arr[i-1])
            ret[i] = INC;
        else if(arr[i] < arr[i-1])
            ret[i] = DEC;
    }
    return ret;
}

int func_c(vector<int> arr){
    int length = arr.size();
    int ret = 0;
    for(int i = 0; i < length; i++)
        if(ret < arr[i])
            ret = arr[i];
    if(ret == 2)
        return 0;
    return ret;
}

int solution(vector<int> S){
    vector<int> check = func_b(S);
    vector<int> dp = func_a(check);
    int answer = func_c(dp);
    return answer;
}