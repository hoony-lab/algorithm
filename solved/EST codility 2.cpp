//// you can use includes, for example:
//// #include <algorithm>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <set>
//using namespace std;
//// you can write to stdout for debugging purposes, e.g.
//// cout << "this is a debug message" << endl;
//
//struct tree{
//	int x;
//	tree *l;
//	tree *r;
//};
//
//
//int solution(tree * T) {
//	// write your code in C++14 (g++ 6.2.0)
//	int answer = 0;
//	int depth = 0;
//
//	set<int> nums;
//
//	queue<tree *> q;
//	q.push(T);
//	nums.insert(T->x);
//
//
//	while (!q.empty()) {
//		++depth;
//
//		int size = q.size();
//		for (int level = 1; level < size; ++level) {
//
//			tree * node = q.front();
//			q.pop();
//
//			//int tx = node.x;
//			tree * tl = node->l;
//			tree * tr = node->r;
//			int lx = tl->x;
//			int rx = tr->x;
//
//			//left
//			if (tl != nullptr) {
//				if (nums.find(lx) == nums.end()) {
//					q.push(tl);
//					nums.insert(lx);
//				}
//			}
//
//			//right
//			if (tr != nullptr) {
//				if (nums.find(rx) == nums.end()) {
//					q.push(tr);
//					nums.insert(rx);
//				}
//			}
//
//		}
//
//
//	}
//	cout << depth << endl;
//
//	return depth;
//}
//
//int main() {
//
//	cout << solution((1, (2, (3, (2, nullptr, nullptr), nullptr), (6, nullptr, nullptr)), (3, (3, nullptr, nullptr), (1, (5, nullptr, nullptr), (6, nullptr, nullptr)))));
//
//
//
//}



#include <algorithm>
#include <queue>
#include <set>
#include <iostream>
using namespace std;

int answer = 0;
void dfs(tree * node, int dep, set<int> s) {


	answer = max(answer, dep);

	tree * tl, *tr;
	int lx, rx;

	//left
	if (node->l != nullptr) {
		tl = node->l;
		lx = tl->x;
		if (s.find(lx) == s.end()) {
			answer = max(answer, dep + 1);
			s.insert(lx);
			dfs(tl, dep + 1, s);
			s.erase(s.find(lx));
		}
	}




	//right
	if (node->r != nullptr) {
		tr = node->r;
		rx = tr->x;
		if (s.find(rx) == s.end()) {
			s.insert(rx);
			dfs(tr, dep + 1, s);
			s.erase(s.find(rx));
		}
	}


}


int solution(tree * T) {
	set<int> nums;

	nums.insert(T->x);
	answer = 0;
	dfs(T, 1, nums);

	return answer;
}



int main() {
	tree *node = new tree{ 1, nullptr, (2, (1, nullptr, nullptr), (1, (4, nullptr, nullptr), nullptr)) };
	//cout << solution(node);

	tree *node1 = new tree(1, {2, {3, {2, nullptr, nullptr}, nullptr}, {6, nullptr, nullptr}}, {3, {3, NULL, nullptr}, {1, {5, nullptr, nullptr}, {6, nullptr, nullptr}}} );

	cout << solution(node1);



	//cout << solution((1, (2, (3, (2, nullptr, nullptr), nullptr), (6, nullptr, nullptr)), (3, (3, nullptr, nullptr), (1, (5, nullptr, nullptr), (6, nullptr, nullptr)))));



}