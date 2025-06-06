#include <iostream>
#include <iomanip>
#define LL unsigned long long
#define FF double
#define eps 0.00000001
#define MAX 100000000
using namespace std;


FF abs(FF in) {
	if(in < 0) return -in;
	else return in;
}

LL power10 (LL in, LL ans=1) {
	if(!in)
		return ans;
	else
		return power10(in-1, ans*10);
}

LL near(FF in) {
	FF err = in - (FF)(LL)in;
	//cout.precision(15);
	//cout << in << " near " << (FF)(LL)in << endl;
	if(err>=0.5) return (LL)in+1;
	else return (LL) in;
}

LL ant_dig(LL in, LL ans=0) {
	if(!in) return ans;
	else return ant_dig(in/10, ans+1);
}

int main(void) {
	//setprecision(9);
	FF x;
	cin >> x;
	if(x >= 10.0) {
		cout << "No solution" << endl;
		return 0;
	}
	bool exist=false;
	for(LL i = 0; i < 9; i++) {
		FF fac = (x*((FF)power10(i))-1.0)/(10.0-x);
		//cout << endl << endl << fac << endl << endl;
		for(LL a = 1; a < 10; a++) {
			FF b = ((FF)a) * fac;
			/*
			FF b = fac;
			for(LL j=1; j < a; k++) {
				b += fac;
			}
			*/
			//cout << "b: " << b << endl; 
			LL hel = near(b);
			LL nb = ant_dig(hel);
			if(nb>i) break;
			if(abs(b-((FF)hel))<eps) {
				//cout << "a: " << a << " b: " << b << " hel: " << hel << endl;
				LL out = hel+a*power10(nb);
				if(out < MAX) {
					cout << hel+a*power10(nb) << endl;
					exist = true;
				}
				else {
					break;
				}
			}
		}
	}
	if(!exist) {
		cout << "No solution" << endl;
	}
	return 0;
}
