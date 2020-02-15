#include <string>
#include <vector>

using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}

int solution(vector<vector<int>> grid) {
    int answer = 0;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            for(int k = j + 1; k < 4; k += 2)
                answer = max(answer, max(grid[i][j] + grid[i][k], grid[j][i] + grid[k][i]));
    return answer;
}