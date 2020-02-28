#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arrA, vector<int> arrB){
    int arrA_idx = 0, arrB_idx = 0;
    int arrA_len = arrA.size();
    int arrB_len = arrB.size();
    vector<int> answer;
    while(@@@){
        if(arrA[arrA_idx] < arrB[arrB_idx])
            answer.push_back(arrA[arrA_idx++]);
        else
            answer.push_back(arrB[arrB_idx++]);
    }
    while(@@@)
        answer.push_back(arrA[arrA_idx++]);
    while(@@@)
        answer.push_back(arrB[arrB_idx++]);
    return answer;
}

// The following is main function to output testcase.
int main() {
    vector<int> arrA = {-2, 3, 5, 9};
    vector<int> arrB = {0, 1, 5};
    vector<int> ret = solution(arrA, arrB);

    // Press Run button to receive output. 
    cout << "Solution: return value of the function is {";
    for(int i = 0; i < ret.size(); i++){
        if (i != 0) cout << ", ";
        cout << ret[i];
    }
    cout << "} ." << endl;
}