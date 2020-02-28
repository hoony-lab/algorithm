#include "SDSbasic.h"
#pragma warning(disable : 4996)

//
//void SDSbasic::q1110()
//{
//	int num = 0, newNum = 0, temp = 0, cnt = 0;
//
//	cin >> num;
//	newNum = num;
//
//	do{
//		temp = newNum;
//
//		if (temp < 0)
//			temp *= 10;
//
//		int temp1 = temp / 10;
//		int temp2 = temp % 10;
//
//		newNum = (temp2 * 10) + (temp1 + temp2) % 10;
//		cnt++;
//
//	}while (num != newNum);
//
//	cout << cnt;
//}
//
//void SDSbasic::q1652()
//{
//	//NxN Á¤»ç°¢Çü
//	//µÎÄ­ ÀÌ»óÀÇ ºóÄ­, °¡·Î/¼¼·Î
//	//°ËÁ¤»öÀÌ ÁüÄ­
//
//	int n;
//	char ch[101][101];
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> ch[i];
//	}
//
//	int row = 0;
//	bool isXrow = true;
//
//	for (int j = 0; j < n; j++)
//	{
//		for (int k = 0; k < n - 1; k++)
//		{
//			if (ch[j][k] == '.' && ch[j][k + 1] == '.' && isXrow) {
//				row++; isXrow = false;
//				//cout << j << '\t' << k << '\n';
//			}
//			
//			if (ch[j][k] == 'X')	isXrow = true;
//		}
//		isXrow = true;
//	}
//
//	int col = 0;
//	bool isXcol = true;
//
//	for (int j = 0; j < n; j++)
//	{
//		for (int k = 0; k < n-1; k++)
//		{
//			if (ch[k][j] == '.' && ch[k+1][j] == '.' && isXcol) {
//				col++; isXcol = false;
//				//cout << k << '\t' << j << '\n';
//			}
//			
//			if (ch[k][j] == 'X')	isXcol = true;
//		}
//		isXcol = true;
//	}
//	cout << row << ' ' << col;
//}
//
//void SDSbasic::q2621()
//{
//	//R B Y G, 1-9  4*9=36, 5Àå »Ì°í °è»ê
//	char ch[5];
//	int num[5], temp[5], max = 0, cntNum = 0, cntNum2=0, cntColor = 0, cntContinue = 0, sameNum = 0, smallNum, bigNum, score;
//	bool countStart = true, card2 = false, card3 = false, card4 = false, card5 = false, cardBig2 = false, cardBig3 = false,  sameColor = false, continueNum = false;
//
//	for (int i = 0; i < 5; i++)
//	{
//		cin >> ch[i];
//		cin >> num[i];
//		
//		temp[i] = num[i];
//		
//		max > num[i] ?
//			true : max = num[i];	
//	}
//	
//	sort(temp, temp + 5);
//	for (int i = 0; i < 5 - 1; i++)
//	{
//		if (temp[i + 1] == temp[i] + 1)
//			cntContinue++;
//
//
//		if ((temp[i + 1] == temp[i]) && countStart) {
//			cntNum++;
//			smallNum = temp[i];
//		}
//		else if ((temp[i + 1] == temp[i]) && !countStart) {
//			cntNum2++;
//			bigNum = temp[i];
//		}
//		else if(cntNum > 0) countStart = false;
//
//
//		if (ch[i + 1] == ch[i])
//			cntColor++;
//
//		cout << temp[i] << '\t' << temp[i+1] << '\t'<< cntContinue << endl;
//	}
//
//	if (cntContinue == 4)
//		continueNum = true;
//
//
//	if (cntNum == 1)
//		card2 = true;
//	else if (cntNum == 2)
//		card3 = true;
//	else if (cntNum == 3)
//		card4 = true;
//	else if (cntNum == 4)
//		card5 = true;
//
//	if (cntNum2 == 1) {
//		cardBig2 = true;
//	}
//	else if (cntNum2 == 2) {
//		cardBig3 = true;
//	}
//
//
//	if (cntColor == 4)
//		sameColor = true;
//
//
//	if (sameColor && continueNum)
//		score = max + 900;
//	else if (card4)
//		score = smallNum + 800;
//
//	else if (card3 && cardBig2)
//		score = smallNum * 10 + bigNum + 700;
//	else if (card2 && cardBig3)
//		score = bigNum * 10 + smallNum + 700;
//
//	else if (sameColor)
//		score = max + 600;
//
//	else if (continueNum && !card5)
//		score = max + 500;
//
//	else if (card3)
//		score = smallNum + 400;
//
//	else if (card2 && cardBig2)
//		score = bigNum * 10 + smallNum + 300;
//
//	else if (card2)
//		score = smallNum + 200;
//
//	else
//		score = max + 100;
//
//	cout << score;
//}


//void graphing(int);


//¹æÇâÀÌ ¾ø¾î¼­ ¹æ¹®ÀÌ 1Â÷¿ø ?
////¿Ö 2Â÷¿øÀÌ ¾Æ´Ò±î
//void graphing(int node) {
//
//	cnt++;
//	visited[node] = true;
//
//	queue<int> q;
//	q.push(node);
//
//	while (!q.empty()) {
//		int a = q.front();
//		q.pop();
//
//		for (int i = 1; i <= n; i++)
//		{
//			if (graph[a][i] == 1 && visited[i] == false) {
//				visited[i] = true;
//				q.push(i);
//			}
//		}
//	}
//}


void SDSbasic::q11724()
{
	//Á¤Á¡ n, °£¼± m

	int n, m, cnt = 0, graph[101][101] = { 0, };
	bool visited[1001] = { false, };
	queue<int> q;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		//¹«¹æÇâ ±×·¡ÇÁ
		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	int k;
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == false)
			//graphing(i);


			q.push(i);

		while (!q.empty()) {
			cnt++;
			visited[i] = true;

			while (!q.empty()) {
				int a = q.front();
				q.pop();

				for (int j = 1; j <= n; j++)
				{
					if (graph[a][j] == 1 && visited[j] == false) {
						visited[j] = true;
						q.push(j);
					}
				}
			}
		}

	}
	cout << cnt;
}

void SDSbasic::q2606()
{
	int n, m, cnt = 0, graph[101][101] = { 0, };
	bool visited[101] = { false, }, goodtogo = false;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u][v] = 1;
		graph[v][u] = 1;
		if ((u == 1 && v != 1) || (u != 1 && v == 1))
			goodtogo = true;
	}

	if (goodtogo) {

		visited[1] = true;
		queue<int> q;
		q.push(1);

		while (!q.empty()) {
			int a = q.front();
			q.pop();

			for (int i = 1; i <= m; i++)
			{
				if (visited[i] == false && graph[a][i] == 1) {
					visited[i] = true;
					q.push(i);
					cnt++;
					cout << "visited : " << i << '\t';
				}
			}
		}

	}

	cout << cnt;
}


//
//int cnt[53], graph[53][53];
//int i=0, m = 0, n = 0, k = 0;
//bool visited[53][53], start;
//
//void q1012loop(int, int);
//void q1012loop(int q, int w)
//{
//
//	//if (graph[q][w] == 1 && visited[q][w] == false) {
//		//if (start)
//		//	cnt[i]++;
//		start = false;
//		visited[q][w] == true;
//
//		if (q > 1 && graph[q - 1][w] == 1) {
//			//visited[q - 1][w] == true;
//			q1012loop(q - 1, w);
//		}
//		if (q + 1 < m && graph[q + 1][w] == 1) {
//			//visited[q + 1][w] = true;
//			q1012loop(q + 1, w);
//		}
//		if (w > 1 && graph[q][w - 1] == 1) {
//			//visited[q][w - 1] = true;
//			q1012loop(q, w - 1);
//		}
//		if (w + 1 < n && graph[q][w + 1] == 1) {
//			//visited[q][w + 1] = true;
//			q1012loop(q, w + 1);
//		}
//	
//}
//
//
//
//void SDSbasic::q1012()
//{
//	int a;
//	cin >> a;
//	for (i = 0; i < a; i++)
//	{
//		m=0, n=0, k=0;
//		graph[53][53] = { 0, };
//		visited[53][53] = { false, };
//		cin >> m >> n >> k;
//
//		for (int j = 0; j < k; j++)
//		{
//			int u, v;
//			cin >> u >> v;
//			graph[u][v] = 1;
//		}
//
//		cnt[i] = 0;
//		start = true;
//		for (int q = 0; q < m; q++)
//		{
//			for (int w = 0; w < n; w++)
//			{
//				
//				//start = true;
//				if (graph[q][w] == 1 && visited[q][w] == false) {
//					q1012loop(q, w);
//					cnt[i]++;
//					//cout << "loop : " << q << ", " << w << '\n';
//				}
//			}
//		}
//	}
//
//	for (int p = 0; p< a; p++)
//	{
//		cout << cnt[p] << '\n';
//	}
//}

//
//int rect[102][102];
//bool visited[102][102];
//int area[51], n, m, k, num=0, cnt=0;
//int dx[4] = { -1, 1, 0, 0 };
//int dy[4] = { 0, 0, -1, 1 };
//vector<int> v;
//
//void Search(int x, int y);
//
//void Search(int x, int y) {
//	//search
//	visited[x][y] = true;
//
//	for (int a = 0; a < 4; a++) {
//		int mx = dx[a] + x;
//		int my = dy[a] + y;
//
//		if (mx > 0 && my > 0 && mx < n  && my < m && rect[mx][my] == 0 && visited[mx][my] == false)
//		{
//			Search(mx, my);
//			cnt++;
//
//		}
//	}
//}
//
//void SDSbasic::q2583()
//{
//	int area[3];
//	cin >> m >> n >> k;
//
//	int rect[102][102] = { 0, }, num=0;
//	bool visited[102][102] = { false, };
//
//	
//
//	for (int i = 0; i < k; i++) {
//		int x1, y1, x2, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		for (int y = y1; y < y2; y++) {
//			for (int x = x1; x < x2; x++) {
//				rect[y][x] = 1;
//			}
//		}
//	}
//	cout <<n << "done property " << m<< endl;
//
//	for (int y = 0; y < m; y++) {
//		for (int x = 0; x < n; x++) {
//			
//			if (visited[y][x] == false && rect[y][x] == 0) {
//				//cout << "start searching " << endl;
//				cnt = 1;
//				Search(y, x);
//				v.push_back(cnt);
//			}
//		}
//	}
//
//
//	for (int y = 0; y < m; y++) {
//		for (int x = 0; x < n; x++) {
//			cout << rect[x][y];
//		}
//		cout << '\n';
//	}
//
//
//	cout << num << '\n';
//	for (int i = 0; i < num; i++)
//	{
//		cout << area[i] << ' ';
//	}
//}



