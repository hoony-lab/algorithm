#include <iostream>
using namespace std;
#define F(i, n) for (int i = 0; i < n; ++i)

int r, c, ans;
char map[10002][502];

int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy[] = { 1, 1, 1, 0, -1, -1, -1, 0 };

bool check(int x, int y) {
    return !(x < 0 || y < 0 || x >= r || y >= c);
}
bool go(int x, int y) {
    if (y == c - 1) {
        ans++;
        return true;
    }
    F(a, 3) {
        int nx = x + dx[a], ny = y + dy[a];
        if (!check(nx, ny) || map[nx][ny] == 'x') continue;

        map[nx][ny] = 'x';

        if (go(nx, ny)) return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c;
    F(x, r) F(y, c) cin >> map[x][y];

    F(x, r) go(x, 0);

    cout << ans;
    return 0;
}