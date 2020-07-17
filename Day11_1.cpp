#include<iostream>
#include<vector>
using namespace std;


struct Node {
public:
	int data;
	Node* left;
	Node* right;
	int depth;

	Node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->depth = -1;
	}
};

class BST {
public:
	Node* root;
	vector<Node*> node_list;

	BST() {
		this->root = NULL;
	}

	void treeDestructor(Node* root) {
		if (root == NULL)
			return;
		if (root->left != NULL)
			this->treeDestructor(root->left);
		if (root->right != NULL)
			this->treeDestructor(root->right);
		delete root;
	}

	void insertChild(int data) {
		Node* newN = new Node(data);
		if (this->root == NULL) {
			this->root = newN;
			this->root->depth = 0;
			node_list.push_back(this->root);
			return;
		}
		else {
			Node* cur = root;
			Node* tmp = NULL;
			while (cur!=NULL) {
				tmp = cur;
				if (cur->data < data)
					cur = cur->right;
				else if (cur->data > data)
					cur = cur->left;
			}
			if (tmp->data < data)
				tmp->right = newN;
			else 
				tmp->left = newN;
			 
			newN->depth = tmp->depth + 1;
			node_list.push_back(cur);
		}
	}

	Node* Search(int data) {
		Node* cur = root;
		while (cur!=NULL) {
			if (cur->data < data)
				cur = cur->right;
			else if (cur->data > data)
				cur = cur->left;
			else
				return cur;
		}
		return NULL;
	}

	void printD(int data) {
		Node* tmp = Search(data);
		if (tmp == NULL) {
			cout << 0 << "\n";
			return;
		}
		else {
			int degree = 0;
			if (tmp->left != NULL)
				degree++;
			if (tmp->right != NULL)
				degree++;

			cout << degree << " " << tmp->depth << "\n";
			return;
		}
	}
};

int main() {
	int T, N, M, x;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		BST bst;
		cin >> N;
		while (N--) {
			cin >> x;
			bst.insertChild(x);
		}
		cin >> M;
		while (M--) {
			cin >> x;
			bst.printD(x);
		}
		bst.treeDestructor(bst.root);
	}
}