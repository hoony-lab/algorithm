#include "DP.h"
using namespace std;

//dp
void DP::q1463()
{
	int n, cnt = 0;
	cin >> n;

	int dp[1000001];
	dp[1] = 0;

	for (int i = 2; i <= n; i++) {
		//1을 빼는 경우
		dp[i] = dp[i - 1] + 1;

		//2으로 나누어 떨어지면 2으로 나누는 경우
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
			dp[i] = dp[i / 2] + 1;

		//3으로 나누어 떨어지면 3으로 나누는 경우
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
			dp[i] = dp[i / 3] + 1;
	}

	cout << dp[n];
	//while (n!=1) {
	//	cnt++;
	//	if (n % 3 == 0) {
	//		n /= 3;;
	//	}
	//	else if (n % 2 == 0) {
	//		n /= 2;
	//	}
	//	else n -= 1;

	//	if (n == 2)
	//		break;

	//	cout << n<<endl;
	//}

	//cout << cnt;
}

void DP::q11726()
{
	/*
	//2xN 사이즈 직사각형
	n		세로직사각형 갯수
		0	1	2	3	4	5	6
	1		1								1
	2	1		1							2
	3		2		1						3
	4	1		3		1					5
	5		3		4		1				8
	6	1		6		5		1			13
	7		4		10		6		1		21
		
	dp[i] = dp[i-1] + dp[i-2];
	*/

	int n;
	cin >> n;

	int dp[3003];
	dp[1] = 1;
	dp[2] = 2;
	
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[n];
	
}

void DP::q11727()
{
	//2x1 && 2x2
	/*
		n		세로직사각형 갯수
		0	1	2	3	4	5	6
	1		1								1
	2	1		1							2	1	3
	3		2		1						3	2	5
	4	1		3		1					5	6	11
	5		3		4		1				8
	6	1		6		5		1			13
	7		4		10		6		1		21
	*/
	int n;
	cin >> n;

	int dp[1001];
	dp[1] = 1;
	dp[2] = 3;


	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + 2*dp[i - 2]) % 10007;
	}

	cout << dp[n];
}
/*
1	
2	3
3	
4	3*3 + 2 = 11
5
6	3*3*3 + 2*6 = 39
7
8	3*3*3*3 + 2*2*2*3*3 = 153 = 81 + 72
*/

void DP::q11052()
{
	/*
	5
	10	9		8		7		6
	10	1010

	4
	1		5		6		7
	1		5		6		55

	4
	5		2		8		10
	5		55		555		5555

	4
	3		5		15		16
	3		33		15		3 15
	*/

	//dp[1] = card[1];
//dp[2] = max(card[2], card[1] * 2);	//2 11				2
//dp[3] = max(card[3], card[1] * 3, card[2] + card[1]);	//3	111	12			3
//dp[4] = max(card[4], card[1] * 4, card[3] * card[1], card[2] * 2, card[2] + card[1] * 2)	//4	1111	31	22	211		5
//dp[5] = max(card[5], card[1] * 5, card[4] + card[1], card[3] + card[2], card[3] + card[1] * 2, card[2] * 2 + card[1]);
//5	41	32	311	221	2111	11111						32																7

//6	51	42	411	33	321	3111	222	2211	21111	111111											42 33	222			11
//7	61	52	511	43	421	4111	331	322	3211	31111	2221	22111	211111	1111111				52	43	322			15
//8	71	62	611	53	521	5111	44	431	422	4211	41111	332	3311	3221	32111	311111	2222	62	53	44	422 332 2222

	int n,card[1001],dp[10001];
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> card[i];
	}


	dp[0] = 0;
	dp[1] = card[1];

	//n장 뽑기
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i - j] + card[j], dp[i]);
		}
	}

	cout << dp[n];
}

