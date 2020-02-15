#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool func_a(vector<string> list, string s) {
    for (int i = 0; i < list.size(); i++)
        if (s.compare(list[i]) == 0)
            return true;
    return false;
}

bool func_b(string s) {
    int length = s.size();
    for (int i = 0; i < length / 2; i++)
        if (s[i] != s[length - i - 1])
            return false;
    return true;
}

string func_c(vector<string> palindromes, int k) {
    sort(palindromes.begin(), palindromes.end());
    if (palindromes.size() < k)
        return "NULL";
    else
        return palindromes[k - 1];
}

string solution(string s, int k) {
    vector<string> palindromes;
    int length = s.size();
    for (int start_idx = 0; start_idx < length; start_idx++) {
        for (int cnt = 1; cnt < length - start_idx + 1; cnt++) {
            string sub_s = s.substr(start_idx, cnt);
            if (func_@@@(@@@)) {
                if (func_@@@(@@@) == false)
                    palindromes.push_back(sub_s);
            }
        }
    }

    string answer = func_@@@(@@@);
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    string s1 = "abcba";
    int k1 = 4;
    string ret1 = solution(s1, k1);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

    string s2 = "ccddcc";
    int k2 = 7;
    string ret2 = solution(s2, k2);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}