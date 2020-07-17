#include<iostream>
#include<vector>
using namespace std;


struct Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

class BST {
public:
	Node* root;

	BST() {
		root = NULL;
	}

	void insert(Node* tree, int data) {
		Node* newN = new Node(data);
		if (tree == NULL) {
			root = newN;
		}
		else {
			if (tree->data < data) {
				if (tree->right == NULL)
					tree->right = newN;
				else
					insert(tree->right, data);
			}
			else if (tree->data > data) {
				if (tree->left == NULL)
					tree->left = newN;
				else
					insert(tree->left, data);
			}
		}
	}

	Node* Search(Node* tree,int data) {
	
		if (tree==NULL) {
			return NULL;
		}
		else {
			if (tree->data > data) {
				Search(tree->left, data);
			}
			else if (tree->data < data)
				Search(tree->right, data);
			else
				return tree;
		}
		
	}
	void deletion(Node* tree,int data) {
		Node* tmp = Search(tree, data);
		Node* min = tree->right;
		while (min->left->left != NULL) {
			min = min->left;
		}
		tmp->data = min->left->data;
		min->left = NULL;
		delete min->left;
	}

	void PreTraversal(Node* tree) {
		if (tree != NULL) {
			cout << tree->data << " ";
			PreTraversal(tree->left);
			PreTraversal(tree->right);
		}
	}

};

int main() {
	int T;
	cin >> T;
	while (T--) {
		BST* bst = new BST();	
		int N;
		cin >> N;
		while (N--) {
			int x;
			cin >> x;
			bst->insert(bst->root,x);
		}
		int M;
		cin >> M;
		while (M--) {
			int x;
			cin >> x;
			bst->deletion(bst->root,x);
		}
		bst->PreTraversal(bst->root);
	}
}