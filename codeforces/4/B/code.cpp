#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int sum(vector<int> v) {
    int s = 0;
    for (auto i : v) {
        s += i;
    }
    return s;
}

int main(void) {
    int n, t;
    cin >> n >> t;
    vector<int> l(n);
    vector<int> u(n);
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> u[i];
    }
    int ls = sum(l), us = sum(u);
    if (t < ls || t > us) {
        cout << "NO" << endl;
	return 0;
    }
    cout << "YES" << endl;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      ans[i] = l[i];
      t -= l[i];
    }
    for (int i = 0; i < n; i++) {
      if (u[i] - l[i] >= t) {
	ans[i] += t;
	break;
      } else {
	ans[i] += u[i] - l[i];
	t -= u[i] - l[i];
      }
    }
    for (auto i : ans) {
      cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
