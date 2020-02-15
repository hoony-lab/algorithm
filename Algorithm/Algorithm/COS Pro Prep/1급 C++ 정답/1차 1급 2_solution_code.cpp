#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string func_a(string str, int len){
    string padZero = "";
    int padSize = len - str.length();
    for(int i = 0; i < padSize; ++i)
        padZero += "0";
    return padZero + str;
}

int solution(string binaryA, string binaryB) {
    int max_length = max(binaryA.length(), binaryB.length());
    if(max_length > binaryA.length())
        binaryA = func_a(binaryA, max_length);
    if(max_length > binaryB.length())
        binaryB = func_a(binaryB, max_length);
    
    int hamming_distance = 0;
    for(int i = 0; i < max_length; ++i)
        if(binaryA[i] != binaryB[i])
            hamming_distance += 1;
    return hamming_distance;
}