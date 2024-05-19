#include <bits/stdc++.h>
#define LL unsigned long long
using namespace std;

bool find_cd(vector <LL> mcd, LL tmp) {
	LL sup = 0, upp = mcd.size(), curr;
	while(1) {
		curr = (sup + upp) / 2;
		if(mcd[curr] == tmp) return true;
		else if (sup == upp) return false;
		else if(mcd[curr] < tmp) sup = curr+1;
		else upp = curr-1;

		// cout << curr << sup << upp << mcd[curr] << tmp << endl;

	}
}

int main(void) {
	while(1) {
		LL m, n;
		cin >> m >> n;
		if(!m && !n) break;
		vector <LL> mcd, ncd, v (max(m,n));
		for(LL i=0; i<m; i++) {
			LL tmp; cin >> tmp;
			mcd.push_back(tmp);
		}
		/*
		for(LL i=0; i<n; i++) {
			LL tmp; cin >> tmp;
			if(find_cd(mcd, tmp)) ans++;
		}
		cout << ans << endl;
		*/
		for(LL i=0; i<n; i++) {
			LL tmp; cin >> tmp;
			ncd.push_back(tmp);
		}
		vector <LL>::iterator it = set_intersection(mcd.begin(), mcd.end(), 
				ncd.begin(), ncd.end(), v.begin());
		cout << it-v.begin() << endl;
	}
	return 0;
}
