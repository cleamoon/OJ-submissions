#include <bits/stdc++.h>
using namespace std;

int main(void) {
	double L, K, T1, T2, H;
	cin >> L >> K >> T1 >> T2 >> H;
	if(H < L) {
		printf("%.9lf %.9lf\n", H, H);
	}
	else {
		double ans;
		double S = H+(T1+T2)*K;
		if((H-L)<1e-8) {
			ans = H;
		}
		else {
			ans = (S/T1+sqrt(S*S/T1/T1-4*L*K/T1))/2*T1;
		}
		printf("%.9lf %.9lf\n", ans, (S/T1+sqrt(S*S/T1/T1-4*L*K/T1))/2*T1);
	}
	return 0;
}
