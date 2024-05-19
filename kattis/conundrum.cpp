#include <iostream>
#include <string>
#define LL int
using namespace std;

int main(void) {
	LL ans=0;
	string str;
	cin >> str;
	LL l=str.length();
	for(LL i=0; i<l; i++) {
		if((i%3==0)&&(str[i]!='P'))
			ans++;
		else if((i%3==1)&&(str[i]!='E'))
			ans++;
		else if((i%3==2)&&(str[i]!='R'))
			ans++;
		else
			continue;
	}
	cout << ans << endl;
	return 0;
}
