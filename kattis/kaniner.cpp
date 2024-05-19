#include <iostream>
#define ULL long long 
using namespace std;

ULL x, y;
ULL *a;
ULL sum(ULL *a, ULL x);
void monthGo(ULL *a, ULL x, ULL y);

int main(void) {
    cin >> x >> y;
    a = new ULL [x];
    a[0] = 1;
    for(ULL i=1; i<x; i++) {
        a[i] = 0;
    }
    for(ULL i=0; i<9; i++) {
        monthGo(a, x, y);
        cout << sum(a, x) << " ";
    }
    monthGo(a, x, y);
    cout << sum(a, x) << endl;
    return 0;
}

ULL sum (ULL *a, ULL x) {
    ULL s=0;
    for(ULL i=0; i<x; i++) {
        s += a[i];
    }
    return s;
}

void monthGo(ULL *a, ULL x, ULL y) {
    if(x==1) {
        a[0] += a[0]*y;
    }
    else {
        ULL tmp = a[x-1];
        for(ULL i=x-2; i>=0; i--) {
            a[i+1] = a[i];
        }
        a[x-1] += tmp;
        a[0] = tmp*y;
    }
}


