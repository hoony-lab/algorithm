#include <string>
#include <vector>

using namespace std;

string solution(string phrases, int second) {
    string answer = "";
    string display = "";
    display.append("______________");
    display.append(phrases);
    for(int i = 0; i < second; ++i)
    {
    	display.push_back(display[0]);
    	display.erase(0,1);
    }
    answer = display.substr(0,14);
    return answer;
}