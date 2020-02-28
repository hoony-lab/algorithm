// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))

int solution(vector<int> arr) {
    // 여기에 코드를 작성해주세요.
    int answer = 0;
	int count = 0;
	for (int i = 0; i < arr.size()-1; ++i) {
		if (arr[i] < arr[i + 1]) {
			count++;
			answer = max(answer, count);
		}
		else count = 0;
	}

    return answer+1;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    vector<int> arr = {3, 1, 2, 4, 5, 1, 2, 2, 3, 4};
    int ret = solution(arr);


    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;

}