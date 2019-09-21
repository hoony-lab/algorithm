#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	//vector<vector<string>> setClothes;
	////setClothes.push_back({ {clothes[0][1], clothes[0][0]} });
	//vector<string> temp;
	//temp.push_back(clothes[0][1]);
	//temp.push_back(clothes[0][0]);
	//setClothes.push_back({ {clothes[0][1], clothes[0][0]} });
	//int comb[31] = { 0, };
	//int index = 0;

	//for (int i = 1; i < clothes.size(); i++){
	//	int size = setClothes.size();

	//	for (int j = 0; j < size; j++) {
	//		if (clothes[i][1] == setClothes[j][1]){
	//			setClothes[0].push_back(clothes[i][0]);
	//			//comb[j]++;
	//			break;
	//		}
	//		else if (clothes[i][1] != setClothes[j][1]) {
	//			setClothes.push_back({ clothes[i][1], clothes[i][0] });
	//			//comb[++j]++;
	//			break;
	//		}
	//	}
	//}

	map<string, int> m;
	map<string, int>::iterator it;

	for (int i = 0; i < clothes.size(); i++) {
		it = m.find(clothes[i][1]);

		// if its in map
		if (it != m.end()) {
			m[clothes[i][1]]++;
		}
		else {
			m.insert({ clothes[i][1], 1 });
		}
	}

	for (auto i : m) {
		answer *= (1 + i.second);
	}
	return answer - 1;
}
int main() {
//	[[yellow_hat, headgear], [blue_sunglasses, eyewear], [green_turban, headgear]]
//		[[crow_mask, face], [blue_sunglasses, face], [smoky_makeup, face]]

		cout << solution({ {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} });


}