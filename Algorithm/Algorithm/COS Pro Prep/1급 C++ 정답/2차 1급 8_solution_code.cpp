#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int left = 0, right = arr.size() - 1;
    int idx = 0;
    vector<int> answer(arr.size(), 0);
    while(left <= right){
        if(idx % 2 == 0){
            answer[idx] = arr[left];
            left += 1;
        }
        else{
            answer[idx] = arr[right];
            right -= 1;
        }
        idx += 1;
    }
    return answer;
}