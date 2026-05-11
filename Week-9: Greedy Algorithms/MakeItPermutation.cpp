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
	int n, c, d;
	cin >> n >> d >> c;

	set<int>s;
	vector<int>a(n + 1);
	int sol = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (s.count(x) == 0) {
			s.insert(x);
		}
		else sol += d;
	}

	int cnt = 0;
	for (auto x : s)a[++cnt] = x;

	int ans = 2e18;

	for (int i = 1; i <= cnt; i++) {
		ans = min(ans, (a[i] - i) * c + (cnt - i) * d);
	}

	ans = min(ans, (cnt * d) + c);
	cout << ans + sol << nl;
}
int32_t main()
{
	init_code();
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--)
	{
		RakibOne8();
	}
	return 0;
}