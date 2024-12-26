#include <iostream>
#define ULL unsigned long long 
using namespace std;

ULL pow2(ULL in) {
    ULL out = 2;
    while(in!=1) {
        out *= 2;
        in --;
    }
    return out;
}

int main() {
    ULL cases;
    cin >> cases;
    for(ULL i=0; i<cases; i++) {
        ULL exp;
        cin >> exp;
        cout << pow2(exp) - 1 << endl;
    }
    return 0;
}
