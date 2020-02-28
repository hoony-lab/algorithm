#pragma warning (disable : 4996)
#include "abocadoTest.h"
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;


void abocadoTest::q16987()
{

	int num, cnt = 0, eggDurSum = 0, eggWSum = 0;
	int eggDur[8];
	int eggW[8];
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> eggDur[i] >> eggW[i];
		eggDurSum += eggDur[i];
		eggWSum += eggW[i];
	}
	cout << eggDurSum << '\t' << eggWSum << endl;

	if (eggDurSum <= eggWSum)
		cout << "THIS " << num << endl;
	else {
		for (int k = 0; k < num - 1; k++)
		{
			if (eggDur[k] > 0 && eggDur[k + 1] > 0) {
				if (eggDur[k] < eggW[k + 1]) {
					eggDur[k] = eggDur[k] - eggW[k + 1];
					cnt++;
					for (int j = k; j < num - 1; j++)
					{
						if (eggDur[k] = eggDur[j] - eggW[j + 1] < 0)
							cnt++;
					}
				}

				if (eggDur[k + 1] < eggW[k]) {
					eggDur[k + 1] = eggDur[k + 1] - eggW[k];
					cnt++;
				}
			}


		}
		cout << "THAT  ";
		cout << cnt << endl;
	}

}

void abocadoTest::q14103()
{
	int num, quiz, a, b[10000], cnt = 0;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> quiz;
		for (int j = 2; j < quiz; j++)
		{
			if (a = quiz % j == 0)
				b[cnt++] = a;
		}
	}

}

/*
bool DFS(int r, int c) {
	int row, col;
int input[500][2];
char inputs[500][500];
bool visit[500][500] , available[500][500];

	visit[r][c] = true;

	int nextRow = r + input[inputs[r][c] - 'A'][0];
	int nextCol = c + input[inputs[r][c] - 'A'][1];

	//|| available[nextRow][nextCol]
	if (nextRow > row || nextCol > col || 0 >= nextRow || 0 >= nextCol || available[nextRow][nextCol])
	{
		return true;
	}

	if (!visit[nextRow][nextCol])
	{
		visit[nextRow][nextCol] = true;
		//cout << nextRow << ", " << nextCol << " : visited" << endl;
		available[nextRow][nextCol] = DFS(nextRow, nextCol);
		visit[nextRow][nextCol] = false;

		if (available[nextRow][nextCol])
			return true;
	}
	return false;
}
void abocadoTest::q17090()
{

	cin >> row >> col;

	input[(int)('U' - 'A')][0] = -1;
	input[(int)('L' - 'A')][1] = -1;
	input[(int)('R' - 'A')][1] = 1;
	input[(int)('D' - 'A')][0] = 1;

	//cout << 'U' - 'A' << endl;
	//cout << 'L' - 'A' << endl;
	//cout << 'R' - 'A' << endl;
	//cout << 'D' - 'A' << endl;

	for (int i = 1; i < row+1; i++)
	{
		char temp;
		for (int j = 1; j < col+1; j++)
		{
			cin >> temp;
			inputs[i][j] = temp;
		}
	}

	//for (int i = 1; i < row+1; i++)
	//{
	//	for (int j = 1; j < col+1; j++)
	//	{
	//		cout << inputs[i][j];
	//	}
	//	cout << endl;
	//}

	for (int i = 1; i < row+1; i++)
	{
		for (int j = 1; j < col+1; j++)
		{
			if (!available[i][j])
				available[i][j] = DFS(i, j);
		}
	}
	int cnt = 0;
	for (int i = 1; i < row+1; i++)
	{
		for (int j = 1; j < col + 1; j++)
		{
			if (available[i][j])
				cnt++;
		}
	}
	cout << cnt << endl;

	//
	//for (int i = 0; i < row; i++)
	//{
	//	int tempi = i;
	//	for (int j = 0; j < col; j++)
	//	{
	//		int tempj = j;
	//		int count = 0;
	//		//cout << inputs[i][j];
	//		while (i < row || j < col) {
	//			switch (inputs[i][j])
	//			{
	//			case 'D':
	//				i++;
	//				break;
	//			case 'U':
	//				//cout << "UP" << endl;
	//				i--;
	//				break;
	//			case 'L':
	//				//cout << "LEFT" << endl;
	//				j--;
	//				break;
	//			case 'R':
	//				j++;
	//				break;
	//			}
	//			if (++count > row * col) break;
	//		}
	//		if (i >= row || j >= col) {
	//			cout << i << ", " << j << endl;
	//			cnt++;
	//		}
	//		j = tempj;
	//	}
	//	//cout << endl;
	//	i = tempi;
	//}
	//cout << cnt << endl;
}
*/



