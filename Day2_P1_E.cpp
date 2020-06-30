#include<iostream>
using namespace std;

class arr {
public:
	int ar[10000] = { 0, };


	int at(int index) {
		if(ar[index] != 0)
			return ar[index];
		return 0;
	}

	void set(int index, int x) {
		if (ar[index] == 0) {
			cout << 0 << "\n";
			return;
		}
		ar[index] = x;
	}

	void add(int index, int x) {
		int tmp;
		int i = 0;
		while (1) {
			if (ar[i] == 0) {
				tmp = i;
				break;
			}
			i++;
		}
		if (ar[index] != 0 && tmp >= index) {
			for (int j = tmp; j >= index; j--) {
				ar[j + 1] = ar[j];
			}
			ar[index] = x;
			return;
		}
		else if (ar[0] == 0)
			ar[0] = x;
		else
			ar[tmp] = x;
	}

};

int main() {
	arr myar;
	string str;
	int m,x,a,b;
	cin >> m;

	while (m--) {

		cin >> str;
		if (str == "at") {
			cin >> x;
			cout << myar.at(x) << "\n";
		}
		else if (str == "add") {
			cin >> a >> b;
			myar.add(a, b);
		}
		else if (str == "set") {
			cin >>a >> b;
			myar.set(a, b);
		}
	}
	return 0;
}