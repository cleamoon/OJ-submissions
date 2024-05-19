#include <iostream>
#include <cmath>
#include <cstdio>
#define LL unsigned long long
using namespace std;

int main(void) {
	LL a, b;
	while(scanf("%llu%llu", &a, &b)==2) {
		//	cin >> a >> b;
		if(a<b)
			cout << b-a << endl;
		else
			cout << a-b << endl;
	}
	return 0;
}
