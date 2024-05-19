#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define LL int 
using namespace std;

int main(void) {

	LL n;
	cin >> n;

	for(LL i=0; i<n; i++) {
		vector <LL> go;
		vector <LL> me;
		LL lgo, lme;
		cin >> lgo >> lme;
		for(LL j=0; j<lgo; j++) {
			LL tmp;
			cin >> tmp;
			go.push_back(tmp);
		}
		for(LL j=0; j<lme; j++) {
			LL tmp;
			cin >> tmp;
			me.push_back(tmp);
		}
		sort(go.begin(), go.end());
		sort(me.begin(), me.end());
		LL igo=0, ime=0;
		while(1) {
			if(igo == go.size()) {
				cout << "MechaGodzilla\n";
				break;
			}
			else if(ime == me.size()){
				cout << "Godzilla\n";
				break;
			}
			else {
				if(go[igo]<me[ime]) {
					igo++;
				}
				else {
					ime++;
				}
			}
		}
	}
	return 0;
}
