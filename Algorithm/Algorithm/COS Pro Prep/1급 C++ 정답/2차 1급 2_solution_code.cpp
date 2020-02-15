#include <string>
#include <vector>

using namespace std;

int func_a(string times){
    int hour = stoi(times.substr(0, 2));
    int minute = stoi(times.substr(3));
    return hour*60 + minute;
}

int solution(vector<string> subway_times, string current_time) {
    int current_minute = func_a(current_time);
    int INF = 1000000000;
    int answer = INF;
    for(int i = 0; i < subway_times.size(); ++i){
        int subway_minute = func_a(subway_times[i]);
        if(subway_minute >= current_minute){
            answer = subway_minute - current_minute;
            break;
        }
    }
    if(answer == INF)
        return -1;
    return answer;
}