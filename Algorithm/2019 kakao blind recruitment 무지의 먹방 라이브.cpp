#include <string>
#include <vector>
#include <iostream>
#include <set>
typedef long long ll;
using namespace std;

set<int> s;
int solution(vector<int> food_times, ll k) {
    int answer = 0;
    ll foods = 0;
    ll round = k / food_times.size();
    ll post = k % food_times.size();
    ll all_eat_cnt = 0;

    for (int i = 0; i < food_times.size(); ++i) {
         
        ll eat = i < post ? round : round + 1;
        foods += food_times[i];

        if (food_times[i] <= eat)
            all_eat_cnt++;
        
            
    }

    if (foods < k)
        return -1;

    return answer;
}




int main() {
    cout << solution({ 3,1,2 }, 5);     // 1
    return 0;
}