#include <bits/stdc++.h>
#define ULL unsigned
#define TXT "Simon says"
using namespace std;

int main(void) {
	ULL n;
	cin >> n;
	getchar();
	ULL l = ((string) TXT).length();
	//cout << ((string) "a").length() << endl;
	for(ULL i=0; i<n; i++) {
		string str;
		getline(cin, str);
		if((str.length() >= l-1)&&(str.substr(0, l) == ((string) TXT).substr(0, l))) {
			cout << str.substr(l+1) << endl;
		}
	}
	return 0;
}
