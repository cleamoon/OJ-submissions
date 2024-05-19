#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define LL long long
using namespace std;

int main(void) {
	LL in;
	cin >> in;
	LL d = in/25;
	LL lim;
	if(in%25) {
		lim = (d+1)*25;
		d += 2;
	}
	else {
		d += 1;
		lim = in;
	}
	char* s;
	s = (char*) malloc((d+1)*sizeof(char));
	memset(s, '\0', (d+1));
	for(LL i=0; i<d; i++) {
		if(i%2) {
			s[i] = 'z';
		}
		else {
			s[i] = 'a';
		}
	}
	//printf("%s", s);
	LL diff = lim - in;
	//cout << s << endl;
	if(d>2) {
		s[1] -= diff/2;
		if(diff%2) {
			if(s[d-1]>s[d-2]) s[d-1]--;
			else s[d-1]++;
		}
	}
	else {
		s[1] -= diff;
	}

	printf("%s", s);
	free(s);
	return 0;
}