#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using vi = vector<int>;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;

    vi gap;
    for (int i = 0; i < weak.size() - 1; ++i)
        gap.push_back(weak[i + 1] - weak[i]);
    gap.push_back(n - weak[weak.size() - 1] + weak[0]);
    
    sort(gap.begin(), gap.end(), greater<int>());
    
    int gap_sum = 0, dist_sum = 0;
    for (int i = 1; i < gap.size(); ++i) {
        gap_sum += gap[i];
    }
    for (int i = dist.size() - 1; i >= 0; --i) {
        dist_sum += dist[i];
        answer++;
        if (gap_sum <= dist_sum) return answer;
    }
    if (gap_sum > dist_sum) return -1;
    //return answer;
}


int main() {
    int n = 12;
    vi weak = { 1, 5, 6, 10 };      // 4 1 4 3      _ 1 4 3     4 1 _ 3
    vi dist = { 1, 2, 3, 4 };       

    vi weak2 = { 1, 3, 4, 9, 10 };  // 2 1 5 1 3    2 1 _ 1 3
    vi dist2 = { 3, 5, 7 };
    cout << solution(n, weak, dist);
    return 0;
}