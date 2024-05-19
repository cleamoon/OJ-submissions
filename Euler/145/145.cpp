#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull lim = 1000000000;

inline ull rev(ull i) {
    if (i % 10 == 0)
        return i;
    ull ans = 0;
    while (i != 0) {
        ans *= 10;
        ans += i % 10;
        i /= 10;
    }
    return ans;
}

int main() {
    ull ans = 0;

    for (int i = 1; i <= lim; i++) {
        ull s = i + rev(i);
        bool isrevnum = true;
        while (s != 0) {
            if ((s % 10) % 2 == 0) {
                isrevnum = false;
                break;
            } else {
                s /= 10;
            }
        }
        if (isrevnum) {
            ans += 1;
        }
    }
    cout << ans << endl;
}