#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <functional>
using namespace std;
#define F(i,n) for(int i = 0 ; i < n ; ++i)
#define MAX 100002
int ans, n, male, female;
multiset<int> mm, mf, pf, pm;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	F(i, n) {
		cin >> male;
		//male < 0  ? mm.push_back(male) : pm.push_back(male);
		if (male < 0)	mm.insert(-male);
		else			pm.insert(male);
	}
	F(i, n) {
		cin >> female;
		//female < 0  ? mf.push_back(female) : pf.push_back(female);
		if (female < 0)	mf.insert(-female);
		else			pf.insert(female);
	}
	
	//sort(mm.begin(), mm.end(), greater<>());		// -1 -2 -3 -4
	//sort(pf.begin(), pf.end());						//        2 3 4 5

	//sort(mf.begin(), mf.end(), greater<>());		// -1 -2 -3 -4
	//sort(pm.begin(), pm.end());						//        2 3 4 5

	//for (int i : mm) cout << i << " "; cout << '\n';
	//for (int i : pf) cout << i << " "; cout << '\n';
	//for (int i : mf) cout << i << " "; cout << '\n';
	//for (int i : pm) cout << i << " "; cout << '\n';

	for (int f : pf) {
		auto iter = mm.upper_bound(f);

		if (iter != mm.end())
			mm.erase(iter), ++ans;
	}

	for (int m : pm) {
		auto iter = mf.upper_bound(m);

		if (iter != mf.end())
			mf.erase(iter), ++ans;
	}
	cout << ans;
	return 0;
}

/*
한 유형은 자신보다 키가 큰 여자이고,
다른 유형은 자신보다 키가 작은 유형이다.
 == 여자
키가 같은 남자와 여자가 춤을 추는 일은 일어나지 않는다.

키가 양수인 경우에는 자신보다 키가 큰 여자와 춤을 추기를 원하는 남자이고,
 음수인 경우에는 키가 작은 사람과 춤을 추기를 원하는 남자이다.

5
-3 -2 -4 -1 -9
3 4 2 5 2
 */