void abocadoTest::q11403()
{
	int n;
	cin >> n;

	int graph[102][102] = { 0, };
	int visited[102][102] = { 0, };
	//vector<int> v[102];
	queue<int> q;
	

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> graph[y][x];

			//if (graph[y][x] == 1)
			//	v[y].push_back(x);
		}
	}

	//for (int j = 0; j < n; j++) {
	//	for (int i = 0; i < n; i++) {

	//		if (v[i].at(j) == 1) {

	//			v[i].push_back(j);
	//			v[j].push_back(i);
	//		}
	//	}
	//}

	//14 
	//27
	//45 46
	//51
	//67
	//73
	// xxx
	// y
	// y,x


	//for (int y = 0; y < n; y++) {
	//	for (int x = 0; x < n; x++) {

	//		if (graph[y][x] == 1) {
	//			visited[y][x] = 1;
	//			q.push(y);

	//			while (!q.empty()) {
	//				int tempY = q.front();
	//				q.pop();

	//				
	//				int size = v[tempY].size();
	//				cout << "size : " << size << endl;
	//				for (int i = 0; i < size; i++) {
	//					int tempX = v[tempY].at(i);

	//					cout << " pusing : " << y << ": " << tempY << ", " << tempX << '\n';

	//					if (visited[y][tempX] == 0) {
	//						visited[y][tempX] = 1;
	//						q.push(tempX);
	//						cout << " pusing : " << y << ", " << tempX << '\n';
	//					}

	//					//graph[tempY][tempX] == 1

	//				}

	//			}



	//			//break;
	//		}
	//	}
	//}


	for (int y = 0; y < n; y++) {
		q.push(y);
		while (!q.empty()) {
			int tempX = q.front();
			q.pop();

			for (int x = 0; x < n; x++) {
				if (graph[tempX][x] && visited[y][x] == 0) {
					visited[y][x] = 1;
					q.push(x);
				}
			}
		}
	}


	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cout << visited[y][x] << " ";
		}
		cout << '\n';
	}


}

void abocadoTest::q11053()
{
	int n, nums[1002], total[1002], result=0;
	vector<int> v;
	cin >> n;

	nums[0] = 0;
	for (int i = 1; i <= n; i++)	{
		cin >> nums[i];
	}

	sort(nums, nums + n);

	for (int i = 1; i <= n; i++) {
		if (nums[i] > nums[i - 1]){
			result++;
			total[i] = nums[i] + nums[i - 1];
		}
	}

	cout << result;

}


void abocadoTest::sw7835()
{
	int t;
	cin >> t;
	vector<long long> v;

	for (int a = 1; a <= t; a++) {
		string str;
		cin >> str;

		long long result = 1;
		int size = str.size();

		if (size == 1) result = 1;

		else if (size == 2) {
			if (str[1] != str[0])
				result = 2;
			else result = 1;
		}

		else {
			if (str[1] != str[0])
				result *= 2;
			if (str[size - 1] != str[size - 2])
				result *= 2;

			for (int i = 1; i < str.size() - 1; i++) {
				int mul;

				if ((str[i] == str[i - 1] && str[i] != str[i + 1])				//112
					|| (str[i + 1] == str[i - 1] && str[i] != str[i + 1])		//121
					|| (str[i] != str[i - 1] && str[i] == str[i + 1])) {		//221
					mul = 2;
				}
				else if (str[i] != str[i - 1] && str[i] != str[i + 1] && str[i - 1] != str[i + 1]) {	//123
					mul = 3;
				}
				else if (str[i] == str[i - 1] && str[i] == str[i + 1] && str[i - 1] == str[i + 1]) {	//111
					mul = 1;
				}

				result = result * mul;
			}
		}
		long long bb =  result % (long long)(pow(10, 9) + 7);
		
		v.push_back(bb);
	}
	for(int i = 1; i <= v.size(); i++)
		cout << "#" << i << " " << v.at(i-1) << '\n';

	cout << 2 / 10;

	//1차 15/100

/*
6
aaafsdindlfbmpwomdlskmvoiwmpsmxcvklnlskvnl
aaafsdindlfbmpwomdlskmvoiwmpsmxcvklnlskvn
aaafsdindlfbmpwomdlskmvoiwmpsmxcvklnlskv
aaafsdindlfbmpwomdlskmvoiwmpsmxcvklnlsk
aaafsdindlfbmpwomdlskmvoiwmpsmxcvklnls
aaafsdindlfbmpwomdlskmvoiwmpsmxcvklnl
*/
}

