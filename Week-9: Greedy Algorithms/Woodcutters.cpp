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

	vector<int>x(n + 2), h(n + 2);
	x[0] = -1e18;
	x[n + 1] = 1e18;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		cin >> h[i];
	}
	debug(x);

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (x[i] - h[i] > x[i - 1]) {
			cnt++;
			continue;
		}
		if (x[i] + h[i] < x[i + 1]) {
			cnt++;
			x[i] += h[i];
		}
	}
	debug(x, h);
	cout << cnt << nl;
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