#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
    string doc("ABCDEFGHIJKLMNOPQRSTUVWXYZ_.");
    unsigned l = doc.length();
    unsigned k;
    string s;
    while(1) {
        cin >> k; if(!k) break;
        cin >> s;
        reverse(s.begin(),s.end());
        for(unsigned i=0; i<s.length(); i++) {
        	unsigned n = doc.find(s[i]);
            //unsigned n = s[i]-'A';
            n = (n+k)%l;
            printf("%c", doc[n]);
        }
        cout << endl;
    }
    return 0;
}