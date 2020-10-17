// 20201017 1730 - 1813
#include<iostream>
#include <string>
//#include <stdio.h>
#include <cstdio>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <set>
#define MAX 7
#define F(i, n) for(int i = 0 ;i < n ; ++i)
#pragma warning (disable : 4996)
#define ll long long
using namespace std;
enum NUM { A = 10, B, C, D, E, F };
int n, k, ans;
string s;
set<string, greater<>> st;
vector<string> v;
string hex_to_dec(string str) {
	ll ret = 0;
	int idx = 0;
	for (int i = str.size() - 1; i >= 0; --i) {

		if ('0' <= str[i] && str[i] <= '9') {
			ll tmp = str[i] - '0';
			ret += (pow(16, idx) * tmp);
		}
		else {
			ll tmp = str[i] - 'A' + 10;
			ret += (pow(16, idx) * tmp);
		}
		idx++;
	}
	return to_string(ret);
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
*/
	freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		st.clear();
		v.clear();
		ans = 0;

		cin >> n >> k >> s;

		//  문자열 모든 경우의 자물쇠
		int ssize = (int)s.size();
		int lock_len = ssize / 4;
		F(i, lock_len) {
			// 한칸 이동
			string str = s.substr(ssize - i) + s.substr(0, ssize - i);
			// 모든 문자열 조합
			F(a, 4) {
				st.insert(str.substr(a * lock_len, lock_len));
				v.push_back(str.substr(a * lock_len, lock_len));
			}
		}

		sort(v.begin(), v.end(), greater<>());
		unique(v.begin(), v.end());

		cout << "#" << test_case << " " << hex_to_dec(v[k - 1]) << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}