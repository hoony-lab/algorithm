#include <iostream>
#include <string>
#define MAX 10001
using namespace std;

int num[MAX];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> num[i + 1];
    st
    int start = 1, end = start, sum = num[start], ans = 0;

    while (end <= n) {
        cout << "start : " << start << ", " << end << '\n';

        if (sum < m)        sum += num[++end];
        else if (sum > m)   sum -= num[start++];
        else if (sum == m) {
            ans++, sum -= num[start++];
        }
    }

    cout << ans;
    return 0;
}