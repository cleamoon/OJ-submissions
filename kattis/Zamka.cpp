#include <iostream>
#include <string>
#include <cmath>
#define ULL unsigned long long
using namespace std;

ULL digitalsum(ULL in, ULL res=0) {
	if(!in) return res;
	else return digitalsum(in/10, res+in%10);
}

int main(void) {
	ULL l, r, s;
	cin >> l >> r >> s;
	ULL maximum = l-1;
	ULL minimum = r+1; 
	for(ULL i=l; i<=r; i++) {
		if(digitalsum(i) == s) {
			if(i > maximum) maximum = i;
			if(i < minimum) minimum = i;
		}
	}
	cout << minimum << endl << maximum << endl;
	return 0;
}