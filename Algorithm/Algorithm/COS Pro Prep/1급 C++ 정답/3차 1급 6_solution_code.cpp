#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    int i, j, k;
    vector<int> prime;
    prime.push_back(2);
    for (i = 3; i <= n; i += 2) {
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                break;
            }
        }
        if (j == i) {
            prime.push_back(i);
        }
    }
    int prime_n = prime.size();
    for (i = 0; i < prime_n - 2; i++) {
        for (j = i + 1; j < prime_n - 1; j++) {
            for (k = j + 1; k < prime_n; k++) {
                if (prime[i] + prime[j] + prime[k] == n) {
                    answer += 1;
                }
            }
        }
    }
    return answer;
}