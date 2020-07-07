#include<iostream>
#include<vector>
using namespace std;

struct Node {
public:
	int data;
	vector<Node*> child;
	Node* par;

	Node(int data) {
		this->data = data;
		this->par = NULL;
	}

	void InsertChild(Node* chi) {
		child.push_back(chi);
	}
};

class Tree {
public:
	Node* root;
	vector<Node*> node_list;

	Tree(int data) {
		this->root = new Node(data);
		this->node_list.push_back(root);
	}

	void insert(int par_data, int child_data) {
		Node* newN = new Node(child_data);

		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == par_data) {
				node_list[i]->InsertChild(newN);
				newN->par = node_list[i];
				node_list.push_back(newN);
			}
		}
	}

	void printPre(Node* tree) {
		cout << tree->data << " ";
		for (int i = 0; i < tree->child.size(); i++)
			printPre(tree->child[i]);
	}

	void printPost(Node* tree) {
		for (int i = 0; i < tree->child.size(); i++)
			printPost(tree->child[i]);
		cout << tree->data << " ";
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		Tree* tree = new Tree(1);

		int N;
		cin >> N;
		while (N--) {
			int p, c;
			cin >> p >> c;
			tree->insert(p, c);
		}
		tree->printPre(tree->root);
		cout << "\n";
		tree->printPost(tree->root);
		cout << "\n";
	}
}