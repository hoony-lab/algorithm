#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>

template <class Container>
void split(const std::string& str, Container& cont)
{
	std::istringstream iss(str);
	std::copy(std::istream_iterator<std::string>(iss),
		std::istream_iterator<std::string>(),
		std::back_inserter(cont));
}

template <class Container>
void split(const std::string& str, Container& cont, char delim)
{
	std::stringstream ss(str);
	std::string token;
	while (std::getline(ss, token, delim)) {
		cont.push_back(token);
	}
}

int main() {
	int cnt = 0;
	std::vector<std::string> v;
	std::string s;		std::cin >> s;
	std::stringstream sstream(s);

	// split string with ':' delimeter
	std::string ss;
	while (std::getline(sstream, ss, ':')) {

		// fill zeros from front if its length is not 4
		std::string temp;
		while (ss.length() + temp.length() != 4) temp += "0";

		v.push_back(temp + ss);
		cnt++;
	}

	std::string ans;
	for (auto num : v) {
		if (num == "0000") {
			while (cnt++ < 8)
				ans.append("0000:");
		}
		ans.append(num + ":");
	}

	std::cout << ans.substr(0, ans.length() - 1);
	
	return 0;
}
//25:09:1985:aa:091:4846:374:bb
//0025:0009:1985:00aa:0091:4846:0374:00bb

/*
	// python3
	"s = input().split(\":\")\n",
	"ans = \"\"\n",
	"size = len(s)\n",
	"flag = 1\n",
	"for ss in s:\n",
	"\n",
	"    if ss == \"\" and flag == 1:\n",
	"        flag = 0\n",
	"        while size < 9:          \n",
	"            ans += \"0000:\"\n",
	"            size += 1\n",
	"            \n",
	"    else:\n",
	"        ans += ss.rjust(4,'0') + \":\"\n",
	"        \n",
	"print(ans[:-1])"

*/