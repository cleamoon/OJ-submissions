#include <iostream>
#include <string>
using namespace std;

typedef int LL;

int main(void) {
	LL h, m;
	cin >> h >> m;
	if(m<45) {
		h--; 
		m = m + 60 - 45;
		if(h<0) {
			h = 23;
		}
	}
	else {
		m -= 45;
	}
	cout << h << " " << m << endl;
	return 0;
}