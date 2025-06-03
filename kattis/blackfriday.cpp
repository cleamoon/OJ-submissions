#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#define ULL unsigned
using namespace std;

int main(void) {
	ULL n, input, max=0, maxid, size=101;
	vector <pair <ULL, ULL> > list;
	for(ULL i=0; i<size; i++) {
		pair<ULL, ULL> p = make_pair(0, 0);
		list.push_back(p);
	}
	cin >> n;	
	for(ULL i=0; i<n; i++) {
		cin >> input;
		list[input].first ++;
		list[input].second = i+1;
	}
/*	for(ULL i=0; i<n; i++) {
		cout << list[i].first << endl;
	}*/
	for(ULL i=0; i<size; i++) {
		if(list[i].first==1 && i>max) {
			max = i;
			maxid = list[i].second;
		}
	}
	if (max==0) {
		cout << "none" << endl;
	}
	else {
		cout << maxid << endl;
	}
	return 0;
}
