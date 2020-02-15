#include<vector>
using namespace std;
int solution(vector<int> prices){
    int inf = 1000000001;
    int mn = inf;
    int ans = -inf;
    for(int price : prices){
        if(mn != inf) ans = max(ans, price - mn);
        mn = min(mn, price);
    }
    return ans;
}
