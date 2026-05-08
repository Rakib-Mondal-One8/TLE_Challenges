#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#ifdef Rakib_18
#include "debug.hpp"
#else
#define debug(...)
#endif
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void RakibOne8()
{
	int n, m;
	cin >> n >> m;

	vector<int>a(n);
	for (auto &x : a)cin >> x;

	vector<int>f(m + 1);
	vector<int>changes;
	for (int i = 0; i < n; i++) {
		if (a[i] > m)changes.push_back(i);
		else {
			if (f[a[i]] == n / m)changes.push_back(i);
			else f[a[i]]++;
		}
	}

	int changesSum = 0;
	for (int i = 1; i <= m; i++) {
		while (f[i] < n / m) {
			a[changes.back()] = i;
			changes.pop_back();
			changesSum++;
			f[i]++;
		}
	}

	cout << n / m << " " << changesSum << nl;
	for (auto x : a)cout << x << " ";
	cout << nl;
}
int32_t main()
{
	// init_code();
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	// cin >> t;
	while (t--)
	{
		RakibOne8();
	}
	return 0;
}