void abocadoTest::sw7854()
{
	int test_case;
	int T;
	cin >> T;
	vector<long long> v;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		long long num, temp, fiveNum, twoNum, exp = 0, cnt = 0;
		cin >> num;
		temp = num;

		if (num < 1000) {
			if (num == 1) 				cnt += 1;
			else if (num < 5) 			cnt += 2;
			else if (num < 10) 			cnt += 3;
			else if (num < 20) 			cnt += 4;
			else if (num < 25) 			cnt += 5;
			else if (num < 50) 			cnt += 6;
			else if (num < 100) 		cnt += 7;
			else if (num < 125)			cnt += 8;
			else if (num < 200)			cnt += 9;
			else if (num < 250)			cnt += 10;
			else if (num < 500)			cnt += 11;
			else if (num < 1000)		cnt += 12;
		}
		else{
			while (num > 999) {
				num = num / 10;
				exp++;
			}
			if (num < 10)			exp += 1;
			else if (num < 100)		exp += 2;
			else					exp += 3;

			for (int five = 0; five <= exp; five++) {
				for (int two = 0; two <= exp; two++) {
					if (five - two <= 3 && five - two >= -1) {

						fiveNum = pow(5, five);
						twoNum = pow(2, two);
						if (fiveNum * twoNum == (4 || 40)) continue;
						if (fiveNum * twoNum > temp) continue;

						cnt++;
						cout << fiveNum << ", " << twoNum << endl;
					}
				}
			}
			// 1 케이스 추가
			cnt++;
			
		}
		v.push_back(cnt);
	}
		//1 2 5 10 20 25 50 100
		//	for (int j = 1; j < 25; j *= 5)
		//	{
		//		
		//		for (int i = 1; i <= 4; i *= 2)
		//		{
		//			if(j*i == 4)
		//				continue;
		//			cnt2++;
		//		}
		//		cnt5++;
		//	}

	
	/*

	1 2 5 10 20 25 50 100 125 200 250 500 1000 
	1000000000 = 43 = 10 ^ 9

5의개수 - 2 =
		_ 2하나 2
		5 3			5 10 20									1 0~4 = 1 -1
		55 4		25 50 100 200				2 - 0~4 = 2 -1
	   555	5		125 250 500 1000 2000		3 - 0~4 = 3 -1
		5555 5											4 - 1~ 6 = 3 ~-1
		55555 5
		555555 222 부터시작 5개 ~ 222 22222
		5 7 	5
		5 8    5						22222 ~ 22222 2222			8개 5개 ~ 9개		5갯-2갯 = 3 ~ -1
		5 9   4			55555 5555 22222 2 ~ 22222 2222			9개 6개~9개
			2 3 4 5 5 5 5 5 5 4
				for(int five = 0; five < exp ; five++){
					for(int two = 0; two <= exp ; two++){
						if(five - two <= 3 && five - two >= -1)
							cnt++;
					}
				}
		10 ^ 8
		2 3 4 5 5 5 5 5 4

		7
		2 3 4 5 5 5 5 4

		6
		2 3 4 5 5 5 4

		5
		2 3 4 5 5 4

		4
		2 3 4 5 4

		3		-	13
		0		2
		5 		3	5 10 20 .
		55 		4	25 50 100 200
		555 	4	125 250 500 1000

		<>2 	5갯-2갯 = 3 ~ -1

		1
		0 2 		1
		5  			3
		55 			3

		2 2
		5 5 10
		2 3 2

		*/
	
	for (int i = 1; i <= v.size(); i++)
		cout << "#" << i << " " << v.at(i - 1) << '\n';
	
}

void abocadoTest::sw7732()
{
	/*
	
3
00:00:00
23:59:59

23:59:59
00:00:00

03:29:35
15:01:52	

#1 23:59:59
#2 00:00:01
#3 11:32:17
	*/
	int test_case, T;
	cin >> T;
	vector<string> v;
	for (test_case = 1; test_case <= T; ++test_case) {

		int time[3][3];
		string time1,time2,newTime;
		cin >> time1 >> time2;

		time[0][0] = stoi(time1.substr(0, 2));
		time[0][1] = stoi(time1.substr(3, 2));
		time[0][2] = stoi(time1.substr(6, 2));

		time[1][0] = stoi(time2.substr(0, 2));
		time[1][1] = stoi(time2.substr(3, 2));
		time[1][2] = stoi(time2.substr(6, 2));

		for (int i = 2; i >= 0; i--){
			if (time[1][i] >= time[0][i]) {
				time[2][i] = time[1][i] - time[0][i];
			}
			else  {
				if (i > 0) {
					time[2][i] = 60 + time[1][i] - time[0][i];
					time[1][i - 1] -= 1;
				}
				else {
					time[2][i] = 24 + time[1][i] - time[0][i];
				}
			}
		}

		cout << "#" << test_case << " " 
			<< setw(2) << setfill('0') <<  time[2][0] % 24 << ":" 
			<< setw(2) << setfill('0') << time[2][1] % 60 << ":" 
			<< setw(2) << setfill('0') << time[2][2] % 60 << '\n';

	}

	//for (int i = 1; i <= v.size(); i++)
	//	cout << "#" << i << " " << v.at(i - 1) << '\n';
	
}

void abocadoTest::sw7829()
{
	/*
	42
	2 3 7 14 21
	*/
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {

		int p;
		cin >> p;
		long long result = 0, num[1000000];
		for (int i = 0; i < p; i++) {
			cin >> num[i];
		}

		sort(num, num + p);
		result = num[0] * num[p-1];

		cout << "#" << test_case << " " << result << '\n';
	}
}

void abocadoTest::sw7728()
{

	int test_case;
	int T;
	cin >> T;
	getchar();
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int result = 0, numCnt[12] = { 0, };
		//char ch;
		//while ((ch = getchar()) != '\n') {
		//	//cout << ch << '\t';
		//	for (int i = 0; i < 10; i++) {

		//		if (ch - '0' == i) {
		//			numCnt[i] ++;
		//			break;
		//		}
		//	}
		//}
		////getchar();

		string str;
		cin >> str;
		for (int a = 0; a < str.size(); a++){
			for (int i = 0; i < 10; i++) {

				if (str[a] - '0' == i) {
					numCnt[i] ++;
					break;
				}
			}
			//if (a == str.size() - 1) break;
		}
		
		for (int i = 0; i < 10; i++){
			if (numCnt[i] > 0) result++;
		}

		cout << "#" << test_case << " " << result << '\n';
	}
}

void abocadoTest::sw7810()
{
	/*

크기 N인 수열이 주어졌을 때, 수열에 대응하는 숫자 H가 찾고 싶다.

H는 수열에서 H보다 크거나 같은 숫자가 H개 이상 존재하는 값이다.

2
5
10 1 8 1 1
5
8 2 2 4 10

#1 2
#2 3

			// 2 2 4 8 10 => 3
			//1 1 1 6 8 10 => 3
*/
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int result = 1;
		int n;
		vector<int> v;
		cin >> n;
		bool noResult = false;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			v.push_back(temp);

		}
		if (v.at(0) == 0 && v.at(v.size() - 1) == 0) noResult = true;
		sort(v.begin(), v.end());
		bool done = false;

		for (int i = 0; i < n - 1; i++) {
			if (v.at(i) == v.at(i + 1)) continue;

			for (int j = v.at(i + 1) - 1; j >= v.at(i); j--) {
				//int len = n - i;
				//cout << "chekcing : " << i << " ," <<  v.at(i+1)-1 << endl;
				if (n - i - 1 >= j) {
					//cout << "cchekcing : " << j << endl;
					result = j;
					done = true;
					break;
				}
			}
			if (done) break;
		}
		if (noResult) result = 0;
		cout << "#" << test_case << " " << result << '\n';
	}
}

