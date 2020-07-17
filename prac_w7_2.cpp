#include<iostream>
#include<vector>
using namespace std;

struct Node {
public:
	int num;
	int capacity;
	vector<Node*> chi;
	Node* par;

	Node(int num) {
		this->num = num;
		this->par = NULL;
	}
	
	void setCapacity(int capacity) {
		this->capacity = capacity;
	}

	void insertChild(Node* chi) {
		this->chi.push_back(chi);
	}
};

class Tree {
public:
	Node* root;
	vector<Node*> node_list;
	int sum;

	Tree(int num) {
		root = new Node(num);
		node_list.push_back(root);
		sum = 0;
	}

	void setSum() {
		this->sum = 0;
	}

	void insert(int parent, int child) {
		Node* newN = new Node(child);

		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->num == parent) {
				node_list[i]->insertChild(newN);
				newN->par = node_list[i];
				node_list.push_back(newN);
			}
		}
	}

	Node* searchNode(int data) {
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->num == data)
				return node_list[i];
		}
	}

	void printSum(Node* n) {
		for (int i = 0; i < n->chi.size(); i++)
			printSum(n->chi[i]);
		sum += n->capacity;
	}
};

int main() {
	Tree* tree = new Tree(1);
	int N, K, p, c, capacity;
	cin >> N >> K;

	int* cap = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> c >> capacity;
		cap[c] = capacity;
	}

	while (N--) {
		cin >> p;
		while (1) {
			cin >> c;
			if (c == 0)
				break;
			tree->insert(p, c);
		}
	}

	for (int i = 0; i < tree->node_list.size(); i++) {
		tree->node_list[i]->setCapacity(cap[tree->node_list[i]->num]);
	}

	while (K--) {
		tree->setSum();
		cin >> c;
		tree->printSum(tree->searchNode(c));
		cout << tree->sum << "\n";
	}
}

