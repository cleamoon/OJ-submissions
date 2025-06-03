#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main(void) {
  LL n, tmp, ans = 0;
  scanf("%lld", &n);
  for(LL i=0; i<n; i++) {
    scanf("%lld", &tmp);
    if(tmp < 0) ans++;
  }
  cout << ans << endl;
  return 0;
}
