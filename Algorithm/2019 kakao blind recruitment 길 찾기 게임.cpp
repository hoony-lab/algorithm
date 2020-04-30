#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> answer;
vector<int> pre, post;

struct Node {
	Node* l = nullptr;
	Node* r = nullptr;
	int x, y, value;
} *root;

void print(Node* node) {
	cout << "NODE : " << node->x << ", " << node->y << ", " << node->value << '\n';
}
Node *newNode(vector<int> v) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->x = v[0], node->y = v[1], node->value = v[2];
	node->l = nullptr, node->r = nullptr;
	return node;
}

void Insert(Node *node) {
	
	if (root == nullptr) {
		root = node;
	}
	else{
		Node* tmp = root;

		while (true) {
			if (tmp->x > node->x) {
				if (tmp->l == nullptr) {
					tmp->l = node;
					break;
				}
				else tmp = tmp->l;
			}
			else {
				if (tmp->r == nullptr) {
					tmp->r = node;
					break;
				}
				else tmp = tmp->r;
			}
		}
		//print(tmp);
	}
}

void preorder(Node* node) {
	pre.push_back(node->value);

	if(node->l != nullptr)
		preorder(node->l);
	if(node->r != nullptr)
		preorder(node->r);
}

void postorder(Node* node) {
	if (node->l != nullptr)
		postorder(node->l);
	if (node->r != nullptr)
		postorder(node->r);

	post.push_back(node->value);
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {

	for (int i = 0; i < nodeinfo.size(); ++i)
		nodeinfo[i].push_back(i + 1);

	sort(nodeinfo.begin(), nodeinfo.end(),
		[](vector<int> v1, vector<int> v2) {
			if (v1[1] == v2[1])
				return v1[0] < v2[0];
			return v1[1] > v2[1];
		});

	//Tree *tree = root;
	for (auto v : nodeinfo)
		Insert(newNode(v));

	preorder(root);
	postorder(root);

	answer.push_back(pre);
	answer.push_back(post);
	return answer;
}

int main() {
	vector<vector<int>> nodeinfo = {
		{5, 3}, {11, 5}, {13, 3},
		{3, 5}, {6, 1}, {1, 3},
		{8, 6}, {7, 2}, {2, 2} };

	vector<vector<int>> result = solution(nodeinfo);

	cout << result.size() << '\n';
	for (auto a : result) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << "\n\n";
	}

	return 0;
}