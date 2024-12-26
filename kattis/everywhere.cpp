#include <bits/stdc++.h>
#define ULL unsigned
using namespace std;

int main(void) {
	ULL n;
	cin >> n;
	for(ULL i=0; i<n; i++) {
		set <string> l;
		ULL c;
		cin >> c;
		string tmp;
		for(ULL j=0; j<c; j++) {
			cin >> tmp;
			l.insert(tmp);
		}
		cout << l.size() << endl;
	}
	return 0;
}