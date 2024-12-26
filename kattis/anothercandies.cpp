#include <cstdlib>
#include <cstdio>
#include <cmath>
#define ULL unsigned long long
using namespace std;

ULL test, n;

int main(void) {
  scanf("%llu", &test);
  for(ULL t=0; t<test; t++) {
    scanf("%llu", &n);
    ULL res=0, tmp;
    for(ULL i=0; i<n; i++) {
      scanf("%llu", &tmp);
      res += tmp;
      res %= n;
    }
    if (!res) {
      printf("YES\n" );
    }
    else {
      printf("NO\n");
    }
  }
  return 0;
}
