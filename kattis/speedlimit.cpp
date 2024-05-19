#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

int main(void) {
	LL n;
	while(cin >> n) {
		if(n == -1) break;
		LL speed[n];
		LL time[n+1];
		time[0] = 0;
		for(LL i=0; i<n; i++) {
			LL a, b;
			cin >> a >> b;
			speed[i] = a;
			time[i+1] = b;
		}
		LL ans = 0;
		for(LL i=0; i<n; i++) {
			ans += speed[i]*(time[i+1]-time[i]);
		}
		cout << ans << " miles" << endl;
	}
	return 0;
}