//
//int n, cnt1 = 0, cnt2 = 0;
//int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
//char map[102][102] = { }, map2[102][102] = { };
//bool visited[102][102] = { false, }, visited2[102][102] = { false, };
//
//char CharacterCheck(char ch) {
//	char result;
//	if (ch == 'R' || ch == 'G')
//		result = 'R';
//	else
//		result = 'B';
//
//	return result;
//}
//
//void Search(int i, int j, char ch) {
//	visited[i][j] = true;
//	//cout << "visiting : "<<  i << ", " << j << endl;
//	for (int a = 0; a < 4; a++)
//	{
//		int mx = dx[a] + i;
//		int my = dy[a] + j;
//
//		if (mx >= 0 && my >= 0 && mx < n && my < n && !visited[mx][my] && map[mx][my] == ch) {
//			Search(mx, my, ch);
//		}
//	}
//}
//
//
//void Search2(int i, int j, char ch) {
//	visited2[i][j] = true;
//	///cout << "visiting2 : " << i << ", " << j << endl;
//	//char temp = CharacterCheck(ch);
//
//	for (int a = 0; a < 4; a++)
//	{
//		int mx = dx[a] + i;
//		int my = dy[a] + j;
//
//		if (mx >= 0 && my >= 0 && mx < n && my < n && !visited2[mx][my] && map2[mx][my] == ch) {
//			Search2(mx, my, ch);
//		}
//	}
//}
//
//
//void SDSbasic::q10026()
//{
//	//Å©±â°¡ NxN , RGB, °°Àº»ö»ó ÀÎÁ¢ÇÏ¸é °°Àº ±¸¿ª
//
//	cin >> n;
//	
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++){
//			char k;
//			cin >> k;
//			map[i][j] = k;
//			map2[i][j] = CharacterCheck(k);
//		}
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (!visited[i][j]) {
//				Search(i, j, map[i][j]);
//				cnt1++;
//			}
//			if (!visited2[i][j]) {
//				///cout << "visiting2 : " << i << ", " << j << ", " << map[i][j] << endl;
//				Search2(i, j, map2[i][j]);
//				cnt2++;
//			}
//		}
//	}
//
//	cout << cnt1 << ' ' << cnt2;
//}
//


//int dx[] = { -1, 1, 0, 0 }, dy[] = { 0,0,-1, 1 };
//int n, cnt = 0;
//int map[27][27] = { 0, };
//bool visited[27][27] = { false, };
//vector<int> v;
//
//void Search(int i, int j) {
//	visited[i][j] = true;
//
//	for (int a = 0; a < 4; a++)
//	{
//		int mx = dx[a] + i;
//		int my = dy[a] + j;
//
//		if (mx >= 0 && my >= 0 && mx < n && my < n && !visited[mx][my] && map[mx][my] == 1) {
//			Search(mx, my);
//			cnt++;
//		}
//	}
//}
//void SDSbasic::q2667()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++){
//			char num;
//			cin >> num;
//			map[i][j] = num - 48;
//		}
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (!visited[i][j] && map[i][j] == 1) {
//				cnt = 1;
//				///cout << "visiting : " << i << ", " << j << endl;
//				Search(i, j);
//				v.push_back(cnt);
//			}
//		}
//	}
//
//	sort(v.begin(), v.end());		//algorithm
//	cout << v.size() << '\n';
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v.at(i) << '\n';
//	}
//}


//
//int n, m, k;
//vector<int> map[1001];
//bool visited[1001];
//queue<int> q;
//
//
//void DFS(int k) {
//	visited[k] = true;
//	cout << k << " ";
//
//	for (int node : map[k]){
//		if (!visited[node])
//			DFS(node);
//	}
//}
//
//void BFS(int k) {
//	visited[k] = true;
//
//	q.push(k);
//	while (!q.empty()) {
//		int temp = q.front();
//		q.pop();
//		cout << temp << " ";
//
//		for (int node : map[temp]) {
//			if (!visited[node]) {
//				visited[node] = true;
//				q.push(node);
//			}
//		}
//	}
//}
//
//void SDSbasic::q1260()
//{
//	//¹æ¹®°¡´ÉÀÌ ¿©·¯°³¸é Á¤Á¡¹øÈ£°¡ ÀÛÀº°ÅºÎÅÍ, 1-N
//	//Á¤Á¡ N, ¾ç¹æÇâ °£¼± M, 
//
//
//	cin >> n >> m >> k;
//	for (int i = 0; i < m; i++) {
//		int u, v;
//		cin >> u >> v;
//		map[u].push_back(v);
//		map[v].push_back(u);
//	}
//
//	for (int i = 1; i <= n; i++) {
//		sort(map[i].begin(), map[i].end());
//	}
//
//	DFS(k);
//	cout << '\n';
//	//memset(visited, 0, sizeof(visited));
//	visited[1001] = { false, };
//	BFS(k);
//}


void SDSbasic::q1697() {
	int n, k, temp, cnt = 0;
	cin >> n >> k;
	//using bfs

	int visited[100001] = { 0, };
	queue<int> q;

	temp = n;
	visited[temp] = 1;
	q.push(temp);

	while (!q.empty()) {
		temp = q.front();
		q.pop();

		if (temp == k) {
			cout << visited[temp] - 1;
			break;
		}

		if (temp - 1 >= 0 && visited[temp - 1] == 0) {
			q.push(temp - 1);
			visited[temp - 1] = visited[temp] + 1;
		}

		if (temp + 1 <= 100000 && visited[temp + 1] == 0) {
			q.push(temp + 1);
			visited[temp + 1] = visited[temp] + 1;
		}

		if (temp * 2 <= 100000 && visited[temp * 2] == 0) {
			q.push(temp * 2);
			visited[temp * 2] = visited[temp] + 1;
		}
	}
}

void SDSbasic::q7576()
{
	int m, n, cnt = 0, zeroCnt = 0;
	int map[101][101];
	int visited[101][101] = { 0, };
	cin >> m >> n;

	queue<int> qx, qy;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> map[x][y];
			if (map[x][y] == 1) {
				qx.push(x);
				qy.push(y);
				visited[x][y] = 1;
			}
			if (map[x][y] == 0)
				zeroCnt++;
		}
	}


	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };


	while (!qx.empty()) {
		cnt++;
		//cout << "starting : " << cnt << " stack : " << qx.size() << endl;
		//int mx, my;

		int num = qx.size();
		for (int i = 0; i < num; i++) {
			int tempX = qx.front();
			int tempY = qy.front();
			qx.pop();	qy.pop();


			for (int a = 0; a < 4; a++) {

				int mx = dx[a] + tempX;
				int my = dy[a] + tempY;

				if (mx >= 0 && my >= 0 && mx < m && my < n && map[mx][my] == 0 && visited[mx][my] != 1) {
					//cout << " calculating : " << mx << ", " << my << '\n';
					visited[mx][my] = 1;
					zeroCnt--;
					map[mx][my] = map[tempX][tempY] + 1;
					qx.push(mx);
					qy.push(my);
				}
			}
		}


		////debug
		//for (int y = 0; y < n; y++) {
		//	for (int x = 0; x < m; x++) {
		//		cout << map[x][y];
		//	}
		//	cout << endl;
		//}
		//cout << endl;
	}






	if (zeroCnt != 0)
		cout << "-1";
	else if (cnt > 1)
		cout << cnt - 1;
	else if (zeroCnt == 0)
		cout << "0";

}

void SDSbasic::q2178()
{
	int n, m;
	int map[101][101];
	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			char ch;
			cin >> ch;
			map[x][y] = ch - 48;
		}
	}

	queue<pair<int, int>> q;
	q.push(make_pair<int>(0, 0));

	while (!q.empty()) {
		int tempX = q.front().first;
		int tempY = q.front().second;
		q.pop();

		int dx[] = { -1, 1, 0, 0 };
		int dy[] = { 0, 0, -1, 1 };

		for (int a = 0; a < 4; a++) {
			int mx = dx[a] + tempX;
			int my = dy[a] + tempY;

			if (mx >= 0 && my >= 0 && mx < m && my < n && map[mx][my] == 1) {
				map[mx][my] = map[tempX][tempY] + 1;
				q.push(make_pair(mx, my));

				;
			}
		}
	}


	cout << map[m - 1][n - 1];
}

void SDSbasic::q7562()
{
	int n;
	cin >> n;
	vector<int> v;
	int dx[] = { 1,2,2,1,-1,-2,-2,-1 };
	int dy[] = { 2,1,-1,-2,-2,-1,1,2 };

	while (n--) {
		int map[301][301] = { 0, }, visitied[301][301];
		int len, x1, y1, x2, y2;
		cin >> len >> x1 >> y1 >> x2 >> y2;

		queue<pair<int, int>> q;
		q.push(make_pair(x1, y1));

		map[x1][y1] = 1;

		while (!q.empty()) {
			int tx = q.front().first;
			int ty = q.front().second;
			q.pop();

			for (int a = 0; a < 8; a++) {
				int mx = dx[a] + tx;
				int my = dy[a] + ty;

				if (mx >= 0 && my >= 0 && mx < len && my < len && map[mx][my] == 0) {
					map[mx][my] = map[tx][ty] + 1;
					q.push(make_pair(mx, my));
					//cout << map[mx][my] << " : try, " << mx << ", " << my << '\n';
				}
				/*if (mx == x2 && my == y2)
					break;*/
			}
		}
		v.push_back(map[x2][y2]);
	}

	for (auto k : v) {
		cout << k - 1 << '\n';
	}
}

