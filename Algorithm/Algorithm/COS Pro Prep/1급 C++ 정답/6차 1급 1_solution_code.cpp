#include <string>
#include <vector>
#include <queue>

using namespace std;

class Flower {
    public:
    int x, y, day;
    
    Flower(int x, int y, int day) {
        this->x = x;
        this->y = y;
        this->day = day;
    }
};

int solution(int n, vector<vector<int>> garden) {
    int answer = 0;
    
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    
    queue<Flower> q;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(garden[i][j])
                q.push(Flower(i, j, 0));
        }
    }
    
    while(!q.empty()) {
        Flower flower = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int next_x = flower.x + dx[i];
            int next_y = flower.y + dy[i];
            int next_day = flower.day + 1;
            
            if((0 <= next_x && next_x < n && 0 <= next_y && next_y < n) && !garden[next_x][next_y]) {
                garden[next_x][next_y] = 1;
                answer = next_day;
                q.push(Flower(next_x, next_y, next_day));
            }
        }
        
    }
    
    return answer;
}