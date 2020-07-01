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

class LinkedList {
public:
	Node* head;
	Node* tail;

	LinkedList() {
		head = NULL;
		tail = NULL;
	}

	void add(int data) {
		Node* newN = new Node(data);
		if (head == NULL) {
			head = tail = newN;
		}
		else {
			tail->next = newN;
			tail = newN;
			tail->next = head;
		}
	}
	 
	void Delete(int idx) {
		Node* tmp = head;
		for (int i = 0; i < idx; i++)
			tmp = tmp->next;
		if (tmp == head) {
			head = head->next;
			tail->next = head;
			delete tmp;
		}
		else if (tmp == tail) {
			Node* a = head;
			while (a->next != tail)
				a = a->next;
			tail = a;
			tail->next = head;
			delete tmp;
		}
		else {
			Node* a = head;
			while (a->next != tmp)
				a = a->next;
			a->next = tmp->next;
			delete tmp;
		}
	}

	void showList() {
		Node* tmp = head;
		while (1) {
			cout << tmp->data << " ";
			if (tmp == tail)
				break;
			tmp = tmp->next;
		}
		cout << "\n";
	}
};


int main() {
	int N;
	cin >> N;
	while (N--) {
		LinkedList ll;
		for (int i = 0; i < 10; i++) {
			int x;
			cin >> x;
			ll.add(x);
		}
		for (int i = 0; i < 3; i++) {
			string str;
			int x;
			cin >> str >> x;
			ll.Delete(x);
		}
		ll.showList();
	}
}