void SDSbasic::q2589()
{
	char map[51][51];
	int visited[51][51] = { 0, }, cnt[51][51], time = 1000, result = 0, mintime = 0;
	int n, m;
	cin >> n >> m;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++)
		{
			cin >> map[y][x];
		}
	}

	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };
	int mx = 0, my = 0;
	queue<pair<int, int>> q;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {

			if (map[y][x] == 'L') {
				//cout << "starting : " << y << ", " << x << '\n';
				//visited[51][51] = { 0, };
				memset(visited, 0, sizeof(visited));

				visited[y][x] = 1;

				q.push(make_pair(y, x));


				while (!q.empty()) {
					int ty = q.front().first;
					int tx = q.front().second;
					q.pop();

					for (int a = 0; a < 4; a++) {
						my = dy[a] + ty;
						mx = dx[a] + tx;

						if (mx >= 0 && my >= 0 && mx < m && my < n && map[my][mx] == 'L' && visited[my][mx] == 0) {
							q.push(make_pair(my, mx));
							visited[my][mx] = visited[ty][tx] + 1;
							mintime = min(visited[my][mx], time);
							//cout << "loop : " << my << ", " << mx << '\n';
						}
					}
				}
			}
			result = max(mintime, result);


		}
	}
	cout << result - 1;

	//for (int y = 0; y < n; y++) {
	//	for (int x = 0; x < m; x++) {
	//		cout << map[y][x];
	//	}
	//	cout << endl;
	//}
}

void SDSbasic::q2309()
{
	//9ÁÙ, ´Ù´õÇØ¼­ 100
	vector<int> v;
	int height[9], a, b, sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> height[i];
		sum += height[i];
	}

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - (height[i] + height[j]) == 100) {
				a = height[i];
				b = height[j];
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (!(height[i] == a || height[i] == b))
			v.push_back(height[i]);
	}

	sort(v.begin(), v.end());

	for (auto i : v) {
		cout << i << '\n';
	}
}


//void loop() {
//	vector<string>::iterator iterAwful;
//	vector<string>::iterator iterDisgusting;
//	bool find = true;
//	while(find)
//		for (vector<string>::iterator iterAwful = awful.begin(); iterAwful < awful.end(); iterAwful++) {
//			for (vector<string>::iterator iterDisgusting = disgusting.begin(); iterDisgusting < disgusting.end(); iterDisgusting++) {
//				if (*iterAwful == *iterDisgusting) {
//					awfulDisgusting.push_back(*iterAwful);
//					awful.erase(iterAwful);
//					disgusting.erase(iterDisgusting);
//
//				}
//			}
//		}
//	} while ((iterAwful == awful.end());
//}

void SDSbasic::q1764()
{
	/*
	int n, m, start = 0;
	cin >> n >> m;

	vector<string> awful, disgusting, awfulDisgusting;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		awful.push_back(str);
	}
	for (int j = 0; j < m; j++) {
		cin >> str;
		disgusting.push_back(str);
	}
	sort(awful.begin(), awful.end());	sort(disgusting.begin(), disgusting.end());

	//vector<string>::iterator iterAwful;
	//vector<string>::iterator iterDisgusting;
	bool notfind = true;

	//while (notfind) {
	//	notfind = true;
	//	for (vector<string>::iterator iterAwful = awful.begin(); iterAwful < awful.end(); iterAwful++) {
	//		for (vector<string>::iterator iterDisgusting = disgusting.begin(); iterDisgusting < disgusting.end(); iterDisgusting++) {
	//			if (*iterAwful == *iterDisgusting) {
	//				awfulDisgusting.push_back(*iterAwful);
	//				awful.erase(iterAwful);		disgusting.erase(iterDisgusting);
	//				notfind = false;
	//				break;
	//			}
	//		}if (!notfind && (iterAwful == awful.end() && iterDisgusting == disgusting.end())
	//			|| awful.empty() || disgusting.empty()) break;
	//	}
	//}

	//while (notfind) {
		for (int i = 0; i < n; i++) {
			for (int j = start; j < m; j++){
				if (awful.at(i) == disgusting.at(j)) {
					//vector<string>::iterator iterAwful = awful.begin();
					//vector<string>::iterator iterDisgusting = disgusting.begin();

					awfulDisgusting.push_back(awful.at(i));
					//awful.erase(iterAwful+i);	disgusting.erase(iterDisgusting+j);
					//n--;	m--;
					start = j + 1;
					//notfind = false;
					break;
				}
				if (awful.at(i) < disgusting.at(j)) break;
			}
		}//if (!notfind) break;
	//}



	cout << awfulDisgusting.size() << '\n';
	for (auto name : awfulDisgusting) {
		cout << name <<'\n';
	}


	*/
	int n, m, start = 0;
	cin >> n >> m;

	vector<string> awful, disgusting, awfulDisgusting;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		awful.push_back(str);
	}
	for (int j = 0; j < m; j++) {
		cin >> str;
		disgusting.push_back(str);
	}
	sort(awful.begin(), awful.end());	sort(disgusting.begin(), disgusting.end());

	for (int i = 0; i < n; i++) {
		for (int j = start; j < m; j++) {
			if (awful.at(i) == disgusting.at(j)) {
				awfulDisgusting.push_back(awful.at(i));
				start = j + 1;
				break;
			}
			if (awful.at(i) < disgusting.at(j)) break;
		}
	}



	cout << awfulDisgusting.size() << '\n';
	for (auto name : awfulDisgusting) {
		cout << name << '\n';
	}
}

struct conference {
	int begin, end;
};
conference conf[100001];

bool cmp(const conference& a, const conference& b) {
	if (a.end == b.end)
		return a.begin < b.begin;
	else
		return a.end < b.end;
}

void SDSbasic::q1931()
{
	//int n, cnt = 0, maxnum = 0, minnum = INT_MAX - 1;
	//cin >> n;
	//vector<int> conference[100001];
	//for (int i = 0; i < n; i++) {
	//	int u, v;
	//	cin >> u >> v;
	//	conference[u].push_back(v);
	//	maxnum = max(maxnum, u);
	//	minnum = min(minnum, u);
	//}

	//sort(conference, conference + n);

	//queue<pair<int, int>> qq;
	//qq.push(make_pair(minnum, conference[minnum].front()));

	//queue<int> q;
	//q.push(minnum);

	//while (!q.empty()) {
	//	cnt++;

	//	int startTime = q.front();
	//	q.pop();
	//	int num = conference[startTime].size();
	//	
	//	if (num != 0) {
	//		sort(conference[startTime].begin(), conference[startTime].end());

	//		int endTime = conference[startTime].front();
	//		q.push(endTime);

	//		int shortTime = maxnum;
	//		for (int i = 0; i < num; i++) {
	//			int endTime = conference[startTime].at(i);
	//			shortTime = min(shortTime, endTime);

	//			q.push();
	//		}
	//	}
	//	else if (startTime++ < maxnum) {
	//		q.push(startTime);
	//	}
	//	
	//}

	//cout << cnt;




	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		conf[i] = { u,v };
	}

	sort(conf, conf + n, cmp);

	int cnt = 1;
	int end = conf[0].end;
	int begin = conf[0].begin;

	for (int i = 1; i < n; i++) {
		if (end <= conf[i].begin) {
			cnt++;
			end = conf[i].end;
			//cout << conf[i].begin << ", " << conf[i].end << endl;
		}
	}
	cout << cnt;
}

void SDSbasic::q1026()
{
	int n, a[51], b[51], total = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		int k;
		cin >> b[i];
	}

	sort(a, a + n);	sort(b, b + n, greater<int>());

	for (int i = 0; i < n; i++) {
		total += (a[i] * b[i]);
	}
	cout << total;
}

void SDSbasic::q1449()
{
	int n, len, leaking[1001], cnt = 0, result = 1, check;
	cin >> n >> len;
	for (int i = 0; i < n; i++) {
		cin >> leaking[i];
	}

	sort(leaking, leaking + n);

	check = leaking[0];
	for (int i = 1; i < n; i++) {
		if (leaking[i] - check > len - 1) {
			result++;
			check = leaking[i];
		}
	}

	cout << result;
}

void SDSbasic::q2661()
{
	//123À¸·Î¸¸ ÀÌ·ç¾îÁö´Â ¼ö¿­
	//ÀÎÁ¢ÇÑ µÎ°³ÀÇ ºÎºÐ¼ö¿­ÀÌ µ¿ÀÏÇÏ¸é ³ª»Û³ð

	int n;
	cin >> n;

	string str;

	str.push_back('1');

	bool done = true;


	//2¹øÂ° ¼ýÀÚºÎÅÍ n-1¹ø ¹Ýº¹ »ðÀÔ
	for (int i = 2; i <= n; i++) {

		bool notAvailable[] = { false, false, false };
		bool num[] = { false, false, false };
		int correctNum = 4;
		vector<int> v;

		//len ºñ±³ÇÏ´Â ¹®ÀÚ¿­ ±æÀÌ
		for (int len = 1; len <= i / 2; len++) {

			//for (int index = len/2; index < str.size() + 2 - len*2; index++) {
				//bool condition = false;


			//2°³	0
			//3°³	1
			//4°³	2	0
			//5°³	3	1
			//	4	2	0

			//index ºÎÅÍ ¹®ÀÚ¿­ ºñ±³
			int index = i - len * 2;

			//1,2,3 ³Ö°í ÀÌ»ó¾ø´ÂÁö È®ÀÎ
			for (int a = 1; a < 4; a++) {

				str.push_back(a + '0');
				if (str.substr(index, len) != str.substr(index + len, len)) {
					//if(notAvailable)
					num[a - 1] = true;
					cout << a << " is true" << endl;
				}
				else
					num[a - 1] = false;

				str.pop_back();

			}
			cout << endl << endl;

			for (int a = 1; a < 4; a++) {
				if (num[a - 1])
					notAvailable[a = 1] = true;
			}


		}

		for (int a = 3; a > 0; a--) {
			if (num[a - 1])
				correctNum = min(correctNum, a);
		}

		str.push_back(correctNum + '0');
	}
	cout << str;
}
/*
1
12
121
1213
12131
121312
1213121
12131231
121312312
1213123121
12131231213
121312312131
1213123121312
*/

