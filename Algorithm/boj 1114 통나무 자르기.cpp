#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int l, k, c, cut[10001], ans = 0;
int s, e, m;

//bool foo(int idx) {
//	if (cut[idx - 1] > m) return false;
//
//	int len = 0, start = 0, cnt = 0;
//	for (int i = idx; i <= k+1; ++i) {
//
//		if (cut[i] - cut[i - 1] > m) return false;
//
//		if (len + cut[i] - cut[i - 1] > m) {
//			cnt++;
//			len = cut[i] - cut[i - 1];
//			if (cnt > c) return false;
//		}
//		else {
//			len += cut[i] - cut[i - 1];
//		}
//	}
//	ans = m;
//	return true;
//}

bool foo(int len, int chk) {
	int p = l, cnt = 0;
	for (int i = k; i >= 0; --i) {
		if (cut[i + 1] - cut[i] > len) return false;
		if (p - cut[i] > len) {
			cnt++;
			p = cut[i + 1];
		}
	}
	if (cnt <= c) {
		if (chk)	return cut[1];		// 처음꺼 구하기
		else		return true;
	}

	return false;
}

int main() {
	cin >> l >> k >> c;
	for (int i = 1; i <= k; ++i) cin >> cut[i];
	cut[0] = 0, cut[k + 1] = l;

	sort(cut + 1, cut + k + 1);

	// 길이 기준
	s = 0, e = 1e9;
	while (s < e) {
		m = (s + e) / 2;	

		if (foo(m, 0)) e = m;
		else s = m + 1;
	}

	cout << e << " " << foo(e, 1);
	return 0;

	//int d = 0;
	//for (int i = 1; i <= k; ++i) {
	//	if (foo(i + 1)) {
	//		d = i;
	//		break;
	//	}
	//}

	//cout << ans << " " << cut[d];
	//return 0;
}

/*
9 2 1
4 5

5 4



1000 4 3
44 67 99 501

1000 4 3
200 400 700 900

*/