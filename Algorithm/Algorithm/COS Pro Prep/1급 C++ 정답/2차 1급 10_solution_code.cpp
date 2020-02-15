#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    s += '#';
    string answer = "";
    for(int i = 0; i < s.length(); ++i){
        if (s[i] == '0' && s[i+1] != '0')
            answer += "0";
        else if(s[i] == '1')
            answer += "1";
    }
    return answer;
}