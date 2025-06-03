#include <iostream>
#include <bits/stdc++.h>
#define ULL unsigned
using namespace std;

int main(void) {
	ULL r, c, zr, zc;
	cin >> r >> c >> zr >> zc;
	getchar();
	for(ULL k=0; k<r; k++) {
		vector <char> str;
		for(ULL i=0; i<c; i++) {
			char c = getchar();
			//vector <char> str;
			//cout << "the char is " << c << endl; 
			for(ULL j=0; j<zc; j++) {
				str.push_back(c);
			}
		}
		getchar();
		str.push_back('\n');
		//cout << "the size of str is " << str.size() << endl;
		ULL ll = str.size();
		for(ULL l=0; l<zr; l++) {
			for(ULL m=0; m<ll; m++) {
				printf("%c", str[m]);
			}
		}
	}
	return 0;
}
