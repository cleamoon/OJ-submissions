#include <iostream>
#define ULL unsigned long long
using namespace std;
int main(void) {
    ULL n, m;
    ULL upp=1, ner=1;
    cin >> n >> m;
    ULL ans=1;
    for(ULL i=1; i<=n-1; i++) {
        ans *= (m + n - i);
        ans /= i;
    }
    cout << ans << endl;
    return 0;
}
