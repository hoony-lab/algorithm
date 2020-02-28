#include <iostream>
#include <Windows.h>
#include <string>
#include "q.h"
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <deque>
using namespace std;


void q::q1000() {
	int A, B;
	std::cin >> A;
	std::cin >> B;
	std::cout << A + B;
}

void q::q1008()
{
	double A, B;
	cin >> A;
	cin >> B;
	if (B != 0)
		cout << setprecision(10) << A / B;
	else
		cout << stderr;
}

void q::q10430()
{
	int A, B, C;
	cin >> A >> B >> C;
	system("cls");
	cout << (A + B) % C << '\n';
	cout << (A%C + B % C) % C << '\n';
	cout << (A*B) % C << '\n';
	cout << (A%C * B%C) % C << '\n';
}

void q::q2839()
{
	/*
	N % 5 == 0

		16 >> 10 6
		17 >> 5 12
		18 >> 15 3
		19 >> 10 9

		21 >> 15 6
		22 >> 10 12
		23 >> 20 3
		24 >> 15 9

		5 patterns
		*/
	int N, cnt5, cnt3;
	cin >> N;

	if (N == 4 || N == 7) {
		cnt5 = 0;
		cnt3 = -1;
	}
	else if (N % 5 == 0) {
		cnt5 = N / 5;
		cnt3 = 0;
	}
	else if (N % 5 == 2) {
		cnt5 = N / 5 - 2;
		cnt3 = (N - cnt5 * 5) / 3;
	}
	else if (N % 5 == 3) {
		cnt5 = N / 5;
		cnt3 = (N - cnt5 * 5) / 3;
	}
	else {
		cnt5 = N / 5 - 1;
		cnt3 = (N - cnt5 * 5) / 3;
	}
	cout << cnt5 + cnt3;
}

void q::q1152()
{
	int cnt = 0, flag = 1;
	string str;
	char c;

	getline(cin, str);
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
			flag = 1;
		else if (flag == 1) {
			cnt++;
			flag = 0;
		}
	}
	cout << cnt;
	//while(c = getchar()){
	//	if (c == ' ' || c == '\n')
	//		cnt++;
	//	cout << c << '\t' << cnt << endl;
	//}

}

void q::q2577()
{
	int A, B, C, result, num[10] = {};
	cin >> A >> B >> C;
	result = A * B * C;
	string str = to_string(result);

	for (int i = 0; i < str.length(); i++)
	{
		switch (str.at(i))
		{
		case '0':
			num[0] += 1;
			break;
		case '1':
			num[1] += 1;
			break;
		case '2':
			num[2] += 1;
			break;
		case '3':
			num[3] += 1;
			break;
		case '4':
			num[4] += 1;
			break;
		case '5':
			num[5] += 1;
			break;
		case '6':
			num[6] += 1;
			break;
		case '7':
			num[7] += 1;
			break;
		case '8':
			num[8] += 1;
			break;
		case '9':
			num[9] += 1;
			break;
		}
		//cout << str.at(i);
	}
	for (int j = 0; j < 10; j++)
	{
		cout << num[j] << endl;
	}
}

void q::q8958()
{
	int num;
	string quiz;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		int score = 0, total = 0;
		cin >> quiz;
		for (int j = 0; j < quiz.length(); j++)
		{
			if (quiz.at(j) == 'O')
				total += ++score;
			else score = 0;
		}
		cout << total << endl;
	}
}

void q::q2920()
{
	int flag = 0, melodys[8];

	for (int i = 0; i < 8; i++)
	{
		cin >> melodys[i];
	}

	//for (int j = 0; j < 8 - 1; j++)
	//{
	//	if ((melodys[j] + 1) == melodys[j+1] ) {
	//		if (flag == 1) {
	//			flag = 2;
	//			cout << result[flag];
	//			return;
	//		}
	//		flag = 0;
	//	}
	//	else if ((melodys[j] - 1) == melodys[j+1] ) {
	//		if (flag == 0) {
	//			flag = 2;
	//			cout << result[flag];
	//			return;
	//		}
	//		flag = 1;
	//	}
	//	
	//}
	//cout << result[flag] << endl;

	//8 1 7 2 6 3 5 4
	for (int i = 0; i < 7; i++)
	{
		if (melodys[i] - melodys[i + 1] == -1) {
			flag++;
		}
		else if (melodys[i] - melodys[i + 1] == 1) {
			flag--;
		}
	}

	if (flag == 7)
		cout << "ascending";
	else if (flag == -7)
		cout << "descending";
	else
		cout << "mixed";

}

void q::q10039()
{
	int score[5], total = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> score[i];
		if (score[i] < 40)
			score[i] = 40;
		total += score[i];
	}
	cout << total / 5;


}

void q::q2292()
{
	//1	2-7(6)	8-19(12)	20-37(18)	38-51(24)

	int n, ans = 1, range = 0;
	cin >> n;

	if (n == 1) cout << ans;
	else {
		while (n > 1)
		{
			ans++;
			range += 6;
			n -= range;
		}
		cout << ans;
	}
}

