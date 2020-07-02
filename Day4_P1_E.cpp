#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class Stack {
public:
	Node* head;
	Node* tail;
	int sz;

	Stack() {
		head = NULL;
		tail = NULL;
		sz = 0;
	}

	void Push(int data) {
		Node* newN = new Node(data);

		if (head == NULL) {
			head = tail = newN;
		}
		else {
			newN->next = head;
			head = newN;
		}
		this->sz++;
	}

	int top() {
		if (sz == 0)
			return -1;
		return head->data;
	}

	bool empty() {
		if (sz == 0)
			return 1;
		return 0;
	}
};

int main() {
	Stack stk;
	int N, x;
	string str;

	cin >> N;

	while (N--) {
		cin >> str;
		if (str == "push") {
			cin >> x;
			stk.Push(x);
		}
		else if (str == "top") {
			cout << stk.top() << "\n";
		}
		else if (str == "empty")
			cout << stk.empty() << "\n";
	}
}