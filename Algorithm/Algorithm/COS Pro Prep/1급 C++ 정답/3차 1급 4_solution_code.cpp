#include <string>
#include <vector>

using namespace std;

int overlap(string s1, string s2) {
    int len = min(s1.length(), s2.length());
    int over_len = 0;
    for(int i = 1; i <= len; ++i){
        string f = s1.substr(s1.length() - i);
        string s = s2.substr(0, i);
        if(f == s)
            over_len = i;
    }
    return s1.length() + s2.length() - over_len;
}

int solution(string s1, string s2) {
    return min(overlap(s1, s2), overlap(s2, s1));
}