#include <iostream>
#define ULL unsigned long long
using namespace std;
int main() {
    ULL n, h, b, k;
    ULL tK=0;
    cin >> n;
    for(ULL i=0; i<n; i++) {
        cin >> h >> b >> k;
        if(h>=b)
            continue;
        else {
            tK += k*(b-h);
        }
    }
    cout << tK << endl;
    return 0;
}
