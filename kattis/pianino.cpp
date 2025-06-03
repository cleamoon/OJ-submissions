#include <bits/stdc++.h>
#define ULL long long
using namespace std;

ULL n, f, t, ans = 0;
vector <ULL> k;
vector <ULL> in;

bool debug = 0;

int main(void) {
	cin >> n;
	cin >> f;
	k.push_back(0);
	for(ULL i=1; i<n; i++) {
		cin >> t;
		k.push_back(t-f);
	}
	ULL c = 0;
	ULL id = 0;
	in.push_back(0);
	for(ULL i=1; i<n; i++) {
		if(k[i] > c) {
			id++;
		}
		else if(k[i] < c) {
			id--;
		}
		else {
			;
		}
		in.push_back(id);
		c = k[i];
	}
	vector <ULL> res;
	for(ULL i=0; i<n; i++) {
		if(!in[i]) {
			if(!k[i]) {
				ans++;
				continue;
			}
			else continue;
			/*else
				continue;*/
		}
		/*if(!in[i]) {
			continue;
		}*/
		if(!(k[i]%in[i])) {
			res.push_back(k[i]/in[i]);
		}
	}
	map <ULL, ULL> s;
	typedef map <ULL, ULL>::iterator muui;
	for(ULL i=0; i<res.size(); i++) {
		muui it = s.find(res[i]);
		if(it == s.end()) {
			s.insert( make_pair(res[i], 1));
		}
		else {
			it->second++;
		}
	}
	ULL max = 0, cu;
	for(muui it=s.begin(); it != s.end(); it++) {
		//if(debug) cout << "map" << it-> first << " " << it->second << endl;
		if ((it -> second > max) && (it->first >= 0)) {
			max = it -> second;
			cu = it -> first;
		}
	}
	cout << ans+max << endl << cu << endl;
	return 0;
}