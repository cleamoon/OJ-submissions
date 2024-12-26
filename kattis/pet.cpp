#include <iostream>
#include <cstdio>
#define ULL unsigned int
using namespace std;

int main(void) {
  ULL a, b, c, d, sum, max=0, maxid, id=1;
  while(scanf("%u%u%u%u", &a, &b, &c, &d)==4) {
    sum = a + b + c + d;
    if(sum > max) {
      maxid = id;
      max = sum;
    }
    id ++;
    //    cout << maxid << " " << max << endl;
  }
  cout << maxid << " " << max << endl;
  return 0;
}
