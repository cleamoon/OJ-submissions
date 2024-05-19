#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int t, tt, c, cc, in;
	cin >> t;
	for(tt = 0; tt < t; tt++) {
		cin >> c;
		vector <int> v;
		for(cc = 0; cc < c; cc++) {
			cin >> in;
			auto it = find(v.begin(), v.end(), in);
			if(it == v.end()) v.push_back(in);
			else v.erase(it);
		}
		cout << "Case #" << tt+1 << ": " << v[0] << endl;
	}
	return 0;
}
