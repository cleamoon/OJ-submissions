#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    char c = '\0';
    for(int i=0; i<s.length(); i++) {
        if(s[i] != c) printf("%c", s[i]);
        c = s[i];
    }
    printf("\n");
    return 0;
}
