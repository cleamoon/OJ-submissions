#include <iostream>
#include <cmath>
#define ULL unsigned long long 
using namespace std;

ULL countd (ULL r1, ULL r2) {
  return ((ULL) (sqrt(4*r1*r2)))+1;
}

int main(void) {
  cout << 302 << endl;
  cout << 0 << " " << 1000000 << endl;
  ULL p = countd (1000000, 300);
  for (ULL i=0; i<300; i++) {
    cout << p << " " << 300-i << endl;
    p += countd(300-i, 300-i-1);
  }
  cout << p+countd(1, 1000000) << " " << 1000000 << endl;
  return 0;
}
