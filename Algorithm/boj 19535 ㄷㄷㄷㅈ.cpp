#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define MAX 300001
#define D cout << "D"
#define G cout << "G"
#define DG cout << "DUDUDUNGA"
ll dd, gg;
int visited[MAX];

int main() {
    int n, u, v;
    cin >> n;
    vector<vector<int>> graph(n+1);

    //vector<int> v(MAX); generate(v.begin(), v.end(), [num = 0]() mutable {return num++; });

    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    //find_g();
    //find_d();

    for (int i = 1; i <= n; ++i) {
        if (graph[i].size() >= 3)  {
            ll cnt = graph[i].size();
            gg += (cnt * (cnt - 1) * (cnt - 2)) / 6;
        }
    }

    for (int i = 1; i <= n; ++i) {
        ll max = graph[i].size() - 1;
        for (int j : graph[i]) {
            if (visited[j]) continue;
            dd += max * (graph[j].size() - 1);
        }
        visited[i] = true;
    }


    if (dd > gg * 3) D;
    else if (dd < gg * 3) G;
    else DG;

    return 0;
}

/*
 D-트리 : ‘ㄷ’이 ‘ㅈ’의 3배보다 많은 트리                ㄷ > ㅈ * 3
 G-트리 : ‘ㄷ’이 ‘ㅈ’의 3배보다 적은 트리                ㄷ < ㅈ * 3
 DUDUDUNGA-트리 : ‘ㄷ’이 ‘ㅈ’의 정확히 3배만큼 있는 트리 ㄷ == ㅈ * 3
 */