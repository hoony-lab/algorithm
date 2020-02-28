#include <string>
#include <vector>
#include <iostream>

using namespace std;

int numbers_int[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
string numbers_char = "0123456789";

const int char_to_int(char ch) {
    for (int i = 0; i < 10; i++)
        if (ch == numbers_char[i])
            return numbers_int[i];
}

const char int_to_char(int val) {
    for (int i = 0; i < 10; i++)
        if (val == numbers_int[i])
            return numbers_char[i];
}

string convert_scale(int num, int q) {
    if (num == 0) return "";
    return convert_scale(num / q, q) + int_to_char(num % q);
}

int parse_decimal(string s, int p) {
    int num = 0;
    for (int i = s.size() - 1, mul = 1; i >= 0; i--, mul *= p)
        num += char_to_int(s[i]) * mul;
    return num;
}

string solution(string s1, string s2, int p, int q) {
    int num1 = parse_decimal(s1, p);
    int num2 = parse_decimal(s2, p);
    string answer = convert_scale(num1 + num2, q);
    return answer;
}