void q::q1193()
{
	//1	2-3	4-6	7-10		1 1 2 3
	int n, range = 1;
	cin >> n;
	if (n == 1) cout << n << "/" << n;
	else {
		while (n > range)
		{
			n -= range++;
		}
		if (range % 2 == 1) cout << range + 1 - n << "/" << n;
		else cout << n << "/" << range + 1 - n;
	}
}

void q::q1011()
{
	/*
	1	1		1
	2	11		2
	3	111		3	2
	4	121		3
	5	1211	4	2
	6	1221	4
	7	12211	5	3
	8	12221	5
	9	12321	5
	10	123211	6	3
	11	123221	6
	12	123321	6
	13	1233211	7	4
	14	1233221
	15	1233321
	16	1234321
	17	12343211	8	4
	18	12343221
	*/
	int n;
	long turns[100000];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		long long x, y, length, total = 1, range = 0, turn = 1;
		cin >> x >> y;
		length = y - x;

		while (length > total) {
			range++;

			turn++;
			total += range;
			if (length <= total) break;

			turn++;
			total += range;
			if (length <= total) break;
		}
		if (length < total) turn--;
		turns[i] = turn;
	}
	for (int j = 0; j < n; j++)
	{
		cout << turns[j] << '\n';
	}
}

/*
3분 그래프
*/

void q::q17113()
{
	/*타이머가 망가져서 직접 시간을 재야함
	컴파일이 안되는거면 전자레인지를 비우고, 새 그래프를 넣고 조리
	컴파일이되는걸, 그래프를 꺼내먹는당
	*/

	int time;
	cin >> time;

	if (time > 170 && time < 190) {
		for (int i = 1; i <= time; i++)
		{
			Sleep(1000);
			cout << i << ' ';
		}
		cout << "\n맞았습니다!!\n";
	}
	else cout << "\n틀렸습니다\n";




}

void q::q17180()
{
	/*
5 4
apple
apla
apple
*/
	int n, m, diff[400], total = 0;
	char a[400], b[400];
	cin >> n >> m;
	if (n >= m) {
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int j = 0; j < m; j++)
		{
			cin >> b[j];
		}
	}
	else {
		for (int i = 0; i < m; i++)
		{
			cin >> a[i];
		}
		for (int j = 0; j < n; j++)
		{
			cin >> b[j];
		}
	}



	for (int i = 0; i < n; i++)
	{
		int min = 26;
		for (int j = 0; j < m; j++)
		{
			if (a[i] == b[j]) {
				min = 0;
				break;
			}
			else {
				diff[i] = abs(a[i] - b[j]);
				diff[i] < min ? (min = diff[i]) : min;
			}
		}
		total += min;
	}
	cout << total;
}

bool q10814_compare(pair<int, pair<string, int >> a, pair<int, pair<string, int >> b) {
	if (a.first == b.first) {
		return a.second.second < b.second.second;
	}
	else return a.first < b.first;
}
void q::q10814()
{
	//int num, age, cnt = 0;
	//string name;
	//vector<pair<int, pair<string, int>>> info;
	//cin >> num;
	//for (int i = 0; i < num; i++)
	//{
	//	cin >> age >> name;
	//	info.push_back(pair<int, pair<string, int>>(age, make_pair(name, num)));
	//	//auto temp = make_pair(age, name);
	//	//info.push_back(temp);

	//}
	//
	//sort(info.begin(), info.end(), q10814_compare);

	//sort(info.begin(), info.end(), [](auto &left, auto &right) {
	//	return left.first < right.first;
	//});
	//for (int i = 0; i < info.size(); i++)
	//{
	//	cout << info.at(i).first << " " << info.at(i).second.first << endl;
	//}


	int num;
	cin >> num;
	vector<pair<pair<int, int>, string>> info;
	for (int i = 0; i < num; i++) {
		int age;
		string name;

		cin >> age >> name;
		info.push_back(pair<pair<int, int>, string>(make_pair(age, i), name));
	}
	sort(info.begin(), info.end());

	for (int i = 0; i < num; i++)
	{
		cout << info.at(i).first.first << " " << info.at(i).second << '\n';
	}


}

void q::q11652()
{
	/*
5
1
2
1
2
1
*/

//long long a = -1000000003000000L;
//int b;
////a = 9223372036854775803L;
//
//b = 1024*1024 -1;
//cout << a << '\n' << b;

	int n, cnt = 0, maxcnt = 0;
	long long card[100000];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> card[i];
	}

	sort(card, card + n, greater<long long>());
	long long many = card[0];

	for (int i = 0; i < n; i++)
	{
		if (card[i] == card[i + 1])
			cnt++;
		else cnt = 1;
		if (maxcnt < cnt) {
			maxcnt = cnt;
			many = card[i];
		}
	}
	cout << many << endl;
}

