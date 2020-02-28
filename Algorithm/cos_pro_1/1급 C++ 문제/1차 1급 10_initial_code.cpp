#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> prices){
    int INF = 1000000001;
    int tmp = INF;
    int answer = -INF;
    for(int price : prices){
        if(tmp != INF)
            answer = max(answer, tmp - price);
        tmp = min(tmp, price);
    }
    return answer;
}

// The following is main function to output testcase. The main function is correct and you shall correct solution function.
int main() {
    vector<int> prices1 = {1, 2, 3};
    int ret1 = solution(prices1);
    
    // Press Run button to receive output. 
    cout << "Solution: return value of the function is " << ret1 << " ." << endl;
    
    vector<int> prices2 = {3, 1};
    int ret2 = solution(prices2);
    
    // Press Run button to receive output. 
    cout << "Solution: return value of the function is " << ret2 << " ." << endl;
}