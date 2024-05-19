#include <iostream>
#define US int
using namespace std;
int main(void) {
    US h, w, sum=0;
    char ch;
    cin >> h >> w;
    bool a[w][h];
    for(US i=0; i<h; i++) 
        for(US j=0; j<w; j++) {
            if((cin >> ch, ch)=='.')
                a[j][i]=0;
            else
                a[j][i]=1;
        }
    for(US i=0; i<w; i++) {
        bool ifneed=0;
        for(US j=0; j<h; j++) 
            if(a[i][j]) {
                ifneed = 1;
                break;
            }
            else
                continue;
        if(!ifneed)
            continue;
        else {
            US highest;
            for(US j=h-1; j>=0; j--) {
                if(a[i][j]) highest=j;
            }
            for(US j=h-1; j>highest; j--) 
                if(!a[i][j])
                    sum++;
        }
    }
    cout << sum << endl;
    return 0;
}
