#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using vs = vector<string>;
using vi = vector<int>;

vector<int> solution(vector<string> words, vector<string> queries) {
	vi answer;

	sort(words.begin(), words.end(), [](string s1, string s2) {
		return s1.length() == s2.length() ? s1 < s2 : s1.length() < s2.length();
		});

	for (string query : queries) {
		int flag, start = 0, end = query.length() - 1, mid = (start + end) / 2;

			// ??????
			if (query[0] == '?' && query[query.length() - 1] == '?') {
				flag = 1;
			}

		// ???zen
			else if (query[0] == '?') {
				while (start <= end) {
					mid = (start + end) / 2;
					if (query[mid - 1] == '?' && query[mid] != '?') break;
					else if (query[mid] == '?') start = mid + 1;
					else if (query[mid] != '?') end = mid - 1;
				}
				flag = 2;
			}

		// fro???
			else if (query[query.length() - 1] == '?') {
				while (start <= end) {
					mid = (start + end) / 2;
					if (query[mid - 1] != '?' && query[mid] == '?') break;
					else if (query[mid] != '?') start = mid + 1;
					else if (query[mid] == '?') end = mid - 1;
				}
				flag = 3;
			}

		int ans = 0;
		//cout << "query : " << query << " :: mid : " << mid << '\n';
		for (string word : words) {
			//cout << "word : " << word << '\n';
			if (query.length() > word.length()) continue;
			if (query.length() < word.length()) break;


			if (flag == 1) {
				ans++;
			}
			else if (flag == 2) {
				if (word.substr(mid, word.length() - mid) == query.substr(mid, query.length() - mid))
					ans++;
			}
			else if (flag == 3) {
				if (word.substr(0, mid) == query.substr(0, mid))
					ans++;
			}

		}
		answer.push_back(ans);
	}
	return answer;
}




/*
vector<int> solution(vector<string> words, vector<string> queries) {
	vi answer;

	for (string query : queries) {
		int ans = 0;
		for (string word : words) {
			if (query.length() != word.length()) continue;

			bool fail = false;
			for (int i = 0; i < word.size(); ++i) {
				if (query[i] == '?') continue;
				if (word[i] != query[i]){
					fail = true; break;
				}
			}
			if (!fail) ans++;
		}
		answer.push_back(ans);
	}
	return answer;
}
*/



int main() {
	vs words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
	vs queries = { "fro??", "????o", "fr???", "fro???", "pro?" };
	vi answer = solution(words, queries);		// 3 2 4 1 0

	for (auto ans : answer)
		cout << ans << ' ';

	return 0;
}