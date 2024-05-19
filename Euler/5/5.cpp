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
    
    int prime[41];
    
    for (int i = 0; i < 41; i++) {
        prime[i] = true;
    }
    for (int i = 4; i < 41; i += 2) {
        prime[i] = false;
    }
    for (int i = 3; i < 41; i += 2) {
        for (int j = i * i; j < 41; j += 2 * i) {
            prime[j] = false;
        }
    }
    
    vector<vector<int>> nfact;
    vector<int> f0 = {0};
    vector<int> f1 = {1};
    nfact.push_back(f0);
    nfact.push_back(f1);
    
    for (int i = 2; i < 41; i++) {
        int ci = i;
        vector<int> fact ;
        while (ci != 1) {
            for (int j = 2; j < 41; j++) {
                if (prime[j] and ci % j == 0) {
                    fact.push_back(j);
                    ci /= j;
                    break;
                }
            }
        }
        nfact.push_back(fact);
    }
    
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        unsigned long long ans = 1;
        for (int i = 2; i <= n; i++) {
            unsigned long long ca = ans;
            vector<int> un;
            for (auto p : nfact[i]) {
                if (ca % p != 0) {
                    un.push_back(p);
                } else {
                    ca /= p;
                }
            }
            for (auto p : un) {
                ans *= p;
            }
        }
        cout << ans << endl;
    }
    return 0;
}