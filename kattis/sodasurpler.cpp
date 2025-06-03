#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
	ll e, f, c, ans=0;
	cin >> e >> f >> c;
	ll left = e+f;
	while(1) {
		if(left < c) break;
		else {
			ll tmp = left/c;
			ans += tmp;
			left = left%c + tmp;
		}
	}
	cout << ans << endl;
	return 0;
}
