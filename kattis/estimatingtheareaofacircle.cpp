#include <bits/stdc++.h>
#define pi 3.1415926535897
#define eps 1e-6
using namespace std;

int main(void) {
	double r, m, c;
	while(1) {
		cin >> r >> m >> c;
		if (r<eps && m<eps && c<eps) break;
		printf("%.10F %.10F\n", r*r*pi, c/m*(r*r)*4);
	}
}