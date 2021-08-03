#include <iostream>
#include <vector>
#include <cstring>
#define MAX 2020
using namespace std;

// vector<vector<int>> v; 동적할당 보다 빠른 배열,,,
vector<int> v[MAX];
int visit[MAX];
bool friends;

void DFS(int start, int depth) {
    
    if (depth == 5) {
        friends = true;
        return;
    }
    
    for (auto next : v[start]) {
        
        if (visit[next]) continue;

        visit[next] = true;
        DFS(next, depth + 1);
        visit[next] = false;

        if (friends) return;
    }
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, e; cin >> u >> e;
        v[u].push_back(e), v[e].push_back(u);
    }

    for (int start = 0; start < n; start++) {

        if (v[start].size() == 0) continue;

        memset(visit, 0, sizeof(visit));
        visit[start] = true;

        //cout << "start : " << start << '\n';

        DFS(start, 1);

        if (friends) break;
    }

    friends == true 
        ? cout << 1 : cout << 0;

    return 0;
}