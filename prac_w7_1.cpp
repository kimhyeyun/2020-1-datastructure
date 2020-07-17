#include<iostream>
#include<vector>
using namespace std;

struct Node {
public:
	int data;
	Node* par;
	vector<Node*> chi;
	
	Node(int data) {
		this->data = data;
		this->par = NULL;
	}

	void insertChild(Node* ch) {
		chi.push_back(ch);
	}
};

class Tree {
public:
	Node* root;
	vector<Node*> node_list;

	Tree(int data) {
		root = new Node(data);
		node_list.push_back(root);
	}

	void insert(int parent_data, int child_data) {
		Node* newN = new Node(child_data);

		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == parent_data) {
				node_list[i]->insertChild(newN);
				newN->par = node_list[i];
				node_list.push_back(newN);
			}
		}
	}

	void printPre(Node* root) {
		cout << root->data << " ";
		for (int i = 0; i < root->chi.size(); i++)
			printPre(root->chi[i]);
	}

	void printPost(Node* root) {
		for (int i = 0; i < root->chi.size(); i++)
			printPost(root->chi[i]);
		cout << root->data << " ";
	}

};

int main() {
	Tree* tree = new Tree(1);

	int N, p, c;
	cin >> N;
	while (N--) {
		cin >> p;
		while (1) {
			cin >> c;
			if (c == 0)
				break;
			tree->insert(p, c);
		}
	}
	tree->printPre(tree->root);
	cout << "\n";
	tree->printPost(tree->root);
	cout << "\n";
}