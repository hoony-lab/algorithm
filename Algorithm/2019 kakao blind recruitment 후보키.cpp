#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <bitset>
using namespace std;
#define RMAX 20

vector<vector<string>> r;
int xmax, ymax, loop, answer;
bitset <RMAX> bits;
set<string> s[RMAX];
bool possible_candidate[RMAX];

void dfs(int cnt, bool visit[]) {
 
    if (cnt == 0) {
        bitset<RMAX> b;
        
        set<string> check;
        for (int x = 0; x < xmax; ++x) {

            string tmp;
            for (int y = 0; y < ymax; ++y)
                if(visit[y]) tmp += r[x][y];

            check.insert(tmp);
        }

        if (check.size() == xmax)
            answer++;

        return;
    }

    for (int y = 0; y < ymax; ++y) {
        if (!possible_candidate[y] || visit[y]) continue;
        visit[y] = true;
        dfs(cnt - 1, visit);
        visit[y] = false;
    }
}

int solution(vector<vector<string>> relation) {
    
    r = relation;
    xmax = relation.size();
    ymax = relation[0].size();

    for (int y = 0; y < ymax; ++y) {
        for (int x = 0; x < xmax; ++x)
            s[y].insert(relation[x][y]);
        
        if (s[y].size() != xmax)
            possible_candidate[y] = true, loop++;
        else answer++;
    }

    for (int cnt = 2; cnt <= loop; ++cnt) {
        bool visit[RMAX]{};
        dfs(cnt, visit);
    }

    return answer;
}

int main() {

    vector<vector<string>> relation = {
        {"100", "ryan", "music", "2"},
        {"200", "apeach", "math", "2"},
        {"300", "tube", "computer", "3"},
        {"400", "con", "computer", "4"},
        {"500", "muzi", "music", "3"},
        {"600", "apeach", "music", "2"}};

    cout << solution(relation);     // 2

    return 0;
}