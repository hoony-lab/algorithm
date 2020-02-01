#include <iostream>
#include <string>
using namespace std;

struct Node {
	char val;
	Node *left, *right;

	Node(char val, Node *ln, Node *rn) { 
		this->val = val;
		this->left = ln;
		this->right = rn;
	}
};

void push(Node *root,Node *node) {
	
	if (root == nullptr) root = node;
	else {
		while () {

		}
	}
}

void preorder(Node *root) {
	if (root == nullptr) return;

	cout << root->val;
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node *root) {
	if (root == nullptr) return;

	inorder(root->left);
	cout << root->val;
	inorder(root->right);
}

void postorder(Node *root) {
	if (root == nullptr) return;

	postorder(root->left);
	postorder(root->right);
	cout << root->val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Node * root;



	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char val, ln, rn;
		Node *left, *right;
		cin >> val >> ln >> rn;

		if (ln == '.')	ln = NULL;
		else if(rn == '.')	rn = nullptr:
		Node *newNode = new Node(val,ln,rn);

		
	}



	preorder(root);
	cout << '\n';
	inorder(root);
	cout << '\n';
	postorder(root);
	cout << '\n';
}