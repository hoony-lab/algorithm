#include <iostream>
#include <string>
#define MAX 10001
int num[MAX];

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    int n, m; std::cin >> n >> m;
    for (int i = 0; i < n; ++i) std::cin >> num[i + 1];
    
    int start = 1, end = start, sum = num[start], ans = 0;

    while (end <= n) {
        //std::cout << "start : " << start << ", " << end << '\n';

        if (sum < m)        sum += num[++end];
        else if (sum > m)   sum -= num[start++];
        else if (sum == m) {
            // cout << "\tfind : " << start << ", " << end << '\n';
            ans++, sum -= num[start++];
        }
    }

    std::cout << ans;
    return 0;
}