#include <iostream>
#define MAX 100
#define ULL long long 
using namespace std;

ULL n;
char *ch;

bool check(char *ch, ULL n);
void change(char *ch, ULL n);

int main(void) {
    cin >> n;
    ch = new char [n];
    for(ULL i=0; i<n; i++) {
        cin >> ch[i];
    }
    for(ULL i=0;; i++) {
        if(check(ch, n)) {
            cout << i << endl;
            return 0;
        }
        else {
            change(ch, n);
        }
    }
}

bool check(char *ch, ULL n) {
    for(ULL i=0; i<n-1; i++) {
//        cout << "check once" << endl;
        if((ch[i]=='H')and(ch[i+1]=='V')) {
            return 0;
        }
    }
    return 1;
}

void change(char *ch, ULL n) {
    for(ULL i=0; i<n-1; i++) {
        if((ch[i]=='H')and(ch[i+1]=='V')) {
            ch[i]='V';
            ch[i+1]='H';
            i++;
        }
    }
}