void abocadoTest::sw7964()
{
	/*
3
6 2
1 0 0 0 0 1
10 2
0 0 1 0 1 0 0 0 0 1
10 1
0 0 0 0 0 0 0 0 0 0

*/
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		//int n, d, city[30002];
		//int result = 0;

		//cin >> n >> d;
		//city[0] = 1;
		//for (int i = 1; i <= n; i++) {
		//	cin >> city[i];
		//}
		//city[n + 1] = 1;
		//
		//int cityNum = 0;
		//bool done = false;

		//while(cityNum != n+1){
		//	//cout << "chekcing : " << cityNum << '\n';
		//	if (city[cityNum] == 1) {
		//		for (int i = cityNum+1; i <= cityNum + d; i++)
		//		{
		//			//if (city[i] == 0) continue;
		//			if (city[i] == 1) {
		//				cityNum = i;
		//				break;
		//			}
		//			if (city[i] == 0 && i == cityNum + d) {
		//				city[i] = 1;
		//				cityNum = i;
		//				result++;
		//				//cout << "ccounting : " << cityNum << '\n';
		//			}
		//		}
		//	}

		//}
		


		//int n, d;
		//int result = 0;
		//vector<int> v;

		//cin >> n >> d;
		//v.push_back(1);
		//for (int i = 1; i <= n; i++) {
		//	int temp;
		//	cin >> temp;
		//	v.push_back(temp);
		//}
		//v.push_back(1);

		//int cityNum = 0;
		//bool done = false;

		//while (cityNum != n + 1) {
		//	//cout << "chekcing : " << cityNum << '\n';
		//	if (v.at(cityNum) == 1) {
		//		for (int i = cityNum + 1; i <= cityNum + d; i++) {
		//			
		//			if (v.at(i) == 1) {
		//				cityNum = i;
		//				break;
		//			}
		//			if (v.at(i) == 0 && i == cityNum + d) {
		//				//city[i] = 1;
		//				v.erase(v.begin() + i, v.begin() + i + 1);
		//				v.emplace(v.begin() + i, 1);
		//				cityNum = i;
		//				result++;
		//				//cout << "ccounting : " << cityNum << '\n';
		//			}
		//		}
		//	}
		//}


		int n, d, len = 0, result = 0, lastCity = 1, presentCity;
		cin >> n >> d;

		for (int i = 1; i <= n; i++) {
			cin >> presentCity;
			if (presentCity == 0) {
				len++;
				if (len == d) {
					result++;
					presentCity = 1;
					cout << "counting at : " << i << '\n';
				}
			}
			if (presentCity == 1) {
				len = 0;
			}
			presentCity = lastCity;
		}
		cout << "#" << test_case << " " << result << '\n';
	}
}

int mypow(const int& x) {
	unsigned long long ret = 1;
	unsigned long long factor = x;
	unsigned long long exp = x;
	while (exp) {
		if (exp & 1) {
			ret = ret * factor;
		}
		exp = exp >> 1;
		factor = factor * factor;
		factor %= 1000000007;
		ret %= 1000000007;
	}
	return ret;
}