void SDSbasic::sw1767()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	int dy[] = { -1,0,1,0 };
	int dx[] = { 0,1,0,-1 };

	int test_case, T;
	std::cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int result = 0, n;
		std::cin >> n;

		std::vector<std::pair<int, int>> v;
		v.clear();
		//std::vector<std::pair<int, int>> vDirLen;
		int map[13][13];

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				std::cin >> map[y][x];
				if (!map[y][x] || y == 0 || x == 0 || y == n - 1 || x == n - 1) continue;
				v.push_back({ y,x });
			}
		}

		std::vector<std::pair<int, int>> vTemp;

		int size = v.size();
		//check the only core line
		for (int i = 0; i < size; i++) {
			//for (int i = size - 1; i >= 0; i--) {
			int y = v.at(i).first;
			int x = v.at(i).second;

			//cout << " C : " << y << ", " << x << '\n';
			int len[4];
			int newMap[13][13][4];
			int onlyLen = n, onlyLenIndex = 0;
			int invalidRoute = 0;
			int compare[13];

			memset(len, 0, sizeof(len));
			memset(newMap, 0, sizeof(newMap));

			for (int a = 0; a < 4; a++) {
				int ny = dy[a] + y;
				int nx = dx[a] + x;

				bool possibleRoute;
				while (true) {
					if (ny < 0 || nx < 0 || ny >= n || nx >= n) break;
					if (map[ny][nx] != 0) {
						invalidRoute++;
						possibleRoute = false;
						break;
					}
					else possibleRoute = true;

					len[a]++;
					newMap[ny][nx][a] = 2;

					ny += dy[a];
					nx += dx[a];
				}

				//store len of [a]'s direction
				if (possibleRoute && len[a] > 0) {
					onlyLen = len[a];
					onlyLenIndex = a;
				}
			}




			//update map
			if (invalidRoute != 3) continue;
			result += onlyLen;

			for (int y = 0; y < n; y++) {
				for (int x = 0; x < n; x++) {
					if (newMap[y][x][onlyLenIndex] == 2)
						map[y][x] += newMap[y][x][onlyLenIndex];
					//cout << map[y][x];
				}
				//cout << '\n';
			}
			//cout << '\n';
		}



		//check
		for (int i = 0; i < size; i++) {
			int y = v.at(i).first;
			int x = v.at(i).second;

			//cout << " C : " << y << ", " << x;
			int len[4], minLen = n, minLenIndex = 0;
			int newMap[13][13][4];
			int invalidRoute = 0;

			memset(len, 0, sizeof(len));
			memset(newMap, 0, sizeof(newMap));

			for (int a = 0; a < 4; a++) {
				int ny = dy[a] + y;
				int nx = dx[a] + x;

				bool possibleRoute;
				while (true) {
					if (ny < 0 || nx < 0 || ny >= n || nx >= n) break;
					if (map[ny][nx] != 0) {
						invalidRoute++;
						possibleRoute = false;
						break;
					}
					else possibleRoute = true;

					len[a]++;
					newMap[ny][nx][a] = 2;

					ny += dy[a];
					nx += dx[a];
				}

				if (!possibleRoute) continue;

				//store len of [a]'s direction
				if (len[a] > 0 && minLen > len[a]) {
					minLen = len[a];
					minLenIndex = a;
				}
			}

			if (invalidRoute == 4) continue;
			result += minLen;

			//update map
			for (int y = 0; y < n; y++) {
				for (int x = 0; x < n; x++) {
					if (newMap[y][x][minLenIndex] == 2)
						map[y][x] += newMap[y][x][minLenIndex];
					//cout << map[y][x];
				}
				//cout << '\n';
			}
			//cout << '\n';
		}


		//for (int y = 0; y < n; y++) {
		//	for (int x = 0; x < n; x++) {
		//		//check line of core
		//		if (!map[y][x] || y == 0 || x == 0 || y == n - 1 || x == n - 1) continue;

		//		cout << " C : " << y << ", " << x;
		//		int len[4], minLen = n, minLenIndex = 0;
		//		int newMap[13][13][4];
		//		memset(len, 0, sizeof(len));
		//		memset(newMap, 0, sizeof(newMap));

		//		for (int a = 0; a < 4; a++) {
		//			int ny = dy[a] + y;
		//			int nx = dx[a] + x;

		//			int invalidRoute = 0;
		//			while (true) {
		//				if (ny < 0 || nx < 0 || ny >= n || nx >= n) break;
		//				if (map[ny][nx]) {
		//					invalidRoute++;
		//					break;
		//				}
		//				len[a]++;
		//				newMap[ny][nx][a] = 2;

		//				ny += dy[a];
		//				nx += dx[a];
		//			}
		//			if (invalidRoute) continue;

		//			//store len of [a]'s direction
		//			if (len[a] > 0 && minLen > len[a]) {
		//				minLen = len[a];
		//				minLenIndex = a;
		//			}
		//		}

		//		result += minLen;
		//		cout << ", " << minLen << '\n';

		//		//update map
		//		for (int y = 0; y < n; y++) {
		//			for (int x = 0; x < n; x++) {
		//				if (newMap[y][x][minLenIndex] == 2)
		//					map[y][x] += newMap[y][x][minLenIndex];
		//				cout << map[y][x];
		//			}cout << '\n';
		//		}
		//		cout << '\n';

		//	}
		//}


		std::cout << "#" << test_case << " " << result << '\n';
	}


}

void SDSbasic::sw8104()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	int test_case, T;
	std::cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int result = 0;

		//n¸í, kÁ¶
		int n, k, sum[22] = { 0, }, index = 0;
		std::cin >> n >> k;
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < n*k; i++) {
			if ((i / k) % 2 == 0) {
				index++;
				cout << index << "\t";
				sum[index] += (i + 1);
			}
			else {
				cout << index << "\t";
				sum[index] += (i + 1);
				index--;
			}

		}

		std::cout << "#" << test_case;
		for (int i = 1; i <= k; i++)
			std::cout << " " << sum[i];
		std::cout << '\n';
	}
	/*

	12345
	10 9876
	11 12 13 14 15

	1 2 3 4 5 6 7
	14 13 12 11 10 9 8
	15 16 17 18 19 20 21
	28 27 26 25 24 23 22


	1 2 3 ...
		1 2 3...
	21 22 23...
		20 19 18 ...
	41 42 43...
		1 2 3...
	*/
}

void SDSbasic::sw4014()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	int test_case, T;
	std::cin >> T;

	int map[21][21];

	for (test_case = 1; test_case <= T; ++test_case) {
		int result = 0;
		int n, l;
		std::cin >> n >> l;

		memset(map, 0, sizeof(map));
		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++)
				std::cin >> map[y][x];

		////»óÇÏÁÂ¿ì
		//int dy[] = { -1,1,0,0 };
		//int dx[] = { 0,0,1,-1 };

		//row
		std::cout << "starting row" << '\n';
		for (int y = 0; y < n; y++) {
			bool invalidHeightGap = false, check[21] = { false, };

			for (int x = 0; x < n - 1; x++) {
				int tx = x + 1;
				int heightGap = map[y][x] - map[y][tx];

				if (!heightGap) continue;

				if (heightGap > 1 || heightGap < -1) {
					invalidHeightGap = true; break;
				}

				//decline
				if (heightGap == 1) {
					check[tx] = true;
					for (int i = 1; i < l; i++) {
						int nx = tx + i;
						if (nx < 0 || nx >= n || map[y][tx] != map[y][nx] || check[nx]) {
							invalidHeightGap = true; break;
						}
						check[nx] = true;
					}
				}

				//incline
				else if (heightGap == -1) {
					check[x] = true;
					for (int i = 1; i < l; i++) {
						int nx = x - i;
						if (nx < 0 || nx >= n || map[y][x] != map[y][nx] || check[nx]) {
							invalidHeightGap = true; break;
						}
						check[nx] = true;
					}
				}
				if (invalidHeightGap) break;
			}
			if (!invalidHeightGap) {
				result++;
				//std::cout << y << '\n';
			}
		}

		//col
		std::cout << "starting col\n";
		for (int x = 0; x < n; x++) {
			bool invalidHeightGap = false, check[21] = { false, };

			for (int y = 0; y < n - 1; y++) {
				int ty = y + 1;
				int heightGap = map[y][x] - map[ty][x];

				if (!heightGap) continue;

				if (heightGap > 1 || heightGap < -1) {
					invalidHeightGap = true; break;
				}

				//decline
				else if (heightGap == 1) {
					check[ty] = true;
					for (int i = 1; i < l; i++) {
						int ny = ty + i;
						if (ny < 0 || ny >= n || map[ty][x] != map[ny][x] || check[ny]) {
							invalidHeightGap = true; break;
						}
						check[ny] = true;
					}
				}

				//incline
				else if (heightGap == -1) {
					check[y] = true;
					for (int i = 1; i < l; i++) {
						int ny = y - i;
						if (ny < 0 || ny >= n || map[y][x] != map[ny][x] || check[ny]) {
							invalidHeightGap = true; break;
						}
						check[ny] = true;
					}
				}
				if (invalidHeightGap) break;
			}
			if (!invalidHeightGap) {
				result++;
				//std::cout << x << '\n';
			}
		}

		std::cout << "#" << test_case << " " << result << '\n';
		//for (int i = 0; i < n; i++){

		//	bool possible[4];
		//	for (int a = 0; a < 4; a++) {
		//		int ty = dy[a] + i;
		//		int tx = dx[a] + i;

		//		possible[a] = true;
		//		bool invalidHeightGap = false, building = false;
		//		while (!(ty < 0 || tx < 0 || ty >= n || tx >= n) || invalidHeightGap) {
		//			int ny = dy[a] + ty;
		//			int nx = dx[a] + tx;

		//			if (map[ty][tx] - map[ny][nx] > 1 ||
		//				map[ty][tx] - map[ny][nx] < -1) {
		//				possible[a] = false; break;
		//			}

		//			//³ôÀÌ°¡ Â÷ÀÌ³ª´Â°÷
		//			if (map[ty][tx] - map[ny][nx] == 1 ||
		//				map[ty][tx] - map[ny][nx] == -1) {

		//				if (a / 2 == 0) {

		//				}
		//				else {

		//				}

		//				if (building) {
		//					possible[a] = false; break;
		//				}
		//				building = true;
		//			}
		//			else {

		//			}

		//			ty += dy[a];
		//			tx += dx[a];
		//		}



		//	}

		//	for (int a = 0; a < 4; a += 2) {
		//		if (possible[a] && possible[a + 1]) result++;
		//	}




			//std::queue < std::pair<int, int>>q;
			//q.push({ n,n });

			//while (!q.empty()) {
			//	int ty = q.front().first;
			//	int tx = q.front().second;
			//	q.pop();
			//	
			//	for (int a = 0; a < 4; a++) {
			//		int ny = dy[a] + ty;
			//		int nx = dx[a] + tx;

			//		while (!(ny < 0 || nx < 0 || ny >= n || nx >= n)) {

			//			q.push({ ny + dy[a], nx + dx[a] });

			//		}
			//	}
			//}




			//int ty = i;
			//int tx = i;

			//for (int a = 0; a < 4; a++) {
			//	int ny = dy[a] + ty;
			//	int nx = dx[a] + tx;
			//	std::cout << "C : " << ny << ", " << nx << '\n';

			//	bool invalidHeightGap = false, building = false;
			//	while (!(ny < 0 || nx < 0 || ny >= n || nx >= n)) {

			//		if (map[ny][nx] - map[ty][tx] > 1 ||
			//			map[ny][nx] - map[ty][tx] < -1) continue;

			//		if (map[ny][nx] - map[ty][tx] == 1 ||
			//			map[ny][nx] - map[ty][tx] == -1) {

			//			if (building) {
			//				invalidHeightGap = true; break;
			//			}
			//			building = true;

			//			int nny = ny;
			//			int nnx = nx;
			//			for (int b = 0; b < l; b++) {
			//				nny += dy[a];
			//				nnx += dx[a];
			//				if (nny < 0 || nnx < 0 || nny >= n || nnx >= n) break;

			//				if (map[ny][nx] != map[nny][nnx]) {
			//					invalidHeightGap = true; break;
			//				}
			//			}
			//			if (building) building = false;
			//			std::cout << "CC : " << ny << ", " << nx << '\n';

			//		}
			//		std::cout << "CCC : " << ny << ", " << nx << '\n';
			//		ny += dy[a];
			//		nx += dx[a];
			//	}

			//	if (invalidHeightGap || building) continue;
			//	result++;
			//}

	}
}

