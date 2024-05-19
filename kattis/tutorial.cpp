#include <iostream>
#include <cmath>
#include <vector>
#define LL unsigned long long
using namespace std;

int main(void) {
	LL m, op, v, lim;
	cin >> m >> op >> v;
	switch(v) {
	case 1:
		lim = 1;
		for(LL i=op; i>=1; i--) {
			lim *= i;
			//cout << lim << endl;
			if (lim > m) {
				cout << "TLE" << endl;
				break;
			}
			if (i==1) {
				cout << "AC" << endl;
				break;
			}
		}
		break;
	case 2:
		lim = 1;
		for(LL i=0; i<op; i++) {
			lim *= 2;
			if (lim > m) {
				cout << "TLE" << endl;
				break;
			}
			if (i == op-1) {
				cout << "AC" << endl;
				break;
			}
		}
		break;
	case 3:
		if(m<op*op*op*op) {
			cout << "TLE\n";
			//break;
		}
		else {
			cout << "AC\n";
		}
		break;
	case 4:
		if(m<op*op*op) {
			cout << "TLE\n";
		}
		else {
			cout << "AC\n";
		}
		break;
	case 5:
		if(m<op*op) {
			cout << "TLE\n";
		}
		else {
			cout << "AC\n";
		}
		break;
	case 6:
		if(m<op*log(op)/log(2)) {
			cout << "TLE\n";
		}
		else {
			cout << "AC\n";
		}
		break;
	case 7:
		if(m<op) {
			cout << "TLE\n";			
		}
		else {
			cout << "AC\n";
		}
		break;
	}
	return 0;
}
