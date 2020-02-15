#include <string>
#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> votes) {
    int vote_counter[11] = {0};
    for (int i = 0; i < votes.size(); ++i) {
        vote_counter[votes[i]] += 1;
    }
    int max_val = 0;
    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        if (max_val < vote_counter[i]) {
            max_val = vote_counter[i];
            cnt = 1;
        }
        else if(max_val == vote_counter[i]){
            cnt += 1;
        }
    }
    vector<int> answer(cnt, 0);
    for (int i = 1, idx = 0; i <= N; ++i){
        if (vote_counter[i] == max_val) {
            answer[idx] = i;
            idx += 1;
        }
    }
    return answer;
}