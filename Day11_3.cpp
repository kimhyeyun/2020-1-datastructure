#include<iostream>
#include<vector>
using namespace std;

struct Node {
public:
	int data;
	Node* par;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		this->par = NULL;
		this->left = NULL;
		this->right = NULL;
	}
};

class BST {
public:
	Node* root;

	BST() {
		this->root = NULL;
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

			newN->par = tmp;
		}
	}

	Node* Search(int data) {
		Node* tmp = root;
		while (tmp != NULL) {
			if (tmp->data > data)
				tmp = tmp->left;
			else if (tmp->data < data)
				tmp = tmp->right;
			else
				return tmp;
		}
		return NULL;
	}

	void removeNode(int data) {
		Node* tmp = Search(data);
		if (tmp == NULL)
			return;
		if (tmp->left == NULL && tmp->right == NULL) {
			if (tmp == root)
				root = NULL;
			else if (tmp->par->left == tmp)
				tmp->par->left = NULL;
			else
				tmp->par->right = NULL;
		}
		else if (tmp->left != NULL && tmp->right == NULL)
			transplant(tmp, tmp->left);
		else if (tmp->left == NULL && tmp->right != NULL)
			transplant(tmp, tmp->right);
		else {
			Node* cur = tmp->right;
			while (cur->left != NULL)
				cur = cur->left;
			if (cur != tmp->right) {
				transplant(cur, cur->right);
				cur->right = tmp->right;
				tmp->right->par = cur;
			}
			transplant(tmp, cur);
			cur->left = tmp->left;
			tmp->left->par = cur;
		}
		delete tmp;
	}

	void transplant(Node* p, Node* c) {
		if (p->par == NULL)
			root = c;
		else if (p->par->left == p)
			p->par->left = c;
		else
			p->par->right = c;
		if (c != NULL)
			c->par = p->par;
	}

	void preTraversal(Node* tree) {
		if (tree == NULL)
			return;
		cout << tree->data << " ";
		if (tree->left != NULL)
			preTraversal(tree->left);
		if (tree->right != NULL)
			preTraversal(tree->right);
	}
};

int main() {
	int T, N,M, x;

	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		BST bst;
		cin >> N;
		while (N--) {
			cin >> x;
			bst.insertNode(x);
		}
		cin >> M;
		while (M--) {
			cin >> x;
			bst.removeNode(x);
		}
		bst.preTraversal(bst.root);
		cout << "\n";
		bst.treeDestructor(bst.root);
	}
}