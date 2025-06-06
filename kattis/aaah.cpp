#include <iostream>
#include <string>
#define LL unsigned
using namespace std;

int main(void) {
	string s1, s2;
	cin >> s1 >> s2;
	if(s1.length()>=s2.length())
		cout << "go" << endl;
	else
		cout << "no" << endl;
	return 0;
}
