#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int t;
    cin >> t;
    
    set<int> ps;
    
    for (int i = 100; i < 999; i++) {
        for (int j = i; j < 1000; j++) {
            int p = i * j;
            string s = to_string(p);
            bool pl = true;
            for (int k = 0; k < s.size()/2; k++) {
                if (s[k] != s[s.size()-k-1]) {
                    pl = false;
                    break;
                }
            }
            if (pl) ps.insert(p);
        }
    }

    vector<int> num (ps.begin(), ps.end());
    sort(num.begin(), num.end());
    
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int ans = 0;
        for (int i = num.size()-1; i>=0; i--) {
            if (num[i] < n) {
                cout << num[i] << endl;
                break;
            }
        }
    }
    return 0;
}
