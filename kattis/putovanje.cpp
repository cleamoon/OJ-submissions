#include <bits/stdc++.h>
#define ULL unsigned
using namespace std;

int main(void) {
	ULL n, c, tmp;
	cin >> n >> c;
	ULL max = 0, curr;
	//vector <ULL> m;
	vector <ULL> f;
	for(ULL i=0; i<n; i++) {
		cin >> tmp;
		f.push_back(tmp);
	}
	for(ULL i=0; i<n; i++) {
		ULL eaten = 0;
		curr = 0;
		for(ULL j=i; j<n; j++) {
			if(eaten+f[j] <= c) {
				eaten += f[j];
				curr ++;
				if(eaten >= c) break;
			}
			else continue;
		}
		if (curr > max) max = curr;
	}
	cout << max << endl;
	return 0;
}