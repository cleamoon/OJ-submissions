#include <bits/stdc++.h>
#define ULL int
using namespace std;

int main(void) {
	vector <int> should = {1, 1, 2, 2, 2, 8};
	vector <int> have;
	int tmp;
	for(int i=0; i<6; i++) {
		cin >> tmp;
		have.push_back(tmp);
	}
	for(int i=0; i<5; i++) {
		cout << should[i]-have[i] << " ";
	}
	cout << should[5]-have[5] << endl;
	return 0;
}