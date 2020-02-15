// <undefined>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(long long num) {
	num++;
	long long digit = 1;
	while (num / digit % 10 == 0) {
		num += digit;
		digit *= 10;
	}
	return num;
}