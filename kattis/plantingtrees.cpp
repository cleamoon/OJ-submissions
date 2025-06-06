#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define LL unsigned long long
using namespace std;

int main(void) {
	LL tot; 
	cin >> tot;
	vector <LL> trees;
	for(LL i=0; i<tot; i++) {
		LL tmp;
		cin >> tmp;
		trees.push_back(tmp);
	}
	sort(trees.begin(), trees.end());
	for(LL i=0; i<tot; i++) {
		trees[tot-i-1] += i+1;
		//cout << trees[tot-i-1] << endl;
	}
	LL max=0;
	for(LL i=tot; i>0; i--) {
		if(trees[i-1]>max) {
			max = trees[i-1];
		}
	}
	cout << max+1 << endl;
	return 0;
}
