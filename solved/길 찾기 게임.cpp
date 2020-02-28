// https://programmers.co.kr/learn/courses/30/lessons/42892?language=cpp
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Node {
public:
	//vector<int> val;	//val, x, y
	int val;
	int x;
	int y;
	Node *left = nullptr;
	Node *right = nullptr;
};
class Tree {
public:
	Node *root;
};

vector<int> preorder(Node *root) {
	vector<int> answer;
	
	answer.push_back(root->val);
	preorder(root->left);
	preorder(root->right);

	return answer;
}

vector<int> postorder(Node *root) {
	vector<int> answer;

	postorder(root->left);
	postorder(root->right);
	answer.push_back(root->val);

	return answer;
}
void insert(Tree *tree, Node *node) {
	if (tree->root == nullptr) tree->root = node;
	else {
		if (tree->root->val > node->val) {
			if(tree->root->left != nullptr)
				tree->root->left = node;
		}
		else if (tree->root->val < node->val) {
			if (tree->root->right != nullptr)
				tree->root->right = node;
		}
	}
}





vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	for (int i = 0; i < nodeinfo.size(); i++)
	{
		nodeinfo[i].insert(nodeinfo[i].begin(), i + 1);
	}

	sort(nodeinfo.begin(), nodeinfo.end(), [](vector<int> v1, vector<int> v2) {
		if (v1[2] == v2[2]) return v1[1] < v2[1];
		else return v1[2] > v2[2];
	});

	

	Tree *tree = nullptr;
	for (auto node : nodeinfo) {
		Node *nody = new Node{ node[0], node[1], node[2] };
		insert(tree, nody);
	}


	

	vector<vector<int>> answer;
	answer.push_back(preorder(tree->root));
	answer.push_back(postorder(tree->root));


	for (auto order : answer) {
		for (auto num : order) {
			cout << num << ", ";
		}
		cout << '\n';
	}


	return answer;
}
int main() {

	vector<vector<int>> main =
		solution({ {5, 3},{11, 5},{13, 3},{3, 5},{6, 1},{1, 3},{8, 6},{7, 2},{2, 2} });




}