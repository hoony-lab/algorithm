#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pair{
    public:
    int first_num;
    int second_num;
};

int func_a(int numA, int numB, char exp){
    if (exp == '+')
        return numA + numB;
    else if (exp == '-')
        return numA - numB;
    else
        return numA * numB;
}

int func_b(string exp){
    for(int i = 0; i < exp.length(); i++){
        char e = exp[i];
        if(e == '+' || e == '-' || e == '*')
            return i;
    }
    return -1;
}

Pair func_c(string exp, int idx){
    Pair ret;
    ret.first_num = stoi(exp.substr(0, idx));
    ret.second_num = stoi(exp.substr(idx+1));
    return ret;
}

int solution(string expression) {
    int exp_index = func_@@@(@@@);
    Pair numbers = func_@@@(@@@);
    int result = func_@@@(@@@);
    return result;
}

// The following is main function to output testcase.
int main() {
    string expression = "123+12";
    int ret = solution(expression);

    // Press Run button to receive output. 
    cout << "Solution: return value of the function is " << ret << " ." << endl;
}