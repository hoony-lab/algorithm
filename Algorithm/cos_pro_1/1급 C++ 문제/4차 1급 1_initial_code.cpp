#include <string>
#include <iostream>
#include <vector>
using namespace std;

string vowels[5] = {"A", "E", "I", "O", "U"};
vector<string> words;

void create_words(int lev, string str) {
    words.push_back(str);
	for (int i = 0; i < 5; i++) {
		if (lev < 5) {
			create_words(lev + 1, str + vowels[i]);
		}
	}
}


int solution(string word) {
    int answer = 0;
    //words.clear();
    create_words(0, "");
    int words_n = words.size();
    for (int i = 0; i < words_n; i++) {
        if (word.compare(words[i]) == 0) {
            answer = i;
            break;
        }
    }
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 코드입니다. 아래에는 잘못된 부분이 없으니, 위의 코드만 수정하세요.
int main() {
    string word1 = "AAAAE";
    int ret1 = solution(word1);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환값은  " << ret1 << " 입니다." << endl;
    
    string word2 = "AAAE";
    int ret2 = solution(word2);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환값은 " << ret2 << " 입니다." << endl;
    
    return 0;
}