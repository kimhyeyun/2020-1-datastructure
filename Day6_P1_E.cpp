#include<iostream>
using namespace std;

struct Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class LinkedQueue {
public:
	Node* head;
	Node* tail;
	int sz;

	LinkedQueue() {
		this->head = NULL;
		this->tail = NULL;
		this->sz = 0;
	}

	void enqueue(int data) {
		Node* newN = new Node(data);
		if (head == NULL) {
			head = tail = newN;
		}
		else {
			tail->next = newN;
			tail = newN;
		}
		this->sz++;
	}

	int size() {
		return sz;
	}

	bool isEmpty() {
		if (sz == 0)
			return 1;
		return 0;
	}


};

int main() {
	LinkedQueue lq;

	int S, N,x;
	string str;

	cin >> S >> N;

	while (N--) {
		cin >> str;
		if (str == "enqueue") {
			cin >> x;
			if (lq.sz == S)
				cout << "Full" << "\n";
			else
				lq.enqueue(x);
		}
		else if (str == "size") {
			cout << lq.size() << "\n";
		}
		else if (str == "isEmpty") {
			cout << lq.isEmpty() << "\n";
		}
	}
}