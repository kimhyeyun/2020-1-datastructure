#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
	}
};

class SLinkedList {
public:
	Node* head;
	Node* tail;

	SLinkedList() {
		head = NULL;
		tail = NULL;
	}

	void addFront(int data) {
		Node* newN = new Node(data);
		if (head == NULL)
			head = tail = newN;
		else {
			newN->next = head;
			head = newN;
		}
	}

	int removeFront() {
		if (head == NULL)
			return -1;
		else {
			Node* tmp = head;
			head = head->next;
			return tmp->data;
		}
	}

	int front() {
		if (head == NULL)
			return -1;
		else
			return head->data;
	}

	bool empty() {
		if (head == NULL)
			return 1;
		else
			return 0;
	}
};

int main() {
	SLinkedList ll;
	int N;
	string str;
	int x;
	cin >> N;
	while (N--) {
		cin >> str;

		if (str == "addFront") {
			cin >> x;
			ll.addFront(x);
		}
		else if (str == "removeFront") {
			cout << ll.removeFront() << "\n";
		}
		else if (str == "front")
			cout << ll.front() << '\n';
		else if (str == "empty")
			cout << ll.empty() << "\n";
	}
	return 0;
}