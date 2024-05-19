#include <bits/stdc++.h>
#define ULL int
using namespace std;

int main(void) {
	ULL a, b, c;
	cin >> a >> b >> c;
	if(a+b == c) cout << a << "+" << b << "=" << c << endl;
	else if(a-b == c) cout << a << "-" << b << "=" << c << endl;
	else if(a*b == c) cout << a << "*" << b << "=" << c << endl;
	else if(a == b*c) cout << a << "=" << b << "*" << c << endl;
	else if(a == b+c) cout << a << "=" << b << "+" << c << endl;
	else if(a == b-c) cout << a << "=" << b << "-" << c << endl;
	else if(!(a/b)&&(a/b == c)) cout << a << "/" << b << "=" << c << endl;
	else if(!(!b/c)&&(b/c == a)) cout << a << "=" << b << "/" << c << endl;
	else cout << "what the hell?" << endl;
	return 0;
}