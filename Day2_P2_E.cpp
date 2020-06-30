#include<iostream>
using namespace std;

int main() {
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int N;
		int china = 0;
		int korea = 0;
		int japan = 0;
		
		cin >> N;
		int* gemgo = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> gemgo[i];
			if (i % 3 == 0)
				korea += gemgo[i];
			else if (i % 3 == 1)
				japan += gemgo[i];
			else
				china += gemgo[i];
		}
		cout << korea << " " << japan << " " << china << endl;
	}
}