/* This is an example solution to the "A Different List Game" problem
 * from the Spotify Programming Challenge, held on May 29, 2010.
 *
 * The solution is provided as-is, is not documented, and may be
 * generally difficult to read.
 *
 * This work by Scrool (http://scrool.se/) is licensed under a
 * Creative Commons Attribution-Share Alike 2.5 Sweden License
 * (http://creativecommons.org/licenses/by-sa/2.5/se/deed.en).  You
 * are free to redistribute it as you like as long as this license
 * information is not removed.
 */
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

bool debug = true;

vi reduct(vi v, const vi &p) {
  for (int i = 0; i < p.size(); ++i)
    if (!v[p[i]]--) return vi();
  return v;
}

int gen(vector<int> v, vector<int> lb, int tobeat) {
  int tot = 0;
  for (int i = 0; i < v.size(); ++i) tot += v[i];

  if (lb.empty()) lb.push_back(0);
  else
  for (int i = 0; ++lb[i] >= v.size(); ++i) {
    if (i == lb.size()-1) {
      lb = vi(lb.size()+1, 0);
      break;
    } else {
      lb[i] = lb[i+1]+1;
      for (int j = 0; j < i; ++j)
	lb[j] = lb[i];
    }
  }

  if (tobeat >= tot/lb.size()) return tobeat;
  vi g = reduct(v, lb);
  if (!g.empty()) tobeat = 1+gen(g, lb, max(tobeat-1, 0));
  tobeat = gen(v, lb, tobeat);
  return tobeat;
}

int main(void) {
  ll X;
  vector<int> v;
  scanf("%lld", &X);
  int k = 0;
  for (ll p = 2; p*p <= X; ++p) {
    int e = 0;
    while (X % p == 0) X /= p, ++e;
    if (e) {
      ++k;
      if (e > 1) v.push_back(e-1);
    }
  }
  if(debug) {
	  for(vi::iterator it=v.begin(); it != v.end(); it++) {
		  cout << *it << endl;
	  }
  }
  if (X != 1) ++k;
  vi lb(1, v.size());
  if (!v.empty()) k += gen(v, lb, 0);
  printf("%d\n", k);
  return 0;
}
