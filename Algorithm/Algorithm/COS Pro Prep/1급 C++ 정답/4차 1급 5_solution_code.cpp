#include <string>
#include <vector>
#include <iostream>

using namespace std;

string reverse(string number);

string solution(int n) {
	string answer = "";
	for(int i = 0; i < n; ++i)
	{
		answer.push_back(i%9 + 1 + '0');
		answer = reverse(answer);
	}
	return answer;
}

string reverse(string number)
{
	string reverse_number;
	for(int i = number.length()-1; i >= 0; --i)
	{
		reverse_number.push_back(number[i]);
	}
	return reverse_number;
}