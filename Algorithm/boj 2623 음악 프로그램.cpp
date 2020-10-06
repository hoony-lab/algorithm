#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

int n, m;
vector<int> pd[101], graph[1001], ans;
int prerequisite[1001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0, singer_cnt, singer; i < m; ++i) {
        cin >> singer_cnt;

        for (int j = 0; j < singer_cnt; ++j) {
            cin >> singer;
            pd[i].push_back(singer);

            if (j > 0) {
                prerequisite[singer]++;
                graph[pd[i][j - 1]].push_back(singer);
            }
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (prerequisite[i] == 0) q.push(i);

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        ans.push_back(top);

        for (int i = 0; i < (int)graph[top].size(); ++i) {
            prerequisite[graph[top][i]]--;

            if (prerequisite[graph[top][i]] == 0)
                q.push(graph[top][i]);
        }
    }

    if (ans.size() == n)
        for (int a : ans) cout << a << '\n';
    else cout << 0 << '\n';

    return 0;
}