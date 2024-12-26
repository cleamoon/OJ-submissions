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
    vector<unsigned long long> num = {1, 2};
    int i = 0;
    unsigned long long lim = 40000000000000000;
    while (true) {
        unsigned long long s = num[i] + num[i+1];
        if (s > lim) break;
        num.push_back(s);
        i++;
    }
    
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        unsigned long long n;
        cin >> n;
        unsigned long long sum = 0;
        for (int i = 1; i < num.size(); i++) {
            if (num[i] > n) break;
            if (i % 3 == 1) sum += num[i];
        }
        cout << sum << endl;
    }
    return 0;
}
