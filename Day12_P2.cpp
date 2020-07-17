#include<iostream>
using namespace std;

#define MAX 353333

class arr {
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
	return(17 - (idx % 17));
}

void insertHash(int v, int k) {
	int h = hashfunc(k);
	int d = hashfunc2(k);

	if (HashArr[h].flag == true) {
		while (HashArr[h].flag == true) {
			h += d;
			if (h >= MAX)
				h = MAX - h;
		}
	}
	HashArr[h].data = v;
	HashArr[h].flag = true;
	sz++;
	return;
}

void printprobe(int v) {
	int h = hashfunc(v);
	int d = hashfunc2(v);
	int cnt = 1;
	while (HashArr[h].flag == true) {
		if (HashArr[h].data == v) {
			cout << 1 << " " << cnt << "\n";
			return;
		}
		else {
			h += d;
			cnt++;
			if (h >= MAX)
				h = MAX - h;
		}
	}
	cout << 0 << " " << cnt << "\n";
	return;
}

int main() {
	int T, N, M, x;
	cin >> T;
	while (T--) {
		cin >> N;
		while (N--) {
			cin >> x;
			insertHash(x, x);
		}
		cin >> M;
		while (M--) {
			cin >> x;
			printprobe(x);
		}
		for (int i = 0; i < MAX; i++) {
			HashArr[i].data = 0;
			HashArr[i].flag = false;
		}
	}
}