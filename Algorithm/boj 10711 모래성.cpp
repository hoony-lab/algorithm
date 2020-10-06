#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <memory.h>
using namespace std;
#define F(i ,n) for(int i = 0 ; i < n ; ++i)
#define FF(i ,n, m) for(int i = m ; i < n ; ++i)
int dx[] = { -1,0,1,0,-1,1,1,-1 };
int dy[] = { 0,1,0,-1,1,1,-1,-1 };

int h, w, ans;
int map[1001][1001];

// int count_around(int x, int y){
//   int cnt = 0;
//   F(a, 8) if(map[x+dx[a]][y+dy[a]] == 0) cnt++;
//   return cnt;
// }

bool check(int x, int y) {
    return !(x < 0 || y < 0 || x >= h || y >= w);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> h >> w;
    char ch;
    F(x, h) F(y, w) {
        cin >> ch;
        if (ch == '.') map[x][y] = 0;
        else map[x][y] = ch - '0';
    }

    // check map: store water
    queue<pair<int, int>> q;
    F(x, h) F(y, w) {
        if (map[x][y] != 0) continue;
        q.push({ x, y });
    }

    while (1) {

        int qsize = (int)q.size();
        F(i, qsize) {
            int x = q.front().first, y = q.front().second;
            q.pop();

            F(a, 8) {
                int nx = x + dx[a], ny = y + dy[a];

                if (!check(nx, ny) || map[nx][ny] == 0) continue;

                map[nx][ny]--;

                if (map[nx][ny] == 0)
                    q.push({ nx, ny });

            }
        }

        if (q.empty()) break;
        ans++;
    }

    cout << ans;
    return 0;
}