void abocadoTest::sw7965()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	//시그마 아이의 아이승
	int test_case;
	int T;
	cin >> T;

	int result[1000001];
	result[1] = 1;
	for (int i = 2; i < 1000001; i++) {
		result[i] = (result[i - 1] + mypow(i)) % 1000000007;
	}
	for (test_case = 1; test_case <= T; ++test_case) {
		//unsigned long long result = 0, temp;
		//int n;
		//cin >> n;

		//for (int i = 1; i <= n; i++) {
		//	temp = powl(i, i);
		//	temp %= 1000000007;
		//	result += temp;
		//	result %= 1000000007;
		//}

		//for (int i = 1; i <= n; i++)
		//{
		//	temp = 1;
		//	int cnt = i;
		//	while (cnt--)
		//	{
		//		temp *= i;
		//	}
		//	
		//	temp %= 10000000000;
		//	result += temp;

		//	result %= 10000000000;
		//	cout << temp << '\t' << result << '\n';
		//}
		//result %= 1000000007;
		//cout << "#" << test_case << " " << result << '\n';



		int n;
		cin >> n;
		cout << "#" << test_case << " " << result[n] << '\n';

		

	}
}
void abocadoTest::sw7675()
{
	//첫문자 대문자, 나머지 소문자
	//마지막 구두점
	//대문자 한글자
	int test_case, T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {

		int lineSize = 0, lineIndex = 0 , result[8] = { 0, };
		cin >> lineSize;

		while (lineSize) {
			string str;
			cin >> str;

			bool upperStart = false, invalidName = false;
			int cntTemp = 0, size = str.size();

			//map <int,int> m;
			//m.at(1);

			/*
			숫자 ㄴ
			대문자 2개 ㄴ
			첫대문자 ㅇ, 나머지소문자
			온점 ㅇ
			*/

			for (int i = 0; i < size; i++) {
				if (str.at(i) >= 'a' && str.at(i) <= 'z') continue;
				if (str.at(i) >= '0' && str.at(i) <= '9') {
					cntTemp = 0;
					break;
				}
				if (str.at(i) >= 'A' && str.at(i) <= 'Z') {
					if (upperStart) {
						cntTemp = 0;
						break;
					}
					if (i == 0) {
						upperStart = true;
						cntTemp = 1;
					}
				}
				if (str.at(i) == '.')
					cntTemp = 1;
			}

			result[lineIndex] += cntTemp;
			if (str.at(size-1) == '.' || str.at(size - 1) == '!' || str.at(size - 1) == '?') {
				lineIndex++;
				lineSize--;
			}
			
		}


		cout << "#" << test_case << " ";
		for (int i = 0; i < lineIndex; i++)
			cout << result[i] << " ";
		cout << '\n';		
	}
	
	/*
	 
2
2
Annyung Hasae Yo! LoL!
3
my name is Hye Soo. my id is
Rhs0266. what your id Bro?
	 */
}
void abocadoTest::sw7792()
{
	int test_case, T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		/*
		알파벳 종류가많고
		사전순으로 빠른
		*/
		int n;
		cin >> n;
		getchar();
		string result, name[103];
		int nameBits[103], maxNameBits = 0, maxNameIndex = 0;
		
		for (int i = 0; i < n; i++) {
			nameBits[i] = 1;
			
			//cin.getline(name[i], 100);
			getline(cin, name[i]);

			string temp;
			temp = name[i];
			sort(temp.begin(), temp.end());
			for (int j = 0; j < temp.size() - 1; j++) {
				if (temp[j] != temp[j+1]) {
					nameBits[i]++;
				}
			}

			//if (i == 0) continue;
			// 0번째 말고 1번째 부터 비교


			if (maxNameBits == nameBits[i]) {	
				
				for (int k = 0; k < 50; k++) {
					if (k == min(name[maxNameIndex].size(), name[i].size()) + 1) break;
					if (name[maxNameIndex][k] == name[i][k]) {
						continue;
					}
					if (name[maxNameIndex][k] < name[i][k]) {
						//maxNameIndex = maxNameIndex;
						result = name[maxNameIndex];
						break;
					}
					else if (name[maxNameIndex][k] > name[i][k]) {
						maxNameIndex = i;
						result = name[i];
						break;
					}
				}
			}
			else if (maxNameBits < nameBits[i]) {
				maxNameBits = nameBits[i];
				maxNameIndex = i;
				result = name[i];
			}
			else {
				//maxNameBits = maxNameBits;
				//maxNameIndex = maxNameIndex;
				result = name[maxNameIndex];
			}
		}
		if (n == 1) result = name[0];
		cout << "#" << test_case << " " << result << '\n';
	}


	/*
4
3
BBIBBI
DEAD BEEF
ABCDDCBA
2
ABC
AAAA BBBB CCCC
1
P
4
AAAAAAAAAAAAAABA
AAAAAAAAAAAAAAAB
AAAAAAAAAAAAAABA
AAAAAAAAAAAAAAAA

	*/
}
void abocadoTest::sw7584()
{

	int test_case, T;
	cin >> T;		
	
	//p(i+1) = p(i) + 0 + 반전(좌우반전(p(i))
	//string str = "001", newStr = str;
	//while(newStr.size() < 1000){
	//	string funcStr;
	//	for (int i = newStr.size() - 1; i >= 0; i--) {
	//		//if (newStr.at(i) == '1') funcStr.append("0");
	//		//else if (newStr.at(i) == '0') funcStr.append("1");
	//		newStr.at(i) == '1' ?
	//			funcStr.append("0") : funcStr.append("1");

	//	}
	//	newStr.append("0" + funcStr);
	//}
	//cout << newStr << '\n';

	string newStr = "001001100011011";
	for (test_case = 1; test_case <= T; ++test_case) {
		char result;
		long long n, moduloBy16, moduloBy8, dividedBy8;
		cin >> n;



		
		while (true) {
			moduloBy16 = n % 16;
			moduloBy8 = n % 8;
			dividedBy8 = n / 8;

			if (moduloBy16 == 4) {
				result = '0'; break;
			}
			else if (moduloBy16 == 12) {
				result = '1'; break;
			}
			else if (moduloBy8 == 0) {
				n = dividedBy8;
			}
			else {
				result = newStr[moduloBy16 - 1]; break;
			}

		}
		cout << "#" << test_case << " " << result << '\n';
	}
	/*
	001
	0010011
	001001100011011
	0010011000110110001001110011011
	001001100011011000100111001101100010011000110111001001110011011
	0010011000110110001001110011011000100110001101110010011100110110 001001100011011000100111001101110010011000110111001001110011011

	0010011000110110001001110011011000100110001101110010011100110110	0010011000110110001001110011011100100110001101110010011100110110
	0010011000110110001001110011011000100110001101110010011100110111	001001100011011000100111001101110010011000110111001001110011011

	0010011000110110001001110011011000100110001101110010011100110110
	001001100011011000100111001101110010011000110111001001110011011

	3 7 11 15

	6

	n % 8 == 4
		0101010101

	001001100011011000100111001101
	0010011000110110001001110011011
	*/

}
void abocadoTest::sw7733()
{
	//cheese theif
	int test_case, T;
	cin >> T;
	
	int dy[] = { 0,0,-1,1 };
	int dx[] = { -1,1,0,0 };

	for (test_case = 1; test_case <= T; ++test_case) {
		int n;
		cin >> n;

		int map[101][101], visited[101][101], partNum, result = 0;

		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++)
				cin >> map[y][x];	
		
		for (int time = 1; time <= 100; time++) {
			memset(visited, 0, sizeof(visited));
			partNum = 0;

			//count cheese parts
			for (int y = 0; y < n; y++) {
				for (int x = 0; x < n; x++) {
					if (map[y][x] == 0 || visited[y][x] == 1)	continue;
					partNum++;
					visited[y][x] = 1;

					queue<pair<int, int>> q;
					q.push(make_pair(y, x));

					while (!q.empty()) {
						int ty = q.front().first;
						int tx = q.front().second;
						q.pop();

						for (int a = 0; a < 4; a++) {
							int ny = dy[a] + ty;
							int nx = dx[a] + tx;

							if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] == 1 || map[ny][nx] == 0) continue;
							visited[ny][nx] = 1;
							q.push(make_pair(ny, nx));
						}
					}
				}
			}
			result = max(partNum, result);
			if (partNum == 0) break;

			//modify eaten cheeses
			for (int y = 0; y < n; y++) {
				for (int x = 0; x < n; x++) {
					if (map[y][x] == time) 
						map[y][x] = 0;
					//cout << map[y][x];
				}//cout << endl;
			}//cout << endl;
		}
		cout << "#" << test_case << " " << result << '\n';
	}
	/*
2
2
1 2
2 1
5
6 8 2 6 2
3 2 3 4 6
6 7 3 3 2
7 2 5 3 6
8 9 5 2 7
	*/
}

