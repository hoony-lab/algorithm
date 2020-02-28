// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
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