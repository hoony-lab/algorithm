#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string pos){
    int dx[] = {1,1,-1,-1,2,2,-2,-2};//{1, 2, 2, 1,-1,-2, -2, -1};
    int dy[] = {2,-2,-2,2,1,-1,-1,1};//{2, 1,-1,-2,-2,-1, 1, 2};
    int cx = pos[0] - 'A';
    int cy = pos[1] - '0' - 1;
    int ans = 0;
    for(int i = 0; i < 8; ++i){
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if(nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
            ans++;
    }
    return ans;
}