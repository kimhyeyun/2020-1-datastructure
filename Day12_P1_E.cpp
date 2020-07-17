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

int hasfunc(int idx) {
	return idx % MAX;
}

void insertHash(int v, int k) {
	int h = hasfunc(k);

	if (HashArr[h].flag == false) {
		HashArr[h].data = v;
		HashArr[h].flag = true;
		sz++;
		return;
	}
	else
		return insertHash(v, k + 1);
}

void printprobe(int v) {
	int h = hasfunc(v);
	int cnt = 1;

	for (int i = 0; i < sz; i++) {
		if (HashArr[h].data == v) {
			cout << 1 << " " << cnt << "\n";
			return;
		}
		else if (HashArr[h].flag == false) {
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
	int T, N, x, M;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;

		for (int j = 0; j < N; j++) {
			cin >> x;
			insertHash(x, x);
		}
		cin >> M;
		
		for (int j = 0; j < M; j++) {
			cin >> x;
			printprobe(x);
		}
		for (int j = 0; j < MAX; j++) {
			HashArr[j].data = 0;
			HashArr[j].flag = false;
		}
	}
}