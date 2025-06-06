#include <bits/stdc++.h>
#define ULL unsigned
using namespace std;

int main(void) {
	string str;
	cin >> str;
	ULL l = str.length();
	ULL half = l/2+1;
/*
	char fi = str[0];
	bool done = 1;
	for(ULL i=1; i<l; i++) {
		if(str[i] != fi) {
			done = 0;
			break;
		}
	}
	if(done) {
		cout << fi << endl;
		return 0;
	}
*/
	bool yes, overallyes = 0;
	for(ULL i = 1; i < half; i++) {
		if(!(l%i)) {
			ULL div = l/i;
			//cout << l << " " << i << endl;
			string ori = str.substr(0, i);
			//cout << " 0 i " << i << endl;
			//cout << str.substr(0, 2) << " " << str.substr(2, 4) << endl;
			string comp = ori;
			sort(comp.begin(), comp.end());
			yes = 1;
			//cout << "comp is " << comp << endl;
			for(ULL j=1; j<div; j++) {
				string cc = str.substr(j*i, i);
				//cout << "begin and end " << j*i << " " << j*i+i << endl;
				sort(cc.begin(), cc.end());
				//cout << "cc is " << cc << endl;
				if(cc != comp) {
					yes = 0;
					break;
				}
			}
			if(yes) {
				overallyes = 1;
				cout << ori << endl;
				return 0;
			}
		}
	}
	if(!overallyes) cout << "-1" << endl;
	return 0;
}