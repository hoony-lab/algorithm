#include <iostream>
#include <algorithm>

using namespace std;

int ans, n, m, play[10001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> play[m];
	



	cout << ans;
	return 0;
}

1	2	3	4	5
1
1	2
1		3
1	2		4
1				5
1	2	3
1
1	2		4!!

1		3
1	2			5
1		3
1	2		4