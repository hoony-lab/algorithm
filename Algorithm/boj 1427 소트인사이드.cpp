#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>
int main() {
	std::string s;
	std::cin >> s;

	/*
		»ğÀÔ ¼±ÅÃ ¹öºí
		½© Äü Èü ¸ÓÁö 
	*/
	
	std::vector<char> v;
	for (char ch : s)
		v.push_back(ch);

	std::sort(v.begin(), v.end(), std::greater<>());

	for (char ch : v)
		std::cout << ch;
	


}