void q::q14501()
{
	int n, time[20], profit[20], dp[20], ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> time[i] >> profit[i];
		dp[i] = profit[i];
	}


	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (time[j] + j <= i)
				dp[i] = max(dp[j] + profit[i], dp[i]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (i + time[i] <= n + 1)
			ans = max(ans, dp[i]);
	}
	cout << ans;
}

void q::q1654()
{

	int k;
	long long line_need, line[10000], max = 0, min = 1, ans = 0, mid;
	cin >> k >> line_need;
	for (int i = 0; i < k; i++)
	{
		cin >> line[i];
		if (max < line[i])
			max = line[i];
	}

	//sort(line, line + k);
	//long long max = line[k - 1], min = line[0], avg;
	//cout << min << '\n' << max;

	while (min <= max) {

		mid = (max + min) / 2;

		int cnt = 0;
		for (int i = 0; i < k; i++)
		{
			cnt += (line[i] / mid);
		}

		if (cnt >= line_need) {

			if (ans < mid)
				ans = mid;
			min = ++mid;
		}
		else {
			max = --mid;
		}
	}
	cout << ans;

}
//이분탐색 + 그래프
void q::q1939()
{
	vector<pair<long long, pair<long long, long long>>> bridge;
	long long island_total_num, bridge_total_num, x, y, max1 = 1, max2 = 1;
	cin >> island_total_num >> bridge_total_num;

	for (long long i = 0; i < bridge_total_num; i++)
	{
		long long island_num1, island_num2, weight;
		cin >> island_num1 >> island_num2 >> weight;
		bridge.push_back(pair<long long, pair<long long, long long>>
			(weight, make_pair(island_num1, island_num2)));
		//if (max < weight)
		//	max = weight;
	}

	//a	sort(bridge.begin(), bridge.end());

	cin >> x >> y;

	for (auto brid : bridge)
	{
		if ((brid.second.first == x && brid.second.second == y) ||
			(brid.second.first == y && brid.second.second == x))
		{
			if (max1 <= brid.first)
				max1 = brid.first;

		}
		else {
			if (max2 <= brid.first)
				max2 = brid.first;
		}

	}

	max1 > max2 ? cout << max1 : cout << max2;
	/*
3 4
1 2 4
3 1 3
2 3 6
1 3 2
1 3
	*/

	//info.push_back(pair<pair<int, int>, string>(make_pair(age, i), name));
	//sort(bridge, bridge + bridge_num);
	//long long max = bridge[bridge_num - 1], min = bridge[0];
	//cout << min << '\n' << max;


}
/*
입력
첫째 줄에 나무의 수 N과 상근이가 집으로 가져가려고 하는 나무의 길이 M이 주어진다. (1 ≤ N ≤ 1,000,000, 1 ≤ M ≤ 2,000,000,000)

둘째 줄에는 나무의 높이가 주어진다. 나무의 높이의 합은 항상 M을 넘기 때문에, 상근이는 집에 필요한 나무를 항상 가져갈 수 있다. 높이는 1,000,000,000보다 작거나 같은 양의 정수 또는 0이다.

출력
적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 출력한다.
*/
void q::q2805()
{
	long long tree_num, target, tree_length[100001], max_length = 0, height = 0, total = 0;
	cin >> tree_num >> target;
	for (long long i = 0; i < tree_num; i++)
	{
		cin >> tree_length[i];
		max_length > tree_length[i] ?
			max_length = max_length : max_length = tree_length[i];
	}

	long long start = 1, end = max_length, mid;
	while (start <= end) {
		total = 0;
		mid = (start + end) / 2;
		for (long long i = 0; i < tree_num; i++)
		{
			if (mid < tree_length[i])
				total += tree_length[i] - mid;
		}

		if (total < target) {
			end = mid - 1;
		}
		else if (total >= target) {
			start = mid + 1;

			if (height < mid)
				height = mid;
		}

	}

	cout << height;
}

void q::q3115()
{
	vector<pair<long long, long long>> garden;
	long long size, flower_num;
	cin >> size >> flower_num;
	for (long long i = 0; i < flower_num; i++)
	{
		//garden.push_back(30, 40);
	}
}

void q::q10815()
{
	long long mycard_num;
	vector<long long> mycards;
	cin >> mycard_num;
	for (long i = 0; i < mycard_num; i++)
	{
		long temp;
		cin >> temp;
		mycards.push_back(temp);
	}
	sort(mycards.begin(), mycards.end());

	long long card_num;
	vector<long long> cards;
	cin >> card_num;
	for (long long i = 0; i < card_num; i++)
	{
		long temp;
		cin >> temp;
		cards.push_back(temp);
	}

	//for (vector<long long>::iterator iter = mycards.begin(); iter != mycards.end() ; iter++)
	//{
	//	cout << &iter << '\t' << *iter << endl;
	//}

	for (long long i = 0; i < card_num; i++)
	{
		long long start = 0, end = mycard_num - 1, mid, find = 0;
		while (start <= end) {
			mid = (start + end) / 2;
			if (mycards.at(mid) == cards.at(i)) {
				cout << '1';
				find = 1;
				break;
			}
			else if (mycards.at(mid) < cards.at(i))
				start = 1 + mid;
			else
				end = mid - 1;

		}
		if (find == 0)
			cout << '0';
		cout << ' ';
	}

	//vector<int> yesoryes;
	//for (long long i = 0; i < card_num; i++)
	//{
	//	int yesorno;
	//	for (long long j = 0; j < mycard_num; j++)
	//	{
	//		if (mycards.at(j) == cards.at(i)) {
	//			yesorno = 1;
	//			break;
	//		}
	//		else yesorno = 0;
	//	}
	//	yesoryes.push_back(yesorno);
	//}

	//for (long long i = 0; i < yesoryes.size(); i++)
	//{
	//	cout << yesoryes.at(i) << ' ';
	//}
}

