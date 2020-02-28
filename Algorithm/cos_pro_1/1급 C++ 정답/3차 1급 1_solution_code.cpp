#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> func_a(vector<int> arr){
    int length = arr.size();
    vector<int> ret(length*2);
    for(int i = 0; i < length; i++)
        ret[i + length] = ret[i] = arr[i];
    return ret;
}

bool func_b(vector<int> first, vector<int> second){
    const int MAX_NUMBER = 1001;
    vector<int> counter(MAX_NUMBER, 0);
    for(int i = 0; i < first.size(); i++){
        counter[first[i]]++;
        counter[second[i]]--;
    }
    for(int i = 0; i < MAX_NUMBER; i++)
        if(counter[i] != 0)
            return false;
    return true;
}

bool func_c(vector<int> first, vector<int> second){
    int length = second.size();
    for(int i = 0; i < length; i++){
        int j;
        for(j = 0; j < length; j++)
            if(first[i + j] != second[j])
                break;
        if(j == length)
            return true;
    }
    return false;
}

bool solution(vector<int> arrA, vector<int> arrB) {
    if(arrA.size() != arrB.size())
        return false;
    if(func_b(arrA, arrB)){
        vector<int> arrA_temp = func_a(arrA);
        if(func_c(arrA_temp, arrB))
            return true;
    }
    return false;
}