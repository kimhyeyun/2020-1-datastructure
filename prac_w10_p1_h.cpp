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
		this->depth = -1;
		this->left = NULL;
		this->right = NULL;
	}
};

class BST {
public:
	Node* root;
	vector<Node*> node_list;

	BST() {
		this->root = NULL;
	}

	void insert(Node* tree, int data) {
		if (tree == NULL) {
			root = new Node(data);
			root->depth = 0;
			node_list.push_back(root);
		}
		else {
			if (tree->data < data) {
				if (tree->right == NULL) {
					tree->right = new Node(data);
					tree->right->depth = tree->depth + 1;
					node_list.push_back(tree->right);
				}
				else
					insert(tree->right, data);
			}

			else if (tree->data > data) {
				if (tree->left == NULL) {
					tree->left = new Node(data);
					tree->left->depth = tree->depth + 1;
					node_list.push_back(tree->left);
				}
				else
					insert(tree->left, data);
			}
			return;
		}
	}

	void printHeight() {
		int max = 0;
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->depth > max)
				max = node_list[i]->depth;
		}
		cout << max << "\n";
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		BST* bst = new BST();
		int N, x;
		cin >> N;
		while (N--) {
			cin >> x;
			bst->insert(bst->root,x);
		}
		bst->printHeight();
	}
}