//
//void dfs7510(int ty, int tx, int tz, char map[][21]) {
//	for (int a = 0; a < 4; a++) {
//		int ny = dy[a] + ty;
//		int nx = dx[a] + tx;
//		int nz = tz;
//		if (ny < 0 || nx < 0 || ny >= r || nx >= c ) continue;
//
//		bool overlapChar = false;
//		for (int i = 0; i < v.size(); i++) {
//			if (v.at(i) == map[ny][nx])
//				overlapChar = true;
//			else overlapChar = false;
//		}
//
//		if (overlapChar) break;
//		else {
//			v.push_back(map[ny][nx]);
//			dfs7510(ny, nx, nz, map);
//			v.pop_back();
//			//tz++;
//		}
//	}
//}

void abocadoTest::sw7510()
{
	//	int dy[] = { -1,1,0,0 };
	//	int dx[] = { 0,0,-1,1 };
	//
	//	int test_case, T;
	//	cin >> T;
	//
	//	for (test_case = 1; test_case <= T; ++test_case) {
	//		int r, c, result = 0;
	//		cin >> r >> c;
	//		char map[21][21];
	//		for (int y = 0; y < r; y++)
	//			for (int x = 0; x < c; x++)
	//				cin >> map[y][x];
	//
	//		int visited[21][21][21] = { 0, };
	//		vector<char> v;
	//		v.push_back(map[0][0]);
	//		queue<tuple<int, int,int>> q;
	//		q.push(make_tuple(0, 0, 0));
	//		visited[0][0][0] = 1;
	//
	//		while (!q.empty()) {
	//			//int ty = q.front().first;
	//			//int tx = q.front().second;
	//			int ty, tx, tz;
	//			tie(ty, tx, tz) = q.front();
	//			q.pop();
	//			
	//			vector<char> checkTreasure;
	//			bool overlapChar = false;
	//
	//			for (int a = 0; a < 4; a++) {
	//				int ny = dy[a] + ty;
	//				int nx = dx[a] + tx;
	//				int nz = 1 + tz;
	//
	//				if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx][tz]) continue;
	//
	//				sort(v.begin(), v.end());
	//
	//				
	//				for (int i = 0; i < v.size(); i++) {
	//					//overlapped by previous round
	//					if (map[ny][nx] == v.at(i)) {
	//						overlapChar = true;
	//						break;
	//					}
	//					else if (map[ny][nx] != v.at(i)) {
	//						overlapChar = false;
	//					}
	//				}				
	//				
	//				if (overlapChar) {
	//					break;
	//				}
	//				else if(!overlapChar){
	//					for (int i = 0; i < checkTreasure.size(); i++) {
	//						//overlapped by present round
	//						if (map[ny][nx] == checkTreasure.at(i)) {
	//							overlapChar = true;
	//						}
	//						else if (map[ny][nx] != checkTreasure.at(i)) {
	//							overlapChar = false;
	//						}
	//					}
	//
	//					if (overlapChar) {
	//						visited[ny][nx][nz] = visited[ty][tx][tz] + 1;
	//						q.push(make_tuple(ny, nx, nz));
	//					}
	//					else if (!overlapChar) {
	//						visited[ny][nx][tz] = visited[ty][tx][tz] + 1;
	//						q.push(make_tuple(ny, nx, tz));
	//						checkTreasure.push_back(map[ny][nx]);
	//					}
	//				}				
	//			}
	//			int size = checkTreasure.size();
	//			//cout << "pushing : ";
	//			for (int i = 0; i < size; i++) {
	//				//cout << checkTreasure.at(checkTreasure.size() - 1) << '\t';
	//				v.push_back(checkTreasure.at(checkTreasure.size()- 1));
	//				checkTreasure.pop_back();
	//			}
	//	
	//		}
	//
	//		for (int y = 0; y < r; y++)
	//		{
	//			for (int x = 0; x < c; x++)
	//			{
	//				cout << visited[y][x][0];
	//			}cout << endl;
	//		}cout << endl;
	//
	//		cout << "#" << test_case << " " << v.size() << '\n';
	//	}
	ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	int r, c, result = 0;
	int dy[] = { -1,1,0,0 };
	int dx[] = { 0,0,-1,1 };
	int visited[21][21] = { 0, };
	vector<char> v;
	char map[21][21] = { 0, };
	int test_case, T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {

		cin >> r >> c;
		for (int y = 0; y < r; y++)
			for (int x = 0; x < c; x++)
				cin >> map[y][x];

		int y = 0, x = 0, z = 1;
		//dfs7510(y, x, z, map);

		cout << "#" << test_case << " " << z << '\n';
	}



	/*
	
3
2 4
CAAB
ADCB
3 6
HFDFFB
AJHGDH
DGAGEH
5 5
IEFCJ
FHFKC
FFALF
HFGCF
HMCHH	
	*/


	//21ms 모범답안
	/*
	
	#include <iostream>
#include <cstring>
#include <numeric>
 
char cells[20][20];
bool alphabatChecker[26], find;
int answer;
int r, c;
int maxCount;
 
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
 
void dfs(int x, int y, int count)
{
    if (find)
        return;
 
    for (register int i = 0; i < 4; ++i)
        if (0 <= x + dx[i] && x + dx[i] < c && 0 <= y + dy[i] && y + dy[i] < r) //범위내인가?
        {
            if (!alphabatChecker[cells[x + dx[i]][y + dy[i]] - 'A'])    //알파벳 방문했는데인가?
            {
                alphabatChecker[cells[x + dx[i]][y + dy[i]] - 'A'] = true;
                dfs(x + dx[i], y + dy[i], count + 1);
                alphabatChecker[cells[x + dx[i]][y + dy[i]] - 'A'] = false;
            }
        }
 
    answer = answer < count ? count : answer;
    if (maxCount == count)
        find = true;
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();
 
    int T;
    std::cin >> T;
 
    for (register int test_case = 1; test_case <= T; ++test_case)
    {
 
        std::cin >> r >> c;     //r 행 c 열 : y , x
        memset(cells, 0, sizeof(cells));
        memset(alphabatChecker, 0, sizeof(alphabatChecker));
        answer = 0;
        find = false;
 
        bool checker[26];
        memset(checker, 0, sizeof(checker));
 
        for (register int i = 0; i < r; ++i)
        {
            char input[20];
            std::cin >> input;
            for (register int j = 0; j < c; ++j)
            {
                cells[j][i] = input[j];
                checker[cells[j][i] - 'A'] = true;
            }
        }
 
        maxCount = std::accumulate(checker, checker + 26, 0);
 
        alphabatChecker[cells[0][0] - 'A'] = true;
        dfs(0, 0, 1);
 
        std::cout << "#" << test_case << " " << answer << "\n";
    }
 
    return 0;
}

	*/
}

