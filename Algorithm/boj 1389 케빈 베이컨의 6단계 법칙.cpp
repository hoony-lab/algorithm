#include <iostream>
#include <queue>
int visited[102][102];
int friends[102][102];
//std::vector <std::vector<int>> v;

int main() {
    int n, m, a, b;
	std::cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		std::cin >> a >> b;
		friends[a][b] = friends[b][a] = 1;
	}

	int ans = 0, min = 1e10;
	std::queue<int> q;
	for (int start = 1; start <= n; ++start) {

		q.push(start);
		visited[start][start] = true;

		int temp = 0;

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int end = 1; end <= n; ++end) {
				if (friends[now][end] == 1 && !visited[start][end]) {

					q.push(end);
					friends[start][end] = friends[start][now] + friends[now][end];

					visited[start][end] = true;

					temp += friends[start][end];
				}
			}
		}

		if (temp < min) {
			min = temp;
			ans = start;
		}
	}
	std::cout << ans;

	return 0;
}



/*

#include<iostream>
#include<queue>
using namespace std;

int n, m, f[101][101], check[101][101];

int main(void){
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        f[a][b] = f[b][a] = 1;
    }

    int min = 987654321, ans = 0;
    queue<int> q;
    for (int i = 1; i < n + 1; i++){
        q.push(i);
        check[i][i] = true;

        int temp = 0;
        while (!q.empty()){
            int now = q.front();
            q.pop();

            for (int j = 1; j < n + 1; j++){
                if (!check[i][j] && f[now][j] == 1){
                    q.push(j);
                    f[i][j] = f[i][now] + f[now][j];
                    check[i][j] = true;
                    temp += f[i][j];
                }
            }
        }

        if (temp < min){
            min = temp;
            ans = i;
        }
    }
    cout << ans << "\n";
    return 0;
}
https://barefoot-coder.tistory.com/36
*/