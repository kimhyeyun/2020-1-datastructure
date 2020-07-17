#include<iostream>
using namespace std;


struct Node {
public:
	int data;
	Node* left;
	Node* right;
	Node* par; 

	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
		par = NULL;
	}
};

class BST {
public:
	Node* root;
	
	BST() {
		root = NULL;
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


	void insert(int data) {
		Node* newN = new Node(data);
		Node* cur = root;
		Node* parent = NULL;
		while (cur != NULL) {
			parent = cur;
			if (cur->data > data)
				cur = cur->left;
			else
				cur = cur->right;
		}
		if (parent == NULL)
			root = newN;
		else if (parent->data > data)
			parent->left = newN;
		else
			parent->right = newN;
		newN->par = parent;
	}

	void PreTraversal(Node* tree) {
		if (tree == NULL)
			return;
		cout << tree->data << " ";
		if(tree->left!=NULL)
			PreTraversal(tree->left);
		if (tree->right != NULL);
		PreTraversal(tree->right);
	}


	Node* Search(int data) {
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

	void Tree_Delete(int data) {
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

	void transplant(Node*p, Node*c) {
		if (p->par == NULL)
			root = c;
		else if (p->par->left == p)
			p->par->left = c;
		else
			p->par->right = c;
		if (c != NULL)
			c->par = p->par;
	}	
};


int main() {
	int T, N, M, x;
	cin >> T;	

	for(int i=0;i<T;i++){
		BST bst;
		cin >> N;
		for(int j=0;j<N;j++){
			cin >> x;
			bst.insert(x);
		}
		cin >> M;
		for(int j=0;j<M;j++) {
			cin >> x;
			bst.Tree_Delete(x);
		}
		bst.PreTraversal(bst.root);
		cout << "\n";
		bst.treeDestructor(bst.root);
	}

	return 0;
}