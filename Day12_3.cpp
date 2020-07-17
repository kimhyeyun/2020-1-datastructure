#include<iostream>
using namespace std;
#define MAX 353333

struct arr {
public:
	int data;
	bool flag = false;
};

arr HashArr[MAX];
int sz = 0;

int hashfunc(int idx) {
	return idx % MAX;
}

int hashfunc2(int idx) {
	return (17 - (idx % 17));
}


void insertHash(int value, int key) {
	int h = hashfunc(key);
	int d = hashfunc2(key);

	while (HashArr[h].flag) {
		h += d;
	}

	HashArr[h].data = value;
	HashArr[h].flag = true;
}

void Search(int value) {
	int h = hashfunc(value);
	int d = hashfunc2(value);
	int cnt = 1;

	while (1) {
		if (HashArr[h].data == value) {
			cout << 1 << " " << cnt << "\n";
			return;
		}
		else if (h >= MAX) {
			h = MAX - h;
			cnt++;
		}
		else if (!HashArr[h].flag) {
			cout << 0 << " " << cnt << "\n";
			return;
		}
		else {
			h+=d;
			cnt++;
		}
	}
}

int main() {
	int T, N, M, x;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		while (N--) {
			cin >> x;
			insertHash(x, x);
		}
		cin >> M;
		while (M--) {
			cin >> x;
			Search(x);
		}

		for (int i = 0; i < MAX; i++) {
			HashArr[i].data = -1;
			HashArr[i].flag = false;
		}
	}
}