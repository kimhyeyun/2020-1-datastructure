#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int N;
		int china = 0;
		int korea = 0;
		int japan = 0;
		int kor = 0;
		int jap = 0;
		int chi = 0;

		cin >> N;
		int* gemgo = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> gemgo[i];
			if (i % 3 == 0) {
				korea += gemgo[i];
				if(gemgo[i]!=0)
					kor++;
			}
			else if (i % 3 == 1) {
				japan += gemgo[i];
				if (gemgo[i] != 0)
					jap++;
			}
			else {
				china += gemgo[i];
				if (gemgo[i] != 0)
					chi++;
			}
		}
		cout << korea << " " << japan << " " << china << endl;

		if (kor != 0)
			cout << floor(korea / kor) << " ";
		else
			cout << 0 << " ";
		if (jap != 0)
			cout << floor(japan / jap) << " ";
		else
			cout << 0 << " ";

		if (chi != 0)
			cout << floor(china / chi) << endl;
		else
			cout << 0 << endl;
	}
}