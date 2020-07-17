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


	void pop() {
		if (heapSize == 0)
			return;

		else {
			data[1] = data[heapSize];
			data.pop_back();
			heapSize--;

			int idx = 1;
			while (idx * 2 <= heapSize) {
				int left = idx * 2;
				int right = idx * 2 + 1;
				int min;

				if (right <= heapSize) {
					if (data[left] <= data[right])
						min = left;
					else
						min = right;
				}
				else
					min = left;

				if (data[idx] > data[min]) {
					int tmp = data[idx];
					data[idx] = data[min];
					data[min] = tmp;
					idx = min;
				}
				else
					break;
			}
		}
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		Heap hp;

		int N, p;
		cin >> N >> p;
		while (N--) {
			int x;
			cin >> x;
			hp.insert(x);
		}
		cout << hp.data[p] << "\n";
		
		for (int i = 0; i < p - 1; i++)
			hp.pop();

		cout << hp.data[1] << "\n";
	}
	return 0;
}