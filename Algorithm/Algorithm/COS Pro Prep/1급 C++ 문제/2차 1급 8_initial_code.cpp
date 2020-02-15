#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int left = 0, right = arr.size() - 1;
    int idx = 0;
    vector<int> answer(arr.size(), 0);
    while(left <= right){
        if(left % 2 == 0){
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

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. main함수는 잘못된 부분이 없으니, solution함수만 수정하세요.
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    vector<int> ret = solution(arr);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 {";
    for(int i = 0; i < ret.size(); i++){
        if (i != 0) cout << ", ";
        cout << ret[i];
    }
    cout << "} 입니다." << endl;
}