//
//int result = 0, minCount = 10000;
//int N, w, h;
//int map[15][12];
//
//int dy[] = { -1,0,1,0 };
//int dx[] = { 0,1,0,-1 };
//
//void fill5656() {
//	//fill map
//	for (int x = 0; x < w; x++) {
//		for (int y = h - 1; y >= 1; y--) {
//			for (int k = y - 1; k >= 0; k--) {
//				if (map[y][x]) break;
//				if (map[k][x]) {
//					map[y][x] = map[k][x];
//					map[k][x] = 0;
//					break;
//				}
//			}
//		}
//	}
//}
//void copy5656(int a[][12], int b[15][12]) {
//	for (int y = 0; y < h; y++)
//		for (int x = 0; x < w; x++)
//			b[y][x] = a[y][x];
//}
//
//void loop5656(int n) {
//	//map copy
//	int mapCopy[15][12];
//	memset(mapCopy, 0, sizeof(mapCopy));
//	copy5656(map, mapCopy);
//
//	if (N == n) {
//		//count bricks
//		result = 0;
//		for (int y = 0; y < h; y++) {
//			for (int x = 0; x < w; x++) {
//				if (map[y][x] != 0) result++;
//			}
//		}
//
//		if (minCount > result) minCount = result;
//		return;
//	}
//
//	for (int i = 0; i < w; i++) {
//
//		int y = 0, x = i;
//		while (y >= 0 && x >= 0 && y < h && x < w && !map[y][x])
//			y++;
//
//		//bomb bricks
//		std::queue<std::pair<int, int>> q;
//		q.push({ y,x });
//
//		while (!q.empty()) {
//			int ty = q.front().first;
//			int tx = q.front().second;
//			q.pop();
//			//cout << ty << ", " << tx << '\t';
//
//			int bombLen = map[ty][tx];
//			map[ty][tx] = 0;
//			for (int k = 0; k < bombLen; k++) {
//				for (int a = 0; a < 4; a++) {
//					int ny = dy[a] * k + ty;
//					int nx = dx[a] * k + tx;
//
//					if (ny < 0 || nx < 0 || ny >= h || nx >= w || !map[ny][nx]) continue;
//
//					q.push({ ny,nx });
//				}
//			}
//		}
//
//
//		fill5656();
//
		//cout << n << '\n';
		//for (int y = 0; y < h; y++) {
		//	for (int x = 0; x < w; x++) {
		//		std::cout << map[y][x];
		//	}cout << '\n';
		//}cout << '\n';
//
//
//		loop5656(n + 1);
//
//		copy5656(mapCopy, map);
//	}
//
//}
//void SDSbasic::sw5656()
//{
//	std::ios_base::sync_with_stdio(false);
//	std::cin.tie();
//	std::cout.tie();
//
//	int test_case, T;
//	std::cin >> T;
//
//
//	for (test_case = 1; test_case <= T; ++test_case) {
//		std::cin >> N >> w >> h;
//		minCount = 10000;
//
//		//input
//		memset(map, 0, sizeof(map));
//		for (int y = 0; y < h; y++) 
//			for (int x = 0; x < w; x++) 
//				std::cin >> map[y][x];
//
//		//Áßº¹¼ø¿­
//		loop5656(0);
//
//
//		std::cout << "#" << test_case << " " << minCount << '\n';
//	}
//}



//
//int n, k, highest = 0, result = 0;
//int map[8][8], visited[8][8];
//bool construct = false;
//int dy[] = { -1,0,1,0 };
//int dx[] = { 0,1,0,-1 };
//
//void dfs1949(int y, int x, int prev, int count, bool construct) {
//	visited[y][x] = 1;
//	if (count > result) result = count;
//
//	for (int a = 0; a < 4; a++) {
//		int ty = dy[a] + y;
//		int tx = dx[a] + x;
//
//		if (ty < 0 || tx < 0 || ty >= n || tx >= n || visited[ty][tx]) continue;
//
//		if (!construct) {
//			if (map[y][x] > map[ty][tx]) {
//				dfs1949(ty, tx, map[ty][tx], count + 1, false);
//			}
//			else if (map[y][x] > map[ty][tx] - k) {
//				dfs1949(ty, tx, map[y][x] - 1, count + 1, true);
//			}
//		}
//		else {
//			if (prev > map[ty][tx])
//				dfs1949(ty, tx, map[ty][tx], count + 1, true);
//		}
//	}
//
//	visited[y][x] = 0;
//
//}
//void SDSbasic::sw1949() {
//
//	std::ios_base::sync_with_stdio(false);
//	std::cin.tie();
//	std::cout.tie();
//
//	int test_case, T;
//	std::cin >> T;
//
//	for (test_case = 1; test_case <= T; ++test_case) {
//
//		//initialize
//		memset(map, 0, sizeof(map));
//		memset(visited, 0, sizeof(visited));
//		construct = false;
//		result = 0, highest = 0;
//
//		//input
//		std::cin >> n >> k;
//		for (int y = 0; y < n; y++) {
//			for (int x = 0; x < n; x++) {
//				std::cin >> map[y][x];
//				highest = max(highest, map[y][x]);
//			}
//		}
//
//		
//		//dfs
//		for (int y = 0; y < n; y++) {
//			for (int x = 0; x < n; x++) {
//				if (map[y][x] == highest) 
//					dfs1949(y, x, map[y][x], 1, false);
//			}
//		}
//
//
//		std::cout << "#" << test_case << " " << result << '\n';
//	}
//}

//15:00
#define INDEX 24
void SDSbasic::sw4013()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	int test_case, T;
	std::cin >> T;

	int k, result, t1, t2;
	int machine[4][8];
	//int index[4];
	std::queue<std::pair<int, int>> q;

	for (test_case = 1; test_case <= T; ++test_case) {

		//init
		k = 0, result = 0;
		memset(machine, 0, sizeof(machine));
		int index[] = { INDEX, INDEX, INDEX, INDEX };
		while (!q.empty()) q.pop();

		//input
		std::cin >> k;
		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 8; x++)
				std::cin >> machine[y][x];
		for (int i = 0; i < k; i++) {
			std::cin >> t1 >> t2;
			q.push({ t1,t2 });
		}

		while (!q.empty()) {
			int n = q.front().first - 1;
			int r = q.front().second;
			q.pop();

			int move[] = { 0,0,0,0 };
			move[n] = r;
			for (int i = 0; i < 3; i++) {
				int tn = n + i;
				//rotate clockwise rotateNeighbourClockwise(machineNum);
				if (tn >= 3 ||
					machine[tn][(index[tn] + 2) % 8] ==
					machine[tn + 1][(index[tn + 1] + 6) % 8]) break;
				if (machine[tn][(index[tn] + 2) % 8] !=
					machine[tn + 1][(index[tn + 1] + 6) % 8]) {
					if (i % 2 == 1) move[tn + 1] = r;
					else move[tn + 1] = -r;
				}
			}

			for (int i = 0; i < 3; i++) {
				int tn = n - i;
				//rotate revClockwise rotateNeighbourRevClockwise(machinNum);
				if (tn <= 0 ||
					machine[tn][(index[tn] + 6) % 8] ==
					machine[tn - 1][(index[tn - 1] + 2) % 8]) break;
				if (machine[tn][(index[tn] + 6) % 8] !=
					machine[tn - 1][(index[tn - 1] + 2) % 8]) {
					if (i % 2 == 1) move[tn - 1] = r;
					else move[tn - 1] = -r;
				}
			}

			for (int i = 0; i < 4; i++) {
				index[i] -= move[i];
				//std::cout << move[i] << ", ";
			}

			//std::cout << '\n';
			//for (int i = 0; i < 4; i++)
			//{
			//	std::cout << index[i] << ", ";
			//}
			//std::cout << '\n';

			////print
			//for (int y = 0; y < 4; y++)
			//{
			//	for (int x = 0; x < 8; x++)
			//	{
			//		std::cout << machine[y][(index[y] + x) % 8] << " ";
			//	}
			//	std::cout << '\n';
			//}
			//std::cout << '\n';

		}


		for (int i = 0; i < 4; i++) {
			if (machine[i][index[i] % 8]) result += pow(2, i);
			//std::cout << machine[i][index[i] % 8] << " ";
		}
		std::cout << "#" << test_case << " " << result << '\n';
	}
}

