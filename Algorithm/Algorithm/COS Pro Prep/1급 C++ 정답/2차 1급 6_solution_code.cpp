#include <string>
#include <vector>

using namespace std;

vector<int> solution(string commands) {
    vector<int> currentPosition = {0, 0};
    for(int i = 0; i < commands.length(); ++i){
        if (commands[i] == 'L')
            currentPosition[0] -= 1;
        else if(commands[i] == 'R')
            currentPosition[0] += 1;
        else if(commands[i] == 'U')
            currentPosition[1] += 1;
        else if(commands[i] == 'D')
            currentPosition[1] -= 1;
    }
    return currentPosition;
}