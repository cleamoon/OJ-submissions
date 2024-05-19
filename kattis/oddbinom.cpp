#include <iostream>
#include <vector>
#define ULL unsigned long long
using namespace std;

inline ULL power(ULL bas, ULL pow) {
	ULL tmp=1; 
	for(ULL i=0; i<pow; i++) {
		tmp *= bas;
	}
	return tmp;
}

int main(void) {
	vector <bool> bin;
	ULL in, res=0, ant=0;
	cin >> in;
	while(in!=0) {
		if(in%2 == 1) {
			bin.push_back(true);
			in --;
		}
		else {
			bin.push_back(false);
		}
		in /= 2;
	}
	ULL l = bin.size();
	for(int i=l-1; i>=0; i--) {
		if(bin[i]) {
			//cout << l << " " << i << ": ";
			//cout << power(2,ant) << " " << power(3,l-i-1) << endl;
/*			if(i!=l-1) {
				if(bin[i+1]) {
					res += power(2,l-i-1)*power(3,i);
				}
				else {
					res += power(2,l-i-1)*power(3,i)/2;
				}
			}
			else {*/
				res += power(2,ant)*power(3,i);
//			}
			ant++;
		}
	}
	cout << res << endl;
	return 0;
}
