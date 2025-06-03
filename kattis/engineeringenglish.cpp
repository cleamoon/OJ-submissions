#include <iostream>
#include <set>
#include <string>
#define LL long long
using namespace std;

string tolow(string s) {
	string t=s;
	LL l=s.size();
	for(LL i=0; i<l; i++) {
		if(isupper(s[i])) {
			t[i] = tolower(s[i]);
		}
	}
	return t;
}

int main(void) {
	set <string> li;
	string str;
	while(cin >> str) {
		char c=getchar();
		set<string>::iterator it = li.find(tolow(str));
		if((!li.empty())&&(it != li.end())) {
			cout << ".";
		}
		else {
			li.insert(tolow(str));
			cout << str;
		}
		cout << c;
		//cout << li.size() << endl;
	}
	return 0;
}