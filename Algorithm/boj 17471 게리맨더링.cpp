#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int n, people[11], connect[11][11], ans = 987654321;
vector<int> region[2];

void compareRegion() {
    bool inRegion[2][11]; //각 선거구 내의 지역을 T로 표시 
    bool visited[2][11]; //방문여부 -> 관계 검사가 끝났을 때 F라면 연결되지 않는 지역인다. 

    memset(inRegion, false, sizeof(inRegion));
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < region[i].size(); j++) {
            inRegion[i][region[i][j]] = true; //지정된 선거구 내의 지역들을 T로 표시 
        }
    }

    int countPeople[2];
    countPeople[0] = countPeople[1] = 0;

    for (int i = 0; i < 2; i++) {
        if (region[i].size() == 1)
        {
            //선거구 내의 지역이 1개이면 인구수는 그 지역의 인구수이다. 
            countPeople[i] = people[region[i][0]];
            continue;
        }

        //연결 검사 
        queue<int> q;

        q.push(region[i][0]);
        visited[i][region[i][0]] = true;

        while (!q.empty()) {
            int now = q.front();
            q.pop();

            for (int j = 0; j < n; j++) {
                //연결된 지역을 확인 (같은 선거구 내에 있는)
                if (connect[now][j] && inRegion[i][j] && !visited[i][j]) {
                    visited[i][j] = true;
                    q.push(j);
                }
            }
        }

        //인구수 구하기 
        for (int j = 0; j < region[i].size(); j++) {
            if (!visited[i][region[i][j]]) return; //연결되지 않는 지역들 
            countPeople[i] += people[region[i][j]];
        }
    }
    int res = abs(countPeople[0] - countPeople[1]);
    if (ans > res) ans = res;
}

void dfs(int cnt) {
    if (cnt == n) {
        //n개의 지역을 모두 나눔 
        if (region[0].size() > 0 && region[1].size() > 0) {
            compareRegion();
        }
        return;
    }

    for (int i = 0; i < 2; i++)
    {
        region[i].push_back(cnt);
        dfs(cnt + 1);
        region[i].pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> people[i]; //인구수 
    }

    for (int i = 0; i < n; i++) {
        int tmp; //연결 수 
        cin >> tmp;

        for (int j = 0; j < tmp; j++) {
            int b;
            cin >> b;

            connect[i][b - 1] = 1;
            connect[b - 1][i] = 1;
        }
    }

    //각 선거구로 지역을 나눈다. 
    dfs(0);

    if (ans == 987654321) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}