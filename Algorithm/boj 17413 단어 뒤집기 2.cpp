#include <iostream>
#include <string>

std::string reverse(std::string str) {
	std::string ans;
	for (int i = str.size() - 1; i >= 0; i--)
		ans += str[i];
	return ans;
}

int main() {

	std::string str, ans, temp;
	getline(std::cin, str);

	int idx = 0;
	while (idx < str.length()) {

		if (str[idx] == ' ' ) {
			ans += reverse(temp) + " ";
			temp = "";
		}
		else if (str[idx] == '<') {
			ans += reverse(temp);
			temp = "";

			ans += str[idx++];
			while (str[idx] != '>') ans += str[idx++];
			ans += str[idx];
		}
		else {
			temp += str[idx];
		}

		idx++;

		if (idx == str.length())
			ans += reverse(temp);

		//std::cout << ":::" <<  str[idx] << ":::\n";
	}

	std::cout << ans;
	return 0;
}