#include <iostream>
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
    //int current_minute = func_a(@@@);
    int INF = 1000000000;
    int answer = INF;
    for(int i = 0; i < subway_times.size(); ++i){
        int subway_minute = func_a(subway_times[i]);
        //int subway_minute = func_a(@@@);
        if(subway_minute >= current_minute){
        //if(@@@){
            answer = subway_minute - current_minute;
            break;
        }
    }
    if(answer == INF)
        return -1;
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    vector<string> subway_times1 = {"05:31", "11:59", "13:30", "23:32"};
    string current_time1 = "12:00";
    int ret1 = solution(subway_times1, current_time1);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

    vector<string> subway_times2 = {"14:31", "15:31"};
    string current_time2 = "15:31";
    int ret2 = solution(subway_times2, current_time2);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}