struct virus {
	int x;
	int y;
	int amount;
	int dir;
};

void SDSbasic::sw2382()
{

	std::ios_base::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	//0»óÇÏÁÂ¿ì
	int dy[] = { 0,-1,1,0,0 };
	int dx[] = { 0,0,0,-1,1 };

	int test_case, T;
	std::cin >> T;

	int n, m, k, t1, t2, t3, t4, result;
	int map[101][101];
	//std::queue<std::pair<int, int>> qMap;

	for (test_case = 1; test_case <= T; ++test_case) {

		//init	
		std::queue<std::pair<int, int>> q[101][101];


		//input
		std::cin >> n >> m >> k;
		for (int i = 0; i < k; i++) {
			std::cin >> t1 >> t2 >> t3 >> t4;
			q[t1][t2].push({ t3,t4 });
		}

		//solve
		for (int time = 0; time < m; time++) {

			//init
			memset(map, 0, sizeof(map));
			result = 0;

			//check where is virus
			for (int y = 0; y < n; y++) {
				for (int x = 0; x < n; x++) {
					if (q[y][x].empty()) continue;
					for (int i = 0; i < q[y][x].size(); i++)
						map[y][x]++;
				}
			}

			for (int y = 0; y < n; y++) {
				for (int x = 0; x < n; x++) {
					if (!map[y][x]) continue;

					int amountLarge = 0, amountSum = 0, dirLarge = 0;
					int amount, dir, ty, tx;

					int size = map[y][x];
					for (int s = 0; s < size; s++) {
						int amount = q[y][x].front().first;
						int dir = q[y][x].front().second;
						q[y][x].pop();

						//std::cout << "C :" << y << ", " << x << ", " << amount << '\n';

						amountSum += amount;
						if (amountLarge < amount) {
							amountLarge = amount;
							dirLarge = dir;
						}
					}

					ty = dy[dirLarge] + y;
					tx = dx[dirLarge] + x;

					//check
					if (ty == 0 || tx == 0 || ty == n - 1 || tx == n - 1) {
						//std::cout << "die bitch!!" << '\n';
						amountSum /= 2;
						if (dirLarge % 2 == 0) dirLarge--;
						else dirLarge++;
					}

					q[ty][tx].push({ amountSum, dirLarge });

					result += amountSum;

				}
			}
			//std::cout << result << '\t';
		}
		//output result
		std::cout << "#" << test_case << " " << result << '\n';
	}
}

void SDSbasic::sw2383()
{

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int test_case, T;
	std::cin >> T;

	int n, map[10][10], visit[10][10];
	int len[10][2];

	for (test_case = 1; test_case <= T; ++test_case) {
		int result = 0;

		//init
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		memset(len, 0, sizeof(len));
		std::vector<std::pair<int, int>> qP;
		std::vector<std::pair<int, int>> qS;

		//input
		std::cin >> n;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				std::cin >> map[y][x];
				if (map[y][x] == 1) qP.push_back({ y,x });
				else if (map[y][x] > 1) qS.push_back({ y, x });
			}
		}

		//solve
		int qSsize = qS.size();
		int qPsize = qP.size();

		//len between ppl and 
		for (int s = 0; s < qSsize; s++) {
			int y = qS.at(s).first;
			int x = qS.at(s).second;

			for (int p = 0; p < qPsize; p++) {
				int py = qP.at(p).first;
				int px = qP.at(p).second;

				len[p][s] = abs(py - y) + abs(px - x);
			}
		}

		for (int s = 0; s < qSsize; s++) {
			for (int p = 0; p < qPsize; p++) {


			}
		}

		std::cout << "#" << test_case << " " << result << '\n';
	}
}

//19:08 ~ 21:33
void SDSbasic::sw2117()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int test_case, T;
	std::cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int result = 0, count = 0, cost = 0, temp = 0;
		int n, m;
		int map[20][20];
		std::vector<std::pair<int, int>> v;
		int visited[20][20];

		//init
		memset(map, 0, sizeof(map));
		v.clear();
		memset(visited, 0, sizeof(visited));

		//input
		std::cin >> n >> m;
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				std::cin >> map[y][x];
				if (map[y][x]) v.push_back({ y,x });
			}
		}
		int dy[] = { -1,0,1,0 };
		int dx[] = { 0,1,0,-1 };

		//int size = v.size();
		//for (int i = 0; i < size; i++) {
		//int y = v.at(i).first;
		//int x = v.at(i).second;

		//k*k (k-1)*(k-1)
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				memset(visited, 0, sizeof(visited));
				visited[y][x] = 1;

				count = 0;
				if (map[y][x]) count++;

				std::queue<std::pair<int, int>> q;
				q.push({ y,x });

				while (!q.empty()) {
					int ty = q.front().first;
					int tx = q.front().second;
					q.pop();

					int b = visited[ty][tx];
					cost = b * b + (b - 1)*(b - 1);
					temp = 0;

					for (int a = 0; a < 4; a++) {
						int ny = dy[a] + ty;
						int nx = dx[a] + tx;

						if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;

						q.push({ ny,nx });
						visited[ny][nx] = visited[ty][tx] + 1;
						if (map[ny][nx]) count++;
					}

					if (temp < count * m - cost)
						temp = count * m - cost;
					else if (temp > count * m - cost)
						break;
				}

				if (y == 3 && x == 3) {
					for (int y = 0; y < n; y++)
					{
						for (int x = 0; x < n; x++)
						{
							cout << visited[y][x];
						}
						cout << '\n';
					}
					cout << '\n';
				}




			}
			//visited[y][x] = count;
			//cout << count << '\n';
			//std::cout << y << ", " << x << ", maxTemp : " << temp << '\n';

			//count *= m;

		//if (result < count) result = count;
			if (result < temp) result = temp;

		}


		std::cout << "#" << test_case << " " << result << '\n';
	}
}

//21:33

std::queue<std::pair<int, int>> q17070;
int map17070[16][16];
int result17070 = 0;
int dy[] = { 0,1,1 };
int dx[] = { 1,1,0 };
bool way[][3] = { {true, true, false },
				{true, true, true},
				{false, true, true} };

void bfs17070(int y, int x, int n, int num) {

	std::cout << "visiting : " << y << ", " << x << ", " << num << '\n';
	if (y == n - 1 && x == n - 1) {
		cout << "FUCK\n";
		result17070++;
		return;
	}

	for (int a = 0; a < 3; a++) {
		if (way[num][a]) {
			int ny = y + dy[a];
			int nx = x + dx[a];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n || map17070[ny][nx]) continue;
			if (a == 1 && (map17070[ny][nx - 1] || map17070[ny - 1][nx])) continue;
			bfs17070(ny, nx, n, a);
			cout << ny << ", " << nx << " out \n";
			//std::cout << "going : " << y << ", " << x << " >> "  << ny << ", " << nx << '\n';

		}
	}
	//std::cout << "visiting : " << y << ", " << x << '\n';

}
void SDSbasic::q17070()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	std::cin >> n;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			std::cin >> map17070[y][x];
		}
	}

	bfs17070(0, 1, n, 0);



	std::cout << result17070;
}

void SDSbasic::q17136()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int paperSize = 10;
	int map[10][10], visited[10][10];
	int paper[5];
	int result = 0;

	for (int y = 0; y < paperSize; y++)
		for (int x = 0; x < paperSize; x++)
			std::cin >> map[y][x];

	bool invalidPaper = 0;
	int paperCount = 0;
	memset(visited, 0, sizeof(visited));
	memset(paper, 0, sizeof(paper));

	for (int y = 0; y < paperSize; y++) {
		for (int x = 0; x < paperSize; x++) {
			if (!map[y][x] && visited[y][x]) continue;

			visited[y][x] = 1;
			invalidPaper = false;
			paperCount = 1;
			/*
			11 10 01
			22 20 02 21 12
			33 30 03 31 13 32 23
			*/

			for (int i = 1; i < 6; i++) {
				int ty = y + i;
				int tx = x + i;
				if (ty >= paperSize || tx >= paperSize || visited[ty][tx]) invalidPaper = true;

				if (map[ty][tx]) {
					visited[ty][tx] = 1;
					paperCount++;
				}
				else invalidPaper = true;

				for (int b = 0; b < i; b++) {
					if (map[ty][x + b]) {
						visited[ty][x + b] = 1;
						paperCount++;
					}
					else invalidPaper = true;

					if (map[y + b][tx]) {
						visited[y + b][tx] = 1;
						paperCount++;
					}
					else invalidPaper = true;

				}
				if (invalidPaper) break;
			}

			if (paperCount == 25) paper[4]++;
			else if (paperCount == 16) paper[3]++;
			else if (paperCount == 9) paper[2]++;
			else if (paperCount == 4) paper[1]++;
			else paper[0] += paperCount;
		}
	}
	if (paper[0] > 5 || paper[1] > 5 || paper[2] > 5 || paper[3] > 5 || paper[4] > 5) result = -1;
	else {
		for (int i = 0; i < 5; i++) result += paper[i];
	}
	std::cout << result;

}

