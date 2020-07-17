#include<iostream>
#include<vector>
using namespace std;

class Heap {
public:
	vector<int> data;
	int heapSize;

	Heap() {
		data.push_back(-1);
		heapSize = 0;
	}

	void insert(int x) {
		data.push_back(x);
		heapSize++;

		int idx = heapSize;

		while (idx > 1) {
			if (data[idx] < data[idx / 2]) {
				int tmp = data[idx];
				data[idx] = data[idx / 2];
				data[idx / 2] = tmp;
			}
			else
				break;
			
			idx /= 2;
		}
	}

	int size() {
		return heapSize;
	}

	bool isEmpty() {
		if (heapSize == 0)
			return 1;
		return 0;
	}

	void print() {
		if (heapSize == 0) {
			cout << -1 << "\n";
			return;
		}
		else {
			for (int i = 1; i < data.size(); i++)
				cout << data[i] << " ";
			cout << "\n";
		}
	}
};

int main() {
	Heap hp;
	int N;
	cin >> N;

	while (N--) {
		string str;
		cin >> str;
		if (str == "insert") {
			int x;
			cin >> x;
			hp.insert(x);
		}
		else if (str == "size")
			cout << hp.size() << "\n";
		else if (str == "isEmpty")
			cout << hp.isEmpty() << "\n";
		else if (str == "print")
			hp.print();
	}

	return 0;
}