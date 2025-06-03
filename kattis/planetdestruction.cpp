#include <bits/stdc++.h>
#define eps 1e-7
using namespace std;

typedef long long ll;
typedef double dd;
dd r;
ll k;
dd pi = 3.1415926535798;
vector<dd> kommer, v, w;
vector<pair<dd, dd> > inne;

bool innehall(dd t) {
    // cout << t << endl;
    inne.clear();

    for (ll i = 0; i < k; i++) {
        if (t < kommer[i]) continue;
        dd om = v[i] * (t - kommer[i]);
        // cout << om << endl;
        if (om >= pi) return true;
        inne.push_back(make_pair(w[i] - om, w[i] + om));
    }

    dd minim = 2*pi+1, maxim = 0;
    for (ll i = 0; i < inne.size(); i++) {
        if (inne[i].first < 0) {
            minim = min(minim, inne[i].first);
            inne[i].first = 0;
        }
        if (inne[i].second > 2*pi) {
            maxim = max(maxim, inne[i].second);
            inne[i].second = 2*pi;
        }
    }
    
    if (minim < 0) inne.push_back(make_pair(2*pi + minim, 2*pi + eps));
    if (maxim > 2*pi) inne.push_back(make_pair(-eps, maxim - 2*pi));

    sort(inne.begin(), inne.end());

    if (inne[0].first > 0) return false;
    dd cur = inne[0].second;
    for (ll i = 1; i < inne.size(); i++) if (inne[i].first <= cur) cur = max(cur, inne[i].second);
    return cur >= 2*pi;
}

void solve() {
    cin >> r >> k;
    kommer.clear();
    v.clear();
    w.clear();
    dd x, y, rocketv, virusv;
    for (ll i = 0; i < k; i++) {
        cin >> x >> y >> rocketv >> virusv;
        kommer.push_back((sqrt(x*x+y*y)-r) / rocketv);
        w.push_back(atan2(y, x) + pi);
        v.push_back(virusv / r);      
    }
    dd ll = 0, rr = 2*1000000;
    while (rr - ll > eps) {
        dd mid = (rr + ll) / 2;
        // cout << mid << endl;
        if (innehall(mid)) rr = mid;
        else ll = mid;

        // cout << mid << endl;
    }
    cout << fixed << setprecision(12) << ll << endl;
}

int main() {
    ll N;
    cin >> N;
    for (ll i = 0; i < N; i++) solve();
    return 0;
}