int minNum(int a, int b) { if (a < b) return a; return b; }
int maxNum(int a, int b) { if (a > b) return a; return b; }
void SDSbasic::q17135()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, m, d, result = 0;
	std::cin >> n >> m >> d;

	int map[15][15];
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			std::cin >> map[y][x];
		}
	}

	int copy[15][15], visited[15][15];
	for (int a = 0; a < 3; a++) {
		for (int b = a + 1; b < 4; b++) {
			for (int c = b + 1; c < 5; c++) {

				int kill = 0, archerPos[3] = { a,b,c };
				//copy
				int archer = n;
				memset(visited, 0, sizeof(visited));
				memset(copy, 0, sizeof(copy));
				for (int i = 0; i < n; i++)
					for (int j = 0; j < m; j++)
						copy[i][j] = map[i][j];

				cout << a << ", " << b << ", " << c << '\n';

				//time
				while (archer) {
					int killPoint = 0;
					int ty[3] = { 0, }, tx[3] = { 0, };

					for (int y = 1; y <= d; y++) {
						for (int x = 0; x < d; x++) {

							for (int arc = 0; arc < 3; arc++) {
								if (y + x > d || archer < y || archerPos[arc] + x >= m || archerPos[arc] - x < 0) continue;

								if (ty[arc] > 0 && tx[arc] > 0) continue;
								if (copy[archer - y][archerPos[arc] - x]) {
									//copy[archer - y][archerPos[arc] - x] = 0;
									ty[arc] = archer - y;
									tx[arc] = archerPos[arc] - x;
									kill++;
									killPoint++;
									visited[ty[arc]][tx[arc]] = 1;
									std::cout << "KILL : " << ty[arc] << ", " << tx[arc] << '\n';
									continue;
								}
								else if (copy[archer - y][archerPos[arc] + x]) {
									//copy[archer - y][archerPos[arc] + x] = 0;
									visited[ty[arc]][tx[arc]] = 1;
									tx[arc] = archer - y;
									tx[arc] = archerPos[arc] + x;
									kill++;
									killPoint++;
									std::cout << "KILL : " << ty[arc] << ", " << tx[arc] << '\n';
									continue;
								}
							}
							if (killPoint == 3) break;
						}
						if (killPoint == 3) break;
					}

					//kill
					for (int arc = 0; arc < 3; arc++) {
						/*cout << ty[arc] << ", " << tx[arc] << '\n';*/
						//if(ty[arc] > 0 && tx[arc] > 0)
						copy[ty[arc]][tx[arc]] = 0;
						if (!arc) continue;
						if (ty[arc] == ty[arc - 1] && tx[arc] == tx[arc - 1]) kill--;
					}

					std::cout << "archer Pos : " << archer << ", " << kill << '\n';
					for (int y = 0; y < n; y++) {
						for (int x = 0; x < m; x++) {
							std::cout << copy[y][x];
						}
						cout << '\n';
					}
					cout << '\n';

					archer--;
				}

				//memset(copy, 0, sizeof(copy));
				result = maxNum(result, kill);


			}
		}
	}

	std::cout << result;
}

void SDSbasic::q14502()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	//1º®, 2¹ÙÀÌ·¯½º
	int n, m, result;
	std::cin >> n >> m;
	int map[8][8], visited[8][8];
	std::vector<std::pair<int, int>> v, empty;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			std::cin >> map[y][x];
			if (map[y][x] == 2) v.push_back({ y,x });
			else if (map[y][x] == 0) empty.push_back({ y,x });
		}
	}

	int dy[] = { -1,0,1,0 };
	int dx[] = { 0,1,0,-1 };
	int pollution = 0, minPollution = n * m;

	int emptySize = empty.size();
	for (int i = 0; i < emptySize - 2; i++) {
		for (int j = i + 1; j < emptySize - 1; j++) {
			for (int k = j + 1; k < emptySize; k++) {
				map[empty[i].first][empty[i].second] = 1;
				map[empty[j].first][empty[j].second] = 1;
				map[empty[k].first][empty[k].second] = 1;

				pollution = 0;
				memset(visited, 0, sizeof(visited));

				//bfs
				int size = v.size();
				for (int s = 0; s < size; s++) {

					if (visited[v.at(s).first][v.at(s).second]) continue;


					std::queue<std::pair<int, int>> q;
					q.push({ v.at(s).first , v.at(s).second });
					visited[v.at(s).first][v.at(s).second] = 1;

					while (!q.empty()) {
						int ty = q.front().first;
						int tx = q.front().second;
						q.pop();

						for (int a = 0; a < 4; a++) {
							int ny = dy[a] + ty;
							int nx = dx[a] + tx;
							if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || map[ny][nx] == 1) continue;

							visited[ny][nx] = ++pollution;
							if (map[ny][nx] == 2) pollution--;
							q.push({ ny,nx });

						}

					}

					if (minPollution < pollution) break;

				}

				if (minPollution > pollution) {
					minPollution = pollution;
					//for (int y = 0; y < n; y++)
					//{
					//	for (int x = 0; x < m; x++)
					//	{
					//		std::cout << map[y][x];
					//	}
					//	std::cout << '\n';
					//}
					//std::cout << '\n';
				}

				map[empty[i].first][empty[i].second] = 0;
				map[empty[j].first][empty[j].second] = 0;
				map[empty[k].first][empty[k].second] = 0;

				//for (int y = 0; y < n; y++)
				//{
				//	for (int x = 0; x < m; x++)
				//	{
				//		std::cout << visited[y][x];
				//	}
				//	std::cout << '\n';
				//}
				//std::cout << '\n';

			}
		}
	}

	result = empty.size() - minPollution - 3;
	std::cout << result;
}

int dist15868(std::pair<int, int> p1, std::pair<int, int> p2)
{
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void SDSbasic::q15686()
{

	//std::ios_base::sync_with_stdio(false);
	//std::cin.tie(NULL);

	////0ºóÄ­, 1Áý, 2¯ƒ¯ƒ
	//int n, m, result = 987654321;
	//std::cin >> n >> m;
	//int map[50][50];
	//std::vector<std::pair<int, int>> house, chic;
	//for (int y = 0; y < n; y++){
	//	for (int x = 0; x < n; x++){
	//		std::cin >> map[y][x];
	//		if (map[y][x] == 1) house.push_back({ y,x });
	//		else if (map[y][x] == 2) chic.push_back({ y,x });
	//	}
	//}

	//int ind[13];
	//std::vector<int> perm;
	//for (int i = 0; i < m; i++) perm.push_back(i);
	//for (int i = m; i < chic.size(); i++) perm.push_back(m+1);


	//do {
	//	int index = 0;
	//		for (int i = 0; i < perm.size(); i++) {
	//			if (perm[i] < m ) {
	//				ind[index++] = i;
	//			}
	//		}

	//	//dist
	//	int sumLen = 0;
	//	for (int h = 0; h < house.size(); h++) {
	//		int len = 0, minLen = 2600;
	//		for (int c = 0; c < m; c++){
	//				len = dist15868(house[h], chic[ind[c]]);
	//				if (minLen > len) minLen = len;
	//		}

	//		sumLen += minLen;
	//	}

	//	if (result > sumLen) {
	//		result = sumLen;
	//		//std::cout << "perm : ";
	//		//for (int i = 0; i < perm.size(); i++){
	//		//	std::cout << perm[i] << " ";
	//		//}
	//		//std::cout << '\n';
	//	}

	//} while (next_permutation(perm.begin(), perm.end()));

	//std::cout << result;


}

void SDSbasic::swMagnetic()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int test_case, T = 10;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n, result = 0;
		std::cin >> n;

		int map[101][101];
		memset(map, 0, sizeof(map));
		std::vector<int> v[101];

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				std::cin >> map[y][x];
				if (map[y][x])
					v[x].push_back(map[y][x]);
			}
		}

		for (int i = 0; i < n; i++) {
			bool validN = false;

			int size = v[i].size();
			if (size == 1) continue;

			for (int a = 0; a < size; a++) {
				if (a == 0 && v[i][a] == 2) continue;
				if (a == size - 1 && v[i][a] == 1) continue;

				if (v[i][a] == 1) {	//N go down
					validN = true;
				}
				else if (v[i][a] == 2) {	//S go up
					if (validN) {
						validN = false;
						result++;
					}
					else if (!validN) continue;
				}
			}
		}
		std::cout << "#" << test_case << " " << result << '\n';
	}

}


int N, B;
int res;

int man[21];

void solve1(int count, int height) {
	if (res == B) {
		return;
	}
	if (height >= B) {
		if (res > height) {
			res = height;
		}
	}
	else if (count == N) {
	}
	else {
		solve1(count + 1, height);
		solve1(count + 1, height + man[count]);
	}
}

