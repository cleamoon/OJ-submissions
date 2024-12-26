#include <iostream>
#include <string>
#define LL unsigned long long
using namespace std;

int main(void) {
	string str;
	cin >> str;
	LL letters[26];
	for(LL i=0; i<26; i++) {
		letters[i]=0;
	}
	for(LL i=0; i<str.length(); i++) {
		letters[str[i]-'a']++;
	}
	LL ans=0;
	for(LL i=0; i<26; i++) {
		if(letters[i]%2)
			ans++;
	}
	if(ans)
		cout << ans-1 << endl;
	else
		cout << ans << endl;
	return 0;
}


