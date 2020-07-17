#include<iostream>
#include<vector>
using namespace std;

struct Node {
public:
	int data;
	int depth;
	Node* left;
	Node* right;
	Node* par;


	Node(int data) {
		this->data = data;
		depth = 0;
		left = NULL;
		right = NULL;
		par = NULL;
	}

	void insertLChild(Node* left) {
		this->left = left;
		left->par = this;
		left->depth = this->depth + 1;
	}

	void insertRChild(Node* right) {
		this->left = right;
		right->par = this;
		right->depth = this->depth + 1;
	}
};

class BST {
public:
	Node* root;
	vector<Node*> node_list;

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

			node_list.push_back(newN);
			newN->depth = tmp->depth + 1;
		}
	}


	void printH() {
		int max = 0;
		for (unsigned int i = 0; i < node_list.size(); i++) {
			if (max < node_list[i]->depth)
				max = node_list[i]->depth;
		}
		cout << max << "\n";
	}
};


int main() {
	int T, x;
	cin >> T;

	while (T--) {
		BST bst;
		int N;
		cin >> N;
		while (N--) {
			cin >> x;
			bst.insert(x);
		}
		bst.printH();
	}
	return 0;
}