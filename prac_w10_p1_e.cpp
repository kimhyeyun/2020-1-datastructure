#include<iostream>
#include<vector>
using namespace std;

struct Node {
public:
	int data;
	int depth;
	Node* right;
	Node* left;

	Node(int data) {
		this->data = data;
		this->depth = -1;
		this->right = NULL;
		this->left = NULL;
	}
};

class BST {
public:
	Node* root;

	BST() {
		root = NULL;
	}

	void insertNode(Node* tree, int value) {
		if (tree == NULL) {
			root = new Node(value);
			root->depth = 0;
			return;
		}

		else if (tree->data<value){
			if (tree->right == NULL) {
				tree->right = new Node(value);
				tree->right->depth = tree->depth + 1;
				return;
			}
			else
				insertNode(tree->right, value);
		}

		else if (tree->data > value) {
			if (tree->left == NULL) {
				tree->left = new Node(value);
				tree->left->depth = tree->depth + 1;
				return;
			}
			else
				insertNode(tree->left, value);
		}
		return;
	}

	Node* Search(Node* tree, int value) {
		if (!tree)
			return NULL;
		if (value == tree->data)
			return tree;
		else if (value < tree->data)
			Search(tree->left, value);
		else
			Search(tree->right, value);
	}

	void printDegree(Node* tree, int value) {
		int degree = 0;
		if (Search(tree, value) == NULL)
			cout << 0 << "\n";
		else {
			Node* tmp = Search(tree, value);
			if (tmp->left != NULL)
				degree++;
			if (tmp->right != NULL)
				degree++;

			cout << degree << " " << tmp->depth << "\n";
		}
	}
};

int main() {
	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		BST* bst = new BST();

		int N, M, x;
		cin >> N;

		while (N--) {
			cin >> x;
			bst->insertNode(bst->root, x);
		}

		cin >> M;

		while (M--) {
			cin >> x;
			bst->printDegree(bst->root,x);
		}
	}
}