#include <bits/stdc++.h>
using namespace std;

int main(void) {
	string str;
	cin >> str;
	int l = str.length();
	switch(l) {
	case 1:
		if(str=="1") { cout << 1 << endl; break; }
		if(str=="2") { cout << 2 << endl; break; }
		if(str=="6") { cout << 3 << endl; break; }
	case 2:
		cout << 4 << endl; break;
	case 3:
		if(str=="120") { cout << 5 << endl; break; }
		if(str=="720") { cout << 6 << endl; break; }
	case 4: 
		cout << 7 << endl; break;
	case 5:
		cout << 8 << endl; break;
	case 6:
		cout << 9 << endl; break;
	case 7:
		cout << 10 << endl; break;
	default:
		double ld = (double) l;
		for(int i=1; ; i++) {
			//cout << ld << endl;
			if(ld<(log10(i))) {
				cout << i-1 << endl; 
				break;
			}
			ld -= log10(i);
		}
		break;
	}
	return 0;
}
