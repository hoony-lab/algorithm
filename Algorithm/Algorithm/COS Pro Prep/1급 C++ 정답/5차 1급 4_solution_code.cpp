#include <string>
#include <vector>

using namespace std;

string solution(int number) {
    string answer = "";

    vector<int> number_count(10);
    while(number > 0) {
    	number_count[number % 10]++;
    	number /= 10;
    }

    for(int i = 9; i >= 0; i--)
    	if(number_count[i] != 0)
    		answer += (to_string(i) + to_string(number_count[i]));

    return answer;
}