void abocadoTest::sw7699()
{
	int test_case, T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int result = 0;
		int n;
		cin >> n;

		vector<int> v;

		for (int i = 1 ; i < n; i++)
		{
			
			if (n%i == 0) {
				n /= i;
				v.push_back(i);
			}
			if (n == 1) break;
		}

		for (int i = 0; i < v.size(); i++)
		{
			cout << v.at(i) << '\t';
		}
		cout << "#" << test_case << " " << result << '\n';
	}
	/*
	15 1 3 5 . 2			15= 7 8 = 4 5 6 = 1 2 3 4 5
	42	1 3 6 7 14 21 		42= 13 14 15 = 4 5 6 7 8 9 10
	54321 1 3 . 2			54321 = 27160 27611 = 18106 18107 18108 = 
	*/
}






void abocadoTest::sw1953()
{
	int test_case, T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n, m, r, c, l;
		cin >> n >> m >> r >> c >> l;

		int map[52][52], visited[52][52], result = 0;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				cin >> map[y][x];
				visited[y][x] = 0;
			}
		}

		int dy[] = { -1,0,1,0 };
		int dx[] = { 0,1,0,-1 };
		queue<pair<int, int>> q;
		q.push(make_pair(r, c));
		visited[r][c] = 1;

		while (!q.empty()) {
			bool NESW[4][2] = { false, false, false, false, false, false, false, false};
			int ty = q.front().first;
			int tx = q.front().second;
			q.pop();

			//check the type of tunnel
			checkTunnelType(map, ty, tx, NESW, 0);
			
			for (int a = 0; a < 4; a++) {
				if (!NESW[a][0]) continue;
				int ny = dy[a] + ty;
				int nx = dx[a] + tx;


				if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] != 0 || map[ny][nx] == 0) continue;
				//cout << "checking : " << ny << ", " << nx << ", " << a << '\n';
				//if (ny >= 0 && nx >= 0 && ny < n && nx < m && visited[ny][nx] == 0 && map[ny][nx] != 0) {

					//0 2 // 1 3 // 2 0 // 3 1
					checkTunnelType(map, ny, nx, NESW, 1);
					if (!NESW[(a + 2) % 4][1]) continue;

					visited[ny][nx] = visited[ty][tx] + 1;
					//cout << "marked" << '\n';
					if (visited[ny][nx] == l) continue;
					q.push(make_pair(ny, nx));
				//}
			}
		}

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				cout << visited[y][x] << " ";
				if (visited[y][x] != 0)
					result++;
			}cout << '\n';
		}

		cout << "#" << test_case << " " << result << '\n';
	}
	
	/*
	

2
5 6 2 1 3
0 0 5 3 6 0
0 0 2 0 2 0
3 3 1 3 7 0
0 0 0 0 0 0
0 0 0 0 0 0
5 6 2 2 6
3 0 0 0 0 3
2 0 0 0 0 6
1 3 1 1 3 1
2 0 2 0 0 2
0 0 4 3 1 1
	
	*/





	/*
1ms, 316kb 답안
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int T;      // testcase
int N, M;   // N : 세로 , M : 가로
int R, C, L;    // 맨홀 뚜껑위치 R : 세로 , C : 가로 , L : 소요 시간
int ans;
int map[51][51];
int check[51][51];
int dir_x[4] = {0,1,0,-1};  // 12시부터 시계방향
int dir_y[4] = {-1,0,1,0};
int result;
int use_to[8][4] = {
    {},
    {1,1,1,1},
    {1,0,1,0},
    {0,1,0,1},
    {1,1,0,0},
    {0,1,1,0},
    {0,0,1,1},
    {1,0,0,1}
};
 
int use_from[8][4] = {
    {},
    {1,1,1,1},
    {1,0,1,0},
    {0,1,0,1},
    {0,0,1,1},
    {1,0,0,1},
    {1,1,0,0},
    {0,1,1,0}
};
void BFS()
{
    check[R][C] = 1;
    queue<pair<int,int>> q;
    q.push({R,C});
    while (1)
    {
        if (q.empty()) break;
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)      // 4방향 검사
        {
            int temp_y = y + dir_y[i];
            int temp_x = x + dir_x[i];
            if (temp_x < 0 || temp_y < 0 || temp_y > N || temp_x > M) continue;
 
            if (use_to[map[y][x]][i] && use_from[map[temp_y][temp_x]][i] && !check[temp_y][temp_x] && check[y][x] < L)
            {
                check[temp_y][temp_x] = check[y][x] + 1;
                q.push({ temp_y, temp_x});
                result++;
            }
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
     
    cin >> T;
     
    for(int i=1;i<=T;i++)
    {
        cin >> N >> M >> R >> C >> L;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> map[i][j];
                check[i][j] = 0;
            }
        }
        result = 1;
        BFS();
        cout << "#" << i << " " << result << '\n';
    }
    return 0;
}
	*/
}

