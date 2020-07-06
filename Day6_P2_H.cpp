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

class Game {
public:
	LinkedQueue* q1;
	LinkedQueue* q2;
	int score1;
	int score2;

	Game() {
		this->q1 = new LinkedQueue();
		this->q2 = new LinkedQueue();
		this->score1 = 0;
		this->score2 = 0;
	}

	void ing() {
		int a = q1->front();
		int b = q2->front();
		q1->dequeue();
		q2->dequeue();
		if (a > b) {
			this->score1++;
			if (q1->sz != 0) {
				int x = q1->front();
				q1->changeHead(x + a - b - 1);
			}
		}
		else if (a < b) {
			this->score2++;
			if (q2->sz != 0) {
				int x = q2->front();
				q2->changeHead(x + b - a - 1);
			}
		}
	}

	int end() {
		if (this->score1 > this->score2)
			return 1;
		else if (this->score2 > this->score1)
			return 2;
		else
			return 0;
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