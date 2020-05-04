#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using vs = vector<string>;
using vi = vector<int>;

vector<int> solution(vector<string> words, vector<string> queries) {
    vi answer;

    for (string query : queries) {
        int ans = 0;
        for (string word : words) {
            if (query.length() != word.length()) continue;

            bool fail = false;
            cout << "query : " << query << '\n';
            for (int i = 0; i < word.size(); ++i) {
                if (query[i] == '?') continue;

                int qstart = lower_bound(query.begin(), query.end(), '?') - query.begin();
                int qend = upper_bound(query.begin(), query.end(), '?') - query.begin();

                cout << "start : " << qstart << " ::: " << "end : " << qend << '\n';

                if (word[i] != query[i]){
                    fail = true; break;
                }
            }
            if (!fail) ans++;
        }
        answer.push_back(ans);
    }
    return answer;
}


int main() {
    vs words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
    vs queries = {"fro??", "????o", "fr???", "fro???", "pro?"};
    vi answer = solution(words, queries);

    for (auto ans : answer) 
        cout << ans << ' ';
    
    return 0;
}