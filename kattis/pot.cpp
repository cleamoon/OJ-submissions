#include <bits/stdc++.h>
#define ULL unsigned long long
using namespace std;

ULL power(ULL base, ULL po) {
    int ans = 1;
    for(int i=0; i<po; i++) {
        ans *= base;
    }
    return ans;
}

int main(void) {
    int n, ans=0, t;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> t;
        ans += power(t/10, t%10);
    }
    cout << ans << endl;
    return 0;
}