void q::q1300()
{

	long long n, k, i, j;
	vector<long long> arr;
	cin >> n >> k;
	//for (i = 1; i <= n; i++)
	//{
	//	for ( j= 1; j <= n; j++)
	//	{
	//		arr.push_back(i*j);
	//	}
	//}
	sort(arr.begin(), arr.end());

	1000000000 > n*n ?
		cout << arr.at(k - 1) : cout << 1000000000;



	long long start = 0, end = n * n, mid, count = 0, ans;
	while (start <= end)
	{
		mid = (start + end) / 2;

		if (arr.at(mid) == arr.at(k)) {
			ans = arr.at(mid);
			break;
		}

		else if (arr.at(mid) < arr.at(k))
			start = mid + 1;
		else
			end = mid - 1;

	}

	/*

	1
	1 2 2 4
	1 2 2 3 3 4 _6 6 9
	1 2 2 3 3 4 4 4 6 6 8 8 9 12 12 16
	1 2 2 3 3 4 4 4 6 6 8 8 9 12 12 16 20 20 25

	1 2 1
	1 2 3 2 1
	1 2 3 4 3 2 1
	*/

	/*
	long long index = 0, cnt = 0, layers = 0;
	while (index < k) {
		if (k == 1) { cout << '1'; break; }
		layers++;
		if (k == n * n) { cout << n * n; break; }

		if (index < (n*n) / 2) cnt++;
		else cnt--;
		index += cnt;

		cout << cnt << '\t' << layers << '\t' << index << endl;


		if (index > k) {
			cout << (layers - (index - k)) * ((index - k));
		}
		else if (index == k) {
			cout << (layers + 1)* cnt;
		}

	}*/
}

void q::q1920()
{
	/*
5
4 1 5 2 3
5
1 3 7 9 5
*/
	int n, m, temp;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		a.push_back(temp);
	}

	cin >> m;
	vector<int> b;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		b.push_back(temp);
	}
	sort(a.begin(), a.end());
	//sort(b.begin(), b.end());

	//int bigger;
	//n > m ? bigger = n : bigger = m;



	for (int i = 0; i < m; i++)
	{
		int start = 0, end = n - 1, mid, cnt, find = 0;

		while (start <= end)
		{
			mid = (start + end) / 2;

			if (b.at(i) == a.at(mid)) {

				cout << "1\n";
				find = 1;
				break;
			}
			else if (a.at(mid) < b.at(i))
				start = ++mid;
			else
				end = --mid;
		}
		if (find == 0)
			cout << "0\n";
	}



}

class Node {
public:
	int key;
	Node *left, *right;
};

class Tree {
public:
	Node *root;
};

//preorder	전위
//postorder	중위
//inorder	후위
void preorder(Node* root) {
	if (root != NULL) {
		cout << root->key;
		preorder(root->left);
		preorder(root->right);
	}
}
void search(int n) {

}
void insert(int key) {

}
void remove(int n) {

}
void q::q3038()
{



	int n;
	cin >> n;
	Tree binaryTree;
	//insert(binaryTree, 1);
}

void q::q2455()
{
	int in, out, total[4] = {}, maxi = 0;
	int train[2] = { 0,0 };
	for (int i = 0; i < 4; i++)
	{
		cin >> out >> in;
		train[0] += out;
		train[1] += in;
		total[i] = train[1] - train[0];
		maxi = max(total[i], maxi);
	}

	cout << maxi;
}

void q::q1094()
{
	int x, cnt = 1;

	cin >> x;

	while (x > 1)
	{
		if (x % 2 == 1)
			cnt++;
		x /= 2;
	}
	cout << cnt;
}

