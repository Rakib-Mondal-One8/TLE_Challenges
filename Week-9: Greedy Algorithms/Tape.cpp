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
	int n, m, k;
	cin >> n >> m >> k;

	vector<int>a(n);
	for (auto &x : a)cin >> x;

	vector<int>gaps;
	for (int i = 1; i < n; i++) {
		int gap = (a[i] - a[i - 1]) - 1;
		gaps.push_back(gap);
	}
	int ans = n;

	sort(gaps.begin(), gaps.end());
	for (int i = 0; i < n - k; i++) {
		ans += gaps[i];
	}
	cout << ans << nl;
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