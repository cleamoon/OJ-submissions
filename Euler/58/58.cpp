#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

typedef unsigned long long unit;

int main(void) {
    unit lim = 1000000000;

    bool* num = new bool[lim];
    fill_n(num, lim, true);

    for (unit i = 4; i < lim; i += 2) {
        num[i] = false;
    }
    
    for (unit i = 3; i < sqrt(lim); i += 2 ) {
        if (num[i]) {
            for (unit j = i * i; j < lim; j += i + i) {
                num[j] = false;
            }
        }
    }

    unit tot = 1;
    unit pri = 0;

    for (unit i = 0; i < lim; i++) {
        unit s = 2 * i + 3;
        unit k = s * s - s + 1;
        tot += 4;
        if (num[k]) pri += 1;
        if (num[k - s + 1]) pri += 1;
        if (num[k - s - s + 2]) pri += 1;
        if ((double) pri / (double) tot < 0.1) {
            cout << s << endl;
            break;
        }
    }
    return 0;
}