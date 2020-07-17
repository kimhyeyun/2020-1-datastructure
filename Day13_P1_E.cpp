#include<iostream>
#include<vector>
using namespace std;

#define MAX 2001

vector<vector<int>> graph(MAX, vector<int>(MAX, 0));
int ar[MAX] = { 0, };

int main() {
	int N, M, I, S, D;
	int cnt = 0;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> I;
		ar[I] = 1;
	}

	for (int i = 0; i < M; i++) {
		cin >> S >> D;
		if (ar[S] == 0 || ar[D] == 0) {
			cout << -1 << "\n";
		}
		else {
			if (graph[S][D] == 1) {
				cout << -1 << "\n";
			}
			else {
				graph[S][D] = 1;
				graph[D][S] = 1;
				cnt++;
			}
		}
	}
	cout << N << " " << cnt << "\n";
}