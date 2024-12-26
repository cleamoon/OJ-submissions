#include <iostream>
#include <cmath>
using namespace std;

#define LL unsigned
#define FF double

FF length = pow(2., (-3./4.));
FF divid = sqrt(2.);

int main(void) {
	//cout << length << "\n";
	cout.precision(16);
	LL n;
	cin >> n;
	n--;
	FF ans=0.;
	FF np=2., curr;
	bool doable=false;
	for(LL i=0; i<n; i++) {
		cin >> curr;
		//cout << np << " " << curr << "\n";
		if(curr >= np) {
			ans += np*length/2.;
			doable = true;
			break;
		}
		else {
			ans += np*length/2.;
			np = (np-curr)*2.;
			length /= divid;
			continue;
		}
	}
	if(doable)
		cout << ans << "\n";
	else 
		cout << "impossible\n";
	return 0;
}