#include <iostream>
using namespace std;
int main(void) {
    int in;
    cin >> in;
    in *= 1000;
    int ai=1, ai1=1, tmp;
    in -= (ai+ai1);
    for (int i=3;; i++) {
        tmp = ai + ai1;
        in -= tmp; 
        if(in <= 0) {
            cout << i-1 << endl;
            break;
        }
        else {
            ai = ai1;
            ai1 = tmp;
            continue;
        }
    }
    return 0;
}
