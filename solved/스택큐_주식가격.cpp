#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	for (int i = 0; i < prices.size(); i++)
	{
		int time = 0;
		for (int j = i+1; j < prices.size(); j++)
		{
			++time;
			if (prices[i] > prices[j]) break;
		}
		answer.push_back(time);
	}
	return answer;
}
int main() {

	for (auto i : solution({ 1,2,3,2,3 })) {
		cout << i << ", ";
	}
	cout << endl;
	//[4, 3, 1, 1, 0]





	system("pause");

}