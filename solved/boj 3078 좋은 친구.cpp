#include <list>
#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>
using namespace std;

long long answer;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	answer = 0;

	int n, k, strlen;
	string str;
	vector<int> vv[21];
	list<int> l;
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> str;
		//strlen = str.length() - 1;
		//vv[strlen].push_back(i);

		l.push_back(strlen);


	}

	//sort(v.begin(), v.end(), [](pair<string, int> v1, pair<string, int> v2) {
	//	if (v1.first.size() == v2.first.size())
	//		return v1.second < v2.second;
	//	return v1.first.size() < v2.first.size();
	//});

	for (int i = 0; i < 21; ++i) {
		if (vv[i].size() < 2) continue;

		int ind = 0;
		while (ind < vv[i].size() - 1) {

			for (int j = ind+1; j < vv[i].size(); ++j) {

				//if (abs(v[i].second - v[j].second > k)) break;
				//if (v[i].first.size() != v[j].first.size()) break;
				if (vv[i][j] - vv[i][ind] > k) break;
				//if (vv[i][.size() == vv[j].size())
					answer++;
			}
			ind++;
		}
	}
	cout << answer << '\n';

	return 0;
}






/*

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

vector<int> q[25];
char str[21];

int main()
{
	int n, k;
	long long int cnt = 0;
	long long int tmp = 0;
	int charlen;

	scanf("%d %d", &n, &k);

	// 이름을 입력 받았을 때 이름 길이에 해당하는
	// q 벡터에 이름이 아닌 그 이름이 나온 순서를 넣어준다.
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);

		charlen = strlen(str);
		q[charlen].push_back(i);
	}

	for (int i = 2; i <= 20; i++)
	{
		int idxlen = q[i].size();
		int left = 0, right = 0;

		// 큐가 비어있는 경우 다음 큐로 간다.
		if (!idxlen)
			continue;

		// left가 idxlen(해당하는 큐의 크기)에 도달할 때 까지
		while(left < idxlen - 1)
		{
			// right가 끝에 도달하지 않았고, 좋은 친구에 해당 될 때
			if (right < idxlen - 1 && q[i][right] - q[i][left] <= k)
			{
					// right를 한칸 옮겨주고 tmp++
					right++;
					tmp++;

					// right를 한칸 옮겼을 때 q[][right] - q[][left] == k일 때
					if (q[i][right] - q[i][left] == k)
					{

						// 모아둔 tmp를 더해주고 left를 한칸 옮기기에 tmp는 하나 빼준다.
						cnt += tmp;
						tmp--;
						left++;
					}
			}

			// 그외 경우
			else
			{
				// q[][right] - q[][left] <= k 일때만 더해준다.
				if (q[i][right] - q[i][left] <= k)
					cnt += tmp;

				// 그게 아니라면 tmp -1을 한 값을 더해준다.
				else
					cnt += tmp - 1;

				tmp--;
				left++;
			}
		}

		// 해당하는 큐가 끝나면 tmp = 0으로 초기화
		tmp = 0;
	}

	printf("%lld", cnt);

	return 0;
}


출처: https://www.crocus.co.kr/601 [Crocus]

*/





/*

#include <iostream>
#include <deque>
#include <string>
using namespace std;
int N, K;
int table[21];
long counter = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	deque<int> ds;
	
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		int len = s.length();

		if (ds.size() > K) {
			table[ds.front()]--;
			ds.pop_front();
		}
		if (!ds.empty())
		{
			counter += table[len];
		}
		ds.push_back(len);
		table[len]++;

	}
	cout << counter;
}

*/