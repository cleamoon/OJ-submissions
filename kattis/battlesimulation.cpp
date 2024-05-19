#include <bits/stdc++.h>
using namespace std;

int main(void) {
	string in, out;
	cin >> in;

	//cout << in.substr(4,3) << endl;

	for(int i=0; i<in.length(); i++) {
		if(i+2<in.length()) {
			string sub = in.substr(i, 3);
			//cerr << endl << i <<endl << sub << endl;
			sort(sub.begin(), sub.end());
			//cerr << endl << sub << endl;
			if(sub == "BLR") {
				cout << "C";
				i += 2;
				continue;
			}
		}
		switch(in[i]) {
			case 'R': 
				cout << 'S';
				break;
			case 'B':
				cout << 'K';
				break;
			case 'L':
				cout << 'H';
				break;
		}
	}
	cout << endl;
	return 0;
}