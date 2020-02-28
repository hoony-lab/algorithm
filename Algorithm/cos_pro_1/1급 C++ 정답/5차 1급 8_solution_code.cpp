#include <iostream>
using namespace std;

int func_a(int a, int b);
int func_b(int n);
bool func_c(int p, int q);

int func_a(int a, int b) {
    int mod = a % b;
    
    while(mod > 0) {
        a = b;
        b = mod;
        mod = a % b;
    }

    return b;
}

int func_b(int n) {
    int answer = 0;

    for(int i = 1; i <= n; i++) {
        if(func_c(n, i))
            answer++;
    }

    return answer;
}


bool func_c(int p, int q) {
    if(p % q == 0)
        return true;
    else
        return false;
}

int solution(int a, int b, int c) {
    int answer = 0;
    
    int gcd = func_a(func_a(a, b), c);
    answer = func_b(gcd);

    return answer;
}