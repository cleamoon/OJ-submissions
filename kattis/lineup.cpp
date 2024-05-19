#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector <string> s;
	for(int i=0; i<n; i++) {
	    string str;
	    cin >> str;
		s.push_back(str);
	}
    bool in;
    if(s[0] > s[1]) in = false;
    else if (s[0] < s[1]) in = true;
    else {
        cout << "NEITHER" << endl;
        return 0;
    }
    bool ans = true;
    for(int i=0; i+1<s.size(); i++) {
        if(in && s[i]>s[i+1]) {
            ans = false;
            break;
        } else if (!in && s[i]<s[i+1]) {
            ans = false;
            break;        
        }
    }
    if(ans) {
        if(in)
            cout << "INCREASING" << endl;
        else
            cout << "DECREASING" << endl;
    }
    else {
        cout << "NEITHER" << endl;
    }
	return 0;
}
