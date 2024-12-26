#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(void) {
	string in;
	cin >> in;
	double upper=0.0, lower=0.0, space=0.0, other=0.0;
	for(unsigned i=0; i<in.size(); i++) {
		if((in[i]>='a')&&(in[i]<='z')) {
			lower += 1.0;
		}
		else if((in[i]>='A')&&(in[i]<='Z')) {
			upper += 1.0;
		}
		else if(in[i]=='_') {
			//	cout << "yes" << endl;
			space += 1.0;
		}
		else {
			other += 1.0;
		}
	}
	double sum = upper + lower + space + other;
	printf("%.15f\n%.15f\n%.15f\n%.15f\n", space/sum, lower/sum, upper/sum, other/sum);
	return 0;
}
