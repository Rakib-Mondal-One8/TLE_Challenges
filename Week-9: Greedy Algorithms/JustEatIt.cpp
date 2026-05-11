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

	vector<int>a(n);
	for (auto &x : a)cin >> x;

	int total = accumulate(a.begin(), a.end(), 0LL);
	debug(total);

	int mx = 0;
	auto go = [&](int start , int end) {
		int sum = 0;
		for (int i = start; i <= end; i++) {
			if (sum + a[i] <= 0) {
				sum = 0;
				continue;
			}
			sum += a[i];
			mx = max(mx, sum);
		}
	};
	go(0, n - 2);
	go(1, n - 1);

	debug(mx);
	if (mx >= total)cout << "NO" << nl;
	else cout << "YES" << nl;
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