void abocadoTest::checkTunnelType(int map[52][52], int y, int x, bool NESW[4][2], int arrNum)
{
	if (arrNum){
		for (int a = 0; a < 4; a++)
			NESW[a][arrNum] = false;
	}
	switch (map[y][x]) {
	case 1:
		NESW[0][arrNum] = true;	NESW[1][arrNum] = true;	NESW[2][arrNum] = true;	NESW[3][arrNum] = true;
		break;
	case 2:
		NESW[0][arrNum] = true;							NESW[2][arrNum] = true;
		break;
	case 3:
		NESW[1][arrNum] = true;													NESW[3][arrNum] = true;
		break;
	case 4:
		NESW[0][arrNum] = true;	NESW[1][arrNum] = true;
		break;
	case 5:
								NESW[1][arrNum] = true;	NESW[2][arrNum] = true;
		break;
	case 6:
														NESW[2][arrNum] = true;	NESW[3][arrNum] = true;
		break;
	case 7:
		NESW[0][arrNum] = true;													NESW[3][arrNum] = true;
		break;
	default:
		break;
	}
}

void abocadoTest::sw2104()
{

	int test_case, T;
	cin >> T;
	int dx[] = { 1, 1, -1, -1 };
	int dy[] = { 1,-1,-1,1 };
	for (test_case = 1; test_case <= T; ++test_case) {

		int n, result = 0 ;
		cin >> n;

		int map[21][21] = { 0, }, visited[21][21] = { 0, }, num[101] = { 0, };
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if ((y == 0 && x == 0) || (y == n - 1 && x == n - 1) || (y == n - 1 && x == 0) || (y == 0 && x == n - 1))continue;

				if (!visited[y][x]) {
					visited[y][x] = 1;
					int tempVisited[21][21];
					queue<pair<int, int>> q;
					q.push(make_pair(y, x));
					priority_queue<int> pq;
					vector<int> v;
					pq.push(map[y][x]);
					v.push_back(map[y][x]);

					while (!q.empty()) {
						int ty = q.front().first;
						int tx = q.front().second;
						q.pop();

						bool invalidType = false;

						for (int a = 0; a < 4; a++) {
							int ny = dy[a] + ty;
							int nx = dx[a] + tx;

							if (ny < 0 || ny >= n || nx < 0 || ny >= n || visited[ny][nx]) continue;
							
							v.push_back(map[ny][nx]);	pq.push(map[ny][nx]);
							if (v.size() != pq.size()) {
								invalidType = true;
								break;
							}

							visited[ny][nx] = 1;
							q.push(make_pair(ny, nx));
						}
						if (invalidType) break;
					}
				}
			}
		}

		cout << "#" << test_case << " " << result << '\n';
	}

}


/*


	int test_case, T;
	std::cin>>T;

	for(test_case = 1; test_case <= T; ++test_case) {
		int result = 0;


		std::cout << "#" << test_case << " " << result << '\n';
	}


*/