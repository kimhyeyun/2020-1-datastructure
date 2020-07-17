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
		this->chi.push_back(ch);
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

	void insertNode(int parent_data, int child_data) {
		Node* newNode = new Node(child_data);

		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == parent_data) {
				node_list[i]->insertChild(newNode);
				newNode->par = node_list[i];
				node_list.push_back(newNode);
			}
		}
	}

	void printChild(int parent_data) {
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == parent_data) {
				if (node_list[i]->chi.size() == 0)
					cout << "0" << "\n";
				else {
					for (int j = 0; j < node_list[i]->chi.size(); j++)
						cout << node_list[i]->chi[j]->data << " ";
					cout << "\n";
				}
			}
		}
	}
};

int main() {
	Tree *tree=new Tree(1);
	int N, M, p, c;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> p;
		while (1) {
			cin >> c;
			if (c == 0)
				break;
			tree->insertNode(p, c);
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> p;
		tree->printChild(p);
	}
}