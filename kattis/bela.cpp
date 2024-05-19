#include <bits/stdc++.h>
#define ULL unsigned
using namespace std;

int main(void) {
	char d;
	string in;
	char v, s;
	map <char, ULL> dom;
	dom['A'] = 11;
	dom['K'] = 4;
	dom['Q'] = 3;
	dom['J'] = 20;
	dom['T'] = 10;
	dom['9'] = 14;
	dom['8'] = 0;
	dom['7'] = 0;
	map <char, ULL> und;
	und['A'] = 11;
	und['K'] = 4;
	und['Q'] = 3;
	und['J'] = 2;
	und['T'] = 10;
	und['9'] = 0;
	und['8'] = 0;
	und['7'] = 0;
	ULL n;
	cin >> n >> d;
	n *= 4;
	ULL ans = 0;
	for(ULL i=0; i<n; i++) {
		cin >> in;
		if(in[1] == d) {
			ans += dom.find(in[0])->second;
		}
		else {
			ans += und.find(in[0])->second;
		}
	}
	cout << ans << endl;
	return 0;
}