#include <bits/stdc++.h>
#define ULL unsigned long long
#define MOD 1000000007
#define INF 65536*2
using namespace std;

int main(void) {
	ULL n, k;
	cin >> n >> k;
	ULL combi[INF][55];
	ULL key[INF];
	combi[0][0] = 1;
	for (ULL i = 1; i <= n; ++i) {
		for (ULL j = 0; j <= k; ++j) {
			combi[i][j] = combi[i - 1][j];
			if (j > 0)
				combi[i][j] += combi[i - 1][j - 1];
			if (combi[i][j] >= MOD)
				combi[i][j] -= MOD;
		}
	}

	for (ULL i = 0; i < n; ++i)
		scanf("%llu", &key[i]);
	sort(key, key + n);
	ULL res = 0;
	for (ULL i = 0; i < n; ++i)
		res = (res + key[i] * combi[i][k - 1]) % MOD;
	cout << res << endl;
	return 0;
}
