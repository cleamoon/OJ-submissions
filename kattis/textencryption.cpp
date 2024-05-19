#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
#define LL int
//#define FF double

//ios::sync_with_stdio(false);
//cin.tie(NULL);

bool debug=false;

int main(void) {
	LL n;
	while(1) {
		scanf("%d", &n); getchar();
		if(!n) break;
		string str; getline(cin, str);
		LL l = str.length(), nspace = 0;
		for(LL i=0; i<l; i++) if(isspace(str[i])) nspace++;
		l -= nspace;
		string out (l, ' ');
		LL pos=0;
		if(debug) {
			//cout << n << endl;
			cout << nspace << endl;
		}
		for(LL i=0; i<n; i++) {
			LL j=0, p;
			while(1) {
				p=i+n*j; 
				if(p>=l) break; 
				char c = str[pos];
				if(!isspace(c)) {
					out[p] = toupper(c);
					pos++;
				}
				else {
					j--;
					pos++;
				}
				if(debug) {
					//cout << p << endl;
				}
				j++;
			}
		}
		printf("%s\n", out.c_str());
	}
	return 0;
}
