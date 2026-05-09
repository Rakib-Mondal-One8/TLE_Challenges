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
	int n;
	cin >> n;

	vector<int>f(n + 1);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		f[x]++;
	}
	sort(f.rbegin(), f.rend());
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		if (i)f[i] = max(0LL, min(f[i], f[i - 1] - 1));
		ans += f[i];
	}
	cout << ans << nl;
}
int32_t main()
{
	// init_code();
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--)
	{
		RakibOne8();
	}
	return 0;
}