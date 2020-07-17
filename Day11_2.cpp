#include<iostream>
#include<vector>
using namespace std;

struct Node {
public:
	int data;
	int depth;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		this->depth = 0;
		this->left = NULL;
		this->right = NULL;
	}
};

class BST {
public:
	Node* root;
	int height;

	BST() {
		this->root = NULL;
		this->height = 0;
	}

	void treeDestructor(Node* tree) {
		if (tree == NULL)
			return;
		if (tree->left != NULL)
			this->treeDestructor(tree->left);
		if (tree->right != NULL)
			this->treeDestructor(tree->right);
		delete tree;
	}

	void insertNode(int data) {
		if (this->root == NULL)
			this->root = new Node(data);
		else {
			Node* newN = new Node(data);
			Node* tmp = NULL;
			Node* cur = root;

			while (cur != NULL) {
				tmp = cur;
				if (cur->data < data)
					cur = cur->right;
				else
					cur = cur->left;
			}

			if (tmp->data < data)
				tmp->right = newN;
			else
				tmp->left = newN;

			newN->depth = tmp->depth + 1;
			
			if (newN->depth > this->height)
				height = newN->depth;
		}
	}
};

int main() {
	int T, N, x;

	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		BST bst;
		cin >> N;
		while (N--) {
			cin >> x;
			bst.insertNode(x);
		}
		cout << bst.height << "\n";
		bst.treeDestructor(bst.root);
	}
}