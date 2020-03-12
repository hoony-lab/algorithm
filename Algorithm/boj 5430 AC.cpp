#include <iostream>
#include <string>
#include <vector>
#include <deque>
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);	std::cout.tie(NULL);

	int t;
	std::cin >> t;

	while (t--) {
		//std::vector<std::string> v;
		std::deque<std::string> deq;
		bool isreverse = false;
		std::string p, s;
		int n, ind = 1;
		std::cin >> p >> n >> s;

		bool error = false;
		if (s[ind] == ']') {
			std::cout << "error\n"; continue;
		}

		while (n--) {
			int len, ssize = s.size();
			if (ind + 1 < ssize && isdigit(s[ind + 2]) &&
				isdigit(s[ind + 1]) && isdigit(s[ind]))
				len = 3;
			else if (isdigit(s[ind + 1]) && isdigit(s[ind]))
				len = 2;
			else if (ind + 1 == ssize || isdigit(s[ind]))
				len = 1;

			deq.push_back(s.substr(ind, len));
			ind += len + 1;
		}

		int sum = 0, vsize = deq.size();
		for (int i = 0; i < vsize; ++i) {
			sum += stoi(deq[i]);
		}
		ind = 0;

		int psize = p.size();
		while (ind < psize) {
			//prune
			if (deq.size() == 0) {
				error = true; break;
			}

			if (p[ind] == 'R') {
				//std::vector<std::string> v2;
				//for (int i = deq.size() - 1; i >= 0; --i) v2.push_back(deq[i]);
				//deq = v2;
				//std::reverse(v.begin(), v.end());
				if (isreverse) isreverse = false;
				else isreverse = true;
			}
			else if (p[ind] == 'D') {
				//deq.erase(deq.begin());
				if (isreverse) deq.pop_back();
				else deq.pop_front();
			}
			ind++;
		}

		if (error) std::cout << "error\n";
		else {
			std::cout << "[";
			if (isreverse) {
				if (deq.size() == 0) std::cout << "]\n";
				else if (deq.size() == 1) std::cout << deq[0] << "]\n";
				else {
					int vsize = deq.size();
					for (int i = vsize - 1; i > 0; --i) std::cout << deq[i] << ",";
					std::cout << deq[0] << "]\n";
				}
			}
			else {
				if (deq.size() == 0) std::cout << "]\n";
				else if (deq.size() == 1) std::cout << deq[deq.size() - 1] << "]\n";
				else {
					int vsize = deq.size();
					for (int i = 0; i < vsize - 1; ++i) std::cout << deq[i] << ",";
					std::cout << deq[vsize - 1] << "]\n";
				}
			}
		}
	}

}
/*
6
RDD
4
[1,2,3,4]
DD
1
[42]
RRD
6
[1,1,2,3,5,8]
D
0
[]
RDD
6
[1,1,2,3,5,8]
DDDRDDDR
9
[1,1,2,3,5,8,9,11,12]
*/


/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
using namespace std;
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		string cmd;
		string s;
		deque<int> dq;
		cin >> cmd;
		cin >> n;
		cin >> s;
		string tmp;
		for (int i = 0; i < s.size(); i++)
		{

			if (s[i]>='0' && s[i]<='9')
			{
				tmp+=s[i];
			}
			else if(s[i]==','||s[i]==']')
			{
				if(tmp.size())
				{
					dq.push_back(stoi(tmp));
					tmp.clear();
				}
			}
		}
		bool flag = false; //뒤집으면 true
		bool iserror = false;

		for (int i = 0; i < cmd.size(); i++)
		{
			if (cmd[i] == 'R')
			{
				flag = !flag;
			}
			else
			{
				if(!dq.empty())
				{
					if (flag)
					{
						dq.pop_back();
					}
					else
					{
						dq.pop_front();
					}
				}
				else
				{
					iserror = true;
					break;
				}
			}
		}

		if (!iserror)
		{
			if (flag)
			{
				cout << "[";
				while (!dq.empty())
				{
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty())
						cout << ",";
				}
				cout << "]\n";
			}
			else
			{
				cout << "[";
				while (!dq.empty())
				{
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty())
						cout << ",";
				}
				cout << "]\n";
			}
		}
		else
			cout << "error\n";
	}
	return 0;
}
//짜증
*/