void SDSbasic::swHighShelf() {
	//int T;
	//cin >> T;
	//for (int test_case = 1; test_case <= T; ++test_case) {
	//	cin >> N >> B;
	//	for (int i = 0; i < N; ++i) {
	//		cin >> man[i];
	//	}

	//	res = B + 987654321;

	//	solve1(0, 0);

	//	cout << "#" << test_case << " " << res - B << "\n";
	//}

	//	return 0;

	int n = 2;

	//string a = "az AZ";
	//char res[20];
	//strcpy(res, a.c_str());
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << res[i]-0 << ", ";
	//}
	//cout << endl;
	//res[0] = res[0] + n;
	//res[1] = res[1] + n;
	//res[2] = res[2] + n;
	//res[3] = res[3] + n;
	//res[4] = res[4] + n;

	//string ss = "";
	//ss = res;
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << res[i] << ", ";
	//}

	// az : 97 ~ 122
	// AZ : 65 ~ 90

//	string s = "AZ az a B z";
//	char res[8001];
//	strcpy(res, s.c_str());
//	for (int i = 0; i < 5; i++)
//{
//	cout << res[i]-0<< ", ";
//	}cout << endl;
//
//	for (int i = 0; i < s.length(); i++) {
//		if (res[i] == ' ') continue;
//
//		if (res[i] > 96) {
//			if (res[i] + n > 122) res[i] -= 26;
//		}
//		else if (res[i] <= 90) {
//			if (res[i] + n > 90) res[i] -= 26;
//		}
//		res[i] += n;
//	}
//	s = res;
//
//	for (int i = 0; i < 5; i++)
//	{
//		cout << res[i]-0 << ", ";
//	}
//




	//vector<int> s;
	//s.push_back(11);
	//s.push_back(12);
	//s.push_back(13);
	//s.push_back(13);
	//
	//cout << s.size() << endl;
	//
	//vector<int>::iterator it;
	//it = s.begin();
	//s.erase(it);
	//cout << s.size();




	//string s = "aabbaccc";

	//string result;
	//int index, count, resultLength;
	//int sLength = s.length();
	//int minLength = sLength;

	//for (int len = 1; len <= sLength / 2; len++) {

	//	cout << "LEN : " << len << endl;
	//	resultLength = sLength;
	//	index = 0;

	//	while( index < sLength - 1){
	//		count = 0;

	//		if (len != 1 && s.substr(index, len) != s.substr(index + len, len)) break;
	//		if (index + len >= sLength) break;


	//		while (index + len < sLength) {
	//			if (s.substr(index, len) == s.substr(index + len, len)) {

	//				cout << index << " ," << s.substr(index, len) << ", " << s.substr(index + len, len) << endl;
	//				index += len;

	//				++count;

	//			}
	//			else {
	//				index += len;
	//				break;
	//			}
	//		}

	//		cout << s.substr(index) << endl;
	//		if (count) {
	//			resultLength = resultLength - (len * count);
	//			resultLength = resultLength + to_string(count).length();
	//			
	//		}
	//		if (resultLength != 0 && minLength > resultLength)
	//			minLength = resultLength;

	//	}

	//	cout << minLength << endl;
	//	//return minLength;
	//}



//string p = "(()())()";
//	string answer = "";
//	int leftRight[2] = { 0,0 };
//	int sLength = p.length();
//	int change = 0;
//	//if (sLength != 0) return answer;
//
//	for (int i = 0; i < sLength ; i++) {
//		if (p[i] == '(') {
//			leftRight[0]++;
//		}
//		else {
//			leftRight[1]++;
//		}
//	
//		if (leftRight[0] >= leftRight[1] && change < 1) {
//			//answer += p[i];
//			answer.insert(answer.end(), p[i]);
//		}
//		else {
//			if (change > 0 && p[i] == '(') {
//				answer += ')';
//				change--;
//			}
//			else {
//				answer += "(";
//				change++;
//			}
//		}
//	}
//
//	cout << answer << endl;



/*
1,0		2,1		2,2
È¸Àü
0,1		1,0		2,0

1 2		0 1		0 0

2 1		1 2		0 2

0 0 0
1 0 0
0 1 1

1 1 1
1 1 0
1 0 1
*/

//
//vector<vector<int>> key, vector<vector<int>> lock;
//vector<pair<int, int>> v;
//vector<pair<int, int>> vLen;
//
//vector<pair<int, int>> vLock;
//vector<pair<int, int>> vLockLen;
//
//for (int y = 0; y < key.size(); y++)
//{
//	for (int x = 0; x < key.size(); x++)
//	{
//		if (key[y][x]) v.push_back({ y,x });
//	}
//}
//
//int vSize = v.size();
//for (int i = 0; i < vSize; i++)
//{
//	for (int  j = i+1; j < vSize; j++)
//	{
//		int ty = abs(v[i].first - v[j].first);
//		int tx = abs(v[i].second - v[j].second);
//		v.push_back({ ty,tx });
//	}
//}
//
//
//
//for (int y = 0; y < lock.size(); y++)
//{
//	for (int x = 0; x < lock.size(); x++)
//	{
//		if (!lock[y][x]) vLock.push_back({ y,x });
//	}
//}
//
//int vLockSize = v.size();
//for (int i = 0; i < vLockSize; i++)
//{
//	for (int j = i + 1; j < vLockSize; j++)
//	{
//		int ty = abs(v[i].first - v[j].first);
//		int tx = abs(v[i].second - v[j].second);
//		vLockLen.push_back({ ty,tx });
//	}
//}
//
//bool keyToLock = false;
//for (int l = 0; l < vLockLen.size(); l++)
//{
//	
//	for (int k = 0; k < vLen.size(); k++)
//	{
//		keyToLock = false;
//		if (vLockLen[l].first == vLen[k].first &&
//			vLockLen[l].second == vLen[k].second) {
//			keyToLock = true;
//			break;
//		}
//	}
//}
//return keyToLock;



	//vector<string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
	//vector<string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" };
	//vector<int> answer;
	///*
	//["frodo", "front", "frost", "frozen", "frame", "kakao"]
	//["fro??", "????o", "fr???", "fro???", "pro?"]
	//[3, 2, 4, 1, 0]
	//*/

	//bool first;
	////Äõ¸® ºÎÅÍ
	//for (int q = 0; q < queries.size(); q++)
	//{
	//	answer.push_back(0);
	//	string str = "";
	//	int mid = 0;
	//	//¹°À½Ç¥½ÃÀÛÀÎÁö
	//	if (queries[q][0] == '?') first = true;
	//	else first = false;

	//	//¹°À½Ç¥ ½ÃÀÛÀÌ¸é
	//	if (first) {
	//		//binary search
	//		int start = 0, end = queries[q].size() - 1;
	//		while (start <= end) {
	//			mid = (start + end) / 2;

	//			if (queries[q][mid] == '?') {
	//				start = mid + 1;
	//			}
	//			else {
	//				end = mid - 1;
	//			}
	//		}

	//		str = queries[q].substr(mid);

	//		//str = queries[q].substr(queries[q].find_last_of('?') + 1);
	//		cout << mid << " ," << str << endl;
	//	}
	//	
	//	//³¡ÀÌ ¹°À½Ç¥¸é
	//	else {
	//		
	//		//binary search
	//		int start = 0, end = queries[q].size() - 1;
	//		while (start <= end) {
	//			mid = (start + end) / 2;

	//			if (queries[q][mid] == '?') {
	//				end = mid - 1;
	//			}
	//			else {
	//				start = mid + 1;
	//			}
	//		}

	//		str = queries[q].substr(0, mid );
	//		
	//		//str = queries[q].substr(0, queries[q].find('?'));
	//		cout << mid << " ," <<   str << endl;
	//	}

	//	//´Ü¾î ºñ±³
	//	for (int w = 0; w < words.size(); w++)
	//	{
	//		if (words[w].length() != queries[q].length()) continue;
	//		
	//		if (first){
	//			//str = queries[q].substr(queries[q].find_last_of('?') + 1);
	//			if(str == words[w].substr(mid)) {
	//				answer[q]++;
	//			}
	//		}
	//		else {
	//			//str = queries[q].substr(0, queries[q].find('?'));
	//			if (str == words[w].substr(0, mid)) {
	//				answer[q]++;
	//			}
	//		}
	//	}
	//}

	//for (auto i : answer) {
	//	cout << i << endl;
	//}





//int n;
vector<vector<int>> build_frame;
vector<vector<int>> answer;
vector<vector<int>> eraseanswer;

int map[101][101];
for (int xx = 0; xx < build_frame.size(); xx++)
{
	vector<int> v;
	int x = build_frame[x][0];
	int y = build_frame[x][1];
	int a = build_frame[x][2];
	int b = build_frame[x][3];

	//¼³Ä¡
	if (b) {
		map[x][y] = 1;
		//º¸
		if (a) {
			map[x + 1][y] = 1;
		}
		//±âµÕ
		else {
			map[x][y + 1] = 1;
		}
		answer.push_back({ x,y,a });
	}
	//»èÁ¦
	else {
		//º¸
		if (a) {
			//º¸ ÀÖÀ¸¸é
			if (map[x + 1][y]) {
				bool deconstruct = true;
				for (int height = y; y >= 0; y--) {
					if (!map[x + 1][height]) {
						deconstruct = false;
						break;
					}
				}
				if (deconstruct)	eraseanswer.push_back({ x,y,a });
			}
		}
		//±âµÕ
		else {
			//±âµÕ ÀÖÀ¸¸é
			if (map[x][y + 1]) {

			}
		}
	}
}
vector<vector<int>>::iterator it;
for (int ans = 0; ans < answer.size();ans++) {

	for (int era = 0; era < eraseanswer.size(); era++) {


		if(answer[ans][0] == eraseanswer[era][0] && answer[ans][1] == eraseanswer[era][1] && answer[ans][2] == eraseanswer[era][2]){
			answer.erase(it + ans);
				break;
		}
	}
}
/*
	bool build = false;

	//¼³Ä¡
	if (b) {
		if (y == 0 || map[x][y]) {
			build = true;

			//º¸
			if (a) {

			}
			//±âµÕ
			else {

			}
		}
	}
	//»èÁ¦
	else {

	}
*/

sort(answer.begin(), answer.end());
sort(answer.begin(), answer.end(), [](const vector<int> v1, const vector<int> v2) {
	if (v1[0] == v2[0])
		return v1[1] < v2[1];
	else return v1[0] < v2[0];
});
	/*


		std::ios_base::sync_with_stdio(false);
		std::cin.tie(NULL);
		std::cout.tie(NULL);

		int test_case, T;
		std::cin>>T;

		for(test_case = 1; test_case <= T; ++test_case) {
			int result = 0;


			std::cout << "#" << test_case << " " << result << '\n';
		}


	*/
}