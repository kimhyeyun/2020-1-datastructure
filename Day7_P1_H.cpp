#include<iostream>
#include<vector>
using namespace std;

struct Node {
public:
	int data;
	vector<Node*> child;
	Node* par;
	int depth;

	Node(int data) {
		this->data = data;
		this->par = NULL;
		this->depth = -1;
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
		root->depth = 0;
	}

	void insert(int par_data, int child_data) {
		Node* newN = new Node(child_data);

		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == par_data) {
				node_list[i]->InsertChild(newN);
				newN->par = node_list[i];
				node_list.push_back(newN);
				newN->depth = node_list[i]->depth + 1;
				return;
			}
		}
		cout << -1 << "\n";
		return;
	}

	void printChlid(int data) {
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == data) {
				if (node_list[i]->child.size() == 0) {
					cout << 0 << "\n";
					return;
				}
				for (int j = 0; j < node_list[i]->child.size(); j++) {
					cout << node_list[i]->child[j]->data << " ";
				}
				cout << "\n";
				return;
			}
		}
		cout << "-1" << "\n";
	}

	void printDepth(int data) {
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == data) {
				cout << node_list[i]->depth << "\n";
				return;
			}
		}
		cout << "-1" << "\n";
	}
};

int main() {
	Tree* tree = new Tree(1);

	int N;
	string str;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "insert") {
			int x, y;
			cin >> x >> y;
			tree->insert(x, y);
		}
		else if (str == "printChild") {
			int x;
			cin >> x;
			tree->printChlid(x);
		}
		else if (str == "printDepth") {
			int x;
			cin >> x;
			tree->printDepth(x);
		}
	}
}