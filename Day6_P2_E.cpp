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

	int dequeue() {
		if (head == NULL)
			return -1;
		else {
			Node* tmp = head;
			head = head->next;
			int tm = tmp->data;
			delete tmp;
			this->sz--;
			return tm;
		}
	}

	int front() {
		if (head == NULL)
			return -1;
		else
			return head->data;
	}

	void rear() {
		if (head == NULL)
			return;
		else
			cout << tail->data << "\n";
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
	LinkedQueue lq1;
	LinkedQueue lq2;

	int T, N, x;


	cin >> T;

	while(T--){
		int s1 = 0;
		int s2 = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> x;
			lq1.enqueue(x);
		}
		for (int i = 0; i < N; i++) {
			cin >> x;
			lq2.enqueue(x);
		}

		while(lq1.sz!=0) {
			if (lq1.front()< lq2.front())
				s2++;
			else if (lq1.front()>lq2.front())
				s1++;
			lq1.dequeue();
			lq2.dequeue();
		}
		if (s1 > s2)
			cout << 1 << "\n";
		else if (s1 < s2)
			cout << 2 << "\n";
		else
			cout << 0 << "\n";
	}
	return 0;
}