#include <iostream>
#include <cmath>
//#include <ioman>
#define FF long double
#define PI 3.141592653589793238462
#define EPS 0.0000003
using namespace std;

FF del, del2;

FF ans=0.0;

inline FF sanno(FF rin, FF rou) {
	return -(exp(-rou*rou/del2)-exp(-rin*rin/del2));
}

FF area(FF in, FF ou) {
	FF out = PI*(ou*ou-in*in);
	cout << out << endl;
	return out;
}

inline void calc(FF rin, FF rou, int i) {
	FF po;
	if(i==0) po = 50.0;
	else if(i==1) po = 25.0;
	else if(i==2) po = 10.5;
	else if(i==3) po = 10.5*3.0;
	else if(i==4) po = 10.5;
	else po = 10.5*2.0;
	FF multiple = po;
	ans += sanno(rin, rou)*multiple;
	/*
	while(r<=rou) {
		ans += sanno(r)*r*multiple;
		r += EPS;
	}
	*/
}

int main(void) {
	cout.precision(15);
	FF r[7];
	r[0]=0;
	for(int i=1; i<7; i++) {
		FF tmp;
		cin >> tmp;
		r[i] = tmp;
	}

	cin >> del;
	del2 = 2*del*del;
	for(int i=0; i<6; i++) {
		calc(r[i], r[i+1], i);
	}
	cout << ans << endl;
	return 0;
}
