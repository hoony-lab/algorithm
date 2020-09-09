#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define ll long long
using namespace std;
struct j { int w, v; };
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<j> jewel;
    multiset<int> bag;
    int n, k;
    ll ans = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        jewel.push_back({ w, v });
    }

    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        bag.insert(c);
    }

    sort(jewel.begin(), jewel.end(), [](j v1, j v2) {
        return v1.v > v2.v;
    });


    for (vector<j>::iterator iter = jewel.begin(); iter != jewel.end(); ++iter) {
        auto iter_bag = bag.lower_bound(iter->w);

        if (iter_bag != bag.end()) {
            ans += iter->v;
            bag.erase(iter_bag);
        }

    }

    cout << ans;
    return 0;
}