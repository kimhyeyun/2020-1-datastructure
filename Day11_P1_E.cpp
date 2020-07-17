#include<iostream>
using namespace std;

struct Node {
public:
	int data;
	Node* left;
	Node* right;
	int depth;

	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
		depth = 0;
	}
};

class BST {
public:
	Node* root;

	BST() {
		root = NULL;
	}

	~BST() {
		this->treeDestructor(this->root);
	}


	void treeDestructor(Node* root) {
		if (root == NULL)
			return;
		if (root->left != NULL)
			this->treeDestructor(root->left);
		if (root->right != NULL)
			this->treeDestructor(root->right);
		delete(root);
	}

	Node* getRoot() {
		return root;
	}

	void insert(int data) {
		Node* newN = new Node(data);
		Node* tmp = NULL;
		if (root == NULL) {
			root = newN;
			return;
		}
		else {
			Node* cur = root;
			while (cur != NULL) {
				tmp = cur;
				if (data < cur->data)
					cur = cur->left;
				else
					cur = cur->right;
			}
			if (data < tmp->data)
				tmp->left = newN;
			else
				tmp->right = newN;

			newN->depth = tmp->depth + 1;
		}
	}

	Node* Search(Node* tree, int data) {
		Node* tmp = root;
		while (tmp != NULL) {
			if (tmp->data == data)
				return tmp;
			else if (tmp->data < data)
				tmp = tmp->right;
			else
				tmp = tmp->left;
		}
		return NULL;
	}

	void printD(Node* tree,int data) {
		int degree = 0;
		Node* tmp = Search(tree, data);

		if (tmp == NULL)
			cout << 0 << "\n";
		else {
			if (tmp->left != NULL)
				degree++;
			if (tmp->right != NULL)
				degree++;
			cout << degree << " " << tmp->depth << "\n";
		}
		return;
	}
};


int main() {
	int T,x;
	cin >> T;

	while (T--) {
		BST bst;
		int N;
		cin >> N;
		while (N--) {
			cin >> x;
			bst.insert(x);
		}
		int M;
		cin >> M;
		while (M--) {
			cin >> x;
			bst.printD(bst.getRoot(), x);
		}
	}

	return 0;
}