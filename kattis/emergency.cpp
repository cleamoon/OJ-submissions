#include <iostream>
#define ULL unsigned long long
using namespace std;
int main(void) {
    ULL end, step;
    cin >> end >> step;
    end --;
    ULL ans=0;
    if(step*2<=end) {
        ans = step;
        ans += end%step + 1;
    }
    else {
        ans = end;
    }
    cout << ans << endl;
    return 0;
}
