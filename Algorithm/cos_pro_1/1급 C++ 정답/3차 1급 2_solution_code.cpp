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
            if (func_b(sub_s)) {
                if (func_a(palindromes, sub_s) == false)
                    palindromes.push_back(sub_s);
            }
        }
    }

    string answer = func_c(palindromes, k);
    return answer;
}