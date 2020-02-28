#include "Gready.h"
using namespace std;

void Gready::q1541()
{
	int num[51], operCnt = 0, numCnt = 0;
	char oper[51];
	string str;
	while (char c = getchar() != EOF) {
		if (c == '-' || c == '+') {
			num[numCnt++] = stoi(str);
			oper[operCnt++] = c;
			operCnt++;
		}
		str.append(&c);
	}
	int tryNum = operCnt + numCnt;

	while (tryNum--) {

	}
}

//int minLen;
//queue<int> q;
//vector<int> v;
//int n, map[23][23], visited[23][23];

void Gready::q1507()
{
	int minLen;
	queue<int> q;
	vector<int> v;
	int n, map[23][23], visited[23][23];

	cin >> n;

	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			cin >> map[x][y];
			visited[x][y] = 0;
		}
	}

	for (int x = 1; x < n; x++) {
		for (int y = x + 1; y <= n; y++) {

			for (int i = y + 1; i <= n; i++)
			{
				if (map[x][y] > 1) {

				}
			}
		}
	}

	//제국	드븐 다리
	//야생	니달리 나르 아리 워윅
	//싸움꾼	초가스 워윅 


	//기사	가붕이 뽀삐
	//요들	트타 룰루 케넨 뽀삐 나르 베이가


	//야생	니달리 나르 아리 워윅
	//용		쉬바나 솔
	//형상	니달리 나르 쉬바나
	//마법사  아리 솔 유미 룰루 베이가
	//		나르 베이가 룰루

	//6귀족 베인 피오라 가렌 루시안 레오나 케일
	//	드븐 다리(검사)

}

void Gready::q11047()
{
	//long long n, k;
	//cin >> n >> k;

	//int worth[11], dp[11], result = 0;
	//for (int i = 0; i < n; i++)
	//	cin >> worth[i];
	//
	//sort(worth, worth + n);

	//for (int i = n - 1; i >= 0; i--) {
	//	//if (worth[i] == k) {
	//	//	result = 1;
	//	//	break;
	//	//}
	//	if (worth[i] > k) continue;
	//	else {
	//		result += (k / worth[i]);
	//		k %= worth[i];
	//		
	//	}
	//}
	//cout << result;

		//5585
	int n, result = 0;
	cin >> n;
	int worth[6] = { 1,5,10,50,100,500 };
	n = 1000 - n;
	for (int i = 5; i >= 0; i--) {
		result += (n / worth[i]);
		n %= worth[i];
	}
	cout << result;
}

void Gready::q2217()
{
	int n;
	cin >> n;
	
	int rope[100001];
	for (int i = 0; i < n; i++)
		cin >> rope[i];
	//???

}

void Gready::q10610()
{
	vector<int> v;
	string n, str;
	long long result = 0, sum = 0;
	cin >> n;

	bool noZero = true;

	//while (n>0) {
	//	
	//	int res = n % 10;
	//	if (res == 0) noZero = false;
	//	sum += res;
	//	n /= 10;
	//	v.push_back(res);
	//}

	for (int i = 0; i < n.size(); i++)
	{
		if (n[i] == '0') noZero = false;
		int res = n[i] - '0';
		sum += res;
		v.push_back(res);
	}

	if(noZero || sum%3 != 0) cout << -1;
	else {
		sort(v.begin(), v.end());
		string str;
		for (int i = v.size() - 1; i >= 0; i--)
			str.append(to_string(v.at(i)));
		cout << str;
	}
}

void Gready::q2875()
{
	//2여1남, nm / 반드시 k인턴
	int n, m, k;
	cin >> n >> m >> k;

	int result = 0;

	int ppl = n + m;
	int team = ppl / 3;


}
