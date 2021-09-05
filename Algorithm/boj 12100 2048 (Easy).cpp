#include <iostream>
#include <algorithm>
#include <cstring>
#define F(i,n) for(int i=0;i<n;++i)
#define MAX 21
using namespace std;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int ans, n, m[MAX][MAX];
void print(int map[][MAX]) {
    F(x, n) { F(y, n) { cout << map[x][y] << " "; }cout << '\n'; }cout << '\n';
}
bool check(int x, int y) {
    return !(x < 0 || y < 0 || x >= n || y >= n);
}
void move(int way, int map[][MAX]) {
    int tx, ty, nx, ny;
    if (way == 0) {
        F(y, n) {
            tx = 0, nx = 1;
            while (check(nx, y)) {
                if (!map[tx][y]) {           // 0, 2 >> 2, 0
                    if (map[nx][y]) {
                        map[tx][y] = map[nx][y];
                        map[nx][y] = 0;
                    }
                }
                else {
                    while (check(nx, y) && !map[nx][y]) nx++;    // 2, 0, 0, ...   >> 2, 0, 0, ... 
                    if (check(nx, y)) {
                        if (map[tx][y] == map[nx][y]) {         // 2, 0, 0, ... 2 >> 4, 0, 0, ... 0
                            map[tx][y] += map[nx][y];
                            map[nx][y] = 0;
                            tx++;
                        }
                        else if (map[tx][y] != map[nx][y]) {        // 2, 0, 0, ... 4 >> 2, 4, 0, ... 0
                            tx++;
                            if (tx != nx) {
                                map[tx][y] = map[nx][y];
                                map[nx][y] = 0;
                            }
                        }
                    }
                }
                nx++;
            }
        }
    }
    else if (way == 1) {
        F(x, n) {
            ty = n - 1, ny = n - 2;
            // cout << "START : " << x << " :: " << map[x][ty] << ", " << map[x][ny] << '\n';

            while (check(x, ny)) {
                if (!map[x][ty]) {           // 0, 2 >> 2, 0
                    if (map[x][ny]) {
                        map[x][ty] = map[x][ny];
                        map[x][ny] = 0;
                    }
                }
                else {
                    while (check(x, ny) && !map[x][ny]) ny--;    // 2, 0, 0, ...   >> 2, 0, 0, ... 
                    if (check(x, ny)) {
                        if (map[x][ty] == map[x][ny]) {         // 2, 0, 0, ... 2 >> 4, 0, 0, ... 0
                            map[x][ty] += map[x][ny];
                            map[x][ny] = 0;
                            ty--;
                        }
                        else if (map[x][ty] != map[x][ny]) {        // 2, 0, 0, ... 4 >> 2, 4, 0, ... 0
                            ty--;
                            if (ty != ny) {
                                map[x][ty] = map[x][ny];
                                map[x][ny] = 0;
                            }
                        }
                    }
                }
                ny--;
            }
        }
    }
    else if (way == 2) {
        F(y, n) {
            tx = n - 1, nx = n - 2;
            while (check(nx, y)) {
                if (!map[tx][y]) {           // 0, 2 >> 2, 0
                    if (map[nx][y]) {
                        map[tx][y] = map[nx][y];
                        map[nx][y] = 0;
                    }
                }
                else {
                    while (check(nx, y) && !map[nx][y]) nx--;    // 2, 0, 0, ...   >> 2, 0, 0, ... 
                    if (check(nx, y)) {
                        if (map[tx][y] == map[nx][y]) {         // 2, 0, 0, ... 2 >> 4, 0, 0, ... 0
                            map[tx][y] += map[nx][y];
                            map[nx][y] = 0;
                            tx--;
                        }
                        else if (map[tx][y] != map[nx][y]) {        // 2, 0, 0, ... 4 >> 2, 4, 0, ... 0
                            tx--;
                            if (tx != nx) {
                                map[tx][y] = map[nx][y];
                                map[nx][y] = 0;
                            }
                        }
                    }
                }
                nx--;
            }
        }
    }
    else {
        F(x, n) {
            ty = 0, ny = 1;
            while (check(x, ny)) {
                if (!map[x][ty]) {           // 0, 2 >> 2, 0
                    if (map[x][ny]) {
                        map[x][ty] = map[x][ny];
                        map[x][ny] = 0;
                    }
                }
                else {
                    while (check(x, ny) && !map[x][ny]) ny++;    // 2, 0, 0, ...   >> 2, 0, 0, ... 
                    if (check(x, ny)) {
                        if (map[x][ty] == map[x][ny]) {         // 2, 0, 0, ... 2 >> 4, 0, 0, ... 0
                            map[x][ty] += map[x][ny];
                            map[x][ny] = 0;
                            ty++;
                        }
                        else if (map[x][ty] != map[x][ny]) {        // 2, 0, 0, ... 4 >> 2, 4, 0, ... 0
                            ty++;
                            if (ty != ny) {
                                map[x][ty] = map[x][ny];
                                map[x][ny] = 0;
                            }
                        }
                    }
                }
                ny++;
            }
        }
    }
}

void dfs(int cnt, int map[][MAX]) {
    if (cnt == 5) {
        F(x, n)F(y, n) ans = max(ans, map[x][y]);
        return;
    }

    F(a, 4) {
        int c_map[MAX][MAX]{};
        memcpy(c_map, map, sizeof(c_map));
        move(a, c_map);

        dfs(cnt + 1, c_map);
    }
}
int main() {
    cin >> n; F(x, n)F(y, n)cin >> m[x][y];

    dfs(0, m);

    cout << ans;
    return 0;
}
/*
7
2 2 2 2 2 2 2
2 0 2 2 2 2 2
2 0 2 2 2 2 2
2 0 2 2 2 2 2
2 2 2 0 2 2 2
2 2 2 2 2 2 0
2 2 2 2 2 2 0

0
4 4 4 4 4 4 4
4 4 4 4 4 4 4
4 0 4 4 4 4 2
2 0 2 0 2 2 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0

3
8 8 8 4 0 0 0
8 8 8 4 0 0 0
8 8 4 2 0 0 0
4 4 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0

0
16 16 16 8 0 0 0
8 8 4 2 0 0 0
4 4 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0

way, cnt : 3, 3
32 16 8 0 0 0 0
16 4 2 0 0 0 0
8 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0




7 >> 0 1 0 1 0
2 2 2 2 2 2 2
2 0 2 2 2 2 2
2 0 2 2 2 2 2
2 0 2 2 2 2 2
2 2 2 0 2 2 2
2 2 2 2 2 2 0
2 2 2 2 2 2 0

0
4 4 4 4 4 4 4
4 4 4 4 4 4 4
4 0 4 4 4 4 2
2 0 2 0 2 2 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0

1
0 0 0 4 8 8 8
0 0 0 4 8 8 8
0 0 0 4 8 8 2
0 0 0 0 0 4 4
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0

way, cnt : 0, 2
0 0 0 8 16 16 16
0 0 0 4 8 8 2
0 0 0 0 0 4 4
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0

way, cnt : 1, 3
0 0 0 0 8 16 32
0 0 0 0 4 16 2
0 0 0 0 0 0 8
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0

way, cnt : 0, 4
0 0 0 0 8 32 32
0 0 0 0 4 0 2
0 0 0 0 0 0 8
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
*/