int upper_n_divide(int n) {
	return n = ((n * 10) / 2 + 5) / 10;
}
int upper(int n) {
	return n = ((n * 10) + 5) / 10;
}
void q::q1057()
{

	//16 8 9
	//4
	/*

	12 34 56 78 9
	12    34    5
	12          3
	12

	12 34 56 78 910 1112 1314 1516
	12    34    56       7(8)
	12          3(4)
	12

	*/
	//부전승 생각하기
	/*
	int n, n1, n2, cnt = 0;
	cin >> n >> n1 >> n2;
	while (n1 != n2) {
		cnt++;
		n1 /= 2;
		n2 /= 2;
		if (n1 == n2)
			n2++;
		else if (n2 - n1 == 1) {
			cout << cnt;
			break;
		}
	}
	*/


	//int n, n1, n2, cnt = 0, flag=0, n1_, n2_, ans=1;
	//cin >> n >> n1 >> n2;
	//while (ans) {
	//	cnt++;
	//	n = upper_n_divide(n);
	//	n1_ = upper_n_divide(n1);
	//	n2_ = upper_n_divide(n2);
	//	
	//	if(n1 > 1)
	//	n1 /= 2;
	//	n2 /= 2;
	//	cout << n << '\t' << n1 << '\t' << n2 << '\t' << cnt << '\n';
	//	//end condition
	//	if (n2 - n1 == 1) {
	//		if (n2_ - n1_ == 1)
	//			cnt++;
	//		ans = 0;
	//		break;
	//	}

	//	n1 = n1_;
	//	n2 = n2_;

	//	cout << n << '\t' << n1 << '\t' << n2 << '\t' << cnt << '\n';


	//}
	//cout << cnt;

	int N, kim, lim, count = 0;
	cin >> N >> kim >> lim;
	while (kim != lim) {
		kim -= kim / 2;
		lim -= lim / 2;
		count++;
	}
	cout << count;



}

void q::q1021()
{
	// linkedlist or vector erase, remove or deque
	vector<int> num;
	vector<int> train;
	vector<int>::iterator iter = train.begin();

	int n, index, temp, total = 0;
	cin >> n >> index;
	for (int i = 1; i <= n; i++)
	{
		train.push_back(i);
	}
	for (int i = 0; i < index; i++)
	{
		cin >> temp;
		num.push_back(temp);
	}

	int ptr = 0, rev_ptr = 0;



	for (int i = 0; i < index; i++)
	{

		cout << "start looping..." << endl;
		int uppercnt = 0, lowercnt = 0;



		//int cnt = 0;

		//auto erase_index = find(train.begin(), train.end(), num.at(i));
		//auto temp = find(train.begin(), train.end(), erase_index + 1);

		//while (true) {
		//	if (iter == erase_index)
		//		break;
		//	if (iter == train.end()) iter = train.begin();
		//	iter++;
		//	cnt++;
		//}
		//total += min(cnt, train.size() - cnt);
		//train.erase(erase_index);

		//iter = temp;



		//cout << *iter << " " << num.at(i);
		//while (*iter != num.at(i));
		//{
		//	cout << *iter << " " << num.at(i);
		//	if (iter == train.end()) iter = train.begin();
		//	iter++;
		//	uppercnt++;
		//	cout << uppercnt << "kh ";
		//}
		//ptr = ptr + uppercnt % train.size();

		//auto a = train.begin() - iter;
		//
		//total += min(uppercnt, train.size() - uppercnt);

		//auto erase_index = find(train.begin(), train.end(), num.at(i));
		//train.erase(erase_index);

		//cout << "FIRST : " << train.at(0) << endl << endl;

		//iter = train.begin() + ptr;
		//if (iter == train.end()) iter = train.begin();




		//for (auto it = train.begin()+ptr; *it != num.at(i) ; it++, ptr++, uppercnt++)
		//{
		//	if (it == train.end())
		//		it = train.begin();
		//	//cout << *it << " " << ptr << endl;
		//}

		//cout << endl << endl;
		//for (auto rev_it = train.begin() + rev_ptr; *rev_it != num.at(i); rev_it--, rev_ptr--, lowercnt++) {
		//	if (rev_it == train.begin())
		//		rev_it = train.end();
		//	//cout << *rev_it << " ";
		//}
		//cout << num.at(i) << " " << ptr << " " << rev_ptr << endl;




		//for (iter = train.begin()+ptr; num.at(i) == *iter ;ptr= uppercnt++) {
		////	ptr = uppercnt++;
		//	cout << "iter" << " ";
		//	if (iter == train.end())
		//		iter == train.begin();
		//	else iter++;

		//}
		//for (rev_iter = train.begin() + rev_ptr; num.at(i) == *rev_iter ; rev_ptr = n - lowercnt++ ) {
		////	rev_ptr = n - lowercnt++;
		//	cout << "rev_iter" << " ";
		//	if (rev_iter == train.begin())
		//		rev_iter = train.end()-1;
		//	else rev_iter--;

		//}




		/*
		while (num.at(i) != *(iter)) {
			if (iter == train.end())
				iter == train.begin();
			else iter++;
			uppercnt++;
			cout << "iter" << " ";

			//for (iter; *iter == num.at(i); iter++)
			//{
			//	cout << *iter << '\t' << uppercnt << endl;
			//	uppercnt++;
			//}
			//for (rev_iter; *rev_iter == num.at(i); rev_iter--) {
			//	cout << *rev_iter << '\t' << lowercnt << endl;
			//	lowercnt++;
			//}

		}
		while (num.at(i) != *(rev_iter)) {
			if (rev_iter == train.begin())
				rev_iter = train.end() - 1;
			else rev_iter--;
			lowercnt++;
			cout << "rev_iter" << " ";
		}
		*/

		//cout << "calculating complete..." << endl;
		//if (uppercnt < lowercnt) {
		//	total += uppercnt;
		//	train.erase(train.begin()+ptr);

		//	cout << "choose upper" << endl;
		//}
		//else {
		//	total += lowercnt;
		//	train.erase(train.begin() + rev_ptr);

		//	cout << "choose lower" << endl;
		//}






		for (auto its : train)
		{
			cout << its << " ";
		}
		cout << endl << endl << "total : " << total << endl;


	}

	for (auto it : train)
	{
		cout << it;
	}

}

