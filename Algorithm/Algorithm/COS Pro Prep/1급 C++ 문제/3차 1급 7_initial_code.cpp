#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int k) {
	vector<int> answer;

	for (int i = 1; i <= k; i++) {
		long long square_num = i * i;
		long long divisor = 1;
		while (square_num % divisor != 0) {
			long long front = square_num / divisor;
			long long back = square_num % divisor;
			divisor *= 10;
			if (back != 0 && front != 0)
				if (front + back == i) {
					answer.push_back(i);
				}
		}
	}
	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. main함수는 잘못된 부분이 없으니, solution함수만 수정하세요.
int main() {
    int k = 500;
    vector<int> ret = solution(k);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 {";
    for(int i = 0; i < ret.size(); i++){
        if (i != 0) cout << ", ";
        cout << ret[i];
    }
    cout << "} 입니다." << endl;
}