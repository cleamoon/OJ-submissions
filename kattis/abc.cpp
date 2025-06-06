#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int b;
	vector <int> a;
	for(int i=0; i<3; i++) {
		cin >> b;
		a.push_back(b);
	}
	sort(a.begin(), a.end());
	string in;
	cin >> in;
	for(int i=0; i<3; i++) {
		switch(in[i]) {
			case 'A':
				cout << a[0];
				break;
			case 'B':
				cout << a[1];
				break;
			case 'C':
				cout << a[2];
				break;
			default:
				cout << "something went wrong.\n";
				break;
		}
		if (i!=2) cout << " ";
		else cout << endl;
	}
	return 0;
}
