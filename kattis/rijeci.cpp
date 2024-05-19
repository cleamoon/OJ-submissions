#include <iostream>
using namespace std;

typedef long long LL;

int main(void) {
	LL t;
	cin >> t;
	LL nA = 1, nB = 0;
	for(LL i=0; i<t; i++) {
		LL tmp = nA;
		nA = nB;
		nB += tmp;
	}
	cout << nA << " " << nB << endl;
	return 0;
}