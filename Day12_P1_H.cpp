#include<iostream>
using namespace std;

#define MAX 353333


class arr {
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

void insertHash(int v, int k) {
	int h = hashfunc(k);

	if (HashArr[h].flag == false) {
		HashArr[h].data = v;
		HashArr[h].flag = true;
		sz++;
		return;
	}
	else
		return insertHash(v, k + 1);
}

void removehash(int v) {
	int h = hashfunc(v);
	int cnt = 1;

	for (int i = 0; i < MAX; i++) {
		if (HashArr[h].data == v) {
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
			removehash(x);
		}
		for (int j = 0; j < MAX; j++) {
			HashArr[j].data = 0;
			HashArr[j].flag = false;
			HashArr[j].dflag = false;
		}
	}
}