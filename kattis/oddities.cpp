#include <iostream>
using namespace std;

int main(void) {
	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		int in;
		cin >> in;
		if(in%2) {
			cout << in << " is odd\n";
		}
		else {
			cout << in << " is even\n";
		}
	}
	return 0;
}