#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int solution(vector<string> bishops) {
    int dx[] = {1,1,-1,-1};
    int dy[] = {1,-1,1,-1};
    int board[9][9] = {0};
    queue<pair< pair<int, int>, int> > q;
    for(int i = 0; i < bishops.size(); i++){
        int x = bishops[i][0] - 'A' + 1;
        int y = bishops[i][1] - '0';
        board[y][x] = 1;
        for(int j = 0; j < 4; j++)
            q.push({{y,x}, j});
    }
    while(!q.empty()){
        int cur_y = q.front().first.first;
        int cur_x = q.front().first.second;
        int dir = q.front().second;
        q.pop();
        int next_x = cur_x + dx[dir];
        int next_y = cur_y + dy[dir];
        if(next_x >= 1 && next_x <= 8 && next_y >= 1 && next_y <= 8){
            board[next_y][next_x] = 1;
            q.push({{next_y, next_x}, dir});
        }
    }
    int cnt = 0;
    for(int i = 1; i <= 8; i++)
        for(int j = 1; j <= 8; j++)
            cnt += board[i][j];
    return 64 - cnt;
}