#include <string>
#include <vector>

using namespace std;

int func_a(vector<int> &stack);
void func_b(vector<int> &stack1, vector<int> &stack2);
bool func_c(vector<int> stack);

int solution(vector<int> stack1, vector<int> stack2) {
    if(func_c(stack2)){
        func_b(stack1, stack2);
    }
    int answer = func_a(stack2);
    return answer;
}

int func_a(vector<int> &stack) {
    int item = stack.back();
    stack.pop_back();
    return item;
}

void func_b(vector<int> &stack1, vector<int> &stack2) {
    while(!func_c(stack1)) {
        int item = func_a(stack1);
        stack2.push_back(item);
    }
}

bool func_c(vector<int> stack) {
    return (stack.size() == 0);
}
