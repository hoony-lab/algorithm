#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string small_letters = "abcdefghijklmnopqrstuvwxyz";
string big_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string numbers = "0123456789";

const char convert_small(char alphabet) {
	for (int i = 0; i < 26; i++) {
		if (big_letters[i] == alphabet) {
			return small_letters[i];
		}
	}
	return alphabet;
}

const char int_to_string(int val) {
	return numbers[val];
}

string solution(string s) {
	// 여기에 코드를 작성해주세요.
	string answer = "";
	int len = s.size();
	char boss;
	int cnt = 1;

	boss = convert_small(s[0]);
	for (int i = 1; i < len; i++) {
		if (convert_small(s[i]) == boss) {
			cnt += 1;
		}
		else {
			answer += boss;
			answer += int_to_string(cnt);
			boss = convert_small(s[i]);
			cnt = 1;
		}
	}
	answer += boss;
	answer += int_to_string(cnt);
	return answer;
}

//string solution(string s) {
//    transform(s.begin(), s.end(), s.begin(), ::tolower);
//    string answer = "";
//    char previous = s[0];
//    int counter = 1;
//
//    for(int i=1; i<s.size(); i++) {
//        if(s[i] == previous)
//            counter++;
//        else {
//            answer += previous;
//            answer += counter + '0';
//            counter = 1;
//            previous = s[0];
//        }
//    }
//    answer += previous;
//    answer += counter + '0';
//    return answer;
//}

// 아래는 테스트케이스 출력을 해보기 위한 코드입니다. 아래에는 잘못된 부분이 없으니, 위의 코드만 수정하세요.
int main() {
    string s = "YYYYYbbbBbbBBBMmmM";
    string ret = solution(s);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;

}