void q::q1547()
{
	//컵 3개
	int m, a, b, cup[4] = { 0,1,0,0 };
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		if (cup[a] || cup[b] == 1)
			swap(cup[a], cup[b]);
	}
	if (cup[1] == 1)
		cout << '1';
	else if (cup[2] == 1)
		cout << '2';
	else if (cup[3] == 1)
		cout << '3';
	else
		cout << '-1';

}

void q::q10219()
{
	//int T, H, W;	//H줄, W개문자
	//char ch, meat[1000][12][12];
	//cin >> T;
	//for (int a = 0; a < T; a++)
	//{
	//	cin >> H >> W;

	//	for (int i = 0; i < H; i++)
	//	{
	//		for (int j = 0; j < W; j++)
	//		{
	//			ch = getchar();
	//			if (ch == '\n')
	//				ch = getchar();
	//			meat[a][i][j] = ch;
	//		}
	//	}
	//}
	//for (int a = 0; a < T; a++)
	//{
	//	for (int q = H - 1; q >= 0; q--)
	//	{
	//		for (int w = W - 1; w >= 0; w--)
	//		{
	//			cout << meat[a][q][w];
	//		}
	//		cout << endl;
	//	}
	//}


	const int MAX = 12;
	char map[MAX][MAX];
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		int h, w;
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = w - 1; j >= 0; j--) {
				cout << map[i][j];
			}
			cout << "\n";
		}
	}

}

void q::q1024()
{
	vector<long long> num;
	bool finish = true;
	long long N, L, temp;
	cin >> N >> L;


	//for	total+= b

	//N-total/L
	//

	//while (finish) {
	//	long long total = 0;
	//	num.clear();
	//	if (L > 100 || N == L) {
	//		num.push_back(-1);
	//		finish = false;
	//	}
	//	else if (L == 2 && N % 2 == 1) {
	//		temp = N / L;
	//		for (long long i = 0; i < L; i++)
	//			num.push_back(temp + i);
	//		finish = false;
	//	}
	//	else if (N % 2 == 1) {
	//		temp = N / L;
	//		if (temp > 2) {
	//			for (long long i = -L / 2; i <= L / 2; i++) {
	//				num.push_back(temp + i);
	//				total += (temp + i);
	//			}
	//			if(N==total)
	//				finish = false;
	//		}
	//		
	//	}
	//	else if (N%2 == 0) {
	//		temp = N / L + 1;
	//		if (temp > 2) {
	//			for (long long i = -L / 2; i <= L / 2; i++) {
	//				num.push_back(temp + i);
	//				total += (temp + i);
	//			}
	//			if(N == total)
	//				finish = false;
	//		}
	//		
	//	}
	//	else cout << "HELOO";

	//	if (temp < L / 2)
	//		finish = true;
	//	L++;
	//}

	for (long long a = 0; a < num.size(); a++)
	{
		cout << num.at(a) << " ";
	}
}

void q::q1107()
{
	vector<int> num = { 0, 1, 2, 3, 4,5,6,7,8,9 };
	int n, m, temp, smallnum = 10, channel[6], o = 0;

	cin >> n;

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		num.erase(find(num.begin(), num.end(), temp));
	}

	//	for (int i = 0; i < length; i++)
	//	{
	//		
	//	}
	//	for (auto it : num)
	//	{
	//		smallnum = min()
	//	}
}


void q::q10451()
{
	/*
2
8
3 2 7 8 1 4 5 6
10
2 1 3 4 5 6 7 9 10 8*/
	int n;
	cin >> n;
	while(n--)
	{
		int m, ans = 0, cycle[10000];
		bool visit[10000] = {false, };

		cin >> m;


		for (int i = 1; i < m + 1; i++)
		{
			cin >> cycle[i];
		}
		for (int j = 1; j < m + 1; j++)
		{
			if (visit[j] == false) {
				ans++;
				int temp = j;
				while (cycle[temp] != j) {
					visit[temp] = true;
					temp = cycle[temp];
				}
				visit[temp] = true;
			}
		}

		cout << ans << '\n';
	}
}

