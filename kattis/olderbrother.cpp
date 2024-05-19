#include <bits/stdc++.h>
using namespace std;

/*
int main(void) {
	int* prime = (int*) malloc((int)1e5*sizeof(int));
	int n=1;
	bool* pr = (bool*) malloc (3.5e4*sizeof(bool));
	memset(pr, 1, (int)3.5e4);
	for(int i=3; i<(int)3.5e4; i+=2) {
		if(pr[i]) {
			for(int j=i*i; j<(int)3.5e4; j += i) {
				pr[j] = 0;
				//cout << j << endl;
			}
		}
	}
	prime[0]=2;
	for(int i=3; i<3.5e4; i+=2) {
		if(pr[i]) {
			prime[n]=i;
			n += 1;
		}
	} 

	int in;
	cin >> in;
	set <int> div;
	int endi=0;
	//cerr << "eeadsf" << endl;
	for(;;) {
		if(in==1) {
			if(div.empty()) {
				cout << "no" << endl;
				break;
			}
			else {
				if(div.size()==1) {
					cout << "yes" << endl;
					break;
				}
			}
		}
		else {
			for(int i=endi; i<n; i++) {
				if(!in%prime[i]) {
					in /= prime[i];
					endi = i;
					div.insert(prime[i]);
					if(div.size()!=1) {
						cout << "no" << endl;
						return 0;
					}
					break;
				}
			}
		}
	}
	return 0;
}
*/
/*
int main(void) {
	int in;
	cin >> in;
	for(int i=1; i<20; i++) {

	}
}
*/

bool isPrimePower (int q) {
	if ( q==1 ) 
		return false;
	for(int p = 2 ; p*p <= q ; p ++ ) {
		if ( q%p == 0 ) {
			while ( q%p == 0 )
				q /= p ;
			return q == 1 ;
		}
	}
	return true;
}


int main () {
	int in;
	cin >> in;
	if(isPrimePower(in)) {
		cout << "yes" << endl;
	}
	else 
		cout << "no" << endl;
	return 0;
}
