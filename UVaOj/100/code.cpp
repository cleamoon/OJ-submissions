#include <iostream>
#include <array>
using namespace std;

int calc(int in, int ans = 1) {
    if (in == 1) return ans;
    else if (in % 2 == 0) return calc(in / 2, ans + 1);
    else return calc(3 * in + 1, ans + 1);
} 

int main(void) {
    int b, e;
    while(cin >> b >> e) {
        int maxima = -1;
        int beg, end;
        if (b <= e) {
            beg = b;
            end = e;
        } else {
            beg = e;
            end = b;
        }
        for (int i = beg; i <= end; i++) {
            int res = calc(i);
            if (res > maxima) maxima = res;
        }
        cout << b << ' ' << e << ' ' << maxima << endl;
    }
    return 0;
}