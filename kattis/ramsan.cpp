#include <iostream>
using namespace std;

int func (int n, int k) {
  if (n==1) {
    return 1;
  }
  else {
    return ((func (n-1, k) + k - 1) % n + 1);
  }
}

int main(void) {
  int k, n;
  cin >> k >> n;
  cout << func (n, k) << endl;
  return 0;
}
