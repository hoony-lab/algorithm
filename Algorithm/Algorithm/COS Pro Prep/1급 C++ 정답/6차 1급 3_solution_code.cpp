#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr, int K) {
    sort(arr.begin(), arr.end());
    int ans = 1e9;
    for(int i = 0; i <= arr.size() - K; i++)
        ans = min(ans , arr[i + K - 1] - arr[i]);
    return ans;
}