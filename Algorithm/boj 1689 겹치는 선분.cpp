#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
struct P
{
    int a, b;
    bool operator<(const P& temp) const {
        if (a == temp.a) return b < temp.b;
        else return a < temp.a;
    }
};

P p[2000000];
int n, ans, cnt;
int main() {
    cin >> n;

    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;

        //start
        p[i] = { a, 1 };
        //end
        p[i + n] = { b, -1 };
    }

    sort(p, p + 2 * n);

    for (int i = 0; i < 2 * n; i++) {
        cnt += p[i].b;
        ans = max(ans, cnt);
    }

    // 4% TLE
// for(int i = 0 ; i < (*v.end().b) - 1 ; ++i) {
// idx = i;
// cnt = 0;
//
// while(++idx < n) {
//   if((v[i].a < v[idx].a && v[idx].a < v[i].b)
//      || (v[i].a < v[idx].b && v[idx].b < v[i].b))
//     cnt++;
//     else break;
// }
// ans = max(ans, cnt);
// }

    cout << ans;
    return 0;
}