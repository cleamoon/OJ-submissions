#include <bits/stdc++.h>
using namespace std;

typedef long long ULL;

int main(void) {
    ULL k, t;
    scanf("%lld", &k);
    vector <ULL> v;
    v.push_back(0);
    for(ULL i=0; i<k; i++) {
        scanf("%lld", &t);
        v.push_back(t ^ *(v.end()-1));
    }
    ULL n = 0;
    /*
    for(ULL i=0; i<l; i++) {
        n ^= v[i];
    }
    v.push_back(n);
    l++;*/
    //v.push_back(0);
    for(ULL i=0; i<=k; i++) {
        v.push_back(v[i]);
    }

    /*    for(ULL i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;*/
    
    //    l *= 2;
    scanf("%llu", &n);
    ULL b, e, d;
    for(ULL i=0; i<n; i++) {
        scanf("%lld%lld", &b, &e);
        d = (e-b+1) % (k+1);
        b--;
        b %= (k+1);
        ULL ans = 0, bd = b+d; /*
        for(ULL j=b; j<=bd; j++) {
            t = j > l ? j-l : j;
            ans ^= v[t];
            }
            printf("%llu\n", ans);*/
        printf("%lld\n", v[b] ^ v[bd]);
    }
    return 0;
}
