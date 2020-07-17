#include<iostream>
#include<vector>
using namespace std;

struct Node {
public:
	int data;
	int depth;
	Node* par;
	vector<Node*> chi;

	Node(int data) {
		this->data = data;
		this->depth = -1;
		this->par = NULL;
	}

	void insertChild(Node* chi) {
		this->chi.push_back(chi);
	}

};

class Tree {
public:
	Node* root;
	vector<Node*> node_list;

	Tree(int data) {
		root = new Node(data);
		root->depth = 0;
		node_list.push_back(root);
	}

	void insert(int parent_data, int child_data) {
		Node* newN = new Node(child_data);
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == parent_data) {
				node_list[i]->insertChild(newN);
				node_list.push_back(newN);
				newN->par = node_list[i];
				newN->depth = node_list[i]->depth + 1;
			}
		}
	}

	void printDepth(int data) {
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == data)
				cout << node_list[i]->depth << "\n";
		}
	}
};

int main() {
	Tree* tree = new Tree(1);

	int N, M, p, c;
	cin >> N >> M;

	while(N--) {
		cin >> p;
		while (1) {
			cin >> c;
			if (c == 0)
				break;
			tree->insert(p, c);
		}
	}

	while (M--) {
		cin >> c;
		tree->printDepth(c);
	}
}