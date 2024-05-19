#include <string>
#include <iostream>
#define LL unsigned int
using namespace std;

int main(void) {
	LL eeo;
	cin >> eeo;
	string s1, s2;
	cin >> s1 >> s2;
	bool test=true;
	if(eeo%2) {
		for(LL i=0; i<s1.length(); i++) {
			if(s1[i]==s2[i]) {
				test=false;
				break;
			}
		}
	}
	else {
		for(LL i=0; i<s1.length(); i++) {
			if(s1[i]!=s2[i]) {
				test=false;
				break;
			}
		}
	}
	if(test) {
		cout << "Deletion succeeded" << endl;
	}
	else {
		cout << "Deletion failed" << endl;
	}
	return 0;
}
