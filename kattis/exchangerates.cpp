#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <cmath>
using namespace std;

double cd, ad, adt, cdt, change;
double COST=0.970;

inline double max(double a, double b) {
  //   cout << a << " " << b << endl;
  if (a>b) 
    return a;
  else
    return b;
}

inline double r(double a) {
  //  return round((a*100))/100;
  return ((double)((unsigned long long)(a*100)))/100;
}

int main(void) {
  int n;
  //  cout << r(120.123) << " " << r(120.236) << endl;
  while(1) {
    scanf("%d", &n);
    if (!n) {
      break;
    }
    cd = 1000.0;
    ad = 0.0;
    for(int j=0; j<n; j++) {
      scanf("%lf", &change);
      //      cout << change << endl;
      adt = max(ad, r(cd/change*COST));
      cdt = max(cd, r(ad*change*COST));
      ad = adt;
      cd = cdt;
    }
    printf("%.2lf\n", cd);
  }
  return 0;
}
 
