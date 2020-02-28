#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arrA, vector<int> arrB){
    int arrA_idx = 0, arrB_idx = 0;
    int arrA_len = arrA.size();
    int arrB_len = arrB.size();
    vector<int> answer;
    while(arrA_idx < arrA_len && arrB_idx < arrB_len){
        if(arrA[arrA_idx] < arrB[arrB_idx])
            answer.push_back(arrA[arrA_idx++]);
        else
            answer.push_back(arrB[arrB_idx++]);
    }
    while(arrA_idx < arrA_len)
        answer.push_back(arrA[arrA_idx++]);
    while(arrB_idx < arrB_len)
        answer.push_back(arrB[arrB_idx++]);
    return answer;
}