void DP::q2193()
{
	/*
	0으로 시작 안함
	1이 두번 안나옴

	0이면 0또는 1 붙임
	1이면 0만 붙임

	1
	10
	100											101
	1000						1001			1010
	10000	10001				10010			10100			10101
	100000	100001	100010		100101	100100	101000	101001	101010
	2		1		2			1		2		2		1		2
	1
	1

	2
	3

	5
	8

	13


	1			1
	0				1
	01			2
	001				3
	00011		5
	00000111		8
	0000000011111			13

	
	*/

	long long n, dp[100];
	cin >> n;

	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];

}

void DP::q9465()
{
	/*
	스티커를 떼면 상하좌우 손상
	*/
	int test_case;
	cin >> test_case;

	vector<long long> v;
	for (int test = 1; test <= test_case; ++test) {
		int map[2][10001];
		long long dp[2][10001];
		long long n, result;
		cin >> n;
		
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < n;j++) {
				cin >> map[i][j];				
			}
		}

		//dp[0] = max(map[0][0], map[1][0]);
		//dp[1] = max(map[0][0] + map[1][1], map[1][0] + map[0][1]);
		////cout << dp[0] << ", " << dp[1] << ", ";
		//for (int i = 2; i < n; i++) {

		//	if (map[0][i] + map[1][i - 1] < map[1][i]) {
		//		dp[i] = dp[i - 2] + map[1][i];
		//	}
		//	else
		//		dp[i] = dp[i - 1] + map[0][i];

		//	if (map[0][i - 1] + map[1][i] < map[0][i]) {
		//		dp[i] = dp[i - 2] + map[0][i];
		//	}
		//	else
		//		dp[i] = dp[i - 1] + map[1][i];
		//	cout << dp[i] << ", ";
		//}

		dp[0][0] = map[0][0];
		dp[1][0] = map[1][0];
		dp[0][1] = map[0][1] + dp[1][0];
		dp[1][1] = map[1][1] + dp[0][0];

		for (int i = 2; i < n; i++) {
			dp[0][i] = map[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = map[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}

		result = max(dp[0][n - 1], dp[1][n - 1]);
		v.push_back(result);
	}
	//cout << endl << endl;
	for (auto i : v)
		cout << i << '\n';
}

void DP::q10844()
{
	/*
1		2		3		4		5		6		7		8		9
10		12		21	23	32	34	43	45							87	89	98	x
101 x	121	123
*/

	int n;
	cin >> n;

	long long dp[103][10] = { 0, };
	long long result=0;

	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {

			if (j == 0)			dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9)	dp[i][j] = dp[i - 1][j - 1];
			else				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 100000000 ;

			//dp[i][j] = dp[i][j] % 1000000000;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		result += dp[n][i];
		result %= 1000000000;
	}

	cout << result;
}

void DP::q11057()
{
	int n;
	cin >> n;

	long long dp[1001][10] = { 0, }, result = 0;
	
	for (int i = 0; i < 10; i++){
		dp[0][i] = 1;
	}
	for (int i = 1; i < n; i++)	{
		for (int j = 0; j < 10; j++){
			for (int k = j; k < 10; k++){
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 10007;
			}	
		}
	}
	for (int i = 0; i < 10; i++)
	{
		result += dp[n - 1][i];
		result %= 10007;
	}
	cout << result;
}

void DP::q1912()
{
	int n;
	cin >> n;

	long long num[10001] = { 0, }, dp[10001] = { 0, }, result = 0;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	dp[0] = num[0];
	result = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + num[i], num[i]);
		result = max(result, dp[i]);

		//cout << dp[i] << ", " << result << endl;
	}

	cout << result;
}

void DP::q1562()
{
	int n;
	cin >> n;

	long long dp[102][12], result = 0;
	dp[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1]; continue;
			}
			if (j > 0 && j < 9) {
				dp[i][j] = dp[i - 1][j + 1] + dp[i - 1][j - 1]; continue;
			}
			if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1]; continue;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << dp[n][i] << '\t';
		result += dp[n][i];
		result %= 1000000000;
	}cout << endl;
	cout << result;

}
