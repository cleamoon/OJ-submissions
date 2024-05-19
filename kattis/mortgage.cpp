#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
/*
typedef double FF;
typedef int LL;
*/

#define FF double
#define LL long long
#define EPS 0.000000001

FF power(FF base, LL times) {
	FF out = base;
	for(LL i=1; i<times; i++) {
		out *= base;
	}
	return out;
}

int main(void) {
	FF total, month, rate;
	LL year;
	while(1) {
		//cin >> total >> month >> year >> rate; 
		scanf("%lf%lf%lld%lf", &total, &month, &year, &rate);
		LL m = 12*year;
		if(total==0) break;
		if(rate < EPS) {
			if(total/month/12 < year) {
				printf("YES\n");
				continue;
			}
			else {
				printf("NO\n");
				continue;
			}
		}
		
		FF a = pow((1+rate/1200), m);
		if(total*a < month*(a-1)/(rate/1200)) {
			printf("YES\n");
			continue;
		}
		else {
			printf("NO\n");
			continue;
		}
	}
	return 0;
}