#include<iostream>
#include<stdio.h>
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
			int tempt = tmp->data;
			head = head->next;
			delete tmp;
			this->sz--;
			return tempt;
		}
	}

	int front() {
		if (head == NULL)
			return -1;
		else
			return head->data;
	}

	void changeHead(int chang) {
		this->head->data = chang;
	}

};


int main() {
	int T, N, x;


	cin >> T;

	for (int j = 0; j < T;j++) {
		cin >> N;
		LinkedQueue q1;
		LinkedQueue q2;
		int sc1 = 0;
		int sc2 = 0;
		for (int i = 0; i < N; i++) {
			cin >> x;
			q1.enqueue(x);
		}
		for (int k = 0; k < N; k++) {
			cin >> x;
			q2.enqueue(x);
		}
		bool b1 = false;
		bool b2 = false;
		int y = 0;
		while (1) {
			int a = q1.dequeue();
			int b = q2.dequeue();
			if (a == -1)
				break;
			if (b1)
				a = a + y;
			if (b2)
				b += y;
			if (a > b) {
				sc1++;
				y = a - b - 1;
				b1 = true;
				b2 = false;
			}
			else if (a < b) {
				sc2++;
				y = b - a - 1;
				b1 = false;
				b2 = true;
			}
			else {
				b1 = false;
				b2 = false;
			}
		}
		if (sc1 > sc2)
			printf("1\n");
		else if (sc1 < sc2)
			printf("2\n");
		else
			printf("0\n");

	}

	return 0;
}