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

typedef unsigned long long ull;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        string num;
        cin >> num;
        ull maxp = 0;
        for (int i = 0; i < n - k - 2; i++) {
            ull prod = 1;
            for (int j = 0; j < k; j++) {
                prod *= num[i + j] - '0';
            }
            if (prod > maxp)
                maxp = prod;
        }
        cout << maxp << endl;
    }
    return 0;
}
