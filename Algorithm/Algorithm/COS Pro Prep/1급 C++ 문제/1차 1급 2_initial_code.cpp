#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string func_a(string str, int len){
    string padZero = "";
    int padSize = @@@;
    for(int i = 0; i < padSize; i++)
        padZero += "0";
    return padZero + str;
}

int solution(string binaryA, string binaryB) {
    int max_length = max(binaryA.length(), binaryB.length());
    binaryA = func_a(binaryA, max_length);
    binaryB = func_a(binaryB, max_length);
    
    int hamming_distance = 0;
    for(int i = 0; i < max_length; i++)
        if(@@@)
            hamming_distance += 1;
    return hamming_distance;
}

// The following is main function to output testcase.
int main() {
    string binaryA = "10010";
    string binaryB = "110";
    int ret = solution(binaryA, binaryB);
    
    // Press Run button to receive output.
    cout << "Solution: return value of the function is " << ret << " ." << endl;
}