void q::q7576()
{
	int row, col, box[101][101] = {2, }, go = 1, ans=0;
	vector<pair<int,int>> stack;
	cin >> row >> col;
	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {
			cin >> box[i][j];
		}
	}

	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {

			if (box[i][j] == 1) {
				stack.push_back(make_pair(i, j));
				ans++;
				cout << i << ", " << j << '\t' << endl;
				while (!stack.empty())
				{

					i = stack.at(stack.size() - 1).first;
					j = stack.at(stack.size() - 1).second;

					stack.pop_back();
					

					if (i > 1) {
						if (box[i - 1][j] == 0) {
							box[i - 1][j] = 1;
							stack.push_back(make_pair(i - 1, j));
							go = 1;
							cout << i - 1 << ", " << j << '\t';
						}
					}
					if (i + 1 <= col) {
						if (box[i + 1][j] == 0) {
							box[i + 1][j] = 1;
							stack.push_back(make_pair(i + 1, j));
							go = 1;
							cout << i + 1 << ", " << j << '\t';
						}
					}
					if (j + 1 <= row) {
						if (box[i][j + 1] == 0) {
							box[i][j + 1] = 1;
							stack.push_back(make_pair(i, j + 1));
							go = 1;
							cout << i << ", " << j + 1 << '\t';
						}
					}
					if(j > 1) {
						if (box[i][j - 1] == 0) {
							box[i][j - 1] = 1;
							stack.push_back(make_pair(i, j - 1));
							go = 1;
							cout << i << ", " << j - 1 << '\t';
						}
					}
					cout << "next stack" << endl;
				}
			}
		}
	}

	cout << endl;
	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {
			cout << box[i][j];	
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {
			if (box[i][j] == 0)
				ans = -1;
		}
	}
	cout << ans;
}


//int n, feeling;
////float gg, gb, bg, bb, good[100] = { 0, }, bad[100] = { 0, }, g = 0, b = 0;
//int chk_feel(int feel, int n) {
//	if (n == 1) {
//		if (feel == 0) {
//			g = gg;
//			b = gb;
//		}
//		else {
//			g = bg;
//			b = bb;
//		}
//	}
//	else {
//		return chk_feel(feel*bg, n - 1) + chk_feel(feel*gg, n - 1);
//
//	}
//}

void q::q17211()
{
	int n, feeling;
float gg, gb, bg, bb, good[100] = { 0, }, bad[100] = { 0, }, g = 0, b = 0;
	//0 good / 1 bad
	cin >> n >> feeling;

	cin >> gg >> gb >> bg >> bb;
	//good good / good bad / bad good/ bad bad
	//.7		.3			.5			.5
	for (int i = 0; i < n; i++)
	{
		if (n == 1) {
			if (feeling == 0) {
				g = gg;
				b = gb;
			}
			else {
				g = bg;
				b = bb;
			}
		}
		else if (i == n - 1) {

		}
		else if (i == 0) {
			if (feeling == 0) {
				g += gg;

			}
			else {
				g = (bg * gg) + (bb * bg);
				b = (bg * gb) + (bb * bb);
			}
		}
		//만약에 N=3 , 3일 후라면 ?
		// recursion
		//
		g = (bg*gg *gg) + (bg *gb * bg) + (bb *bg*gg) + (bb * bb*bg);
	}
}

void q::q11758()
{
	int x[4], y[4], dxdy[3];
	bool straight = false, clockwise = false, revClockwise = false;
	
	for (int i = 0; i < 3; i++) 
		std::cin >> x[i] >> y[i];

	if ((x[1] == x[0] && x[2] == x[0]) || (y[1] == y[0] && y[2] == y[0]))
		straight = true;
	else {
		for (int i = 1; i < 3; i++)
			dxdy[i] = (y[i] - y[0]) / (x[i] - x[0]);
		if(dxdy[1] == dxdy[2]) straight = true;
		else if (dxdy[1] > dxdy[2]) clockwise = true;
		else if (dxdy[1] < dxdy[2]) revClockwise = true;
	}
	if(straight)
	std::cout << 0;
	else if(clockwise)
	std::cout << -1;
	else if(revClockwise)
	std::cout << 1;
}

void q::q11399()
{
	int n, temp, time_sum = 0;
	vector<pair<int, int>> money;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		money.push_back(make_pair(temp, i));
	}
	sort(money.begin(), money.end());

	for (int i = 0; i < n; i++)
	{
		int temp_sum = 0;
		for (int j = 0; j < i; j++)
		{
			temp_sum += money.at(j).first;
		}
		time_sum += temp_sum + money.at(i).first;
	}
	cout << time_sum;
}

