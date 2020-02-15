#include <string>
#include <vector>

using namespace std;

int solution(int K, vector<string> words) {
    int cnt = 1;
    int sum = 0;
    for(int i = 0; i < words.size(); i++){
        int length = words[i].length();
        if(sum != 0)
            sum++;
        sum += length;
        if(sum > K){
            cnt++;
            i--;
            sum = 0;
        }
    }
    return cnt;
}