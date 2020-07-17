#include<iostream>
using namespace std;

#define MAX 353333

struct arr {
public:
	int data;
	bool flag = false;
	bool dflag = false;
};

arr HashArr[MAX];
int sz = 0;

int hashfunc(int idx) {
	return idx % MAX;
}

void insertHash(int value, int key) {
	int h = hashfunc(key);

	while (HashArr[h].flag) {
		h++;
	}

	HashArr[h].data = value;
	HashArr[h].flag = true;
	return;
}

void removeHash(int value) {
	int h = hashfunc(value);
	int cnt = 1;

	while (1) {
		if (HashArr[h].data == value) {
			cout << 1 << " " << cnt << "\n";
			HashArr[h].data = 0;
			HashArr[h].flag = false;
			HashArr[h].dflag = true;
			return;
		}
		else if (HashArr[h].flag == false && HashArr[h].dflag == false) {
			cout << 0 << " " << cnt << "\n";
			return;
		}
		else if (h == MAX) {
			h = 0;
			cnt++;
		}
		else {
			h++;
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
			removeHash(x);
		}

		for (int i = 0; i < MAX; i++) {
			HashArr[i].data = 0;
			HashArr[i].flag = false;
			HashArr[i].dflag = false;
		}
	}
}