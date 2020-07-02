#include<iostream>
#include<string.h>
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
	int pop() {
		if (sz == 0)
			return -1;
		else {
			int tmp = head->data;
			head = head->next;
			sz--;
			return tmp;
		}
	}
};

int main() {
	int N, x;
	string str;

	cin >> N;

	while (N--) {
		Stack stk;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (48 <= str[i] && str[i] <= 57) {
				x = str[i] - '0';
				stk.Push(x);
			}
			else {
				int b = stk.pop();
				int a = stk.pop();
				if (str[i] == '+') {
					x = a + b;
					stk.Push(x);
				}
				else if (str[i] == '-') {
					x = a - b;
					stk.Push(x);
				}
				else if (str[i] == '*') {
					x = a * b;
					stk.Push(x);
				}
			}
		}
		cout << stk.pop() << "\n";
	}
}