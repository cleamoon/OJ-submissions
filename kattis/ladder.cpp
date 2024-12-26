#include <iostream>
#include <cmath>
#define PI 3.1415926535898
using namespace std;

int main(void) {
	double a, b;
	cin >> a >> b;
	cout << (long)(a/sin(b*PI/180)+1) <<endl;
	return 0;
}
