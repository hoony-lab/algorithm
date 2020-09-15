#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define F(i, n) for(int i = 0 ; i < n; ++i)
using namespace std;
void print(set<int> s) {
	for (int i : s) cout << i << " ";
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (1) {
		int n, k, m;
		cin >> n >> k >> m;
		if (!n && !k && !m)
			return 0;

		vector<int> v(n);
		generate(v.begin(), v.end(), [num = 0] () mutable { return ++num; });

		set<int> s(v.begin(), v.end());
		
		s.erase(m);
		auto idx = s.begin();
		advance(idx, m - 2);

		print(s);


		//set<int> s(v.begin(), v.end());
		//auto aa = distance(s.begin(), idx);
		//advance(idx, k);
		
		
		for (int clock_size = n - 1; clock_size > 1; --clock_size) {
			if (idx == s.end()) idx--;
			int present = distance(s.begin(), idx);
			int after = (present + k + 1) % clock_size;

			int move = after - present;
				//if (present >= dist)	move = present - dist;
				//else					move = dist - present;
			cout << " > " << *idx << " : " << present << ", " << after << ", " << move << '\n';



			advance(idx, move);

			
			s.erase(*idx);
			auto iidx = s.begin();
			advance(iidx, after);
			idx = iidx;
			
			print(s);
			//cout << *idx << '\n';
		}

		cout << *idx << '\n';
	}
	return 0;
}
/*
1	2	3	4	5	6	7	8
1	2	-3	4	5	6	7	8
1	2	-3	4	5	6	7	-8
1	2	-3	4	5	-6	7	-8
1	2	-3	4	-5	-6	7	-8
1	2	-3	4	-5	-6	-7	-8
1	-2	-3	4	-5	-6	-7	-8
1	-2	-3	-4	-5	-6	-7	-8
*/