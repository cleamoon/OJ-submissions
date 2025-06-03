#include <bits/stdc++.h>
#define inf 1e10
using namespace std;

double p, a, b, c, d;

double price(double k) {
	return p*(sin(a*k+b)+cos(c*k+d)+2);
}

int main(void) {
	unsigned n;
	cin >> p >> a >> b >> c >> d >> n;
	vector <double> p;
	vector <double> m;
	for(unsigned i=0; i<n; i++) {
		p.push_back(price(i+1));
	}
	double minimal = inf;
	for(unsigned i=0; i<n; i++) {
		double tmp = p[n-i-1];
		if(tmp < minimal) {
			minimal = tmp;
		}
		m.push_back(minimal);
	}
	reverse(m.begin(), m.end());
	double maximum = 0.0;
	for(unsigned i=0; i<n; i++) {
		if(p[i] > m[i] && (p[i]-m[i])>maximum ) {
			maximum = p[i]-m[i];
		}
	}
	printf("%.10F\n", maximum);
	return 0;
}