void q::q10819()
{
	/*
	6
	20 1 15 8 4 10

	62


	20 1 15 4 10 8
	19 14 11 6 2
	33 19 = 52

	1 20 4 15 8 10
	19 16 11 7 2
	35 20 = 55

	8 15 1 20 4 10
	7 14 19 16 6
	21 35 6 = 56 6 = 62 (o)

	트리 같이 생김..
	아닌듯..
	*/
	deque<int> deq;
	int n, num[10], tot = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	sort(num, num + n); //min_num = num[0]; max_num = num[n];

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			if (i % 4 == 2) deq.push_front(num[n - i / 2 - 1]);
			else deq.push_front(num[i / 2]);
			
		}
		else
		{
			if (i % 4 == 3) deq.push_back(num[i / 2]);
			else deq.push_back(num[n - i / 2 - 1]);
		}
	}


	for (int i = 0; i < n - 1; i++)
	{
		tot += abs(deq.at(i) - deq.at(i + 1));
	}
	cout << tot;
	//deq.push_front(num[0]);
//deq.push_back(num[n-1]);
//deq.push_front(num[n -2]);
//deq.push_back(num[1]);

//1 4 8 9 10 15 20 21
//10 8 20 1 21 4 15 9

//deq.push_front(num[2]);
//deq.push_back(num[n - 3]);
//deq.push_front(num[n-4]);
//deq.push_back(num[3]);
}

void q::q2419()
{
	int n, m, len = 0, me = 0, tot = 0;
	vector<int> wherePlus, whereMinus;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp > 0)
			wherePlus.push_back(temp);
		else
			whereMinus.push_back(temp);
	}

	sort(wherePlus.begin(), wherePlus.end(), greater<>());
	sort(whereMinus.begin(), whereMinus.end() );

	while (m>0) {
		if (wherePlus.empty() || !whereMinus.empty() && (wherePlus.back() > abs(whereMinus.back()))) {

			me = whereMinus.back();
			len = len - me;

			whereMinus.pop_back();
			
		}
		else if (whereMinus.empty() || !wherePlus.empty() && (wherePlus.back() < abs(whereMinus.back()))){

			me = wherePlus.back();
			len = me - len;
			
			wherePlus.pop_back();
		}
		else { // wherePlus.back() == abs(whereMinus.back())
			if (me < 0) {
				me = whereMinus.back();
				len = len - me;
				whereMinus.pop_back();
			}
			else {
				me = wherePlus.back();
				len = me - len;
				wherePlus.pop_back();
			}
		}

		m = m - len;
		tot += m;
		len = me;
		cout << me << '\t' << m << '\t'<<  tot << endl;
	}
	cout << tot;
}

void q::q10171()
{
	
	std::cout <<"\\    \/\\\n )  ( " << "')\n(  \/  )\n \\(__)\|";
}

void q::q2588()
{
//	//#include <iostream>
//	//	int main() {
//	int a, b;
//	std::cin >> a >> b;
//	if (a > b)
//		std::cout << '>';
//	else if (a < b)
//		std::cout << '>';
//	else
//		std::cout << "==";
//}

	//int h, m;
	//std::cin >> h >> m;
	//if (m < 45) {
	//	m += 60;
	//	h -= 1;
	//	if (h < 0) {
	//		h = 23;
	//	}
	//}
	//m -= 45;
	//std::cout << h << " " << m;

	//int a, b, c, mid;
	//std::cin >> a >> b >> c;
	//if (a >= b && b >= c || c >= b && b >= a)
	//	mid = b;
	//else if (a >= c && c >= b || b >= c && c >= a)
	//	mid = c;
	//else if (b >= a && a >= c || c >= a && a >= b)
	//	mid = a;
	//std::cout << mid;

//#include <iostream>
//	int main() {
//		std::ios_base::sync_with_stdio(false);
//		std::cin.tie(NULL);
//
//		int T, a, b;
//		std::cin >> T;
//		for (int t = 1; t <= T; t++) {
//			std::cin >> a >> b;
//			std::cout << "Case #" << t << ": " << a + b << '\n';
//		}
//	}


	//std::ios_base::sync_with_stdio(false);
	//std::cin.tie(NULL);

	//int T;
	//	std::cin >> T;
	//for (int t = 0; t < T; t++) {
	//	for (int a = 0; a < T; a++) {
	//		if (T - t > a+1)
	//			std::cout << " ";
	//		else
	//			std::cout << '*';
	//	}
	//	std::cout << '\n';
	//}

		/*std::ios_base::sync_with_stdio(false);
		std::cin.tie(NULL);

		int n, cnt = 0;
		bool f[43] = { false, };
		for (int i = 0; i < 10; i++) {
			std::cin >> n;
			f[n % 42] = true;
		}
		for (int i = 0; i < 42; i++) {
			if (f[i]) cnt++;
		}
		std::cout << cnt;
*/

	/*
	
	
	#include <iostream>
	int main() {
		std::ios_base::sync_with_stdio(false);
		std::cin.tie(NULL);

	}

	

	*/

	double t, x1, y1, r1, x2, y2, r2, len, result;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		len = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));

		if (len == r1 + r2 || len + r1 == r2 || len + r2 == r1)
			result = 1;
		else if (len > r1 + r2 || (r1 < r2 && len + r1 < r2 )|| (r2 < r1 && len + r2 < r1))
			result = 0;
		else
			result = 2;
		std::cout << result << '\n';
	}
}

