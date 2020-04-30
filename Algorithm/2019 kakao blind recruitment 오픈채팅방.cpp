#include <iostream> 
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
vector<string> solution(vector<string> record) {
	map<string, string> nickname;  /* 닉네임 */
	vector<string> result_id;      /* 이벤트를 발생시킨 id */
	vector<bool> result_in;        /* Enter 여부 */
	vector<string> answer;         /* 결과 */

	for (auto r : record) {
		/* string을 space bar 기준으로 삼분할 */
		istringstream iss(r);
		vector<string> cmds{ istream_iterator<string>{iss},
			istream_iterator<string>{} };
		
		/* 어떤 명령인지? */
		string cmd = cmds[0];
		if (cmd.compare("Enter") == 0) {
			result_id.push_back(cmds[1]);      /* 이벤트를 발생시킨 사람의 id */
			result_in.push_back(true);
			nickname[cmds[1]] = cmds[2];
		}
		else if (cmd.compare("Change") == 0) {
			nickname[cmds[1]] = cmds[2];
		}
		else {
			result_id.push_back(cmds[1]);
			result_in.push_back(false);
		}
	}

	for (int i = 0; i < result_id.size(); i++) {
		string res = nickname[result_id[i]] + "님이";
		if (result_in[i])
			res += " 들어오셨습니다.";
		else
			res += " 나갔습니다.";

		answer.push_back(res);
	}
	return answer;
}

int main() {
	vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo",
		"Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" };

	
	vector<string> ans = solution(record);       // 들, 들, 나, 들
	for (auto v : ans)
		cout << v << "\n";

	return 0;
}

/*

def solution(record):
	idDict = dict()
	answer = []
	logList = []

	for e in record:
		dataList = e.split(" ")

		if dataList[0] == "Leave":
			logList.append([dataList[1], "님이 나갔습니다."])
		elif dataList[0] == "Enter":
			idDict[dataList[1]] = dataList[2]
			logList.append([dataList[1], "님이 들어왔습니다."])
		elif dataList[0] == "Change":
		idDict[dataList[1]] = dataList[2]
			print(logList)
	for log in logList:
		answer.append(idDict[log[0]] + log[1])

	return answer
*/